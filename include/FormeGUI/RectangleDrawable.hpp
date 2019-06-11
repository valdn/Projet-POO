// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef RECTANGLE_DRAWABLE_HPP
#define RECTANGLE_DRAWABLE_HPP


#include "Forme/Rectangle.hpp"
#include "FormeDrawable.hpp"

/**
* \class RectangleD RectangleDrawable.hpp "RectangleDrawable.hpp"
* \brief Classe pour définir un Rectangle graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class RectangleD : public fm::Rectangle, public FormeD {
public:
	/// \brief constructeur de RectangleD
	/// \param couleur en sf::Color
	/// \param position x de l'ancre
	/// \param position y de l'ancre
	/// \param largeur du RectangleD en uint
	/// \param hauteur du RectangleD en uint
	RectangleD(sf::Color couleur, int x, int y, uint largeur, uint hauteur);

	/// \brief constructeur de copie de RectangleD
	/// \param RectangleD en const
	RectangleD(const RectangleD & ori);

	/// \brief constructeur de RectangleD par flux de lecture
		/// \param std::istream
	RectangleD(std::istream & is);

	/// \brief destructeur de RectangleD
	~RectangleD() override;

	/// \brief Permet de savoir si la souris est sur un RectangleD
	/// \param position x de la souris
	/// \param position y de la souris
	/// \return bool
	bool isOver(int _x, int _y) const override;

	/// \brief Permet de dessiner un RectangleD
	/// \param window sf::RenderWindow fenetre d'affichage principale
	/// \return void
	void dessiner(sf::RenderWindow & window) const override;

	/// \brief Permet de mettre a jour la classe RectangleD
	/// \return void
	void maj() override;

	/// \brief Permet de mettre a jour la classe Shape de SFML
	/// \return void
	void recalculate() override;

	/// \brief Methode pour SFML : retourne le nombre de Point du RectangleD
	/// \return std::size_t
	std::size_t getPointCount() const override;

	/// \brief Methode pour SFML : retourne la position des Points du RectangleD
	/// \param index en size_t
	/// \return sf::Vector2f
	sf::Vector2f getPoint(std::size_t index) const override;
};

#endif RECTANGLE_DRAWABLE_HPP
