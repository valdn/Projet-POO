cmake_minimum_required(VERSION 3.1)

project(libforme)

set(SRCS
	Forme.cpp
	Formes.cpp
	Point.cpp
	Rectangle.cpp
)

set(HEADER
	Forme.hpp
	Formes.hpp
	Point.hpp
	Rectangle.hpp
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_library(forme ${SRCS} ${header})
target_link_libraries(forme sfml-graphics)