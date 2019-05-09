#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "Formes.hpp"
#include "Point.hpp"
#include "Ellipse.hpp"
#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML à pas l'air si mal :D");

	Formes gestion(10);	//Creer un gestionnaire de forme

	Forme * selected_form = nullptr;;	//Sert a pointer sur une forme
	uint dist_x, dist_y;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme

	Ellipse *e1 = new Ellipse(sf::Color::Red.toInteger(), 10, 10, 100, 50);
	gestion.ajouter(e1);

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

				//Clic enfoncé souris
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left) {
						
						uint x = event.mouseButton.x;
						uint y = event.mouseButton.y;
						selected_form = gestion.isOver(x, y);	//Selection de la forme
						if (selected_form != nullptr) {	//Si on clique sur une forme
							dist_x = x - selected_form->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
							dist_y = y - selected_form->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
							std::cout << "salut" << std::endl;
						}
					}
					break;

				//Mouvement souris
				case sf::Event::MouseMoved:
					if (selected_form != nullptr) {	//Si on clic sur une forme
						selected_form->setAncre(event.mouseMove.x - dist_x, event.mouseMove.y - dist_y);	//On bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
						selected_form->update();
					}
					break;

				//Relachment bouton souris
				case sf::Event::MouseButtonReleased:
					if (event.mouseButton.button == sf::Mouse::Left) {
						selected_form = nullptr;	//Quand on relache le boutton de la souris on déselectionne la forme
					}
					break;

				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::F)
					{
						std::cout << "the f key was pressed" << std::endl;
						std::cout << "control:" << event.key.control << std::endl;
						std::cout << "alt:" << event.key.alt << std::endl;
						std::cout << "shift:" << event.key.shift << std::endl;
						std::cout << "system:" << event.key.system << std::endl;
					}
					if (event.key.code == sf::Keyboard::Num6 || event.key.code == sf::Keyboard::Subtract)
					{
						std::cout << "the - key was pressed" << std::endl;
						std::cout << "control:" << event.key.control << std::endl;
						std::cout << "alt:" << event.key.alt << std::endl;
						std::cout << "shift:" << event.key.shift << std::endl;
						std::cout << "system:" << event.key.system << std::endl;
					}
					if (event.key.code == sf::Keyboard::Add || event.key.code == sf::Keyboard::Equal)
					{
						std::cout << "the + key was pressed" << std::endl;
						std::cout << "control:" << event.key.control << std::endl;
						std::cout << "alt:" << event.key.alt << std::endl;
						std::cout << "shift:" << event.key.shift << std::endl;
						std::cout << "system:" << event.key.system << std::endl;
					}
				}
					break;

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