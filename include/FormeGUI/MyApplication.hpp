#ifndef MY_APPLICATION_HPP
#define MY_APPLICATION_HPP

#include <iostream>
#include <fstream>

#include "Gestionnaire.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "CercleDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "ImageDrawable.hpp"
#include "PolygoneDrawable.hpp"

////////////////////////////////////////////////////////////
/// \class MyApp MyApp.hpp
/// \brief Classe pour créer le nécessaire pour l'application
/// \authors DI NARDO Valentin, LENHARD Erwan
/// \version 1.0
/// \date 11 juin 2019
///
////////////////////////////////////////////////////////////
class MyApp : public Gestionnaire {
public:
	////////////////////////////////////////////////////////////
	/// \brief Constructeur de MyApp
	/// \return void
	///
	////////////////////////////////////////////////////////////
	MyApp();

	////////////////////////////////////////////////////////////
	/// \brief Destructeur de MyApp
	/// \return void
	///
	////////////////////////////////////////////////////////////
	~MyApp();


	////////////////////////////////////////////////////////////
	/// \brief Ajoute un PointD à l'Application sur le Calque i
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addPoint (int x, int y, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute un RectangleD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la FormeD
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param uint largeur, largeur du RectangleD
	/// \param uint hauteur, hauteur du RectangleD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addRectangle(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute un CarreD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la FormeD
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param uint cote, cote du CarreD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addCarre(sf::Color color, int x, int y, uint cote, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute un CarreD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la FormeD
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param uint rayon, rayon du CercleD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addCercle(sf::Color color, int x, int y, uint rayon, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute une EllipseD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la forme
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param uint largeur, largeur du rectangle
	/// \param uint hauteur, hauteur du rectangle
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addEllipse(sf::Color color, int x, int y, uint largeur, uint hauteur, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute une ImageD à l'Application sur le Calque i
	/// \param std::string path, chemin vers l'image à importer
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addImage(std::string path, int x, int y, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute une TriangleD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la forme
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param size_t ip1, l'index du premier PointD
	/// \param size_t ip2, l'index du deuxieme PointD
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addTriangle(sf::Color color, int x, int y, size_t ip1, size_t ip2, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Ajoute une PolygoneD à l'Application sur le Calque i
	/// \param sf::Color color, la couleur de la forme
	/// \param int x, la position en x du PointD
	/// \param int y, la position en y du PointD
	/// \param std::vector<PointD*> & tabPoint, le vecteur qui contient les PointD*
	/// \param size_t calque, le numéro du Calque
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void addPolygone(sf::Color color, int x, int y, std::vector<PointD*> & tabPoint, size_t calque);

	////////////////////////////////////////////////////////////
	/// \brief Sauvegarde la scene
	/// \param std::string path, chemin vers le lieu du fichier à sauvegarder
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void sauvegarder(std::string path);

	////////////////////////////////////////////////////////////
	/// \brief Charge une scene
	/// \param std::string path, chemin vers le lieu du fichier à charger
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void charger(std::string path);

	////////////////////////////////////////////////////////////
	/// \brief Vide une FormeD, affiche uniquement ces contours
	/// \param FormeD * forme, la forme à vider
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void viderForme(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Remplit une FormeD
	/// \param FormeD * forme, la forme à remplir
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void remplirForme(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Diminue la taille du traits des contours de la FormeD
	/// \param FormeD * forme, la forme à diminuer les traits
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void diminuerTrait(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Augmente la taille du traits des contours de la FormeD
	/// \param FormeD * forme, la forme à augmenter les traits
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void augmenterTrait(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Diminue la transparence d'une ImageD
	/// \param FormeD * forme, l'imageD
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void dimTransparence(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Augmente la transparence d'une ImageD
	/// \param FormeD * forme, l'imageD
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void augTransparence(FormeD * shape);

	////////////////////////////////////////////////////////////
	/// \brief Déplace une FormeD* sur la scène
	/// \param FormeD * forme, la FormeD à déplacer
	/// \param int x, valeur de déplacement en x
	/// \param int y, valeur de déplacement en y
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void move(FormeD * forme, int x, int y);

	////////////////////////////////////////////////////////////
	/// \brief Déplace un PointD sur la scène
	/// \param PointD * point, la FormeD à déplacer
	/// \param int x, valeur de déplacement en x
	/// \param int y, valeur de déplacement en y
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void move(PointD * point, int x, int y);
	
	////////////////////////////////////////////////////////////
	/// \brief Gère le Groupe sélectionné dans le Menu
	///	 Si la FormeD appartient a un Groupe
	///		Si appartient aussi au groupe sélectionné, 
	///			Alors on la supprime du groupe
	///		Sinon ajoute tous les FormeD du groupe de la FormeD au Groupe sélectionné
	///	 Sinon ajoute la forme au groupe sélectionné
	/// \param FormeD * forme, la FormeD à déplacer
	/// \param size_t i, index du Groupe
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void manageGroupe(FormeD* forme, size_t index);

	////////////////////////////////////////////////////////////
	/// \brief Gère le Groupe de la FormeD
	/// \param FormeD * forme, la FormeD à déplacer
	/// \param size_t i, index du Groupe
	/// \return void
	///
	////////////////////////////////////////////////////////////
	void manageGroupe(FormeD* forme);
};

#endif // !MY_APPLICATION_HPP
