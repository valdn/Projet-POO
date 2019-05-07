#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <iostream>
#include "Forme.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef unsigned long ulong;
typedef unsigned int uint;

class Cercle : public Forme {
	uint rayon;

protected:
	void ecrire(std::ostream & os) const override;

public:
	Cercle(ulong couleur, uint x, uint y, uint _rayon);
	Cercle(const Cercle & ori);
	Cercle(std::istream & is);
	~Cercle() override;
	void dessiner(EZWindow & fenetre, bool active = false) const override;
	bool isOver(uint _x, uint _y) const override;
	inline uint getRayon() { return rayon; }
	inline void setDemiLargeur(uint _rayon) { rayon = _rayon; }
	inline double perimetre() const override { return 2 * M_PI * rayon; }
};

#endif