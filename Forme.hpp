#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include "Point.hpp"
#include "ez-draw++.hpp"

typedef unsigned long ulong;
typedef unsigned int uint;

class Forme {
    ulong couleur;
    Point ancre;
    bool selected;

    protected:
        virtual void ecrire(std::ostream & os) const;

    public:
		Forme();
        Forme(const ulong _couleur, uint x, uint y);
        Forme(const Forme &ori);
        Forme(std::istream &is);
        virtual ~Forme();
        inline ulong getCouleur() const {return couleur;}
        inline void setCouleur(ulong _couleur) {couleur = _couleur;}
        inline const Point & getAncre() const {return ancre;}
        inline void setAncre(uint x, uint y) {ancre.setXY(x,y);}
        virtual bool isOver(uint _x, uint _y) const = 0;
        virtual void dessiner(EZWindow &fenetre, bool active=false) const;
        virtual double perimetre() const = 0;
        friend std::ostream & operator<<(std::ostream &os, const Forme &frome);
        static Forme * charger(std::istream &is);
};

#endif