cmake_minimum_required(VERSION 3.1)

#Configuration du projet
project(Forme)

set(LIBRARY_OUTPUT_PATH ${Forme_SOURCE_DIR}/lib)

#Inclusion des en-têtes publics
include_directories(include)

#Configuration de la bibliothèque
file(GLOB_RECURSE
    source_files
    src/*
    include/*
)

add_library(Forme STATIC ${source_files})