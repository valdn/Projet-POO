#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>



#include "GestionnaireFormes.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "GestionnairePoints.hpp"
#include "ImageDrawable.hpp"
#include "PolygoneDrawable.hpp"

void viderForme(FormeD * shape) {
	shape->setFillColor(sf::Color::Transparent);
	shape->togglePleine();
	shape->maj();
}

void remplirForme(FormeD * shape) {
	shape->setFillColor(sf::Color(shape->getCouleur()));
	shape->togglePleine();
	shape->maj();
}

void diminuerTrait(FormeD * shape) {
	if (shape->getOutlineThickness() < -1)
		shape->setOutlineThickness(shape->getOutlineThickness() + 1);
}

void augmenterTrait(FormeD * shape) {
	if (shape->getOutlineThickness() >= -10)
		shape->setOutlineThickness(shape->getOutlineThickness() - 1);
}

void dimTransparence(FormeD * shape) {
	if (shape->getTrsp() > 5) {
		uint i = shape->getTrsp() - 2;
		shape->setFillColor(sf::Color(255, 255, 255, i));
		shape->setTrsp(i);
	}
}

void augTransparence(FormeD * shape) {
	if (shape->getTrsp() < 255) {
		uint i = shape->getTrsp() + 2;
		shape->setFillColor(sf::Color(255, 255, 255, i));
		shape->setTrsp(i);
	}
}

void enregistrer(FormesD & gestion) {
	std::filebuf fb;	//Creer un buffer
	fb.open("test.txt", std::ios::out);	//Ouvre le fichier en ecriture
	std::ostream os(&fb);	//Creer un ostream avec ce buffer
	gestion.sauver(os);		//Sauvegarde la fenetre dans le fichier
	fb.close();	//Ferme le fichier
}

