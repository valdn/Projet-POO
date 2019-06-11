#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>

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
/// \class Polygone Polygone.hpp "Forme/Polygone.hpp"
/// \brief Classe pour créer des Polygones
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Polygone : virtual public Forme {
	
	////////////////////////////////////////////////////////////
	/// \var std::vector<Point*> * tabPoint
	/// \brief Vecteur qui contient les points du Polygone
	///
	////////////////////////////////////////////////////////////
	std::vector<Point*> * tabPoint;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire du Polygone
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

		////////////////////////////////////////////////////////////
		/// \brief Setter - TabPoints
		/// \param std::vector<Point*> * value, Nouveux pointeur sur un vecteur de Point*
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setTabPoint(std::vector<Point*> * value) { tabPoint = value; }

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur du Polygone
		/// \param uint couleur, la couleur du Polygone
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param std::vector<Point*> * tabPoint, pointeur sur un vecteur de Point*
		///
		////////////////////////////////////////////////////////////
		Polygone(uint couleur, int x, int y, std::vector<Point*>* tabPoint);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie du Polygone
		/// \param const Polygone &ori, le Polygone à copier
		///
		////////////////////////////////////////////////////////////
		Polygone(const Polygone & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur u Polygone par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Polygone(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur du Polygone
		/// \warning Ne détruit pas les points qui le compose !
		///
		////////////////////////////////////////////////////////////
		~Polygone() override;

		////////////////////////////////////////////////////////////
		/// \brief Getter - Récupère un pointeur constant sur Point à la 
		///  position i dans le vecteur qui contient les points du Polygone
		/// \return Point* point
		///
		////////////////////////////////////////////////////////////
		inline const Point* getPointAt(size_t i) const { return tabPoint->at(i); }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Change la position d'un Point dans le vecteur de Point* à la position i
		/// \param int x, la position en x du Point
		/// \param int y, la position en y du Point
		/// \param size_t i, la position dans le vecteur de Point*
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setPosPointAt(int x, int y, size_t i) { tabPoint->at(i)->setXY(x,y); }
		
		////////////////////////////////////////////////////////////
		/// \brief Getter - Récupère le nombre de Point que compose le polygone (l'ancre n'est pas comprise)
		/// \return size_t nb_points
		///
		////////////////////////////////////////////////////////////
		inline size_t getNbPoints() const { return tabPoint->size(); }

		////////////////////////////////////////////////////////////
		/// \brief Vérifie si un Point appartient au Polygone
		/// \param const Point * point
		/// \return true si le Point compose le Polygone
		/// \return false si le Point ne compose pas le Polygone
		///
		////////////////////////////////////////////////////////////
		bool pointInShape(const Point * point) const override;

		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre du Polygone
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		double perimetre() const override;
};

}//namespace

#endif POLYGONE_HPP
