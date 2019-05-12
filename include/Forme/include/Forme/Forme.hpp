#ifndef FORME_HPP
#define FORME_HPP

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <string>
#include <cmath>

#include "Point.hpp"

namespace fm {

class Forme {
    uint couleur;
    Point ancre;
    bool selected;

    protected:
        virtual void ecrire(std::ostream & os) const;

    public:
        Forme(uint _couleur, uint x, uint y);
        Forme(const Forme &ori);
        Forme(std::istream &is);
        virtual ~Forme();
        inline uint getCouleur() const {return couleur;}
        inline void setCouleur(uint _couleur) {couleur = _couleur;}
        inline const Point & getAncre() const {return ancre;}
        inline void setAncre(uint x, uint y) {ancre.setXY(x,y);}
				inline bool getSelected() const { return selected; }
				inline void setSelected(bool _selected) {selected = _selected;}
        virtual double perimetre() const = 0;	//Vituelle pure
				friend std::ostream & operator<<(std::ostream &os, const Forme &forme);
        static Forme * charger(std::istream &is);
};

}//namesapce

#endif FORME_HPP