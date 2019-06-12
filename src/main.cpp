#include <SFML/Graphics.hpp>

#include "menuTGUI.hpp"
#include "MyApplication.hpp"

/// \todo Afficher les messages d'erreur sur le menu
/// \todo Animation
/// \todo avoir des info sur la forme / le point sélectionné

int main()
{
	

	MyApp gestion = MyApp(); //Creer un gestionnaire

	Menu menuW(&gestion, sf::VideoMode(250, 850), "Menu window", sf::Style::Close);

	sf::RenderWindow mainW(sf::VideoMode(menuW.getPosXWindow(), menuW.getPosYWindow()), "ShapEditor");

	FormeD * select_shape = nullptr;	//Sert a pointer sur une forme
	FormeD * select_shape_move = nullptr;
	PointD * select_point = nullptr;
	PointD * select_point_move = nullptr;
	Groupe * g = nullptr;
	ImageD * img = nullptr;

	uint dist_x, dist_y = 0;	//Sert pour la distance entre l'ancre et la souris lors du clic sur une forme
	bool mouseIn = true; //Savoir si la souris est dans la fenetre ou non
	bool focus = true;	//Savoir si la fenetre est focus
	bool need_update = false;

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
					menuW.setPosXWindow(event.size.width);
					menuW.setPosYWindow(event.size.height);
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
					select_point = gestion.isOverPoint(x, y); //Selection d'un point
					select_point_move = select_point;
					if (select_point == nullptr) {

						select_shape = gestion.isOverForme(x, y);	//Selection de la forme
						select_shape_move = select_shape;
						if (select_shape != nullptr) {	//Si on clique sur une forme
							dist_x = x - select_shape->getAncre().getX();	//Distance en x entre l'ancre de la forme et de la souris
							dist_y = y - select_shape->getAncre().getY();	//Distance en y entre l'ancre de la forme et de la souris
						}
					}
					else { //Si jamais un point est séléctionner alors on désélectionne la forme 
						select_shape = nullptr;
						img = gestion.getImageByPoint(select_point_move);
					}
				}
				break;

				//Mouvement souris
			case sf::Event::MouseMoved:
				if ((select_point_move != nullptr) && (mouseIn)) {
					if (img != nullptr && img->getActiveRatio()) {	//Si le point appartient à une image
						select_point_move->setPos(event.mouseMove.x, select_point->getY() + event.mouseMove.x - select_point->getX());
					}
					else {
						select_point_move->setPos((event.mouseMove.x), (event.mouseMove.y));
					}
					select_point_move->update();
					need_update = true;
				}
				else if ((select_shape_move != nullptr) && (mouseIn)) {	//Si une forme est selectionné, que la souris est dans la fenetre et que la fenetre est focus
					g = gestion.getGroupe(select_shape_move);
					if (g != nullptr)
						g->deplacer((event.mouseMove.x - dist_x - select_shape->getAncre().getX()), (event.mouseMove.y - dist_y - select_shape->getAncre().getY()));
					else {
						select_shape_move->setAncre((event.mouseMove.x - dist_x), (event.mouseMove.y - dist_y));	//Bouge l'ancre en prenant en compte l'ecart entre la souris et l'ancre
						select_shape_move->maj();	//Update la forme
					}
					need_update = true;
				}
				if (need_update) {
					gestion.update();
					need_update = false;
				}
				break;

				//Relachment bouton souris
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					select_shape_move = nullptr;	//Quand on relache le boutton de la souris on déselectionne la forme
					select_point_move = nullptr;
					img = nullptr;
				}
				break;

			case sf::Event::KeyPressed:
				if (select_shape == nullptr && select_point == nullptr && sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
					gestion.supprimer(menuW.getSelectedCalque());
					menuW.updateCalque();
				}

				else if (select_shape != nullptr) {
					ImageD * img = dynamic_cast<ImageD*> (select_shape);
					if (img != nullptr) {//permet de récupérer uniquement les images
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
							gestion.augTransparence(img);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
							gestion.dimTransparence(img);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
							dynamic_cast<ImageD*> (select_shape)->toggleActiveRatio();
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
							img->getPtrPointD()->setColor(sf::Color::Black);
					}
					else {
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
							if (select_shape->isPleine())
								gestion.viderForme(select_shape);
							else
								gestion.remplirForme(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) || sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
							gestion.diminuerTrait(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) || sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
							gestion.augmenterTrait(select_shape);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	//Bouge la forme de 1 pixel en haut
							gestion.move(select_shape, 0, -1);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	//Bouge la forme de 1 pixel en bas
							gestion.move(select_shape, 0, 1);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	//Bouge la forme de 1 pixel à droite
							gestion.move(select_shape, 1, 0);
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	//Bouge la forme de 1 pixel à gauche
							gestion.move(select_shape, -1, 0);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {	//Déplace la forme (et son groupe si elle en un) au layer souhaité
						g = gestion.getGroupe(select_shape);
						if (g != nullptr)	//Si la forme appartient a un groupe
							gestion.groupeToLayer(g, menuW.getSelectedCalque());	//Déplace tout le groupe au layer souhaité
						else 
							gestion.shapeToLayer(select_shape, menuW.getSelectedCalque());	//Déplace la forme au layer souhaité
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))	//Ajoute la forme au groupe sélectionné
						gestion.manageGroupe(select_shape, menuW.getSelectedGroupe());

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {	//Supprime la forme et son groupe si elle en a un
						gestion.manageGroupe(select_shape);
						select_shape = nullptr;
					}
				}

				if (select_point != nullptr) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {	//Supprime le point
						try {
							gestion.supprimer(select_point);
							select_point = nullptr;
						}
						catch (std::runtime_error & e) {
							std::cerr << e.what() << std::endl;
						}
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {	//Déplace le point au layer souhaité
							gestion.pointToLayer(select_point, menuW.getSelectedCalque());	
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	//Bouge la forme de 1 pixel en haut
						gestion.move(select_point, 0, -1);
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	//Bouge la forme de 1 pixel en bas
						gestion.move(select_point, 0, 1);
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	//Bouge la forme de 1 pixel à droite
						gestion.move(select_point, 1, 0);
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))	//Bouge la forme de 1 pixel à gauche
						gestion.move(select_point, -1, 0);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))	//Toggle l'affichage du calque sélectionné
					gestion.getCalqueAt(menuW.getSelectedCalque())->toggleActive();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))	//Réouvre le MenuTGUI
					menuW.setVisible(true);
					

				break;

			default:
				break;
			}
		}

		while (menuW.pollEvent(event)) {
			menuW.passEvent(event); // Pass the event to the gui
		}

		//Vide la fenetre et peint en blanc
		mainW.clear(sf::Color::White);
		menuW.clear(sf::Color::White);

		//Dessine tous les objet du gestionnaire de formes
		gestion.dessiner(mainW);

		//Dessine le gui
		menuW.drawGui();

		//Affiche les modificiation faites
		mainW.display();
		menuW.display();
	}

	return 0;
}