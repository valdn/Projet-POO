#ifndef POLYGONE_DRAWABLE_HPP
#define POLYGONE_DRAWABLE_HPP

#include <vector>

#include "Forme/Polygone.hpp"
#include "FormeDrawable.hpp"

class PolygoneD : public fm::Polygone, public FormeD {
	std::vector<PointD*> * tabPointD;
	std::vector <sf::Vector2f> tabDistance;

	public:
		PolygoneD(sf::Color couleur, int x1, int y1, std::vector<PointD*> * tabPoint);
		PolygoneD(const PolygoneD & ori);
		PolygoneD(std::istream & is);
		~PolygoneD() override;
		bool isOver(int x, int y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;
		void recalculate() override;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif POLYGONE_DRAWABLE_HPP
