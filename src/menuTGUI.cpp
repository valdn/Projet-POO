#include "menuTGUI.hpp"

Menu::Menu(MyApp * _myApp, sf::VideoMode mode, const sf::String & title, sf::Uint32 style, const sf::ContextSettings & settings)
	: sf::RenderWindow(mode, title, style, settings), myApp(_myApp)
{
	gui = new tgui::Gui(*this);

	initialiseDisplay();
}

Menu::~Menu() {}

void Menu::setView(const sf::View &view) {
	RenderTarget::setView(view);
	gui->setView(getView());
}

void Menu::passEvent(sf::Event event) {
	switch (event.type) {
		//Fenetre fermé
		case sf::Event::Closed:
			close();
			break;

			//fenetre resize
		case sf::Event::Resized:
			setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
			break;

		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {	//Active le bouton createShapeButton
				createShapeButton->setFocused(true);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {	//Active le bouton closeAddShapeButton
				closeAddShapeButton->setFocused(true);	//Focus le bouton close
				sf::Event::KeyEvent data;	//Creer un evenement d'une touche du clavier
				data.code = sf::Keyboard::Enter;	//Met la touche du clavier sur enter
				closeAddShapeButton->keyPressed(data);	//Active le bouton
			}

		case sf::Event::KeyReleased:
			if (!(colorEb1->getText().isEmpty() || colorEb2->getText().isEmpty() || colorEb3->getText().isEmpty())) {
				if (std::stoi((std::string) colorEb1->getText()) > 255) colorEb1->setText("255");
				if (std::stoi((std::string) colorEb2->getText()) > 255) colorEb2->setText("255");
				if (std::stoi((std::string) colorEb3->getText()) > 255) colorEb3->setText("255");
				try {
					exColor->clear(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255));
				}
				catch (std::invalid_argument) {
					std::cerr << "Valeur non comprise";
				}
			}

			break;

		default:
			break;
	}
	gui->handleEvent(event);
}


