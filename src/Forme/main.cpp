#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "libforme/Formes.hpp"
#include "libforme/Point.hpp"
#include "libforme/Rectangle.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML à pas l'air si mal :D");

	Formes gestion(10);	//Creer un gestionnaire de forme

	Forme * select_shape = nullptr;;	//Sert a pointer sur une forme
	uint dist_x, dist_y = 0;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme
	bool mouseIn = true; //Savoir si la souris est dans la fenetre ou non
	bool focus = true;	//Savoir si la fenetre est focus

	Rectangle *r1 = new Rectangle(sf::Color::Red.toInteger(), 10, 10, 100, 50);
	gestion.ajouter(r1);


	//ecrire un fichier
	std::filebuf fb;	//Creer un buffer
	fb.open("test.txt", std::ios::out);	//Ouvre le fichier en ecriture
	std::ostream os(&fb);	//Creer un ostream avec ce buffer
	gestion.sauver(os);		//Sauvegarde la fenetre dans le fichier
	fb.close();	//Ferme le fichier

	while (window.isOpen())
	{
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

				case sf::Event::GainedFocus:
					focus = true;
					break;
				case sf::Event::LostFocus:
					focus = false;
					break;

				case sf::Event::MouseEntered:
					mouseIn = true;
					break;

				case sf::Event::MouseLeft:
					mouseIn = false;

				//Clic enfoncé souris
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left) {
						uint x = event.mouseButton.x;
						uint y = event.mouseButton.y;
						select_shape = gestion.isOver(x, y);	//Selection de la forme
						if (select_shape != nullptr) {	//Si on clique sur une forme
							dist_x = x - select_shape->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
							dist_y = y - select_shape->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
						}
					}
					break;

				//Mouvement souris
				case sf::Event::MouseMoved:
					if (select_shape != nullptr && mouseIn && focus) {	//Si une forme est selectionné, que la souris est dans la fenetre et que la fenetre est focus
						uint nx = event.mouseMove.x - dist_x;	//new x pos
						uint ny = event.mouseMove.y - dist_y;	//new y pos
						if (nx > window.getSize().x)	//Empeche l'ancre d'etre négative en x
							nx = 0;
						if (ny > window.getSize().y)	//Empche l'ancre d'etre négative en y
							ny = 0;

						select_shape->setAncre(nx, ny);	//Bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
						select_shape->update();
					}
					break;

				//Relachment bouton souris
				case sf::Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Left) {
						select_shape = nullptr;	//Quand on relache le boutton de la souris on déselectionne la forme
					}

				default:
					break;
			}
		}


		window.clear(sf::Color::White);
		window.draw(gestion);
		window.display();
	}

	return 0;
}