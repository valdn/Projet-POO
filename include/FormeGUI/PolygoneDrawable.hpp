// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef POLYGONE_DRAWABLE_HPP
#define POLYGONE_DRAWABLE_HPP

#include <vector>

#include "Forme/Polygone.hpp"
#include "FormeDrawable.hpp"

/**
* \class PolygoneD PolygoneDrawable.hpp "PolygoneDrawable.hpp"
* \brief Classe pour définir un Polygone graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class PolygoneD : public fm::Polygone, public FormeD {

	///\var std::vector<PointD*> * tabPointD
	///\brief Tableau de PointD qui vont composer le PolygoneD
	std::vector<PointD*> tabPointD;

	///\var std::vector<sf::Vector2f> tabDistance
	///\brief Tableau de Vector2f des distances entre les différents PointD du PolygoneD
	std::vector<sf::Vector2f> tabDistance;

	public:
		/// \brief constructeur de PolygoneD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param tableau de PointD* composant le PolygoneD
		PolygoneD(sf::Color couleur, int x1, int y1, std::vector<PointD*> & tabPoint);

		//PolygoneD(const PolygoneD & ori);

		/// \brief constructeur de PolygoneD par flux de lecture
		/// \param std::istream
		PolygoneD(std::istream & is);

		/// \brief destructeur de PolygoneD
		~PolygoneD() override;

		/// \brief Permet de savoir si la souris est sur un PolygoneD
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		bool isOver(int x, int y) const override;

		/// \brief Permet de dessiner un PolygoneD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const override;

		/// \brief Permet de mettre a jour la classe PolygoneD
		/// \return void
		void maj() override;

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		void recalculate() override;

		/// \brief Methode pour SFML : retourne le nombre de Point du PolygoneD
		/// \return std::size_t
		std::size_t getPointCount() const override;

		/// \brief Methode pour SFML : retourne la position des Points du PolygoneD
		/// \param index en size_t
		/// \return sf::Vector2f
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif POLYGONE_DRAWABLE_HPP
