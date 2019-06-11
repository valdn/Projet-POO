#ifndef CERCLE_HPP
#define CERLCE_HPP

#include "Forme/Forme.hpp"

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
/// \class Cercle Cercle.hpp "Forme/Cercle.hpp"
/// \brief Classe pour créer des Cercles
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Cercle : virtual public Forme {
	
	////////////////////////////////////////////////////////////
	/// \var uint rayon
	/// \brief Taille du rayon du Cercle
	///
	////////////////////////////////////////////////////////////
	uint rayon;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du Cercle
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Cercle
		/// \param uint couleur, la couleur du Cercle
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param uint rayon, la taille du rayon
		///
		////////////////////////////////////////////////////////////
		Cercle(uint couleur, int x, int y, uint rayon);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie de Cercle
		/// \param const Cercle &ori, le Cercle à copier
		///
		////////////////////////////////////////////////////////////
		Cercle(const Cercle & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Cercle par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Cercle(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur de Cercle
		///
		////////////////////////////////////////////////////////////
		~Cercle() override;

		////////////////////////////////////////////////////////////
		/// \brief Getter - rayon du Cercle
		/// \return uint rayon
		///
		////////////////////////////////////////////////////////////
		inline uint getRayon() const { return rayon; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - rayon
		/// \param uint rayon, nouvelle valeur du rayon
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setRayon(uint value) { rayon = value; }

		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre du Cercle
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return 2 * M_PI * rayon ; }
};

}//namesapce

#endif CERCLE_HPP
