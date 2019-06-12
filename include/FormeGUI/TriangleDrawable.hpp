// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef TRIANGLE_DRAWABLE_HPP
#define TRIANGLE_DRAWABLE_HPP


#include "Forme/Triangle.hpp"
#include "FormeDrawable.hpp"

/**
* \class TriangleD TriangleDrawable.hpp "TriangleDrawable.hpp"
* \brief Classe pour définir un fm::Triangle graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class TriangleD : public FormeD, public fm::Triangle {

	///\var PointD* p1, *p2
	///\brief PointD qui vont composer le TriangleD
	PointD *p1, *p2;

	///\var sf::Vector2f dist1, dist2
	///\brief distances entre les PointD et l'ancre du TriangleD 
	sf::Vector2f dist1, dist2;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du TriangleD
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		/// \brief constructeur de CarreD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param PointD * p1 premier PointD du TriangleD
		/// \param PointD * p2 deuxieme PointD du TriangleD
		TriangleD(sf::Color couleur, int x1, int y1, PointD * p1, PointD * p2);

		/// \brief constructeur de copie de TriangleD
		/// \param TriangleD en const
		TriangleD(const TriangleD & ori);

		/// \brief constructeur de TriangleD par flux de lecture
		/// \param std::istream
		TriangleD(std::istream & is);

		/// \brief destructeur de TriangleD
		~TriangleD() override;

		/// \brief Permet de savoir si la souris est sur un TriangleD
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		bool isOver(int x, int y) const override;

		/// \brief Permet de dessiner un TriangleD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const override;

		/// \brief Permet de mettre a jour la classe TriangleD
		/// \return void
		void maj() override;

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		void recalculate() override;

		/// \brief Donne l'aire du triangle pour faire son isOver
		/// \param sf::Vector2f p1 coordonnées du premier PointD
		/// \param sf::Vector2f p2 coordonnées du deuxieme PointD
		/// \param sf::Vector2f posSouris coordonnées de la position de la souris
		/// \return float
		float getArea(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f posSouris) const;

		/// \brief Methode pour SFML : retourne le nombre de Point du TriangleD
		/// \return std::size_t
		std::size_t getPointCount() const override;

		/// \brief Methode pour SFML : retourne la position des Points du TriangleD
		/// \param index en size_t
		/// \return sf::Vector2f
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif TRIANGLE_DRAWABLE_HPP
