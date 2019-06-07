#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include "Gestionnaire.hpp"
#include "RectangleDrawable.hpp"

class MyApp : public Gestionnaire {
public:
	MyApp();
	~MyApp();

	MyApp* getMyApp() { return this; }
	void addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur);
};

#endif // !MY_APPLICATION_HPP
