#ifndef CERCLE_DRAWABLE_HPP
#define CERLCE_DRAWABLE_HPP

#include "Forme/Cercle.hpp"
#include "FormeDrawable.hpp"

/**
* \class CercleD CercleDrawable.hpp "CercleDrawable.hpp"
* \brief Classe pour définir un Cercle graphiquement sur SFML
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class CercleD : public fm::Cercle, public FormeD {
	public:
		/// \brief constructeur de CercleD
		/// \param couleur en sf::Color
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		/// \param rayon du CercleD
		CercleD(sf::Color couleur, int x, int y, uint rayon);

		/// \brief constructeur de copie de CercleD
		/// \param CercleD en const
		CercleD(const CercleD & ori);
		
		/// \brief constructeur de CercleD par flux de lecture
		/// \param std::istream
		CercleD(std::istream & is);

		/// \brief destructeur de CercleD
		~CercleD() override;

		/// \brief Permet de savoir si la souris est sur un CercleD
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return bool
		bool isOver(int _x, int _y) const override;

		/// \brief Permet de dessiner un CercleD
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow & window) const override;
		
		/// \brief Permet de mettre a jour la classe CercleD
		/// \return void
		void maj() override;

		/// \brief Permet de mettre a jour la classe Shape de SFML
		/// \return void
		void recalculate() override;

		/// \brief Methode pour SFML : retourne le nombre de Point du CercleD
		/// \return std::size_t
		std::size_t getPointCount() const override;

		/// \brief Methode pour SFML : retourne la position des Points du CercleD
		/// \param index en size_t
		/// \return sf::Vector2f
		sf::Vector2f getPoint(std::size_t index) const override;
};

#endif CERLCE_DRAWABLE_HPP