void Menu::initialiseDisplay() {
	layerListCb = tgui::ComboBox::create();
	for (size_t i = 0; i < myApp->getNbCalques(); ++i)
		layerListCb->addItem("Calque " + std::to_string(i+1));
	layerListCb->setPosition("5%", "5");
	layerListCb->setSize("42.5%", "25");
	layerListCb->setSelectedItemByIndex(0);
	gui->add(layerListCb, "layerListCb");

	addLayerButton = tgui::Button::create();
	addLayerButton->setPosition("5%", "layerListCb.bottom+5");
	addLayerButton->setSize("42.5%", "25");
	addLayerButton->setText("Creer Calque");
	gui->add(addLayerButton, "addLayerButton");

	groupListCb = tgui::ComboBox::create();
	for (size_t i = 0; i < myApp->getNbGroupes(); ++i)
		groupListCb->addItem("Groupe " + std::to_string(i + 1));
	groupListCb->setPosition("layerListCb.right + 5%", "5");
	groupListCb->setSize("42.5%", "25");
	groupListCb->setSelectedItemByIndex(0);
	gui->add(groupListCb, "groupListCb");

	addGroupButton = tgui::Button::create();
	addGroupButton->setPosition("addLayerButton.right + 5%", "groupListCb.bottom+5");
	addGroupButton->setSize("42.5%", "25");
	addGroupButton->setText("Creer Groupe");
	gui->add(addGroupButton, "addGroupButton");

	addPointButton = tgui::Button::create();
	addPointButton->setPosition("5%", "addLayerButton.bottom+50");
	addPointButton->setSize("42.5%", "25");
	addPointButton->setText("Point");
	gui->add(addPointButton, "addPointButton");

	addRectangleButton = tgui::Button::create();
	addRectangleButton->setPosition("addPointButton.right + 5%", "addPointButton.top");
	addRectangleButton->setSize("42.5%", "25");
	addRectangleButton->setText("Rectangle");
	gui->add(addRectangleButton, "addRectangleButton");
	
	addEllipseButton = tgui::Button::create();
	addEllipseButton->setPosition("5%", "addRectangleButton.bottom + 5");
	addEllipseButton->setSize("42.5%", "25");
	addEllipseButton->setText("Ellipse");
	gui->add(addEllipseButton, "addEllipseButton");
	
	addCarreButton = tgui::Button::create();
	addCarreButton->setPosition("addEllipseButton.right + 5%", "addEllipseButton.top");
	addCarreButton->setSize("42.5%", "25");
	addCarreButton->setText(std::string("Carré"));	//std::string pour avoir le é
	gui->add(addCarreButton, "addCarreButton");

	addCercleButton = tgui::Button::create();
	addCercleButton->setPosition("5%", "addCarreButton.bottom + 5");
	addCercleButton->setSize("42.5%", "25");
	addCercleButton->setText("Cercle");
	gui->add(addCercleButton, "addCercleButton");

	addTriangleButton = tgui::Button::create();
	addTriangleButton->setPosition("addCercleButton.right + 5%", "addCercleButton.top");
	addTriangleButton->setSize("42.5%", "25");
	addTriangleButton->setText("Triangle");
	gui->add(addTriangleButton, "addTriangleButton");

	addPolygoneButton = tgui::Button::create();
	addPolygoneButton->setPosition("5%", "addTriangleButton.bottom + 5");
	addPolygoneButton->setSize("42.5%", "25");
	addPolygoneButton->setText("Polygone");
	gui->add(addPolygoneButton, "addPolygoneButton");

	addImageButton = tgui::Button::create();
	addImageButton->setPosition("addPolygoneButton.right + 5%", "addPolygoneButton.top");
	addImageButton->setSize("42.5%", "25");
	addImageButton->setText("Image");
	gui->add(addImageButton, "addImageButton");

	widthLabel = tgui::Label::create("Largeur :");
	widthLabel->setPosition("5%", "addImageButton.bottom + 50");
	widthLabel->setVisible(false);
	widthEb = tgui::EditBox::create();
	widthEb->setPosition("5%", "widthLabel.bottom");
	widthEb->setSize("90%", "30");
	widthEb->setDefaultText("Nombre");
	widthEb->setInputValidator(tgui::EditBox::Validator::UInt);
	widthEb->setVisible(false);
	gui->add(widthLabel, "widthLabel");
	gui->add(widthEb, "widthEb");

	heightLabel = tgui::Label::create("Hauteur :");
	heightLabel->setSize("90%", "20");
	heightLabel->setPosition("5%", "widthEb.bottom + 5");
	heightLabel->setVisible(false);
	heightEb = tgui::EditBox::create();
	heightEb->setPosition("5%", "heightLabel.bottom");
	heightEb->setSize("90%", "30");
	heightEb->setDefaultText("Nombre");
	heightEb->setInputValidator(tgui::EditBox::Validator::UInt);
	heightEb->setVisible(false);
	gui->add(heightLabel, "heightLabel");
	gui->add(heightEb, "heightEb");

	singleLabel = tgui::Label::create("valeur");
	singleLabel->setSize("90%", "20");
	singleLabel->setPosition("5%", "addImageButton.bottom + 50");
	singleLabel->setVisible(false);
	singleEb = tgui::EditBox::create();
	singleEb->setPosition("5%", "singleLabel.bottom");
	singleEb->setSize("90%", "30");
	singleEb->setDefaultText("Nombre");
	singleEb->setInputValidator(tgui::EditBox::Validator::All);
	singleEb->setVisible(false);
	gui->add(singleLabel, "singleLabel");
	gui->add(singleEb, "singleEb");

	colorLabel = tgui::Label::create("Couleur :");
	colorLabel->setSize("90%", "20");
	colorLabel->setPosition("5%", "heightEb.bottom + 5");
	colorLabel->setVisible(false);

	exColor = tgui::Canvas::create();
	exColor->setPosition("5%", "colorLabel.bottom + 5");
	exColor->setSize("25%", "30");
	exColor->setVisible(false);

	colorEb1 = tgui::EditBox::create();
	colorEb1->setPosition("5%", "exColor.bottom+5");
	colorEb1->setSize("25%", "30");
	colorEb1->setDefaultText("0-255");
	colorEb1->setInputValidator(tgui::EditBox::Validator::UInt);
	colorEb1->setVisible(false);

	colorEb2 = tgui::EditBox::create();
	colorEb2->setPosition("colorEb1.right+7,5%", "exColor.bottom+5");
	colorEb2->setSize("25%", "30");
	colorEb2->setDefaultText("0-255");
	colorEb2->setInputValidator(tgui::EditBox::Validator::UInt);
	colorEb2->setVisible(false);

	colorEb3 = tgui::EditBox::create();
	colorEb3->setPosition("colorEb2.right + 7, 5 % ", "exColor.bottom+5");
	colorEb3->setSize("25%", "30");
	colorEb3->setDefaultText("0-255");
	colorEb3->setInputValidator(tgui::EditBox::Validator::UInt);
	colorEb3->setVisible(false);

	gui->add(colorLabel, "colorLabel");
	gui->add(exColor, "exColor");
	gui->add(colorEb1, "colorEb1");
	gui->add(colorEb2, "colorEb2");
	gui->add(colorEb3, "colorEb3");

	ancreLabel = tgui::Label::create("Position de l'ancre :");
	ancreLabel->setSize("80%", "20");
	ancreLabel->setPosition("5%", "addImageButton.bottom + 30");
	ancreLabel->setVisible(false);
	gui->add(ancreLabel, "ancreLabel");

	posXLabel = tgui::Label::create("Position X :");
	posXLabel->setSize("40%", "20");
	posXLabel->setPosition("5%", "ancreLabel.bottom");
	posXLabel->setVisible(false);
	posXEb = tgui::EditBox::create();
	posXEb->setPosition("5%", "posXLabel.bottom");
	posXEb->setSize("40%", "30");
	posXEb->setDefaultText("Nombre");
	posXEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posXEb->setVisible(false);
	gui->add(posXLabel, "posXLabel");
	gui->add(posXEb, "posXEb");

	posYLabel = tgui::Label::create("Position Y :");
	posYLabel->setSize("40%", "20");
	posYLabel->setPosition("posXLabel.right + 10%", "ancreLabel.bottom");
	posYLabel->setVisible(false);
	posYEb = tgui::EditBox::create();
	posYEb->setPosition("posXEb.right + 10%", "posYLabel.bottom");
	posYEb->setSize("40%", "30");
	posYEb->setDefaultText("Nombre");
	posYEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posYEb->setVisible(false);
	gui->add(posYLabel, "posYLabel");
	gui->add(posYEb, "posYEb");

	posP1XLabel = tgui::Label::create("Point 1 X :");
	posP1XLabel->setSize("40%", "20");
	posP1XLabel->setPosition("5%", "posXEb.bottom+10");
	posP1XLabel->setVisible(false);
	posP1XEb = tgui::EditBox::create();
	posP1XEb->setPosition("5%", "posP1XLabel.bottom");
	posP1XEb->setSize("40%", "30");
	posP1XEb->setDefaultText("Nombre");
	posP1XEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posP1XEb->setVisible(false);
	gui->add(posP1XLabel, "posP1XLabel");
	gui->add(posP1XEb, "posP1XEb");

	posP1YLabel = tgui::Label::create("Point 1 Y :");
	posP1YLabel->setSize("40%", "20");
	posP1YLabel->setPosition("posP1XLabel.right + 10%", "posXEb.bottom+10");
	posP1YLabel->setVisible(false);
	posP1YEb = tgui::EditBox::create();
	posP1YEb->setPosition("posP1XEb.right + 10%", "posP1YLabel.bottom");
	posP1YEb->setSize("40%", "30");
	posP1YEb->setDefaultText("Nombre");
	posP1YEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posP1YEb->setVisible(false);
	gui->add(posP1YLabel, "posP1YLabel");
	gui->add(posP1YEb, "posP1YEb");

	posP2XLabel = tgui::Label::create("Point 2 X :");
	posP2XLabel->setSize("40%", "20");
	posP2XLabel->setPosition("5%", "posP1XEb.bottom+10");
	posP2XLabel->setVisible(false);
	posP2XEb = tgui::EditBox::create();
	posP2XEb->setPosition("5%", "posP2XLabel.bottom");
	posP2XEb->setSize("40%", "30");
	posP2XEb->setDefaultText("Nombre");
	posP2XEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posP2XEb->setVisible(false);
	gui->add(posP2XLabel, "posP2XLabel");
	gui->add(posP2XEb, "posP2XEb");

	posP2YLabel = tgui::Label::create("Point 2 Y :");
	posP2YLabel->setSize("40%", "20");
	posP2YLabel->setPosition("posP2XLabel.right + 10%", "posP1XEb.bottom+10");
	posP2YLabel->setVisible(false);
	posP2YEb = tgui::EditBox::create();
	posP2YEb->setPosition("posP2XEb.right + 10%", "posP2YLabel.bottom");
	posP2YEb->setSize("40%", "30");
	posP2YEb->setDefaultText("Nombre");
	posP2YEb->setInputValidator(tgui::EditBox::Validator::UInt);
	posP2YEb->setVisible(false);
	gui->add(posP2YLabel, "posP2YLabel");
	gui->add(posP2YEb, "posP2YEb");

	closeAddShapeButton = tgui::Button::create();
	closeAddShapeButton->setPosition("5%", "posXEb.bottom + 30");
	closeAddShapeButton->setSize("25%", "25");
	closeAddShapeButton->setText("Fermer");
	closeAddShapeButton->setVisible(false);
	gui->add(closeAddShapeButton, "closeAddShapeButton");

	createShapeButton = tgui::Button::create();
	createShapeButton->setPosition("closeAddShapeButton.right + 40%", "posXEb.bottom + 30");
	createShapeButton->setSize("25%", "25");
	createShapeButton->setText("Créer");
	createShapeButton->setVisible(false);
	gui->add(createShapeButton, "createShapeButton");


	initialiseConnect();
}

