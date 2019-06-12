#ifndef FORME_DRAWABLE_HPP 
#define FORME_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Forme.hpp"
#include "PointDrawable.hpp"

/**
* \class FormeD FormeDrawable.hpp "FormeDrawable.hpp"
* \brief Classe pour définir une fm::Forme graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class FormeD : public virtual fm::Forme, public sf::Shape {

	///\var bool pleine
	/// \brief Booleen pleine utiliser pour isPleine
	bool pleine;

	///\var PointD ancreD
	/// \brief Un PointD qui va servir d'ancre
	PointD ancreD;

	////////////////////////////////////////////////////////////
	/// \var int border
	/// \brief Taille de la bordure (négative si bordure intérieur)
	///
	////////////////////////////////////////////////////////////
	int border;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire de FormeD
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		/// \brief constructeur de FormeD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		FormeD(sf::Color _couleur, int x, int y);

		/// \brief constructeur de copie de FormeD
		/// \param FormeD en const
		FormeD(const FormeD & ori);

		/// \brief constructeur de FormeD par flux de lecture
		/// \param std::istream
		FormeD(std::istream & is);

		/// \brief destructeur de FormeD
		virtual ~FormeD();

		/// \brief Permet de savoir si une FormeD est pleine ou pas
		/// \return bool
		inline bool isPleine() { return pleine;	}

		/// \brief Change le booleen par son contraire
		/// \return void
		inline void togglePleine() { pleine = !pleine; }

		/// \brief Retourne l'ancre de la FormeD
		/// \return const PointD
		inline const PointD & getAncreD() const { return ancreD; }

		/// \brief Permet de savoir si la souris est sur une FormeD, ne dépent pas de la classe FormeD mais des FormeD qui la compose.
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		virtual bool isOver(int _x, int _y) const = 0;

		/// \brief Permet de mettre a jour la classe CarreD
		/// \return void
		virtual void maj();

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		virtual void recalculate() = 0;

		/// \brief Donne la distance entre 2 points
		/// \param Point
		/// \return sf::Vector2f
		sf::Vector2f getDistance(const fm::Point & p1, const fm::Point & p2);

		/// \brief Permet de dessiner les différentes FormeD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		virtual void dessiner(sf::RenderWindow & window) const = 0;

		/// \brief Permet de charger un fichier de FormeD
		/// \param istream
		/// \return FormeD		
		static FormeD* charger(std::istream & is);

		/// \brief Permet de retourner la taille de la bordure
		/// \return int
		inline int getBorder() const { return border; }

		/// \brief Permet de changer la taille de la bordure
		/// \param int
		/// \return void
		inline void setBorder(int value) { border = value; }
};

#endif FORME_DRAWABLE_HPP 
