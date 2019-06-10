#include "MyApplication.hpp"

#include <regex>

MyApp::MyApp() : Gestionnaire() {

}

MyApp::~MyApp() {}

void MyApp::addPoint(int x, int y, size_t calque) {
	ajouter(new PointD(x, y), calque);
}

void MyApp::addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque) {
	ajouter(new RectangleD(color, x, y, largeur, hauteur), calque);
}

void MyApp::addCarre(sf::Color color, int x, int y, uint cote, size_t calque)
{
	ajouter(new CarreD(color, x, y, cote), calque);
}

void MyApp::addCercle(sf::Color color, int x, int y, uint rayon, size_t calque)
{
	ajouter(new CercleD(color, x, y, rayon), calque);
}

void MyApp::addEllipse(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque)
{
	ajouter(new EllipseD(color, x, y, largeur, hauteur), calque);
}

void MyApp::addImage(std::string path, int x, int y, size_t calque)
{
	ajouter(new PointD(0,0, false), calque);
	ajouter(new ImageD(path, x, y, getLastPoint()) , calque);

}

void MyApp::addTriangle(sf::Color color, int x, int y, size_t ip1, size_t ip2, size_t calque)
{
	PointD* p1 = getPointAt(ip1);
	PointD* p2 = getPointAt(ip2);
	ajouter(new TriangleD(color, x, y, p1, p2), calque);
}

void MyApp::addPolygone(sf::Color color, int x, int y, std::vector<PointD*> & tabPoint, size_t calque)
{
	ajouter(new PolygoneD(color, x, y, tabPoint), calque);
}

void MyApp::sauvegarder(std::string path) {
	std::filebuf fb;	//Creer un buffer
	fb.open(path, std::ios::out);	//Ouvre le fichier en ecriture
	std::ostream os(&fb);	//Creer un ostream avec ce buffer

	Gestionnaire::sauver(os);		//Sauvegarde les points

	fb.close();	//Ferme le fichier
}

void MyApp::charger(std::string path) {
	std::regex pattern{ ".shape" }; // on recherche le motif ".shape"
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

