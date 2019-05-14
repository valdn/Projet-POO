#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "GestionnaireFormes.hpp"
#include "RectangleDrawable.hpp"
#include "CarreDrawable.hpp"
#include "EllipseDrawable.hpp"
#include "CercleDrawable.hpp"


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

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML n'est pas si mal :D");

	FormesD gestion(10);	//Creer un gestionnaire de forme

	FormeD * select_shape = nullptr;	//Sert a pointer sur une forme
	FormeD * select_shape_move = nullptr;
	uint dist_x, dist_y = 0;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme
	bool mouseIn = true; //Savoir si la souris est dans la fenetre ou non
	bool focus = true;	//Savoir si la fenetre est focus

	RectangleD *r = new RectangleD(sf::Color::Red, 10, 10, 100, 50);
	gestion.ajouter(r);

	EllipseD *e = new EllipseD(sf::Color::Blue, 10, 70, 50, 25);
	gestion.ajouter(e);

	CarreD *c = new CarreD(sf::Color::Green, 120, 10, 50);
	gestion.ajouter(c);

	CercleD *ce = new CercleD(sf::Color::Yellow, 120, 70, 25);
	gestion.ajouter(ce);

	enregistrer(gestion);
	charger(gestion);


	//Boucle principale
	while (window.isOpen())
	{
		//Boucle d'evenement
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
				//Fenetre fermé
				case sf::Event::Closed:
					window.close();
					break;

				//fenetre resize
				case sf::Event::Resized:
					window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
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
						uint x = event.mouseButton.x;
						uint y = event.mouseButton.y;
						select_shape = gestion.isOver(x, y);	//Selection de la forme
						select_shape_move = gestion.isOver(x, y);
						if (select_shape != nullptr) {	//Si on clique sur une forme
							dist_x = x - select_shape->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
							dist_y = y - select_shape->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
						}
					}
					break;

				//Mouvement souris
				case sf::Event::MouseMoved:
					if ((select_shape_move != nullptr)) {	//Si une forme est selectionné, que la souris est dans la fenetre et que la fenetre est focus
						uint nx = event.mouseMove.x - dist_x;	//new x pos
						uint ny = event.mouseMove.y - dist_y;	//new y pos
						if (nx > window.getSize().x)	//Empeche l'ancre d'etre négative en x
							nx = 0;
						if (ny > window.getSize().y)	//Empche l'ancre d'etre négative en y
							ny = 0;

						select_shape_move->setAncre(nx, ny);	//Bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
						select_shape_move->maj();
					}
					break;

				//Relachment bouton souris
				case sf::Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Left) {
						select_shape_move = nullptr;	//Quand on relache le boutton de la souris on déselectionne la forme
					}

				case sf::Event::KeyPressed:
					if (select_shape != nullptr) {
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
					break;

				default:
					break;
			}
		}

		//Vide la fenetre et peint en blanc
		window.clear(sf::Color::White);

		//Dessine tous les objet de gestion
		gestion.dessiner(window);

		//Affiche les modificiation faites
		window.display();
	}

	return 0;
}