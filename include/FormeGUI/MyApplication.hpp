#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include <iostream>
#include <fstream>

#include "Gestionnaire.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "CercleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "ImageDrawable.hpp"
#include "PolygoneDrawable.hpp"

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
	void addTriangle(sf::Color color, int x, int y, size_t ip1, size_t ip2, size_t calque);
	void addPolygone(sf::Color color, int x, int y, std::vector<PointD*> & tabPoint, size_t calque);
	void sauvegarder(std::string path);
	void charger(std::string path);
};

#endif // !MY_APPLICATION_HPP
