#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>

#include "Forme/Forme.hpp"
#include "Forme/Point.hpp"

namespace fm {

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

class Polygone : virtual public Forme {
	std::vector<Point*> * tabPoint;
	size_t taille_tab;

	protected:
		void ecrire(std::ostream & os) const override;
		inline std::vector<Point*>* getTabPointPtr() const { return tabPoint; }
		inline Point* getPointPtrAt(size_t i) const { return tabPoint->at(i); }
		inline void setTabPoint(std::vector<Point*>* _tabPoint) { tabPoint = _tabPoint; taille_tab = tabPoint->size(); }

	public:
		Polygone(uint couleur, int x, int y, std::vector<Point*>* tabPoint);
		Polygone(const Polygone & ori);
		Polygone(std::istream & is);
		~Polygone() override;

		//Getter - Setter
		inline const Point* getPointAt(size_t i) const { return tabPoint->at(i); }
		inline void setPosPointAt(int x, int y, size_t i) { tabPoint->at(i)->setXY(x,y); }
		inline size_t getTailleTab() const { return taille_tab; }

		//Longueur de tous les cotés
		double perimetre() const override;
};

}//namespace

#endif POLYGONE_HPP
