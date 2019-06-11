// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef CERCLE_DRAWABLE_HPP
#define CERLCE_DRAWABLE_HPP

#include "Forme/Cercle.hpp"
#include "FormeDrawable.hpp"

class CercleD : public fm::Cercle, public FormeD {
	public:
		CercleD(sf::Color couleur, int x, int y, uint rayon);
		CercleD(const CercleD & ori);
		CercleD(std::istream & is);
		~CercleD() override;
		bool isOver(int _x, int _y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;
		void recalculate() override;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif CERLCE_DRAWABLE_HPP
