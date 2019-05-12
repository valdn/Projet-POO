#ifndef CERCLE_DRAWABLE_HPP
#define CERLCE_DRAWABLE_HPP

#include "Forme/Cercle.hpp"
#include "FormeDrawable.hpp"

class CercleD : public fm::Cercle, public FormeD {
	public:
		CercleD(sf::Color couleur, uint x, uint y, uint rayon);
		CercleD(const CercleD & ori);
		CercleD(std::istream & is);
		~CercleD() override;
		bool isOver(uint _x, uint _y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif CERLCE_DRAWABLE_HPP
