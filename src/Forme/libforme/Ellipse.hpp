#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP


#include "Forme.hpp"

class Ellipse : public Forme, public sf::Shape {
	uint demiLargeur, demiHauteur;
	sf::VertexArray m_vertices;

	protected:
		void ecrire(std::ostream & os) const override;

	public:
		Ellipse(uint couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur);
		Ellipse(const Ellipse & ori);
		Ellipse(std::istream & is);
		~Ellipse() override;
		void reload() override;
		inline uint getDemiLargeur() { return demiLargeur; }
		inline uint getDemiHauteur() { return demiHauteur; }
		inline void setDemiLargeur(uint _demiLargeur) { demiLargeur = _demiLargeur; }
		inline void setDemiHauteur(uint _demiHauteur) { demiHauteur = _demiHauteur; }
		inline double perimetre() const override { return 2 * (demiHauteur + demiLargeur); }
		bool isOver(uint _x, uint _y) const override;

		//SFML Stuff
		virtual std::size_t getPointCount() const;
		virtual sf::Vector2f getPoint(std::size_t index) const;
};

#endif //ELLIPSE_HPP
