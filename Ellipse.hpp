#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <iostream>
#include "Forme.hpp"

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

typedef unsigned long ulong;
typedef unsigned int uint;

class Ellipse : public Forme {
    uint demiLargeur, demiHauteur;

	protected:
		void ecrire(std::ostream & os) const override;

    public:
        Ellipse(ulong couleur, uint x, uint y, uint _demiLargeur, uint _demiHauteur);
        Ellipse(const Ellipse & ori);
        Ellipse(std::istream & is);
        ~Ellipse() override;
        void dessiner(EZWindow & fenetre, bool active = false) const override;
		bool isOver(uint _x, uint _y) const override;
        inline uint getDemiLargeur() {return demiLargeur;}
        inline uint getDemiHauteur() {return demiHauteur;}
        inline void setDemiLargeur(uint _demiLargeur) {demiLargeur = _demiLargeur;}
        inline void setDemiHauteur(uint _demiHauteur) {demiHauteur = _demiHauteur;}
        inline double perimetre() const override {return 2*M_PI*sqrt(((demiLargeur^2)+(demiHauteur^2)/2));}
};

#endif