void charger(FormesD & gestion) {
	std::filebuf fb;	//Creer un buffer
	try {
		if (fb.open("test2.txt", std::ios::in)) {	//Ouvre le fichier en lecture
			std::istream is(&fb);	//Crrer un istream avec ce buffer
			gestion.charger(is);	//Creation du gestionnaire de forme a partir du fichier
		}
		else throw std::runtime_error("Le fichier est introuvable");	//Si le fichier est introuvable
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	fb.close();	//ferme le fichier
}

void ajouterRectangle(FormesD * gestion) {
	try {
		gestion->ajouter(new RectangleD(sf::Color::Black, 400, 10, 100, 200));
	} catch (const std::exception & e ) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	sf::RenderWindow mainW(sf::VideoMode(1000, 500), "SFML n'est pas si mal :D");
	sf::RenderWindow menuW(sf::VideoMode(200, 700), "Menu window", sf::Style::Close | sf::Style::Titlebar);

	//Creation du menu dans la fenetre menuW
	tgui::Gui gui(menuW);
	tgui::Button::Ptr addRecButton = tgui::Button::create();
	addRecButton->setText("Ajouter rectangle");
	gui.add(addRecButton, "addRecButton");

	

	FormesD gestionF(10);	//Creer un gestionnaire de formes
	PointsD gestionP(10); //Creer un gestionnaire de points

	FormeD * select_shape = nullptr;	//Sert a pointer sur une forme
	FormeD * select_shape_move = nullptr;
	PointD * select_point = nullptr;

	uint dist_x, dist_y = 0;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme
	bool mouseIn = true; //Savoir si la souris est dans la fenetre ou non
	bool focus = true;	//Savoir si la fenetre est focus
	bool need_update = false;

	gestionF.ajouter(new RectangleD(sf::Color::Red, 10, 10, 100, 50));
	gestionF.ajouter(new EllipseD(sf::Color::Blue, 10, 70, 50, 25));
	gestionF.ajouter(new CarreD(sf::Color::Green, 120, 10, 50));
	gestionF.ajouter(new CercleD(sf::Color::Yellow, 120, 70, 25));

	


	gestionP.ajouter(new PointD(200, 200));
	gestionP.ajouter(new PointD(100, 150));
	gestionP.ajouter(new PointD(400, 200));
	gestionP.ajouter(new PointD(400, 400));
	gestionP.ajouter(new PointD(300, 300));
	gestionP.ajouter(new PointD(500, 300));
	gestionP.ajouter(new PointD(600, 300));
	gestionP.ajouter(new PointD(600, 350));

	gestionF.ajouter(new TriangleD(sf::Color::Cyan, 100, 300, gestionP.getPointAt(0), gestionP.getPointAt(1)));
	gestionF.ajouter(new TriangleD(sf::Color::Black, 300, 100, gestionP.getPointAt(2), gestionP.getPointAt(1)));

	std::vector<PointD*> * tableau_de_pointD = new std::vector<PointD*>;
	tableau_de_pointD->push_back(gestionP.getPointAt(5));
	tableau_de_pointD->push_back(gestionP.getPointAt(6));
	tableau_de_pointD->push_back(gestionP.getPointAt(7));
	gestionF.ajouter(new PolygoneD(sf::Color::Cyan, 500, 400, tableau_de_pointD));


	enregistrer(gestionF);
	//charger(gestion);

	//Connect tous les boutons avec leur fonction associé
	addRecButton->connect("pressed", ajouterRectangle, &gestionF);


	//Boucle principale
	while (mainW.isOpen())
	{
		sf::Event event;
		while (mainW.pollEvent(event))
		{
			switch (event.type) {
				//Fenetre fermé
				case sf::Event::Closed:
					mainW.close();
					menuW.close();
					break;

				//fenetre resize
				case sf::Event::Resized:
					mainW.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
					break;

				//La fenetre est selectionné
			case sf::Event::GainedFocus:
				focus = true;
				break;

				//La fenetre n'est pas selectionné
			case sf::Event::LostFocus:
				focus = false;
				break;

				//La souris entre dans la fenetre
			case sf::Event::MouseEntered:
				mouseIn = true;
				break;

				//La souris quitte la fenetre
			case sf::Event::MouseLeft:
				mouseIn = false;

				//Clic enfoncé souris
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					int x = event.mouseButton.x;
					int y = event.mouseButton.y;
					select_point = gestionP.isOver(x, y); //Selection d'un point
					if (select_point == nullptr) {

						select_shape = gestionF.isOver(x, y);	//Selection de la forme
						select_shape_move = gestionF.isOver(x, y);
						if (select_shape != nullptr) {	//Si on clique sur une forme
							dist_x = x - select_shape->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
							dist_y = y - select_shape->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
						}
					}
				}
				break;

				//Mouvement souris
			case sf::Event::MouseMoved:
				if ((select_point != nullptr) && (mouseIn)) {
					ImageD * img = gestionF.getImageByPoint(select_point);
					if (img != nullptr && img->getActiveRatio()) {	//Si le point appartient à une image
						if (select_point->getX() - select_shape->getAncre().getX())
							select_point->setPos((event.mouseMove.x), ((event.mouseMove.x)*((select_point->getY() - select_shape->getAncre().getY()) / (select_point->getX() - select_shape->getAncre().getX()))));
					}
					else {
						select_point->setPos((event.mouseMove.x), (event.mouseMove.y));
					}
					select_point->update();
					need_update = true;
				}
				else if ((select_shape_move != nullptr) && (mouseIn)) {	//Si une forme est selectionné, que la souris est dans la fenetre et que la fenetre est focus
					select_shape_move->setAncre((event.mouseMove.x - dist_x), (event.mouseMove.y - dist_y));	//Bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
					select_shape_move->maj();	//Update la forme
					need_update = true;
				}
				if (need_update) {
					gestionF.update();
					need_update = false;
				}
				break;

				//Relachment bouton souris
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					select_shape_move = nullptr;	//Quand on relache le boutton de la souris on déselectionne la forme
					select_point = nullptr;
				}
				break;

			case sf::Event::KeyPressed:
				if (select_shape != nullptr) {
					if (dynamic_cast<ImageD*> (select_shape) != nullptr) {//permet de récupérer uniquement les images
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
							dimTransparence(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
							augTransparence(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
							dynamic_cast<ImageD*> (select_shape)->ToggleActiveRatio();
					}
					else {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
							if (select_shape->isPleine())
								viderForme(select_shape);
							else
								remplirForme(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
							diminuerTrait(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
							augmenterTrait(select_shape);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
						change = 1;
				}
				break;

			default:
				break;
			}
		}

		while (menuW.pollEvent(event)) {
			switch (event.type) {
				//Fenetre fermé
			case sf::Event::Closed:
				menuW.close();
				break;

				//fenetre resize
			case sf::Event::Resized:
				menuW.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				gui.setView(menuW.getView());
				break;
			default:
				break;
			}

		}
		if (change == 1) {
			i +=1 ;
			select_shape->rotate(i);
		}

		//Vide la fenetre et peint en blanc
		mainW.clear(sf::Color::White);
		menuW.clear(sf::Color::White);

		//Dessine tous les objet du gestionnaire de formes
		gestionF.dessiner(mainW);

		//Affiche les modificiation faites
		mainW.display();
		menuW.display();
	}

	return 0;
}