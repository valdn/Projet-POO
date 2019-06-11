#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

/*Pourquoi fait on un héritage virtuel ?
		Dans cette bibliothéque nous ne gérons pas tout ce qui touche aux interfaces. Or si une personne souhaite utiliser cette bibliothéque pour afficher ces formes il devra créer
		des classes qui hérite de celle-ci. Cependant s'il reprend le shéma de notre bibliothéque il peut souhaiter faire classe abstraite pour ses formes. Donc une classe d'un objet
		affichable aurait comme héritage une classe forme (exemple rectangle), qui hérite elle méme de la classe abstraite Forme, et une classe abstraite (exemple FormeAffichable), qui
		hérite elle aussi de la classe abstraite Forme.
		On voit donc ici un probleme, si on souhaite atteindre un membre de Forme comment fait-on au vu de l'ambiguité ?
		Un solution est de passé par l'héritage virtuelle comme éa la classe Forme sera la meme pour une classe de forme (exemple carré) et pour la classe abstraite qui represente les formes
		affichable.

		Sans l'heritage virtuel on aurait quelque chose comme éa :	Forme   Forme								Alors qu'avec on a :		 Forme
																																	|			  |																						/  \
																																Carre   FormeAffichable														Carre	 FormeAffichable
																																		 \ /																							\	 /
																															 Carre Affichable																		Carre Affichable

*/

////////////////////////////////////////////////////////////
/// \namespace fm
/// \brief Namespace pour la bibliothéque de forme
///
////////////////////////////////////////////////////////////
namespace fm {

////////////////////////////////////////////////////////////
/// \class Rectangle Rectangle.hpp "Forme/Rectangle.hpp"
/// \brief Classe pour créer des Rectangles
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Rectangle : public virtual Forme {

	////////////////////////////////////////////////////////////
	/// \var uint largeur
	/// \brief Taille de la largeur du Rectangle
	/// \var uint hauteur
	/// \brief Taille de la hauteur du Rectangle
	///
	////////////////////////////////////////////////////////////
	uint largeur, hauteur;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du Rectangle
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur du Rectangle
		/// \param uint couleur, la couleur du Rectangle
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param uint hauteur, la taille de la hauteur du Rectangle
		/// \param uint largeur, la taille de la largeur du Rectangle
		///
		////////////////////////////////////////////////////////////
		Rectangle(uint couleur, int x, int y, uint _largeur, uint _hauteur);
		
		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie du Rectangle
		/// \param const Rectangle &ori, le Rectangle à copier
		///
		////////////////////////////////////////////////////////////
		Rectangle(const Rectangle & ori);
		
		////////////////////////////////////////////////////////////
		/// \brief Constructeur du Rectangle par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Rectangle(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur du Rectangle
		///
		////////////////////////////////////////////////////////////
		~Rectangle() override;
		
		////////////////////////////////////////////////////////////
		/// \brief Getter - la largeur du Rectangle
		/// \return uint largeur
		///
		////////////////////////////////////////////////////////////
		inline uint getLargeur() const { return largeur; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - largeur
		/// \param uint value, nouvelle valeur de la largeur
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setLargeur(uint value) { largeur = value; }

		////////////////////////////////////////////////////////////
		/// \brief Getter - la hauteur du Rectangle
		/// \return uint hauteur
		///
		////////////////////////////////////////////////////////////
		inline uint getHauteur() const { return hauteur; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - hauteur
		/// \param uint value, nouvelle valeur de la hauteur
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setHauteur(uint value) { hauteur = value; }
		
		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre du Rectangle
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return 2 * (hauteur + largeur); }
};

}//namespace

#endif RECTANGLE_HPP