void Menu::initialiseConnect() {
	addLayerButton->connect("pressed", &Menu::createCalque, this);
	addGroupButton->connect("pressed", &Menu::createGroupe, this);
	addPointButton->connect("pressed", &Menu::displayDefault, this, std::string("point"));
	addRectangleButton->connect("pressed", &Menu::display2ValuesConstructor, this, std::string("rectangle"));
	addEllipseButton->connect("pressed", &Menu::display2ValuesConstructor, this, std::string("ellipse"));
	addCercleButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("cercle"));
	addCarreButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("carre"));
	addImageButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("image"));
	addTriangleButton->connect("pressed", &Menu::displayTriValueConstructor, this, std::string("triangle"));
	closeAddShapeButton->connect("pressed", &Menu::hiddingAddShape, this);
}

void Menu::displayDefault(std::string type) {
	hiddingAddShape(); //reset 

	ancreLabel->setPosition("5%", "addImageButton.bottom + 50");
	ancreLabel->setVisible(true);

	posXLabel->setVisible(true);
	posXEb->setVisible(true);

	posYLabel->setVisible(true);
	posYEb->setVisible(true);

	createShapeButton->setVisible(true);
	closeAddShapeButton->setVisible(true);

	if (type == "point") createShapeButton->connect("pressed", &Menu::createPoint, this);
}

