#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include "Gestionnaire.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "CercleDrawable.hpp"
#include "EllipseDrawable.hpp"

class MyApp : public Gestionnaire {
public:
	MyApp();
	~MyApp();

	void addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);
	void addCarre(sf::Color color, int x, int y, uint cote, size_t calque);
	void addCercle(sf::Color color, int x, int y, uint rayon, size_t calque);
	void addEllipse(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);
};

#endif // !MY_APPLICATION_HPP
