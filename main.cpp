#include "ez-draw++.hpp"
#include "Formes.hpp"
#include "Rectangle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"
#include "Cercle.hpp"

#include <iostream>
#include <fstream>

class MyWindow : public EZWindow
{
	Formes * gestion;	//Sert a pointer sur le gestionnaire de forme
	Forme * selected_form;	//Sert a pointer sur une forme
	int dist_x, dist_y;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme
public:
	MyWindow(int w, int h, const char *name, Formes * _gestion)
		: EZWindow(w, h, name), gestion(_gestion)
	{}

	void expose() {
		gestion->dessiner(*this);
	}

	void keyPress(EZKeySym keysym)	//Quand un touche est enfoncé
	{
		switch (keysym)
		{
		case EZKeySym::Escape:
		case EZKeySym::q:
			EZDraw::quit();	//Quitte l'apllication
			break;
		case EZKeySym::a:
			sendExpose();	//Refresh
			break;
		default: // Dans tous les autres cas on ne fait rien
			break;
		}
	}

	void buttonPress(int x, int y, int button) {	//Clic souris
		selected_form = gestion->isOver(x, y);	//Selection de la forme
		dist_x= x - selected_form->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
		dist_y = y - selected_form->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
	}

	void motionNotify(int x, int y, int button) {	//Mouvement de souris
		if (selected_form != nullptr) {	//Si on clic sur une forme
			selected_form->setAncre(x-dist_x, y-dist_y);	//On bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
			sendExpose();	//on update la vue
		}
	}

	void buttonRelease(int x, int y, int button) {	//Relachement du clic souris
		selected_form = nullptr;	//Quand on lache la souris on déselectionne la forme
	}
};


int main(int , char * [])
{
	EZDraw ezDraw;
	ezDraw.setAutoQuit(true);	//Permet de terminer le programme en cliquant sur la croix rouge

	Formes gestion(10);	//Creer un gestionnaire de forme

	Rectangle * r1 = new Rectangle(ez_red, 10, 10, 100, 50);	//Creer un Rectangle
	gestion.ajouter(r1);	//Ajoute un pointeur sur le Rectangle au gestionnaire

	Carre * c1 = new Carre(ez_magenta, 200, 40, 40);	//Creer un Carre
	gestion.ajouter(c1);	//Ajoute un pointeur sur le Carre au gestionnaire

	Ellipse * e1 = new Ellipse(ez_blue, 20, 150, 100, 40);	//Creer une Ellipse
	gestion.ajouter(e1);	//Ajoute un pointeur sur l'Ellipse au gestionnaire

	Cercle * ce1 = new Cercle(ez_green, 150, 130, 60);	//Creer un Cercle
	gestion.ajouter(ce1);	//Ajoute un pointeur sur le Cercle au gestionnaire

	
	//ecrire un fichier
	std::filebuf fb;	//Creer un buffer
	fb.open("test.txt", std::ios::out);	//Ouvre le fichier en ecriture
	std::ostream os(&fb);	//Creer un ostream avec ce buffer
	gestion.sauver(os);		//Sauvegarde la fenetre dans le fichier
	fb.close();	//Ferme le fichier

	//Lire un fichier 
	try {
		if (fb.open("test2.txt", std::ios::in)) {	//Ouvre le fichier en lecture
			std::istream is(&fb);	//Crrer un istream avec ce buffer
			gestion.charger(is);	//Creation du gestionnaire de forme a partir du fichier
		}
		else throw std::runtime_error("Le fichier est introuvable");	//Si le fichier est introuvable

	} catch(const std::exception &e) {
		std::cerr << e.what();
	}

	MyWindow win1(400, 320, "TP3-Forme", &gestion);	//Creer un fenetre 
	win1.setDoubleBuffer(true);	//emepche le scientillement

	ezDraw.mainLoop();	//Boucle principale de la fenetre

	return 0;
}