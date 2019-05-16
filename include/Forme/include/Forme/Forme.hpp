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
				inline Point * getAncreMem() { return &ancre; }

    public:
        Forme(uint _couleur, int x, int y);
        Forme(const Forme &ori);
        Forme(std::istream &is);
        virtual ~Forme();
        inline uint getCouleur() const {return couleur;}
        inline void setCouleur(uint _couleur) {couleur = _couleur;}
        inline const Point & getAncre() const {return ancre;}
        inline void setAncre(int x, int y) {ancre.setXY(x,y);}
				inline bool getSelected() const { return selected; }
				inline void setSelected(bool _selected) {selected = _selected;}
        virtual double perimetre() const = 0;	//Vituelle pure
				double getLonSeg(const Point p1, const Point p2) const;
				friend std::ostream & operator<<(std::ostream &os, const Forme &forme);
        static Forme * charger(std::istream &is);
};

}//namesapce

#endif FORME_HPP