#ifndef TGUI_MENU_HPP
#define TGUI_MENU_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <string>
#include <iostream>

#include "MyApplication.hpp"

/**
* \class Menu menuTGUI.hpp "menuTGUI.hpp"
* \brief Classe pour définir le Menu grâce à TGUI
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/

class Menu : public sf::RenderWindow {
	tgui::Gui * gui;
	MyApp * myApp;

	std::vector<tgui::ComboBox::Ptr> tab_cb;
	std::vector<PointD*> tab_point;

	tgui::ComboBox::Ptr layerListCb;
	tgui::ComboBox::Ptr groupListCb;

	tgui::Button::Ptr addLayerButton;
	tgui::Button::Ptr addGroupButton;
	tgui::Button::Ptr addPointButton;
	tgui::Button::Ptr addRectangleButton;
	tgui::Button::Ptr addEllipseButton;
	tgui::Button::Ptr addCarreButton;
	tgui::Button::Ptr addCercleButton;
	tgui::Button::Ptr addTriangleButton;
	tgui::Button::Ptr addPolygoneButton;
	tgui::Button::Ptr addImageButton;
	tgui::Button::Ptr createShapeButton;
	tgui::Button::Ptr closeAddShapeButton;
	tgui::Button::Ptr addToPolButton;
	tgui::Button::Ptr saveButton;
	tgui::Button::Ptr loadButton;
	tgui::Button::Ptr generateButton;

	tgui::Label::Ptr widthLabel;
	tgui::Label::Ptr heightLabel;
	tgui::Label::Ptr singleLabel;
	tgui::Label::Ptr colorLabel;
	tgui::Label::Ptr ancreLabel;
	tgui::Label::Ptr posXLabel;
	tgui::Label::Ptr posYLabel;

	tgui::EditBox::Ptr widthEb;
	tgui::EditBox::Ptr heightEb;
	tgui::EditBox::Ptr singleEb;
	tgui::EditBox::Ptr colorEb1;
	tgui::EditBox::Ptr colorEb2;
	tgui::EditBox::Ptr colorEb3;
	tgui::Canvas::Ptr exColor;
	tgui::EditBox::Ptr posXEb;
	tgui::EditBox::Ptr posYEb;

	tgui::TextBox::Ptr pointPol;

public:
	/// \brief constructeur du Menu
	Menu(MyApp * myApp, sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
	
	/// \brief destructeur du Menu
	~Menu();

	/// \brief Permet de modifier la taille de la fenetre
	/// \param sf::View
	/// \return void
	void setView(const sf::View &view);

	/// \brief Permet de dessiner le Menu
	/// \return void
	inline void drawGui() const { gui->draw(); }


	void passEvent(sf::Event event);

	/// \brief Permet de mettre a jour les Calque
	/// \return void
	void updateCalque();

	/// \brief Retourne le numéro du Calque sélectionné dans la ComboBox
	/// \return size_t
	inline size_t getSelectedCalque() const { return layerListCb->getSelectedItemIndex(); }

	/// \brief Retourne le numéro du Groupe sélectionné dans la ComboBox
	/// \return size_t
	inline size_t getSelectedGroupe() const { return groupListCb->getSelectedItemIndex(); }

	/// \brief Permet de retourner la position x de la fenêtre principale
	/// \return int
	inline int getPosXWindow() const { return posXWindow; }

	/// \brief Permet de retourner la position y de la fenêtre principale
	/// \return int
	inline int getPosYWindow() const { return posYWindow; }

	/// \brief Permet de modifier la position x de la fenêtre principale
	/// \param position x en int
	/// \return void
	inline void setPosXWindow(int posx) { posXWindow = posx; }

	/// \brief Permet de modifier la position y de la fenêtre principale
	/// \param position y en int
	/// \return void
	inline void setPosYWindow(int posy) { posYWindow = posy; }

private:
	///\var int posXWindow
	///\brief position x de la fenêtre
	int posXWindow = 1000;

	///\var int posYWindow
	///\brief position y de la fenêtre
	int posYWindow = 500;

	void initialiseDisplay();
	void initialiseConnect();
	tgui::ComboBox::Ptr generatePointsCb();
	void displayDefault(std::string type = "");
	void display2ValuesConstructor(std::string type);
	void display1ValueConstructor(std::string type);
	void displayTriValueConstructor(std::string type);
	void displayFile(std::string type);
	void hiddingAddShape();


	/// \brief Permet de créer un Calque grâce au Menu
	/// \return void
	void createCalque();

	/// \brief Permet de créer un Groupe grâce au Menu
	/// \return void
	void createGroupe();

	/// \brief Permet de créer un Point grâce au Menu
	/// \return void
	void createPoint();

	/// \brief Permet de créer un Rectangle grâce au Menu
	/// \return void
	void createRectangle();

	/// \brief Permet de créer une Ellipse grâce au Menu
	/// \return void
	void createEllipse();

	/// \brief Permet de créer un Carre grâce au Menu
	/// \return void
	void createCarre();

	/// \brief Permet de créer un Cercle grâce au Menu
	/// \return void
	void createCercle();

	/// \brief Permet de créer un Triangle grâce au Menu
	/// \return void
	void createTriangle();

	/// \brief Permet de créer un Polygone grâce au Menu
	/// \return void
	void createPolygone();

	/// \brief Permet de créer une Image grâce au Menu
	/// \return void
	void createImage();

	/// \brief Permet de créer un Tableau de Point grâce au Menu
	/// \return void
	void createTabPoint();

	/// \brief Permet de sauvegarder une session dans un fichier grâce au Menu
	/// \return void
	void saveFile();

	/// \brief Permet de charger une session d'un fichier grâce au Menu
	/// \return void
	void loadFile();

	/// \brief Modifie les valeurs x et y de l'ancre grâce au Menu
	/// \param int * x
	/// \param int * y
	/// \return void
	void getXYValues(int * x, int * y) const;

	/// \brief Modifie les valeurs largeur et hauteur du Carre et de l'Ellipse grâce au Menu
	/// \param int * largeur
	/// \param int * hauteur
	/// \return void
	void getValues(int * largeur, int * hauteur) const;

	/// \brief Modifie la valeur caractéristique d'une Forme grâce au Menu
	/// \param int * single (rayon, cote, path, etc...)
	/// \return void
	void getValues(int * single) const;

	/// \brief Permet de savoir si un PointD et dans un Tableau
	/// \param PointD *
	/// \return bool
	bool isInTabPoint(const PointD* point) const;

	/// \brief Retourne la couleur de la Forme
	/// \return sf::Color
	sf::Color getCouleur() const;

	/// \brief Retourne la position du point dans une ComboBox
	/// \param size_t
	/// \return size_t
	size_t getPointIndex(size_t index) const;
};

#endif // !TGUI_MENU_HPP
