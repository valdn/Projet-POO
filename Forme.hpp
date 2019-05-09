#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include "Point.hpp"
#include <SFML/Graphics.hpp>

class Forme : public sf::Drawable {
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
        virtual bool isOver(uint _x, uint _y) const = 0;	//Vituelle pure
        virtual double perimetre() const = 0;	//Vituelle pure
				virtual void update() = 0;	//Permet d'update la forme sur la fenetre
        friend std::ostream & operator<<(std::ostream &os, const Forme &frome);

        static Forme * charger(std::istream &is);

		//SFML Stuff
		virtual std::size_t getPointCount() const = 0;	//Vituelle pure
		virtual sf::Vector2f getPoint(std::size_t index) const = 0;	//Vituelle pure
};

#endif