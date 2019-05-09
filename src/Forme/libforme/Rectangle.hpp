#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "Forme.hpp"

class Rectangle : public Forme, public sf::Drawable, public sf::Transformable {
	uint largeur, hauteur;
	sf::VertexArray m_vertices;

	protected:
		void ecrire(std::ostream & os) const override;

	public:
		Rectangle(uint couleur, uint x, uint y, uint _largeur, uint _hauteur);
		Rectangle(const Rectangle & ori);
		Rectangle(std::istream & is);
		~Rectangle() override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		inline uint getLargeur() { return largeur; }
		inline uint getHauteur() { return hauteur; }
		inline void setLargeur(uint _largeur) { largeur = _largeur; }
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
		inline double perimetre() const override { return 2 * (hauteur + largeur); }
		bool isOver(uint _x, uint _y) const override;

		//SFML Stuff
		virtual std::size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t index) const override;
		virtual void update() override;
};

#endif //RECTANGLE_HPP
