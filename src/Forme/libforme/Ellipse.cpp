#include "Ellipse.hpp"

void Ellipse::ecrire(std::ostream &os) const {
	os << "Ellipse ";
	Forme::ecrire(os);
	os << demiLargeur << ' ' << demiHauteur;
}

Ellipse::Ellipse(uint couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur) : Forme(couleur, x, y), demiLargeur(_demiLargeur), demiHauteur(_demiHauteur) {
	update();
}

Ellipse::Ellipse(const Ellipse & ori) : Ellipse(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.demiLargeur, ori.demiHauteur) {}

Ellipse::Ellipse(std::istream &is) : Forme(is) {
	is >> demiLargeur;
	is >> demiHauteur;
}

Ellipse::~Ellipse() {}

void Ellipse::update() {
	m_vertices.setPrimitiveType(sf::TriangleFan);
	m_vertices.resize(getPointCount());

	for (size_t i = 0; i < getPointCount(); ++i) {
		m_vertices[i].position = getPoint(i);
		m_vertices[i].color = sf::Color::Color(getCouleur());
	}
}

void Ellipse::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	// on applique la transformation
	states.transform *= Shape::getTransform();

	// Utilise pas de texture
	states.texture = NULL;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}

bool Ellipse::isOver(uint _x, uint _y) const {
	std::cout << ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + demiLargeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + demiHauteur)) << std::endl;
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + demiLargeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + demiHauteur));
}

std::size_t Ellipse::getPointCount() const
{
	return 30; // fixé, mais ça pourrait tout aussi bien être un attribut de la classe
}

sf::Vector2f Ellipse::getPoint(std::size_t index) const
{
	static const float pi = 3.141592654f;

	float angle = index * 2 * pi / getPointCount() - pi / 2;
	float x = std::cos(angle) * demiLargeur;
	float y = std::sin(angle) * demiHauteur;

	return sf::Vector2f(x + getAncre().getX(), y + getAncre().getY());
}
