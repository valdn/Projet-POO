#include "MyApplication.hpp"

#include <regex>

MyApp::MyApp() : Gestionnaire() {}

MyApp::~MyApp() {}

void MyApp::addPoint(int x, int y, size_t calque) {
	try {
		ajouter(new PointD(x, y), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque) {
	try {
		ajouter(new RectangleD(color, x, y, largeur, hauteur), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addCarre(sf::Color color, int x, int y, uint cote, size_t calque) {
	try {
		ajouter(new CarreD(color, x, y, cote), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addCercle(sf::Color color, int x, int y, uint rayon, size_t calque) {
	try {
		ajouter(new CercleD(color, x, y, rayon), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addEllipse(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque) {
	try {
		ajouter(new EllipseD(color, x, y, largeur, hauteur), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addImage(std::string path, int x, int y, size_t calque) {
	try {
		ajouter(new PointD(0, 0, false), calque);
		ajouter(new ImageD(path, x, y, getLastPoint()), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addTriangle(sf::Color color, int x, int y, size_t ip1, size_t ip2, size_t calque) {
	try {
		PointD* p1 = getPointAt(ip1);
		PointD* p2 = getPointAt(ip2);
		ajouter(new TriangleD(color, x, y, p1, p2), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::addPolygone(sf::Color color, int x, int y, std::vector<PointD*> & tabPoint, size_t calque) {
	try {
		ajouter(new PolygoneD(color, x, y, tabPoint), calque);
	}
	catch (std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::out_of_range & e) {
		std::cerr << e.what() << std::endl;
	}
}

void MyApp::sauvegarder(std::string path) {
	std::regex pattern{ ".shape$" }; // on recherche le motif ".shape$" i.e. se termine par ".shape"
	std::string target{ path };
	bool result = std::regex_search(target, pattern);
	if (!result) path = path + +".shape";

	std::filebuf fb;	//Creer un buffer
	fb.open(path, std::ios::out);	//Ouvre le fichier en ecriture et rajoute l'extension .shape
	std::ostream os(&fb);	//Creer un ostream avec ce buffer

	Gestionnaire::sauver(os);		//Sauvegarde les points

	fb.close();	//Ferme le fichier
}

void MyApp::charger(std::string path) {
	std::regex pattern{ ".shape$" }; // on recherche le motif ".shape$" i.e. se termine par ".shape"
	std::string target{ path };
	bool result = std::regex_search(target, pattern);
	if (result) {
		std::filebuf fb;	//Creer un buffer
		try {
			if (fb.open(path, std::ios::in)) {	//Ouvre le fichier en lecture
				std::istream is(&fb);	//Crrer un istream avec ce buffer

				Gestionnaire::charger(is);	//Charge les points
			}
			else throw std::runtime_error("Le fichier est introuvable");	//Si le fichier est introuvable
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		fb.close();	//ferme le fichier
	}
	else std::cerr << "Le fichier doit etre en .shape" << std::endl;
}

void MyApp::viderForme(FormeD * shape) {
	shape->setFillColor(sf::Color::Transparent);
	shape->togglePleine();
	shape->maj();
}

void MyApp::remplirForme(FormeD * shape) {
	shape->setFillColor(sf::Color(shape->getCouleur()));
	shape->togglePleine();
	shape->maj();
}

void MyApp::diminuerTrait(FormeD * shape) {
	if (shape->getOutlineThickness() < -1)
		shape->setOutlineThickness(shape->getOutlineThickness() + 1);
}

void MyApp::augmenterTrait(FormeD * shape) {
	if (shape->getOutlineThickness() > -10)
		shape->setOutlineThickness(shape->getOutlineThickness() - 1);
}

void MyApp::augTransparence(ImageD * img) {
	if (img->getTransparence() > 2) {
		img->setTransparence(img->getTransparence() - 2);
	}
}

void MyApp::dimTransparence(ImageD * img) {
	if (img->getTransparence() < 255) {
		img->setTransparence(img->getTransparence() + 2);
	}
}

void MyApp::move(FormeD * forme, int x, int y) {
	forme->setAncre(forme->getAncre().getX() + x, forme->getAncre().getY() + y);
	forme->maj();
	update();
}

void MyApp::move(PointD * point, int x, int y) {
	point->setPos(point->getX() + x, point->getY() + y);
	point->update();
	update();
}

void MyApp::manageGroupe(FormeD * forme, size_t index) {
	if (getGroupe(forme) != nullptr) {	//Si la forme est dans un groupe
		if (getGroupeAt(index)->inTab(forme))	//Si la forme appartient au groupe a l'index
			getGroupeAt(index)->supprimer(forme);	//On la supprime
		else
			swapToGroup(getGroupe(forme), getGroupeAt(index));	//Sinon on ajoute toutes les formes du groupe de la forme au groupe à l'index 
	}
	else
		getGroupeAt(index)->ajouter(forme);	//Sinon on ajoute la forme au groupe index
}

void MyApp::manageGroupe(FormeD * forme) {
	if (getGroupe(forme) != nullptr) {	//Si la forme est dans un groupe
		supprimer(getGroupe(forme));	//On supprime toutes les formes du groupe
	}
	else
		supprimer(forme);	//Sinon on supprime juste la forme
}

