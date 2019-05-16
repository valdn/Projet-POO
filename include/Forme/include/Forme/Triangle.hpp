#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


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

class Triangle : virtual public Forme {
	Point *p1, *p2;

	protected:
		void ecrire(std::ostream & os) const override;
		inline Point* getPtrP1() { return p1; }
		inline Point* getPtrP2() { return p2; }

	public:
		Triangle(uint couleur, int x, int y, Point * p1, Point * p2);
		Triangle(const Triangle & ori);
		Triangle(std::istream & is);
		~Triangle() override;

		//Getter - Setter
		inline const Point & getP1() const { return *p1; }
		inline void setP1(int x, int y) { p1->setXY(x,y); }
		inline const Point & getP2() const { return *p2; }
		inline void setP2(int x, int y) { p2->setXY(x, y); }

		//Longueur des trois cotés
		inline double perimetre() const override { return (getLonSeg(getAncre(), getP1()) + getLonSeg(getP1(), getP2()) + getLonSeg(getP2(), getAncre()) ); }
};

}//namespace

#endif TRIANGLE_HPP
