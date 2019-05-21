cmake_minimum_required(VERSION 3.1)

project(ShapEditor)

set(SFML_DIR "${ShapEditor_SOURCE_DIR}/include/SFML/lib/cmake/SFML")
set(SFML_DOC_DIR "${ShapEditor_SOURCE_DIR}/include/SFML/doc")

set(EXECUTABLE_OUTPUT_PATH ${ShapEditor_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

file(
        GLOB_RECURSE
        source_files
		src/*
		include/FormeGUI/*
)

add_executable(shapeditor ${source_files})

#Cherche SFML v 2.5 au moins
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

#Inclusion de la libraire Forme
include_directories(include/Forme/include/)
add_subdirectory(include/Forme)
target_link_libraries(shapeditor Forme)

include_directories(include/FormeGUI)

#link la librairie graphic de sfml au projet
target_link_libraries(shapeditor sfml-graphics)


#Copie les .dll nécessaire dans le répertoire de sortie
message(STATUS "Copying SFML binaries")

#debug version
if(NOT EXISTS ${ShapEditor_SOURCE_DIR}/bin/Debug)
	execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${ShapEditor_SOURCE_DIR}/bin/Debug)
endif()
if(TARGET sfml-graphics)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-graphics-d-2.dll	${ShapEditor_SOURCE_DIR}/bin/Debug)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-system-d-2.dll		${ShapEditor_SOURCE_DIR}/bin/Debug)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-window-d-2.dll		${ShapEditor_SOURCE_DIR}/bin/Debug)
endif()

#Release version
if(NOT EXISTS ${ShapEditor_SOURCE_DIR}/bin/Release)
	execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${ShapEditor_SOURCE_DIR}/bin/Release)
endif()
if(TARGET sfml-graphics)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-graphics-2.dll	${ShapEditor_SOURCE_DIR}/bin/Release)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-system-2.dll	${ShapEditor_SOURCE_DIR}/bin/Release)
	execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SFML_DIR}/../../../bin/sfml-window-2.dll	${ShapEditor_SOURCE_DIR}/bin/Release)
endif()