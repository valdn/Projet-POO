#include "Rectangle.hpp"

void Rectangle::ecrire(std::ostream &os) const {
	os << "Rectangle ";
	Forme::ecrire(os);
	os << largeur << ' ' << hauteur;
}

Rectangle::Rectangle(uint couleur, uint x, uint y, uint _largeur, uint _hauteur) : Forme(couleur, x, y), largeur(_largeur), hauteur(_hauteur) {
	update();
}

Rectangle::Rectangle(const Rectangle & ori) : Rectangle(ori.getCouleur(), ori.getAncre().getX(), ori.getAncre().getY(), ori.largeur, ori.hauteur) {}

Rectangle::Rectangle(std::istream &is) : Forme(is) {
	is >> largeur;
	is >> hauteur;
}

Rectangle::~Rectangle() {}

void Rectangle::update() {
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(getPointCount());

	for (size_t i = 0; i < getPointCount(); ++i) {
		m_vertices[i].position = getPoint(i);
		m_vertices[i].color = sf::Color::Color(getCouleur());
	}
}

void Rectangle::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	// on applique la transformation
	states.transform *= getTransform();

	// Utilise pas de texture
	states.texture = NULL;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}

bool Rectangle::isOver(uint _x, uint _y) const {
	return ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + largeur) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + hauteur));
}

std::size_t Rectangle::getPointCount() const {
	return 4; //Obligaotirement 4 points (les 4 sommets) pour un rectangle 
}

sf::Vector2f Rectangle::getPoint(std::size_t index) const {
	float x = getAncre().getX();
	float y = getAncre().getY();
	float largeurf = float(largeur);
	float hauteurf = float(hauteur);

	switch (index) {
	default:
	case 0: return sf::Vector2f(x, y);	//Premier point ancre coin supérieur gauche
	case 1: return sf::Vector2f(x + largeurf, y);	//coin supérieur droit
	case 2: return sf::Vector2f(x + largeurf, y + hauteur);	//coin inférieur droit
	case 3: return sf::Vector2f(x, y + hauteurf);	//coin inférieur gauche
	}
}
