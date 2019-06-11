# Projet - P.O.O.  --- ShapEditor

Le but de ce projet est de créer une application graphique d'édition de forme en c++. Celle-ci doit pouvoir lire un fichier de texte décrivant un ensemble de **formes géométriques** et leurs propriétés (épaisseur de trait, couleur, etc.), qui les trace toutes dans une même fenêtre et qui permet de les **éditer**, c’est-à-dire d’en modifier les propriétés.

# Premiers pas
## Prérequis 
- ***CMake*** pour générer le projet
- ***Un compilateur C++*** (gcc, MSCV, etc)
- ***Doxygen*** pour générer la documentation

## Installation 
### Générer le projet:
- **Ouvrez CMake** puis sélectionner la racine du projet (le répertoire qui contient le fichier README.md et surtout le fichier CMakeLists.txt).
- **Configurer** votre projet puis **générez** le.

### Compiler le projet:
- Lancez le projet.
- Ensuite **compilez** le.
- Enfin lancez **shapeditor.exe** qui apparait dans */bin/debug* ou dans */bin/release* (selon le type de build).

### Générer la documentation :
- ouvrez ***Doxygen***
- File -> Open et chercher le fichier *"Doxyfile"* à la racine du projet
- Allez dans l'onglet "Run" -> cliquer sur "Run doxygen"
- Cliquez sur "Show HTML output"
- Vous avez aussi accès à la documentation ici : projets.lerwox.com/ShapEditor/doc

# Utilisation --- Aide