#ifndef FORME_DRAWABLE_HPP 
#define FORME_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Forme.hpp"
#include "PointDrawable.hpp"

class FormeD : public virtual fm::Forme, public sf::Shape {
	bool pleine;
	PointD ancreD;

	public:
		FormeD(sf::Color _couleur, uint x, uint y);
		FormeD(const FormeD & ori);
		FormeD(std::istream & is);
		virtual ~FormeD();
		inline bool isPleine() { return pleine;	}
		inline void togglePleine() { pleine = !pleine; }
		inline const PointD & getAncreD() const { return ancreD; }
		virtual bool isOver(uint _x, uint _y) const = 0;
		virtual void maj();
		virtual void dessiner(sf::RenderWindow & window) const = 0;
		static FormeD* charger(std::istream & is);
};

#endif FORME_DRAWABLE_HPP 
