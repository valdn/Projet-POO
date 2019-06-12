#ifndef POINT_DRAWABLE_HPP
#define POINT_DRAWABLE_HPP

#include "SFML/Graphics.hpp"
#include "Forme/Point.hpp"

/**
* \class PointD PointDrawable.hpp "PointDrawable.hpp"
* \brief Classe pour définir un fm::Point graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class PointD {
	///\var std::vector<PointD*> tab_points
	///\brief Tableau de PointD*
	static std::vector<PointD*> tab_points;

	///\var sf::Color couleur
	///\brief Couleur du PointD
	sf::Color couleur;

	///\var fm::Point * point
	///\brief Définit un Point
	fm::Point * point;

	///\var sf::CircleShape cercle
	///\brief Définit un Cercle
	sf::CircleShape cercle;

	///\var bool partage
	///\brief Utiliser pour définir si un point peut étre partagé ou non.
	bool partage;

	public:
		/// \brief constructeur de PointD pour les ImageD
		/// \param un Point base du PointD
		/// \param couleur de base du point en noir
		/// \param partage booleen en faux
		PointD(fm::Point * point, sf::Color couleur = sf::Color::Black, bool _partage = false);
		
		/// \brief constructeur de PointD pour les autres cas que l'ImageD
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param partage booleen en vrai
		/// \param couleur de base du point en noir
		PointD(int x, int y, bool partage = true, sf::Color couleur = sf::Color::Black);

		/// \brief constructeur de copie de PointD
		/// \param PointD en const
		PointD(const PointD & ori);

		/// \brief constructeur de PointD par flux de lecture
		/// \param std::istream
		PointD(std::istream & is);

		/// \brief destructeur de CarreD
		~PointD();


		/// \brief Retourne le Point
		/// \return const Point
		inline const fm::Point & getPoint() const { return *point; }

		/// \brief Retourne le Point*
		/// \return Point*
		inline fm::Point * getPtrPoint() { return point; }

		/// \brief permet de donner la taille de la texture a l'ImageD
		/// \param x en uint position x du Point
		/// \param y en uint position y du Point
		/// \return void
		inline void setPos(uint x, uint y) { point->setXY(x,y); }

		/// \brief retourne la position x du Point
		/// \return int
		inline int getX() { return point->getX(); }

		/// \brief retourne la position y du Point
		/// \return int
		inline int getY() { return point->getY(); }
		
		/// \brief retourne si le PointD est partagé ou non
		/// \return bool
		inline bool isPartaged() const { return partage; }

		/// \brief change la couleur du PointD
		/// \param sf::Color couleur
		/// \return void
		void setColor(sf::Color couleur);

		/// \brief Permet de mettre a jour la classe PointD
		/// \return void
		void update();

		/// \brief Permet de dessiner les différents PointD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const;

		/// \brief Permet de savoir si la souris est sur un PointD
		/// \param position y de la souris
		/// \return bool
		bool isOver(int x, int y) const;

		////////////////////////////////////////////////////////////
		/// \brief Getter - l'id du fm::Point de point*
		/// \return size_t id
		///
		////////////////////////////////////////////////////////////
		inline size_t getId() const { return point->getId(); }

		/// \brief Permet de charger un fichier de PointD
		/// \param std::istream
		/// \return PointD	
		static PointD* charger(std::istream & is);

		/// \brief Retourne le Point en PointD
		/// \param Point *
		/// \return PointD
		static PointD* getPointD(const fm::Point * point);

		/// \brief Retourne a la position du PointD en paramètre
		/// \param PointD *
		/// \return size_t
		static size_t getPointDIndex(PointD * point);

		/// \brief Permet d'insérer un PointD dans un flux std::ostream
		/// \param std::ostream
		/// \param Point & p
		///return std::ostream
		friend std::ostream & operator<<(std::ostream &os, const PointD & p);
};

#endif POINT_DRAWABLE_HPP