// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef ELLIPSE_DRAWABLE_HPP
#define ELLIPSE_DRAWABLE_HPP

#include "Forme/Ellipse.hpp"
#include "FormeDrawable.hpp"

/**
* \class EllipseD EllipseDrawable.hpp "EllipseDrawable.hpp"
* \brief Classe pour définir une fm::Ellipse graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class EllipseD : public FormeD, public fm::Ellipse {

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du CarreD
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override final;

	public:
		/// \brief constructeur de EllipseD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param largeur de l'EllipseD en uint
		/// \param hauteur de l'EllipseD en uint
		EllipseD(sf::Color couleur, int x, int y, uint largeur, uint hauteur);

		/// \brief constructeur de copie de EllipseD
		/// \param EllipseD en const
		EllipseD(const EllipseD & ori);

		/// \brief constructeur de EllipseD par flux de lecture
		/// \param std::istream
		EllipseD(std::istream & is);

		/// \brief destructeur de EllipseD
		~EllipseD() override;

		/// \brief Permet de savoir si la souris est sur une EllipseD
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		bool isOver(int _x, int _y) const override;

		/// \brief Permet de dessiner un EllipseD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const override;

		/// \brief Permet de mettre a jour la classe EllipseD
		/// \return void
		void maj() override;

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		void recalculate() override;

		/// \brief Methode pour SFML : retourne le nombre de Point du EllipseD
		/// \return std::size_t
		std::size_t getPointCount() const override;

		/// \brief Methode pour SFML : retourne la position des Points du EllipseD
		/// \param index en size_t
		/// \return sf::Vector2f
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif ELLIPSE_DRAWABLE_HPP
