#ifndef CARRE_HPP
#define CARRE_HPP


#include <iostream>

#include "Forme.hpp"

typedef unsigned long ulong;
typedef unsigned int uint;

class Carre : public Forme {
	uint cote;

protected:
	void ecrire(std::ostream & os) const override;

public:
	Carre(ulong couleur, uint x, uint y, uint cote);
	Carre(const Carre & ori);
	Carre(std::istream & is);
	~Carre() override;
	void dessiner(EZWindow & fenetre, bool active = false) const override;
	inline uint getCote() { return cote; }
	inline void setCote(uint _cote) { cote = _cote; }
	inline double perimetre() const override { return 4 * cote; }
	bool isOver(uint _x, uint _y) const override;
};

#endif