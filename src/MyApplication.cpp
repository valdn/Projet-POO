#include "MyApplication.hpp"

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
	ajouter(new PointD(0, 0), calque);
	ajouter(new ImageD(path, x, y, getLastPoint()), calque);
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
