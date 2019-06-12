#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <vector>

/// \typedef uint = unsigned int
/// \brief Défini un nouveau type uint = unsigned int
typedef unsigned int uint;

////////////////////////////////////////////////////////////
/// \namespace fm
/// \brief Namespace pour la bibliothéque de forme
///
////////////////////////////////////////////////////////////
namespace fm {

////////////////////////////////////////////////////////////
/// \class Point Point.hpp "Forme/Point.hpp"
/// \brief Classe pour créer des Points
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Point {
	
	////////////////////////////////////////////////////////////
	/// \var const uint TAILLE
	/// \brief Taille du Point
	///
	////////////////////////////////////////////////////////////
	static const uint TAILLE = 3;

	////////////////////////////////////////////////////////////
	/// \var std::vector<Point*> tab_points
	/// \brief Vecteur qui contient tous les points instanciés
	///
	////////////////////////////////////////////////////////////
	static std::vector<Point*> tab_points;

	////////////////////////////////////////////////////////////
	/// \var size_t id
	/// \brief id du Point
	///
	////////////////////////////////////////////////////////////
	size_t id;

	////////////////////////////////////////////////////////////
	/// \var int x
	/// \brief Position x du Point
	/// \var int y
	/// \brief Position y du Point
	///
	////////////////////////////////////////////////////////////
	int x,y;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Point
		/// \param int x, la position x du Point
		/// \param int y, position y du Point
		///
		////////////////////////////////////////////////////////////
		Point(int _x, int _y);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur par copie de Point
		/// \param const Point &ori, le Point à copier
		///
		////////////////////////////////////////////////////////////
		Point(const Point &ori);

		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Point par flux de lecture
		/// \param std::istream &is, le flux de lecture
		///
		////////////////////////////////////////////////////////////
		Point(std::istream &is);

		////////////////////////////////////////////////////////////
		/// \brief Destructeur de Point
		///
		////////////////////////////////////////////////////////////
		~Point();

		////////////////////////////////////////////////////////////
		/// \brief Getter - la taille du Point
		/// \return uint TAILLE
		///
		////////////////////////////////////////////////////////////
		inline uint getTaille() const {return TAILLE;}

		////////////////////////////////////////////////////////////
		/// \brief Getter - la position x du Point
		/// \return int x
		///
		////////////////////////////////////////////////////////////
		inline int getX() const {return x;}

		////////////////////////////////////////////////////////////
		/// \brief Getter - la position y du Point
		/// \return int y
		///
		////////////////////////////////////////////////////////////
		inline int getY() const {return y;}

		////////////////////////////////////////////////////////////
		/// \brief Getter - l'id du Point
		/// \return size_t id
		///
		////////////////////////////////////////////////////////////
		inline size_t getId() const {return id;}

		////////////////////////////////////////////////////////////
		/// \brief Setter - Position x
		/// \param int x, nouvelle position en x
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setX(int _x) {x = _x;}

		////////////////////////////////////////////////////////////
		/// \brief Setter - Position y
		/// \param int y, nouvelle position en y
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setY(int _y) {y = _y;}

		////////////////////////////////////////////////////////////
		/// \brief Setter - Position x,y
		/// \param int x, nouvelle position en x
		/// \param int y, nouvelle position en y
		/// \return void
		///
		////////////////////////////////////////////////////////////
		inline void setXY(int _x, int _y) {x=_x; y=_y;}

		////////////////////////////////////////////////////////////
		/// \brief Permet d'insérer un Point dans un flux std::ostream
		///
		////////////////////////////////////////////////////////////
		friend std::ostream & operator<<(std::ostream &os, const Point & p);

		////////////////////////////////////////////////////////////
		/// \brief Permet d'insérer un Point dans un flux std::istream
		///
		////////////////////////////////////////////////////////////
		friend std::istream & operator>>(std::istream &is, Point & p);

		////////////////////////////////////////////////////////////
		///	\brief Récupéré un pointeur vers le Point avec l'id
		/// \param size_t id, l'id recherché
		/// \return Point* point
		///
		////////////////////////////////////////////////////////////
		static Point* getPointByID(size_t id);

	private:
		////////////////////////////////////////////////////////////
		/// \brief Avoir la position, dans le vecteur, du Point
		/// \param Point * point
		/// \return size_t position
		///
		////////////////////////////////////////////////////////////
		static size_t getPointIndex(Point * point);
};

}//namespace

#endif POINT_HPP