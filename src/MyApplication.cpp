#include "MyApplication.hpp"

MyApp::MyApp() : Gestionnaire() {

}

MyApp::~MyApp() {}

void MyApp::addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque) {
	ajouter(new RectangleD(color, x, y, largeur, hauteur), calque);
}
