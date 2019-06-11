#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Point.hpp"

class PointD {
	static std::vector<PointD*> tab_points;
	sf::Color couleur;
	fm::Point * point;
	sf::CircleShape cercle;
	bool partage;

	public:
		PointD(fm::Point * point, sf::Color couleur = sf::Color::Black, bool _partage = false);
		PointD(int x, int y, bool partage = true, sf::Color couleur = sf::Color::Black);
		PointD(const PointD & ori);
		PointD(std::istream & is);
		~PointD();
		inline const fm::Point & getPoint() const { return *point; }
		inline fm::Point * getPtrPoint() { return point; }
		inline void setPos(uint x, uint y) { point->setXY(x,y); }
		inline int getX() { return point->getX(); }
		inline int getY() { return point->getY(); }
		inline bool isPartaged() const { return partage; }
		void setColor(sf::Color couleur);
		void update();
		void dessiner(sf::RenderWindow & window) const;
		bool isOver(int x, int y) const;

		static PointD* charger(std::istream & is);
		static PointD* getPointD(const fm::Point * point);
		static size_t getPointDIndex(PointD * point);

		friend std::ostream & operator<<(std::ostream &os, const PointD & p);
};

#endif POINT_DRAWABLE_HPP