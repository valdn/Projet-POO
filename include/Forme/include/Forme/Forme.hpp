#ifndef FORME_HPP
#define FORME_HPP

/**
* \file Forme.hpp
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

///\def M_PI 3.14159265358979323846
#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <string>
#include <cmath>

#include "Point.hpp"

///\namespace fm
namespace fm {


///\class Forme Forme.hpp "Forme/Forme.hpp"
///\brief classe abstraite de base pour définir des formes
class Forme {
	uint couleur;
	Point ancre;

	protected:

		/// \brief ecris les données nécessaire de la forme
		/// \param &os std::ostream
		/// \return void
		virtual void ecrire(std::ostream & os) const;

		/// \brief donne accès a un pointeur sur l'ancre
		/// \return Point*
		inline Point * getAncrePtr() { return &ancre; }

	public:
		/// \brief constructeur de forme
		/// \param couleur en uint
		/// \param position x de l'ancre
		/// \param position y de l'ancre
		Forme(uint couleur, int x, int y);

		/// \brief constructeur par copie de forme
		/// \param &ori une Forme constante
		Forme(const Forme &ori);

		/// \brief constructeur de forme
		/// \param &is un std::istream
		Forme(std::istream &is);

		/// \brief destructeur de forme
		virtual ~Forme();

		/// \brief getter - couleur
		/// \return uint couleur
		inline uint getCouleur() const {return couleur;}

		/// \brief setter - couleur
		/// \param uint couleur
		inline void setCouleur(uint _couleur) {couleur = _couleur;}

		/// \brief getter - ancre
		/// \return const Point&
		inline const Point & getAncre() const {return ancre;}

		/// \brief setter - ancre
		/// \param int x, position x de l'ancre
		/// \param int y, position y de l'ancre
		inline void setAncre(int x, int y) {ancre.setXY(x,y);}

		///
		virtual double perimetre() const = 0;	//Vituelle pure
		double getLonSeg(const Point p1, const Point p2) const;
		friend std::ostream & operator<<(std::ostream &os, const Forme &forme);
		static Forme * charger(std::istream &is);
};

}//namesapce

#endif FORME_HPP