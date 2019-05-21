#ifndef IMAGE_HPP
#define IMAGE_HPP


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

class Image : virtual public Forme {
	Point *p1;
	std::string img;


	protected:
		void ecrire(std::ostream & os) const override;
		inline Point* getPtrP1() { return p1; }

	public:
		Image(std::string img, int x, int y, Point * p1);
		Image(const Image & ori);
		Image(std::istream & is);
		~Image() override;

		//Getter - Setter
		inline const Point & getP1() const { return *p1; }
		inline void setP1(int x, int y) { p1->setXY(x,y); }
		inline std::string getImg() const { return img ; }

		//Longueur des trois cotés
		inline double perimetre() const override { return (2 * (getP1().getX() - getAncre().getX()) + 2* (getP1().getY() - getAncre().getY())); }
};

}//namespace

#endif IMAGE_HPP
