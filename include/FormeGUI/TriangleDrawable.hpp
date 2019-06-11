// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef TRIANGLE_DRAWABLE_HPP
#define TRIANGLE_DRAWABLE_HPP


#include "Forme/Triangle.hpp"
#include "FormeDrawable.hpp"

class TriangleD : public fm::Triangle, public FormeD {
	PointD *p1, *p2;
	sf::Vector2f dist1, dist2;

	public:
		TriangleD(sf::Color couleur, int x1, int y1, PointD * p1, PointD * p2);
		TriangleD(const TriangleD & ori);
		TriangleD(std::istream & is);
		~TriangleD() override;
		bool isOver(int x, int y) const override;
		void dessiner(sf::RenderWindow & window) const override;
		void maj() override;
		void recalculate() override;

		float getArea(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f posSouris) const;

		//SFML Stuff
		std::size_t getPointCount() const override;
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif TRIANGLE_DRAWABLE_HPP
