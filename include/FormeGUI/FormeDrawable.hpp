#ifndef FORME_DRAWABLE_HPP 
#define FORME_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Forme.hpp"

class FormeD : public virtual fm::Forme, public sf::Shape {
	bool pleine;

	public:
		FormeD(uint _couleur, uint x, uint y);
		FormeD(const FormeD & ori);
		FormeD(std::istream & is);
		virtual ~FormeD();
		inline bool isPleine() { return pleine;	}
		inline void togglePleine() { pleine = !pleine; }
		virtual bool isOver(uint _x, uint _y) const = 0;
		virtual void maj() = 0;
		virtual void dessiner(sf::RenderWindow & window) const = 0;
		static FormeD* charger(std::istream & is);
};

#endif FORME_DRAWABLE_HPP 
