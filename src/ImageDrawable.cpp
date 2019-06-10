#include "ImageDrawable.hpp"

ImageD::ImageD(std::string img, int x1, int y1, PointD* _p1)
	: Forme(sf::Color::White.toInteger(), x1, y1),
		Image(img, x1, y1, _p1->getPtrPoint()), 
		FormeD(sf::Color::White, x1, y1) ,p1(_p1)
{
	p1->setColor(sf::Color::Blue);
	setFillColor(sf::Color::White);
	sf::Texture * texture = new sf::Texture();
	if (!texture->loadFromFile(img)) std::cerr << "La texture n'est pas en .png ou n'est pas trouvable" << std::endl;
	texture->setSmooth(true);
	setTexture(texture);
	setTaille(texture->getSize().x, texture->getSize().y);
	p1->setPos(getAncre().getX() + getLargeur(), getAncre().getY() + getHauteur());
	p1->update();
	dist1 = getDistance(getAncre(), p1->getPoint());
	recalculate();
}

ImageD::ImageD(const ImageD & ori) : ImageD(ori.Image::getImg(), ori.Image::getAncre().getX(), ori.Image::getAncre().getY(), ori.p1) {}

ImageD::ImageD(std::istream & is) : Forme(is), Image(is), FormeD(is) {
	p1 = PointD::getPointD(getPtrP1());

	p1->setColor(sf::Color::Blue);
	setFillColor(sf::Color::White);
	sf::Texture * texture = new sf::Texture();
	if (!texture->loadFromFile(getImg())) std::cerr << "Texture introuvable" << std::endl;
	texture->setSmooth(true);
	setTexture(texture);
	setTaille(texture->getSize().x, texture->getSize().y);
	p1->setPos(getAncre().getX() + getLargeur(), getAncre().getY() + getHauteur());
	dist1 = getDistance(getAncre(), p1->getPoint());
	recalculate();
}

ImageD::~ImageD() {}

bool ImageD::isOver(int _x, int _y) const {
	return ( getAncreD().isOver(_x,_y) || ((_x >= getAncre().getX()) && (_x <= getAncre().getX() + getLargeur()) && (_y >= getAncre().getY()) && (_y <= getAncre().getY() + getHauteur())));
}

void ImageD::dessiner(sf::RenderWindow & window) const {
	window.draw(*this);
	getAncreD().dessiner(window);
	p1->dessiner(window);
}

inline void ImageD::maj() {
	FormeD::maj();
	p1->getPtrPoint()->setXY(getAncre().getX() + dist1.x, getAncre().getY() + dist1.y);
	p1->update();
	recalculate();
}

void ImageD::recalculate() {
	dist1 = getDistance(getAncre(), p1->getPoint());
	setTaille(dist1.x, dist1.y);
	Shape::update();
}

std::size_t ImageD::getPointCount() const {
	return 4;	//Y'a 4 coin dans un carré
}

sf::Vector2f ImageD::getPoint(std::size_t index) const {

	switch (index) {
	default:	//pour eviter le warning
	case 0: return sf::Vector2f(getAncre().getX(), getAncre().getY());	//Premier point ancre coin sup�rieur gauche
	case 1: return sf::Vector2f(getP1().getX(), getAncre().getY());	//coin sup�rieur droit
	case 2: return sf::Vector2f(getP1().getX(),getP1().getY());	//coin inf�rieur droit
	case 3: return sf::Vector2f(getAncre().getX(), getP1().getY());	//coin inf�rieur gauche
	}
}
