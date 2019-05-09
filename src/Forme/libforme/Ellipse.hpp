#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#ifndef M_PI
#define M_PI 3.14159265359
#endif

#include "Forme.hpp"

class Ellipse : public Forme, public sf::Drawable, public sf::Transformable {
	uint demiLargeur, demiHauteur;
	sf::VertexArray m_vertices;

protected:
	void ecrire(std::ostream & os) const override;

public:
	Ellipse(uint couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur);
	Ellipse(const Ellipse & ori);
	Ellipse(std::istream & is);
	~Ellipse() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	inline uint getDemiLargeur() { return demiLargeur; }
	inline uint getDemiHauteur() { return demiHauteur; }
	inline uint setDemiLargeur(uint _demiLargeur) { demiLargeur = _demiLargeur; }
	inline uint setDemiHauteur(uint _demiHauteur) { demiHauteur = _demiHauteur; }
	inline double perimetre() const override { return 2 * M_PI*sqrt(((demiLargeur ^ 2) + (demiHauteur ^ 2) / 2)); }
	bool isOver(uint _x, uint _y) const override;

	//SFML Stuff
	virtual std::size_t getPointCount() const override;
	virtual sf::Vector2f getPoint(std::size_t index) const override;
	virtual void update() override;
};
#endif //ELLIPSE_HPP
