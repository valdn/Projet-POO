#ifndef IMAGE_HPP
#define IMAGE_HPP


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
/// \class Image Image.hpp "Forme/Image.hpp"
/// \brief Classe pour créer des Images
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Image : virtual public Forme {

	////////////////////////////////////////////////////////////
	/// \var Point * p1
	/// \brief Point pour resize l'image
	///
	////////////////////////////////////////////////////////////
	Point *p1;

	////////////////////////////////////////////////////////////
	/// \var std::string img
	/// \brief Chemin vers l'image
	///
	////////////////////////////////////////////////////////////
	std::string img;

	////////////////////////////////////////////////////////////
	/// \var bool activeRatio
	/// \brief Garder le ration ou non de l'Image 
	///
	////////////////////////////////////////////////////////////
	bool activeRatio;


	protected:
		////////////////////////////////////////////////////////////
		/// \brief Ecris les données nécessaire de l'Image
		/// \param std::ostream & os, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ecrire(std::ostream & os) const override;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de l'Image
		/// \param std::string img, cehmin vers une image
		/// \param int x, la position x de l'ancre
		/// \param int y, position y de l'ancre
		/// \param uint cote, la taille du coté
		///
		////////////////////////////////////////////////////////////
		Image(std::string img, int x, int y, Point * p1);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie de l'Image
		/// \param const Image &ori, l'Image à copier
		///
		////////////////////////////////////////////////////////////
		Image(const Image & ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur d'Image par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Image(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur d'Image
		///  ne détruit pas les points qui le compose !
		///
		////////////////////////////////////////////////////////////
		~Image() override;

		////////////////////////////////////////////////////////////
		/// \brief Donne accés a un pointeur constant sur le Point pour resize l'Image
		/// \return Point* point
		///
		////////////////////////////////////////////////////////////
		inline const Point* getP1() const { return p1; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Nouvelle position du Point
		/// \param int x, nouvelle valeur x du Point
		/// \param int y, nouvelle valeur y du Point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setPosP1(int x, int y) { p1->setXY(x,y); }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Nouveau pointeur sur Point
		/// \param Point * point
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setP1(Point * point) { p1 = point; }

		////////////////////////////////////////////////////////////
		/// \brief Getter - Chemin vers l'image
		/// \return std::string path
		///
		////////////////////////////////////////////////////////////
		inline std::string getImg() const { return img ; }

		////////////////////////////////////////////////////////////
		/// \brief Setter - Chemin vers l'image
		/// \param std::string path
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setImg(std::string path) { img = path; }

		////////////////////////////////////////////////////////////
		/// \brief Getter - activeRatio
		/// \return true si garde le ratio
		/// \return false si ne garde pas le ratio
		///
		////////////////////////////////////////////////////////////
		inline bool getActiveRatio() const { return activeRatio; }

		////////////////////////////////////////////////////////////
		/// \brief Basculer la valeur de la sauvegarde du ratio
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void toggleActiveRatio() { activeRatio = !activeRatio; }

		////////////////////////////////////////////////////////////
		/// \brief Vérifie si un Point appartient a l'Image
		/// \param const Point * point
		/// \return true si le Point compose l'Image
		/// \return false si le Point ne compose pas l'Image
		///
		////////////////////////////////////////////////////////////
		bool pointInShape(const Point * point) const override;

		////////////////////////////////////////////////////////////
		/// \brief La valeur du périmètre de l'Image
		/// \return double perimetre
		///
		////////////////////////////////////////////////////////////
		inline double perimetre() const override { return (2 * (p1->getX() - getAncre().getX()) + 2* (p1->getY() - getAncre().getY())); }
};

}//namespace

#endif IMAGE_HPP
