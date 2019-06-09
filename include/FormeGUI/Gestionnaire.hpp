#ifndef GESTION_HPP
#define GESTION_HPP

#include <iostream>

#include "FormeDrawable.hpp"
#include "PointDrawable.hpp"
#include "Calque.hpp"
#include "Groupe.hpp"
#include "ImageDrawable.hpp"

class Gestionnaire {
	std::vector<FormeD*> tab_forme;
  std::vector<PointD*> tab_point;
  std::vector<Calque*> tab_calque;
	std::vector<Groupe*> tab_groupe;

	public:
		Gestionnaire();
		~Gestionnaire();

		void ajouter(FormeD * forme, size_t num_calque = 0);
		void ajouter(PointD * point, size_t num_calque = 0);
		void ajouter(Calque * calque);
		void ajouter(Groupe * groupe);


		void sauver(std::ostream &os) const;
		void charger(std::istream & is);
		void update() const;
		void dessiner(sf::RenderWindow &window) const;
		void addToGroup(Groupe* g1, Groupe* g2);
		void shapeToLayer(FormeD * shape, size_t index);
		void groupeToLayer(Groupe * groupe, size_t index);


		ImageD * getImageByPoint(PointD* p1) const;
		FormeD * isOverForme(int x, int y) const;
		PointD * isOverPoint(int x, int y) const;
		Calque * getCalque(FormeD* shape) const;
		Calque * getCalque(PointD* point) const;
		Groupe * getGroupe(FormeD* shape) const;


		inline size_t getNbFormes() const { return tab_forme.size(); }
		inline FormeD* getFormeAt(size_t i) const { return tab_forme.at(i); }
		size_t getIndex(FormeD* forme) const;

		inline size_t getNbPoints() const { return tab_point.size(); }
		inline PointD* getPointAt(size_t i) const { return tab_point.at(i); }
		inline PointD* getLastPoint() const { return tab_point.back(); }
		size_t getIndex(PointD* point) const;

		inline size_t getNbCalques() const { return tab_calque.size(); }
		inline Calque* getCalqueAt(size_t i) const { return tab_calque.at(i); }
		inline size_t getCalqueIndex(std::istream& is);
		size_t getIndex(Calque* calque) const;

		inline size_t getNbGroupes() const { return tab_groupe.size(); }
		inline Groupe* getGroupeAt(size_t i) const { return tab_groupe.at(i); }
};

#endif GESTION_HPP