#ifndef FORME_DRAWABLE_HPP 
#define FORME_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Forme.hpp"
#include "PointDrawable.hpp"

class FormeD : public virtual fm::Forme, public sf::Shape {
	bool pleine;
	PointD ancreD;
	uint trsp = 255;

	public:
		FormeD(sf::Color _couleur, int x, int y);
		FormeD(const FormeD & ori);
		FormeD(std::istream & is);
		virtual ~FormeD();
		inline bool isPleine() { return pleine;	}
		inline void togglePleine() { pleine = !pleine; }
		inline const PointD & getAncreD() const { return ancreD; }
		virtual bool isOver(int _x, int _y) const = 0;
		virtual void maj();
		virtual void recalculate() = 0;
		sf::Vector2f getDistance(const fm::Point p1, const fm::Point p2);
		virtual void dessiner(sf::RenderWindow & window) const = 0;
		static FormeD* charger(std::istream & is);
		inline int getTrsp() const { return trsp; }
		inline void setTrsp(int i) { trsp = i; }
};

#endif FORME_DRAWABLE_HPP 
