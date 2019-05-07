#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include <iostream>

#include "Forme.hpp"

typedef unsigned long ulong;
typedef unsigned int uint;

class Rectangle : public Forme {
    uint largeur, hauteur;

	protected:
		void ecrire(std::ostream & os) const override;

    public:
		Rectangle(ulong couleur, uint x, uint y, uint _largeur, uint _hauteur);
        Rectangle(const Rectangle & ori);
        Rectangle(std::istream & is);
        ~Rectangle() override;
        void dessiner(EZWindow & fenetre, bool active = false) const override;
        inline uint getLargeur() {return largeur;}
        inline uint getHauteur() {return hauteur;}
        inline void setLargeur(uint _largeur) {largeur = _largeur;}
        inline void setHauteur(uint _hauteur) {hauteur = _hauteur;}
        inline double perimetre() const override {return 2*(hauteur+largeur);}
		bool isOver(uint _x, uint _y) const override;
};

#endif