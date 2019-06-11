#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP


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
/// \class Ellipse Ellipse.hpp "Forme/Ellipse.hpp"
/// \brief Classe pour créer des Ellipses
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Ellipse : virtual public Forme {
	
	////////////////////////////////////////////////////////////
	/// \var uint demiLargeur
	/// \brief Taille de la demi largeur de l'Ellipse
	/// \var uint demiHauteur
	/// \brief Taille de la demi hauteur de l'Ellipse
	///
	////////////////////////////////////////////////////////////
	uint demiLargeur, demiHauteur;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire de l'Ellipse
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de l'Ellipse
		/// \param uint couleur, la couleur de l'Ellipse
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param uint demiHauteur, la taille de la demi hauteur de l'Ellipse
		/// \param uint demiLargeur, la taille de la demi largeur de l'Ellipse
		///
		////////////////////////////////////////////////////////////
		Ellipse(uint couleur, int x, int y, uint demiLargeur, uint demiHauteur);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie de l'Ellipse
		/// \param const Ellipse &ori, l'Ellipse à copier
		///
		////////////////////////////////////////////////////////////
		Ellipse(const Ellipse & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur de l'Ellipse par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Ellipse(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur de l'Ellipse
		///
		////////////////////////////////////////////////////////////
		~Ellipse() override;

		////////////////////////////////////////////////////////////
		/// \brief Getter - demi largeur de l'Ellipse
		/// \return uint demiLargeur
		///
		////////////////////////////////////////////////////////////
		inline uint getDemiLargeur() const { return demiLargeur; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - nouvelle valeur de la demi largeur
		/// \param uint demiLargeur
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setDemiLargeur(uint _demiLargeur) { demiLargeur = _demiLargeur; }
		
		////////////////////////////////////////////////////////////
		/// \brief Getter - demi hauteur de l'Ellipse
		/// \return uint demiHauteur
		///
		////////////////////////////////////////////////////////////
		inline uint getDemiHauteur() const { return demiHauteur; }
		
		////////////////////////////////////////////////////////////
		/// \brief Setter - nouvelle valeur de la demi hauteur
		/// \param uint demiHauteur
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setDemiHauteur(uint _demiHauteur) { demiHauteur = _demiHauteur; }
		
		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre de l'Ellipse
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return M_PI * std::sqrt( 2 * ( std::pow(demiLargeur,2) + std::pow(demiHauteur, 2))); }
};

}//namespace

#endif ELLIPSE_HPP
