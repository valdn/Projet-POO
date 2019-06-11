// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef CARRE_DRAWABLE_HPP
#define CARRE_DRAWABLE_HPP

#include "Forme/Carre.hpp"
#include "FormeDrawable.hpp"

class CarreD : public fm::Carre, public FormeD {
	public:
		CarreD(sf::Color couleur, int x, int y, uint _cote);
		CarreD(const Carre & ori);
		CarreD(std::istream & is);
		~CarreD() override;
		bool isOver(int _x, int _y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;
		void recalculate() override;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif CARRE_DRAWABLE_HPP