void Menu::display2ValuesConstructor(std::string type) {
	displayDefault();

	widthLabel->setVisible(true);
	widthEb->setVisible(true);

	heightLabel->setVisible(true);
	heightEb->setVisible(true);

	colorLabel->setPosition("5%", "heightEb.bottom + 5");
	colorLabel->setVisible(true);
	exColor->setVisible(true);
	colorEb1->setVisible(true);
	colorEb2->setVisible(true);
	colorEb3->setVisible(true);

	ancreLabel->setPosition("5%", "colorEb1.bottom + 10");
	ancreLabel->setVisible(true);

	if (type == "rectangle") createShapeButton->connect("pressed", &Menu::createRectangle, this);
	else if (type == "ellipse") createShapeButton->connect("pressed", &Menu::createEllipse, this);
}

void Menu::display1ValueConstructor(std::string type) {
	displayDefault();

	singleLabel->setVisible(true);
	singleEb->setInputValidator(tgui::EditBox::Validator::UInt);
	singleEb->setVisible(true);

	colorLabel->setPosition("5%", "singleEb.bottom + 5");
	colorLabel->setVisible(true);
	exColor->setVisible(true);
	colorEb1->setVisible(true);
	colorEb2->setVisible(true);
	colorEb3->setVisible(true);

	ancreLabel->setPosition("5%", "colorEb1.bottom + 10");
	ancreLabel->setVisible(true);

	if (type == "cercle") {
		singleLabel->setText("Rayon");
		singleEb->setDefaultText("Nombre");
		createShapeButton->connect("pressed", &Menu::createCercle, this);
	}

	else if (type == "carre") {
		singleLabel->setText(std::string("Coté"));
		singleEb->setDefaultText("Nombre");
		createShapeButton->connect("pressed", &Menu::createCarre, this);
	}

	else if (type == "image") {
		singleLabel->setText("Chemin vers l'image");
		singleEb->setDefaultText("chemin\\vers\\votre\\image.png");
		singleEb->setText("");
		colorLabel->setVisible(false);
		exColor->setVisible(false);
		colorEb1->setVisible(false);
		colorEb2->setVisible(false);
		colorEb3->setVisible(false);
		ancreLabel->setPosition("5%", "singleEb.bottom + 10");
		singleEb->setInputValidator(tgui::EditBox::Validator::All);
		createShapeButton->connect("pressed", &Menu::createImage, this);
	}
}

