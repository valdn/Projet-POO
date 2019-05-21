#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Point.hpp"

class PointD {
	sf::Color couleur;
	fm::Point * point;
	sf::CircleShape cercle;

	public:
		PointD(fm::Point * point, sf::Color couleur = sf::Color::Black);
		PointD(int x, int y, sf::Color couleur = sf::Color::Black);
		PointD(const PointD & ori);
		~PointD();
		inline fm::Point & getPoint() const { return *point; }
		inline fm::Point * getPtrPoint() { return point; }
		inline void setPos(uint x, uint y) { point->setXY(x,y); }
		inline int getX() { return point->getX(); }
		inline int getY() { return point->getY(); }
		void update();
		void dessiner(sf::RenderWindow & window) const;
		bool isOver(int x, int y) const;
		static PointD* charger(std::istream & is);
		friend std::ostream & operator<<(std::ostream &os, const PointD & p);
};

#endif POINT_DRAWABLE_HPP