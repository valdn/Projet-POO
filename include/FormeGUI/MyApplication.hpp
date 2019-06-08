#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include "Gestionnaire.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "CercleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "ImageDrawable.hpp"

class MyApp : public Gestionnaire {
public:
	MyApp();
	~MyApp();

	void addPoint (int x, int y, size_t calque);
	void addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);
	void addCarre(sf::Color color, int x, int y, uint cote, size_t calque);
	void addCercle(sf::Color color, int x, int y, uint rayon, size_t calque);
	void addEllipse(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);
	void addImage(std::string path, int x, int y, size_t calque);
	void addTriangle(sf::Color color, int x, int y, int p1x, int p1y, int p2x, int p2y, size_t calque);
};

#endif // !MY_APPLICATION_HPP