void Menu::displayTriValueConstructor(std::string type) {
	displayDefault();



	colorLabel->setPosition("5%", "addImageButton.bottom + 30");
	colorLabel->setVisible(true);
	exColor->setVisible(true);
	colorEb1->setVisible(true);
	colorEb2->setVisible(true);
	colorEb3->setVisible(true);

	ancreLabel->setPosition("5%", "colorEb1.bottom + 10");
	ancreLabel->setVisible(true);

	posP1XLabel->setVisible(true);
	posP1XEb->setVisible(true);

	posP1YLabel->setVisible(true);
	posP1YEb->setVisible(true);

	posP2XLabel->setVisible(true);
	posP2XEb->setVisible(true);

	posP2YLabel->setVisible(true);
	posP2YEb->setVisible(true);

	closeAddShapeButton->setVisible(true);
	closeAddShapeButton->setPosition("5%", "posP2XEb.bottom + 30");

	createShapeButton->setVisible(true);
	createShapeButton->setPosition("closeAddShapeButton.right + 40%", "posP2XEb.bottom + 30");

	if (type == "triangle") createShapeButton->connect("pressed", &Menu::createTriangle, this);
}


void Menu::hiddingAddShape() {
	widthLabel->setVisible(false);
	heightLabel->setVisible(false);
	singleLabel->setVisible(false);
	colorLabel->setVisible(false);
	exColor->setVisible(false);
	exColor->clear(sf::Color::Black);
	ancreLabel->setVisible(false);
	posXLabel->setVisible(false);
	posYLabel->setVisible(false);
	posP1XLabel->setVisible(false);
	posP1YLabel->setVisible(false);
	posP2XLabel->setVisible(false);
	posP2YLabel->setVisible(false);

	widthEb->setVisible(false);
	widthEb->setText("");
	heightEb->setVisible(false);
	heightEb->setText("");
	singleEb->setVisible(false);
	singleEb->setText("");

	colorEb1->setVisible(false);
	colorEb1->setText("");
	colorEb2->setVisible(false);
	colorEb2->setText("");
	colorEb3->setVisible(false);
	colorEb3->setText("");
	posXEb->setVisible(false);
	posXEb->setText("");
	posYEb->setVisible(false);
	posYEb->setText("");
	posP1XEb->setVisible(false);
	posP1XEb->setText("");
	posP1YEb->setVisible(false);
	posP1YEb->setText("");
	posP2XEb->setVisible(false);
	posP2XEb->setText("");
	posP2YEb->setVisible(false);
	posP2YEb->setText("");

	closeAddShapeButton->setVisible(false);
	createShapeButton->disconnectAll();
	createShapeButton->setVisible(false);
}

