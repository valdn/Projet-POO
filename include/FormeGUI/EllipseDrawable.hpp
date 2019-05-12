#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP


#include "Forme/Ellipse.hpp"
#include "FormeDrawable.hpp"


class EllipseD : public fm::Ellipse, public FormeD {
	public:
		EllipseD(sf::Color couleur, uint x, uint y, uint demiLargeur, uint demiHauteur);
		EllipseD(const EllipseD & ori);
		EllipseD(std::istream & is);
		~EllipseD() override;
		bool isOver(uint _x, uint _y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif ELLIPSE_DRAWABLE_HPP
