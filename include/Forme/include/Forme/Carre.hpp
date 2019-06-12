#ifndef CARRE_HPP
#define CARRE_HPP


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
/// \class Carre Carre.hpp "Forme/Carre.hpp"
/// \brief Classe pour créer des Carrés
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Carre : virtual public Forme {

	////////////////////////////////////////////////////////////
	/// \var uint cote
	/// \brief Taille du coté du Carre
	///
	////////////////////////////////////////////////////////////
	uint cote;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du Carre
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Carre
		/// \param uint couleur, la couleur du Carre
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param uint cote, la taille du coté
		///
		////////////////////////////////////////////////////////////
		Carre(uint couleur, int x, int y, uint cote);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie de Carre
		/// \param const Carre &ori, le Carre à copier
		///
		////////////////////////////////////////////////////////////
		Carre(const Carre & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Carre par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Carre(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur de Carre
		///
		////////////////////////////////////////////////////////////
		~Carre() override;

		////////////////////////////////////////////////////////////
		/// \brief Getter - coté
		/// \return uint cote, le coté du Carre
		///
		////////////////////////////////////////////////////////////
		inline uint getCote() const { return cote; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - coté
		/// \param uint cote, nouvelle valeur du coté
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setCote(uint value) { cote = value; }

		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre du Carre
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return 4 * cote; }
};

}//namespace

#endif CARRE_HPP