void Menu::createCalque() {
	myApp->ajouter(new Calque());
	layerListCb->addItem("Calque " + std::to_string(myApp->getNbCalques()));
	layerListCb->setSelectedItemByIndex(myApp->getNbCalques()-1);
}

void Menu::createGroupe() {
	myApp->ajouter(new Groupe());
	groupListCb->addItem("Groupe " + std::to_string(myApp->getNbGroupes()));
	groupListCb->setSelectedItemByIndex(myApp->getNbGroupes() - 1);
}

void Menu::createPoint() {

	int x = NULL;
	int y = NULL;

	getXYValues(&x, &y);

	if (x != NULL && y != NULL) {
		std::cout << "x : " << x << ", y : " << y << std::endl;
		myApp->addPoint(x, y, getSelectedCalque());
	}
}

void Menu::createRectangle() {
	int x = NULL;
	int y = NULL;
	int largeur = NULL;
	int hauteur = NULL;
	int color = NULL;

	getXYValues(&x, &y);
	getValues(&largeur, &hauteur, &color);

	if (x != NULL && y != NULL && largeur != NULL && hauteur != NULL) {
		std::cout << "Rectangle : x : " << x << ", y : " << y << ", largeur : " << largeur << ", hauteur :" << hauteur << ", couleur :" << color <<  std::endl;
		myApp->addRectangle(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255), x, y, largeur, hauteur, getSelectedCalque());
	}
}

void Menu::createEllipse() {
	int x = NULL;
	int y = NULL;
	int largeur = NULL;
	int hauteur = NULL;
	int color = NULL;

	getXYValues(&x, &y);
	getValues(&largeur, &hauteur, &color);

	if (x != NULL && y != NULL && largeur != NULL && hauteur != NULL) {
		std::cout << "Ellipse : x : " << x << ", y : " << y << ", largeur : " << largeur << ", hauteur :" << hauteur << std::endl;
		myApp->addEllipse(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255), x, y, largeur, hauteur, getSelectedCalque());
	}
}

void Menu::createCarre() {
	int x = NULL;
	int y = NULL;
	int cote = NULL;
	int color = NULL;

	getXYValues(&x, &y);
	getValues(&cote, &color);

	if (x != NULL && y != NULL && cote != NULL) {
		std::cout << "Carre : x : " << x << ", y : " << y << ", cote : " << cote << std::endl;
		myApp->addCarre(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255), x, y, cote, getSelectedCalque());
	}
}

void Menu::createCercle() {
	int x = NULL;
	int y = NULL;
	int rayon = NULL;
	int color = NULL;

	getXYValues(&x, &y);
	getValues(&rayon, &color);

	if (x != NULL && y != NULL && rayon != NULL) {
		std::cout << "Cercle : x : " << x << ", y : " << y << ", rayon : " << rayon << std::endl;
		myApp->addCercle(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255), x, y, rayon, getSelectedCalque());
	}
}

