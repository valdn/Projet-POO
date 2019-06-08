#ifndef TGUI_MENU_HPP
#define TGUI_MENU_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <string>
#include <iostream>

#include "MyApplication.hpp"

class Menu : public sf::RenderWindow {
	tgui::Gui * gui;
	MyApp * myApp;

	std::vector<tgui::ComboBox::Ptr> tab_cb;

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

public:
	Menu(MyApp * myApp, sf::VideoMode mode, const sf::String& title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
	~Menu();

	void setView(const sf::View &view);
	inline void drawGui() const { gui->draw(); }
	void passEvent(sf::Event event);

	inline size_t getSelectedCalque() const { return layerListCb->getSelectedItemIndex(); }
	inline size_t getSelectedGroupe() const { return groupListCb->getSelectedItemIndex(); }

private:
	void initialiseDisplay();
	void initialiseConnect();
	tgui::ComboBox::Ptr generatePointsCb();
	void displayDefault(std::string type = "");
	void display2ValuesConstructor(std::string type);
	void display1ValueConstructor(std::string type);
	void displayTriValueConstructor(std::string type);
	void hiddingAddShape();

	void createCalque();
	void createGroupe();
	void createPoint();
	void createRectangle();
	void createEllipse();
	void createCarre();
	void createCercle();
	void createTriangle();
	void createPolygone();
	void createImage();

	void getXYValues(int * x, int * y);
	void getValues(int * largeur, int * hauteur, int * couleur);
	void getValues(int * single, int * couleur);
};

#endif // !TGUI_MENU_HPP
