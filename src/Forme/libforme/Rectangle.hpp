#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "Forme.hpp"

class Rectangle : public Forme, public sf::Shape {
	uint largeur, hauteur;
	sf::VertexArray m_vertices;

	protected:
		void ecrire(std::ostream & os) const override;

	public:
		Rectangle(uint couleur, uint x, uint y, uint _largeur, uint _hauteur);
		Rectangle(const Rectangle & ori);
		Rectangle(std::istream & is);
		~Rectangle() override;
		void reload() override;
		inline uint getLargeur() { return largeur; }
		inline uint getHauteur() { return hauteur; }
		inline void setLargeur(uint _largeur) { largeur = _largeur; }
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
		inline double perimetre() const override { return 2 * (hauteur + largeur); }
		bool isOver(uint _x, uint _y) const override;

		//SFML Stuff
		virtual std::size_t getPointCount() const;
		virtual sf::Vector2f getPoint(std::size_t index) const;
};

#endif //RECTANGLE_HPP