void Menu::createImage() {
	int x = NULL;
	int y = NULL;

	getXYValues(&x, &y);

	if (singleEb->getText().isEmpty()) {
		singleEb->getRenderer()->setBorderColor(sf::Color::Red);
		singleEb->setFocused(true);
	}

	std::string path = singleEb->getText();

	if (x != NULL && y != NULL && !path.empty()) {
		std::cout << "x : " << x << ", y :" << y << "path : " << path << std::endl;
		myApp->addImage(path, x, y, getSelectedCalque());
	}
}

void Menu::createTriangle(){
	int x = NULL;
	int y = NULL;
	int p1x = NULL;
	int p1y = NULL;
	int p2x = NULL;
	int p2y = NULL;

	getXYValues(&x, &y);
	getP1XP1YValues(&p1x, &p1y);
	getP2XP2YValues(&p2x, &p2y);

	if (x != NULL && y != NULL && p1x != NULL && p1y != NULL && p2x != NULL && p2y != NULL) {
		myApp->addTriangle(sf::Color(std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()), 255), x, y, p1x, p1y, p2x, p2y, getSelectedCalque());
	}


}



void Menu::getXYValues(int * x, int * y) {
	if (posXEb->getText().isEmpty()) {
		posXEb->getRenderer()->setBorderColor(sf::Color::Red);
		posXEb->setFocused(true);
	}
	else if (posYEb->getText().isEmpty()) {
		posYEb->getRenderer()->setBorderColor(sf::Color::Red);
		posYEb->setFocused(true);
	}

	*y = std::stoi((std::string) posYEb->getText());	//PAs besoin de try car on ne peut recevoir que des chiffre
	*x = std::stoi((std::string) posXEb->getText());
}

void Menu::getP1XP1YValues(int * p1x, int * p1y) {
	if (posP1XEb->getText().isEmpty()) {
		posXEb->getRenderer()->setBorderColor(sf::Color::Red);
		posXEb->setFocused(true);
	}
	else if (posP1YEb->getText().isEmpty()) {
		posYEb->getRenderer()->setBorderColor(sf::Color::Red);
		posYEb->setFocused(true);
	}

	*p1y = std::stoi((std::string) posP1YEb->getText());	//PAs besoin de try car on ne peut recevoir que des chiffre
	*p1x = std::stoi((std::string) posP1XEb->getText());
}

void Menu::getP2XP2YValues(int * p2x, int * p2y) {
	if (posP2XEb->getText().isEmpty()) {
		posXEb->getRenderer()->setBorderColor(sf::Color::Red);
		posXEb->setFocused(true);
	}
	else if (posP2YEb->getText().isEmpty()) {
		posYEb->getRenderer()->setBorderColor(sf::Color::Red);
		posYEb->setFocused(true);
	}

	*p2y = std::stoi((std::string) posP2YEb->getText());	//PAs besoin de try car on ne peut recevoir que des chiffre
	*p2x = std::stoi((std::string) posP2XEb->getText());
}

void Menu::getValues(int * largeur, int * hauteur, int * couleur) {
	if (widthEb->getText().isEmpty()) {
		widthEb->getRenderer()->setBorderColor(sf::Color::Red);
		widthEb->setFocused(true);
	}
	else if (heightEb->getText().isEmpty()) {
		heightEb->getRenderer()->setBorderColor(sf::Color::Red);
		heightEb->setFocused(true);
	}

	*hauteur = std::stoi((std::string) heightEb->getText());
	*largeur = std::stoi((std::string) widthEb->getText());
	*couleur = std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()),255;
}


void Menu::getValues(int * single, int * couleur) {
	if (singleEb->getText().isEmpty()) {
		singleEb->getRenderer()->setBorderColor(sf::Color::Red);
		singleEb->setFocused(true);
	}

	try {
		*single = std::stoi((std::string) singleEb->getText());
	}
	catch (std::invalid_argument) {
		singleEb->getRenderer()->setBorderColor(sf::Color::Red);
		singleEb->setFocused(true);
	}

	*couleur = std::stoi((std::string) colorEb1->getText()), std::stoi((std::string) colorEb2->getText()), std::stoi((std::string) colorEb3->getText()),255;
}