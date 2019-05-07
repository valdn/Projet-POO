#include "ez-draw++.hpp"
#include "Point.hpp"
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"
#include "Formes.hpp"

#include <iostream>
#include <fstream>

class MyWindow : public EZWindow
{
	Formes * gestion;
	Forme * selected_form;
public:
	MyWindow(int w, int h, const char *name, Formes * _gestion)
		: EZWindow(w, h, name), gestion(_gestion)
	{}

	void expose() {
		gestion->dessiner(*this);
	}

	void keyPress(EZKeySym keysym)
	{
		switch (keysym)
		{
		case EZKeySym::Escape:
		case EZKeySym::q:
			EZDraw::quit();
			break;
		case EZKeySym::a:
			sendExpose();	//Refresh
			break;
		default: // Dans tous les autres cas on ne fait rien (necessaire
			break; // pour eviter un warning a la compilation).
		}
	}

	void buttonPress(int x, int y, int button) {
		selected_form = gestion->isOver(x, y);
	}

	void motionNotify(int x, int y, int button) {
		if (selected_form != nullptr) {
			selected_form->setAncre(x, y);
			sendExpose();
		}
	}

	void buttonRelease(int x, int y, int button) {
		selected_form = nullptr;
	}
};


int main(int , char * [])
{
	EZDraw ezDraw;

	Formes gestion(10);

	Rectangle * r1 = new Rectangle(ez_red, 10, 10, 100, 50);
	gestion.ajouter(r1);

	Ellipse * e1 = new Ellipse(ez_blue, 50, 50, 100, 40);
	gestion.ajouter(e1);

	//Sauvegarder un fichier avec les formes
	std::filebuf fb;
	fb.open("test.txt", std::ios::out);
	std::ostream os(&fb);
	gestion.sauver(os);
	fb.close();

	//Lire un fichier pour creer les formes
	try {
		if (fb.open("test2.txt", std::ios::in)) {
			std::istream is(&fb);
			gestion.charger(is);
		}
		else throw std::runtime_error("Le fichier est introuvable");

	} catch(const std::exception &e) {
		std::cerr << e.what();
	}

	MyWindow win1(400, 320, "TP3-Forme", &gestion);

	ezDraw.mainLoop();

	return 0;
}