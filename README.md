# Projet - P.O.O. --- ShapEditor {#mainpage}

Le but de ce projet est de créer une application graphique d'édition de forme en c++. Celle-ci doit pouvoir lire un fichier de texte décrivant un ensemble de **formes géométriques** et leurs propriétés (épaisseur de trait, couleur, etc.), qui les trace toutes dans une même fenêtre et qui permet de les **éditer**, c’est-à-dire d’en modifier les propriétés.

# Premiers pas

## Prérequis

-  ***CMake*** pour générer le projet

-  ***Un compilateur C++*** (gcc, MSCV, etc)

-  ***Doxygen*** pour générer la documentation


## Installation

### Générer le projet:

-  **Ouvrez CMake** puis sélectionner la racine du projet (le répertoire qui contient le fichier README.md et surtout le fichier CMakeLists.txt).

-  **Configurer** votre projet puis **générez** le.


### Compiler le projet:

- Lancez le projet.

- Ensuite **compilez** le.

- Enfin lancez **shapeditor.exe** qui apparait dans */bin/debug* ou dans */bin/release* (selon le type de build).


### Générer la documentation :

- Ouvrez ***Doxygen***

- File -> Open et chercher le fichier *"Doxyfile"* à la racine du projet

- Allez dans l'onglet "Run" -> cliquer sur "Run doxygen"

- Cliquez sur "Show HTML output"

- Vous avez aussi accès à la [documentation](https://www.projets.lerwox.com/ShapEditor/doc) en ligne


# Utilisation --- Aide

## Fenêtre Principale

### Souris

- Clique gauche sélectionne un point ou une forme si le curseur est sur l'un d'eux.

- Clique gauche enfoncé plus mouvement de la souris bouge l'objet sélectionné.


### Clavier

#### Si une forme est sélectionnée :

- Bouton **suppr** : Si la forme appartient à un *groupe* supprime toutes les formes de groupe sinon supprime simplement la forme

- Bouton **G** :

  - Si la forme est dans un Groupe : déplace toutes les formes du groupe sur le groupe sélectionné (sur le menu).

  - Sinon si la forme est déja dans le Groupe sélectionné (sur le menu), supprime la forme du Groupe.

  - Sinon ajoute la forme au Groupe sélectionné (sur le menu).

- Bouton **V** : 
  - Si la forme appartient à un Groupe : déplace toutes les formes du groupe sur le Calque sélectionné (sur le menu). 

  - Sinon déplace uniquement la forme sur le Calque

- Bouton **F** : Si la forme est une image bascule la sauvegarde de son ratio, Sinon vide la forme (il y a uniquement les contours).

- Bouton **C** : Bascule l'affichage du *calque* sélectionné (dans le menu)

- Bouton **-** : Si la forme est une image augmente sa transparence, sinon diminue la taille du trait du contour.

- Bouton **+** : Si la forme est une image diminue sa transparence, sinon augmente la taille du trait du contour.

- Bouton **flèche droite** : Déplace de 1 vers la droite la forme

- Bouton **flèche gauche** : Déplace de 1 vers la gauche la forme

- Bouton **flèche haut** : Déplace de 1 vers le haut la forme

- Bouton **flèche bas** : Déplace de 1 vers le bas la forme


#### Si un point est sélectionné :

- Bouton **suppr** : supprime le point

- Bouton **V** : Déplace le point sur le *calque*

- Bouton **C** : Bascule l'affichage du *calque* sélectionné (dans le menu)

- Bouton **flèche droite** : Déplace de 1 vers la droite le point

- Bouton **flèche gauche** : Déplace de 1 vers la gauche le point

- Bouton **flèche haut** : Déplace de 1 vers le haut le point

- Bouton **flèche bas** : Déplace de 1 vers le bas le point


#### Si aucun objet n'est sélectionné

- Bouton **suppr** : supprime le *calque* sélectionné (dans le menu)

- Bouton **C** : Bascule l'affichage du *calque* sélectionné (dans le menu)


## Fenêtre Menu

- La comboBox Calque permet de sélectionner le calque actif

- La comboBox Groupe permet de sélectionner le groupe actif

- Le bouton *Créer Calque* créer un nouveau calque

- Le bouton *Créer Groupe* créer un nouveau groupe

- Le bouton "Objet", ouvre une interface pour créer l'objet

- Le bouton *Charger*, ouvre une interface pour charger un fichier avec l'extension .shape

- Le bouton *Sauvegarder*, ouvre une interface pour sauvegarder un fichier avec l'extension .shape

- Chaque interface est suffisamment explicite, pour qu'il n'y est pas à les détailler plus précisément.


### Fonctionnalité non présentes sur l'interface :

- Impossible de sélectionner un polygone autrement que par son ancre

- Impossible redimensionner : rectangle, carré, ellipse, cercle

- impossible de modifier les points partagé : triangle & polygone

- Impossible de modifier la couleur des formes


### Voir une scène de ShapEditor
- Lancez l'application

- Cliquez sur charger

- Entrez le chemin vers le fichier exemple.shape qui est à la racine du projet

# Copyright & License

Tous droits réservés à DI NARDO Valentin, LENHARD Erwan.