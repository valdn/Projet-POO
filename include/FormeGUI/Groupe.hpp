#ifndef GROUPE_HPP
#define GROUPE_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "SFML/Graphics.hpp"

class Groupe {
	std::vector<FormeD*> * tab_forme;

	public:
		Groupe();
		~Groupe();
		void ajouter(FormeD* forme);
		void supprimer(FormeD* forme);
		void deplacer(int x, int y) const;
		void update() const;
		bool inTab(FormeD* forme) const;

		inline size_t getNbFormes() const { return tab_forme->size(); }
		inline FormeD* getFormeAt(size_t i) const { return tab_forme->at(i); }
};

#endif GROUPE_HPP