#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP


#include "Forme/Rectangle.hpp"
#include "FormeDrawable.hpp"

class RectangleD : public fm::Rectangle, public FormeD {
public:
	RectangleD(sf::Color couleur, int x, int y, uint largeur, uint hauteur);
	RectangleD(const RectangleD & ori);
	RectangleD(std::istream & is);
	~RectangleD() override;
	bool isOver(int _x, int _y) const override;
	void dessiner(sf::RenderWindow & window) const override;
	void maj() override;
	void recalculate() override;

	//SFML Stuff
	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;
};

#endif RECTANGLE_DRAWABLE_HPP
