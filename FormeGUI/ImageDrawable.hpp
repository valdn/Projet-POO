#ifndef IMAGE_DRAWABLE_HPP
#define IMAGE_DRAWABLE_HPP


#include "Forme/Image.hpp"
#include "FormeDrawable.hpp"

class ImageD : public fm::Image, public FormeD {
	PointD *p1;
	sf::Vector2f dist1;
	uint largeur, hauteur;


public:
	ImageD(std::string img, int x, int y, PointD * p1);
	ImageD(const ImageD & ori);
	ImageD(std::istream & is);
	~ImageD() override;
	bool isOver(int _x, int _y) const override;
	void dessiner(sf::RenderWindow & window) const override;
	void maj() override;
	void recalculate() override;
	inline void setTaille(float x, float y) { largeur = x, hauteur = y; }
	inline uint getLargeur() const { return largeur; }
	inline uint getHauteur() const { return hauteur; }


	//SFML Stuff
	std::size_t getPointCount() const override;
	sf::Vector2f getPoint(std::size_t index) const override;
};

#endif IMAGE_DRAWABLE_HPP
