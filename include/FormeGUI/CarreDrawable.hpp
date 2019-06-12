// Enleve les warning pour l'héritage via la dominance
#pragma warning( disable : 4250 )

#ifndef CARRE_DRAWABLE_HPP
#define CARRE_DRAWABLE_HPP

#include "Forme/Carre.hpp"
#include "FormeDrawable.hpp"

/**
* \class CarreD CarreDrawable.hpp "CarreDrawable.hpp"
* \brief Classe pour définir un Carre graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class CarreD : public fm::Carre, public FormeD {
	public:
		/// \brief constructeur de CarreD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param coté du CarreD en uint
		CarreD(sf::Color couleur, int x, int y, uint _cote); 

		/// \brief constructeur de copie de CarreD
		/// \param Carre en const
		CarreD(const CarreD & ori);

		/// \brief constructeur de CarreD par flux de lecture
		/// \param std::istream
		CarreD(std::istream & is);

		/// \brief destructeur de CarreD
		~CarreD() override;

		/// \brief Permet de savoir si la souris est sur un CarreD
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		bool isOver(int _x, int _y) const override;

		/// \brief Permet de dessiner un CarreD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const override;

		/// \brief Permet de mettre a jour la classe CarreD
		/// \return void
		void maj() override;

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		void recalculate() override;

		/// \brief Methode pour SFML : retourne le nombre de Point du CarreD
		/// \return std::size_t
		std::size_t getPointCount() const override;

		/// \brief Methode pour SFML : retourne la position des Points du CarreD
		/// \param index en size_t
		/// \return sf::Vector2f
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif CARRE_DRAWABLE_HPP
