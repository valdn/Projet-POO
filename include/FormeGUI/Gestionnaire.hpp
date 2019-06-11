#ifndef GESTION_HPP
#define GESTION_HPP

#include <iostream>

#include "Calque.hpp"
#include "Groupe.hpp"

////////////////////////////////////////////////////////////
/// \class Gestionnaire Gestionnaire.hpp "Gestionnaire.hpp"
/// \brief Classe pour gérer les instances de :
///  FormeD, PointD, Calque et Groupe
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class Gestionnaire {

	////////////////////////////////////////////////////////////
	/// \var std::vector<FormeD*> tab_forme
	/// \brief Vecteur qui contient des instances de FormeD
	///
	////////////////////////////////////////////////////////////
	std::vector<FormeD*> tab_forme;

	////////////////////////////////////////////////////////////
	/// \var std::vector<PointD*> tab_point
	/// \brief Vecteur qui contient des instances de PointD
	///
	////////////////////////////////////////////////////////////
	std::vector<PointD*> tab_point;

	////////////////////////////////////////////////////////////
	/// \var std::vector<Calque*> tab_calque
	/// \brief Vecteur qui contient des instances de Calque
	///
	////////////////////////////////////////////////////////////
	std::vector<Calque*> tab_calque;

	////////////////////////////////////////////////////////////
	/// \var std::vector<Groupe*> tab_groupe
	/// \brief Vecteur qui contient des instances de Groupe
	///
	////////////////////////////////////////////////////////////
	std::vector<Groupe*> tab_groupe;

	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructeur de Gestionnaire
		///  Instancie tab_forme, tab_point, tab_calque et tab_groupe
		///  Ajoute un Calque et un Groupe
		///
		////////////////////////////////////////////////////////////
		Gestionnaire();

		////////////////////////////////////////////////////////////
		/// \brief Destructeur de Gestionnaire
		///  Détruit tab_forme, tab_point, tab_calque et tab_groupe
		///  Ainsi que leur contenu
		///
		////////////////////////////////////////////////////////////
		~Gestionnaire();

		////////////////////////////////////////////////////////////
		/// \brief Ajouter une FormeD à un Calque
		/// \param FormeD * forme, pointeur sur la forme à mettre dans le calque
		/// \param size_t num_calque, le numéro du calque
		/// \throw std::runtime_error si tab_forme est plein
		/// \throw std::out_of_range si le Calque à la position num_calque n'existe pas
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ajouter(FormeD * forme, size_t num_calque = 0);

		////////////////////////////////////////////////////////////
		/// \brief Ajouter une PointD à un Calque
		/// \param PointD * point, pointeur sur le point à mettre dans le calque
		/// \param size_t num_calque, le numéro du calque
		/// \throw std::runtime_error si tab_point est plein
		/// \throw std::out_of_range si le Calque à la position num_calque n'existe pas
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ajouter(PointD * point, size_t num_calque = 0);

		////////////////////////////////////////////////////////////
		/// \brief Ajouter un Calque
		/// \param Calque * calque, pointeur sur le calque à ajouter à tab_calques
		/// \throw std::runtime_error si tab_calque est plein
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ajouter(Calque * calque);

		////////////////////////////////////////////////////////////
		/// \brief Ajouter un Groupe
		/// \param Groupe * groupe, pointeur sur le groupe à ajouter à tab_groupe
		/// \throw std::runtime_error si tab_groupe est plein
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void ajouter(Groupe * groupe);

		////////////////////////////////////////////////////////////
		/// \brief Supprimer une FormeD, supprimer de son calque et
		///	 de tab_forme
		/// \param FormeD * forme, pointeur sur la forme à supprimer
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void supprimer(FormeD * forme);

		////////////////////////////////////////////////////////////
		/// \brief Supprimer un PointD, supprimer de son calque et
		///	 de tab_point
		/// \param PointD * point, pointeur sur le point à supprimer
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void supprimer(PointD * point);

		////////////////////////////////////////////////////////////
		/// \brief Supprimer un Calque à la position icalque de tab_calques,
		///	 ainsi que son contenu (FormeD et PointD)
		/// \param size_t icalque, la position dans le vecteur
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void supprimer(size_t icalque);

		////////////////////////////////////////////////////////////
		/// \brief Supprimer un Calque et son contenu (FormeD et PointD)
		/// \warning Si c'est le dernier Calque dans tab_calque, alors
		///	 uniquement son contenu sera supprimé
		/// \param Calque * calque
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void supprimer(Calque * calque);

		////////////////////////////////////////////////////////////
		/// \brief Supprimer le contenu d'un Groupe
		/// \param Groupe * groupe
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void supprimer(Groupe * groupe);


		////////////////////////////////////////////////////////////
		/// \brief Sauvegarder la scène dans un fichier .shape
		/// \param std::ostream, le flux d'écriture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void sauver(std::ostream &os) const;

		////////////////////////////////////////////////////////////
		/// \brief Charge une scène depuis un fichier .shape
		/// \param std::istream, le flux de lecture
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void charger(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Update sf::Shape de toutes les FormeD
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void update() const;

		////////////////////////////////////////////////////////////
		/// \brief Dessine les Calque actifs et leurs contenus (FormeD & PointD) 
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void dessiner(sf::RenderWindow &window) const;

		////////////////////////////////////////////////////////////
		/// \brief Déplace le contenu d'un Groupe à un autre Groupe 
		/// \param Groupe * g1, le groupe à vider
		/// \param Groupe * g2, le groupe qui reçoit les FormeD
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void swapToGroup(Groupe* g1, Groupe* g2);

		////////////////////////////////////////////////////////////
		/// \brief Déplace une FormeD sur un Calque à la position index dans tab_calque
		/// \param FormeD * shape
		/// \param size_t index
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void shapeToLayer(FormeD * shape, size_t index);

		////////////////////////////////////////////////////////////
		/// \brief Déplace une PointD sur un Calque à la position index dans tab_calque
		/// \param PointD * point
		/// \param size_t index
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void pointToLayer(PointD * point, size_t index);

		////////////////////////////////////////////////////////////
		/// \brief Déplace le contenu d'un Groupe sur un Calque à la position index dans tab_calque
		/// \param Groupe * groupe
		/// \param size_t index
		/// \return void
		///
		////////////////////////////////////////////////////////////
		void groupeToLayer(const Groupe * groupe, size_t index);


		////////////////////////////////////////////////////////////
		/// \brief Permet de récupérer une ImageD* si un PointD lui appartient
		/// \param PointD * point
		/// \return ImageD * img si le point appartient à une image
		/// \return nullptr sinon
		///
		////////////////////////////////////////////////////////////
		ImageD * getImageByPoint(PointD* point) const;

		////////////////////////////////////////////////////////////
		/// \brief Permet de récupérer une FormeD* en fonction de coordonnée
		/// \param int x, la valeur en x
		/// \param int y, la valeur en y
		/// \return FormeD * forme si les coordonnées appartiennent à une FormeD
		/// \return nullptr sinon
		///
		////////////////////////////////////////////////////////////
		FormeD * isOverForme(int x, int y) const;

		////////////////////////////////////////////////////////////
		/// \brief Permet de récupérer un PointD* en fonction de coordonnée
		/// \param int x, la valeur en x
		/// \param int y, la valeur en y
		/// \return PointD * point si les coordonnées appartiennent à un PointD
		/// \return nullptr sinon
		///
		////////////////////////////////////////////////////////////
		PointD * isOverPoint(int x, int y) const;

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le Calque d'une FormeD
		/// \param FormeD * forme
		/// \return Calque * calque si la forme appartient à un calque
		/// \return nullptr sinon (ce n'est jamais censé arriver)
		///
		////////////////////////////////////////////////////////////
		Calque * getCalque(FormeD* shape) const;

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le Calque d'un PointD
		/// \param PointD * point
		/// \return Calque * calque si le point appartient à un calque
		/// \return nullptr sinon (ce n'est jamais censé arriver)
		///
		////////////////////////////////////////////////////////////
		Calque * getCalque(PointD* point) const;

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le Groupe d'une FormeD
		/// \param FormeD * forme
		/// \return Groupe * groupe si la forme appartient à un groupe
		/// \return nullptr sinon
		///
		////////////////////////////////////////////////////////////
		Groupe * getGroupe(FormeD* shape) const;


		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le nombre de FormeD dans le Gestionnaire
		/// \return size_t nb
		///
		////////////////////////////////////////////////////////////
		inline size_t getNbFormes() const { return tab_forme.size(); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir la FormeD à la position i dans tab_forme
		/// \param size_t i, l'index
		/// \return FormeD * forme
		/// \throw std::out_of_range si il n'y pas de position i 
		///
		////////////////////////////////////////////////////////////
		inline FormeD* getFormeAt(size_t i) const { return tab_forme.at(i); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir l'index dans tab_forme d'une FormeD*
		/// \param FormeD * forme
		/// \return size_t index
		/// \throw std::domain_error si la forme n'est pas dans tab_forme
		///
		////////////////////////////////////////////////////////////
		size_t getIndex(FormeD* forme) const;


		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le nombre de PointD dans le Gestionnaire
		/// \return size_t nb
		///
		////////////////////////////////////////////////////////////
		inline size_t getNbPoints() const { return tab_point.size(); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le PointD à la position i dans tab_point
		/// \param size_t i, l'index
		/// \return PointD * point
		/// \throw std::out_of_range si il n'y pas de position i 
		///
		////////////////////////////////////////////////////////////
		inline PointD* getPointAt(size_t i) const { return tab_point.at(i); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le dernier PointD créé
		/// \return PointD * point
		///
		////////////////////////////////////////////////////////////
		inline PointD* getLastPoint() const { return tab_point.back(); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir un vecteur de PointD partagé uniquement
		/// \return td::vector<PointD*> * vector
		///
		////////////////////////////////////////////////////////////
		std::vector<PointD*> * getPartagedPoint() const;

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir l'index dans tab_point d'un PointD*
		/// \param PointD * point
		/// \return size_t index
		/// \throw std::domain_error si le point n'est pas dans tab_point
		///
		////////////////////////////////////////////////////////////
		size_t getIndex(PointD* point) const;


		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le nombre de Calque dans le Gestionnaire
		/// \return size_t nb
		///
		////////////////////////////////////////////////////////////
		inline size_t getNbCalques() const { return tab_calque.size(); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le Calque à la position i dans tab_calque
		/// \param size_t i, l'index
		/// \return Calque * calque
		/// \throw std::out_of_range si il n'y pas de position i 
		///
		////////////////////////////////////////////////////////////
		inline Calque* getCalqueAt(size_t i) const { return tab_calque.at(i); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir l'index du calque dans un std::istream
		/// \param std::istream & is
		/// \return size_t index
		///
		////////////////////////////////////////////////////////////
		inline size_t getCalqueIndex(std::istream & is);

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir l'index dans tab_calque d'un Calque*
		/// \param Calque * calque
		/// \return size_t index
		/// \throw std::domain_error si le point n'est pas dans tab_point
		///
		////////////////////////////////////////////////////////////
		size_t getIndex(Calque* calque) const;


		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le nombre de Groupe dans le Gestionnaire
		/// \return size_t nb
		///
		////////////////////////////////////////////////////////////
		inline size_t getNbGroupes() const { return tab_groupe.size(); }

		////////////////////////////////////////////////////////////
		/// \brief Permet d'avoir le Groupe à la position i dans tab_groupe
		/// \param size_t i, l'index
		/// \return Groupe * groupe
		/// \throw std::out_of_range si il n'y pas de position i 
		///
		////////////////////////////////////////////////////////////
		inline Groupe* getGroupeAt(size_t i) const { return tab_groupe.at(i); }
};

#endif GESTION_HPP