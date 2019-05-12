#ifndef CERCLE_HPP
#define CERLCE_HPP

#include "Forme.hpp"

/*Pourquoi fait on un héritage virtuel ?
		Dans cette bibliothèque nous ne gérons pas tout ce qui touche aux interfaces. Or si une personne souhaite utiliser cette bibliothèque pour afficher ces formes il devra créer
		des classes qui hérite de celle-ci. Cependant s'il reprend le shéma de notre bibliothèque il peut souhaiter faire classe abstraite pour ses formes. Donc une classe d'un objet
		affichable aurait comme héritage une classe forme (exemple rectangle), qui hérite elle même de la classe abstraite Forme, et une classe abstraite (exemple FormeAffichable), qui
		hérite elle aussi de la classe abstraite Forme.
		On voit donc ici un probleme, si on souhaite atteindre un membre de Forme comment fait-on au vu de l'ambiguité ?
		Un solution est de passé par l'héritage virtuelle comme ça la classe Forme sera la meme pour une classe de forme (exemple carré) et pour la classe abstraite qui represente les formes
		affichable.

		Sans l'heritage virtuel on aurait quelque chose comme ça :	Forme   Forme								Alors qu'avec on a :		 Forme
																																	|			  |																						/  \
																																Carre   FormeAffichable														Carre	 FormeAffichable
																																		 \ /																							\	 /
																															 Carre Affichable																		Carre Affichable

*/

namespace fm {

class Cercle : virtual public Forme {
	uint rayon;

	protected:
		void ecrire(std::ostream & os) const override;

	public:
		Cercle(uint couleur, uint x, uint y, uint _rayon);
		Cercle(const Cercle & ori);
		Cercle(std::istream & is);
		~Cercle() override;
		inline uint getRayon() const { return rayon; }
		inline void setRayon(uint _rayon) { rayon = _rayon; }
		inline double perimetre() const override { return 2 * M_PI * rayon ; }
};

}//namesapce

#endif CERCLE_HPP
