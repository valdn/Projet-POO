// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef IMAGE_DRAWABLE_HPP
#define IMAGE_DRAWABLE_HPP


#include "Forme/Image.hpp"
#include "FormeDrawable.hpp"

/**
* \class ImageD ImageDrawable.hpp "ImageDrawable.hpp"
* \brief Classe pour définir une fm::Image graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/


class ImageD : public fm::Image, public FormeD {

	///\var PointD *p1
	///\brief Point permettant de modifier la taille de l'ImageD
	PointD *p1;

	///\var sf::Vector2f dist1
	///\brief Distance entre l'ancre et le PointD de l'ImageD
	sf::Vector2f dist1;

	///\var uint largeur, hauteur
	///\brief largeur et hauteur de l'ImageD
	uint largeur, hauteur;


public:
	/// \brief constructeur de l'ImageD
	/// \param std::string img path de la texture de l'ImageD
	/// \param position x de l'ancre
	/// \param position y de l'ancre
	/// \param PointD* de l'ImageD
	ImageD(std::string img, int x, int y, PointD * p1);

	/// \brief constructeur de copie de ImageD
	/// \param ImageD en const
	ImageD(const ImageD & ori);

	/// \brief constructeur de ImageD par flux de lecture
	/// \param std::istream
	ImageD(std::istream & is);

	/// \brief destructeur de l'ImageD
	~ImageD() override;

	/// \brief Permet de savoir si la souris est sur une ImageD
	/// \param position x de la souris
	/// \param position y de la souris
	/// \return bool
	bool isOver(int _x, int _y) const override;

	/// \brief Permet de dessiner une ImageD
	/// \param window sf::RenderWindow fenetre d'affichage principale
	/// \return void
	void dessiner(sf::RenderWindow & window) const override;

	/// \brief Permet de mettre a jour la classe ImageD
	/// \return void
	void maj() override;

	/// \brief Permet de mettre a jour la classe Shape de SFML
	/// \return void
	void recalculate() override;

	/// \brief permet de donner la taille de la texture a l'ImageD
	/// \param x en uint largeur de la texture
	/// \param y en uint largeur de la texture
	/// \return void
	inline void setTaille(uint x, uint y) { largeur = x, hauteur = y; }

	/// \brief Retourne la largeur de l'ImageD
	/// \return uint
	inline uint getLargeur() const { return largeur; }

	/// \brief Retourne la hauteur de l'ImageD
	/// \return uint
	inline uint getHauteur() const { return hauteur; }

	/// \brief Retourne le PointD de l'ImageD
	/// \return const PointD*
	inline const PointD* getPointD() const { return p1; }

	/// \brief Retourne le PointD* de l'ImageD
	/// \return PointD*
	inline PointD* getPtrPointD() const { return p1; }

	/// \brief Methode pour SFML : retourne le nombre de Point de l'ImageD
	/// \return std::size_t
	std::size_t getPointCount() const override;

	/// \brief Methode pour SFML : retourne la position des Points de l'ImageD
	/// \param index en size_t
	/// \return sf::Vector2f
	sf::Vector2f getPoint(std::size_t index) const override;
};

#endif IMAGE_DRAWABLE_HPP
