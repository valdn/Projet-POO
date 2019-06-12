#ifndef GROUPE_HPP
#define GROUPE_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "SFML/Graphics.hpp"

/**
* \class Groupe Groupe.hpp "Groupe.hpp"
* \brief Classe pour définir un Groupe
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class Groupe {
	///\var std::vector<FormeD*> * tab_forme
	///\brief Tableau de FormeD*
	std::vector<FormeD*> * tab_forme;

	public:
		/// \brief constructeur de Groupe
		Groupe();

		/// \brief destructeur de Groupe
		~Groupe();

		/// \brief ajouter un Forme au tableau de FormeD*
		/// \param FormeD*
		/// \return void
		void ajouter(FormeD* forme);

		/// \brief supprimer une FormeD dand le tableau de FormeD*
		/// \param FormeD*
		/// \return void
		void supprimer(FormeD* forme);

		/// \brief Permet de déplacer les FormeD dans le même Groupe
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return void
		void deplacer(int x, int y) const;

		/// \brief Permet de mettre a jour le Groupe
		/// \return void
		void update() const;

		/// \brief Permet de savoir si la FormeD passer en paramètre et dans le Groupe
		/// \param FormeD*
		/// \return bool
		bool inTab(FormeD* forme) const;

		/// \brief Retourne le nombre de FormeD du tableau de FormeD*
		/// \return std::size_t
		inline size_t getNbFormes() const { return tab_forme->size(); }

		/// \brief Retourne la FormeD du tableau de FormeD* en fonction de la position i demandée
		/// \param  position en size_t 
		/// \return FormeD*
		inline FormeD* getFormeAt(size_t i) const { return tab_forme->at(i); }
};

#endif GROUPE_HPP