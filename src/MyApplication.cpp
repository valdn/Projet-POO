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

void MyApp::addTriangle(sf::Color color, int x, int y, int p1x, int p1y, int p2x, int p2y, size_t calque)
{
	ajouter(new PointD(p1x, p1y), calque);
	PointD* p1 = getLastPoint();
	ajouter(new PointD(p2x, p2y), calque);
	PointD* p2 = getLastPoint();
	ajouter(new TriangleD(color, x, y, p1, p2), calque);
}

