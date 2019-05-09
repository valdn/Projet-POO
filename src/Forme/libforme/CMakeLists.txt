cmake_minimum_required(VERSION 3.1)

project(libforme)

set(SRCS
	Formes.cpp
	Forme.cpp
	Point.cpp
	Rectangle.cpp
	Ellipse.cpp
)

set(HEADER
	Formes.hpp
	Forme.hpp
	Point.hpp
	Rectangle.hpp
	Ellipse.hpp
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_library(forme ${SRCS} ${header})
target_link_libraries(forme sfml-graphics)