#include "MyApplication.hpp"

MyApp::MyApp() : Gestionnaire() {

}

MyApp::~MyApp() {}

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
