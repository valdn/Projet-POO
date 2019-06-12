#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "Forme/Forme.hpp"
#include "Forme/Point.hpp"

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
/// \class Triangle Triangle.hpp "Forme/Triangle.hpp"
/// \brief Classe pour créer des Triangles
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Triangle : virtual public Forme {
	
	////////////////////////////////////////////////////////////
	/// \var Point * p1
	/// \brief pointeur sur Point qui défini le premier point du Triangle
	/// \var Point * p2
	/// \brief pointeur sur Point qui défini le deuxième point du Triangle
	///
	////////////////////////////////////////////////////////////
	Point *p1, *p2;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du Polygone
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

		////////////////////////////////////////////////////////////
		/// \brief Setter - Nouveau pointeur sur Point pour le premier point du Triangle
		/// \param Point * point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setP1(Point * point) { p1 = point; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Nouveau pointeur sur Point pour le deuxième point du Triangle
		/// \param Point * point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setP2(Point * point) { p2 = point; }

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur du Rectangle
		/// \param uint couleur, la couleur du Rectangle
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param Point * p1, le premier point du Triangle
		/// \param Point * p2, le deuxieme point du Triangle
		///
		////////////////////////////////////////////////////////////
		Triangle(uint couleur, int x, int y, Point * p1, Point * p2);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie du Triangle
		/// \param const Triangle &ori, le Triangle à copier
		///
		////////////////////////////////////////////////////////////
		Triangle(const Triangle & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur du Triangle par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Triangle(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur du Triangle  
		/// \warning Ne détruit pas les points qui le compose !
		///
		////////////////////////////////////////////////////////////
		~Triangle() override;

		////////////////////////////////////////////////////////////
		/// \brief Getter - Récupère un pointeur sur le premier Point du Triangle
		/// \return const Point & point
		///
		////////////////////////////////////////////////////////////
		inline const Point * getP1() const { return p1; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Change la position du premier Point 
		/// \param int x, la nouvelle position en x du Point
		/// \param int y, la nouvelle position en y du Point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setPosP1(int x, int y) { p1->setXY(x,y); }

		////////////////////////////////////////////////////////////
		/// \brief Getter - Récupère un pointeur sur le deuxième Point du Triangle
		/// \return const Point & point
		///
		////////////////////////////////////////////////////////////
		inline const Point * getP2() const { return p2; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Change la position du deuxième Point 
		/// \param int x, la nouvelle position en x du Point
		/// \param int y, la nouvelle position en y du Point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setPosP2(int x, int y) { p2->setXY(x, y); }

		////////////////////////////////////////////////////////////
		/// \brief Vérifie si un Point appartient au Triangle
		/// \param const Point * point
		/// \return true si le Point compose le Triangle
		/// \return false si le Point ne compose pas le Triangle
		///
		////////////////////////////////////////////////////////////
		bool pointInShape(const Point * point) const override;

		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre du Triangle
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return (getLonSeg(getAncre(), *getP1()) + getLonSeg(*getP1(), *getP2()) + getLonSeg(*getP2(), getAncre()) ); }
};

}//namespace

#endif TRIANGLE_HPP
