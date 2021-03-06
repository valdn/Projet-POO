cmake_minimum_required(VERSION 3.1)

#nom du projet
project(ShapEditor)

#Repertoire de sortie
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin CACHE
    PATH "Directory where .exe and .dll files are dumped." FORCE)

#Tous les fichiers de l'executable
file(
        GLOB_RECURSE
        source_files
		src/*
		include/FormeGUI/*
)

#creation executable de l'application
add_executable(shapeditor ${source_files})
#On inclut le repertoire qui contient les drawables
include_directories(include/FormeGUI)

#Inclusion SFML
include_directories(include/SFML/include/)
add_subdirectory(include/SFML)

#Inclusion de la libraire Forme
include_directories(include/Forme/include/)
add_subdirectory(include/Forme)
target_link_libraries(shapeditor Forme)

#Inclusion TGUI
include_directories(include/TGUI/include/)
add_subdirectory(include/TGUI)

#On lie les bibliothèque dynamique de SFML et TGUI avec le projet en fonction du type de build
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	target_link_libraries(shapeditor sfml-graphics)
	target_link_libraries(shapeditor sfml-system)
	target_link_libraries(shapeditor sfml-window)
	target_link_libraries(shapeditor tgui)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_link_libraries(shapeditor sfml-graphics-d)
	target_link_libraries(shapeditor sfml-system-d)
	target_link_libraries(shapeditor sfml-window-d)
	target_link_libraries(shapeditor tgui-d)
endif()
