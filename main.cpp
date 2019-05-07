#include "libforme/ez-draw++.hpp"
#include "libforme/Point.hpp"
#include "libforme/Forme.hpp"
#include "libforme/Rectangle.hpp"
#include "libforme/Ellipse.hpp"
#include "libforme/Formes.hpp"

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

	Ellipse * e1 = new Ellipse(ez_black, 50, 50, 100, 40);
	gestion.ajouter(e1);

	MyWindow win1(400, 320, "TP3-Forme", &gestion);

	ezDraw.mainLoop();

	return 0;
}