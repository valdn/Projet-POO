cmake_minimum_required(VERSION 3.1)

project(ShapEditor)

set(SFML_DOC_DIR "${ShapEditor_SOURCE_DIR}/include/SFML/doc")
set(SFML_DIR "${ShapEditor_SOURCE_DIR}/include/SFML/lib/cmake/SFML")

add_subdirectory(src/forme/libforme)

set(SRCS
	src/Forme/main.cpp
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
add_executable(main ${SRCS})
target_link_libraries(main forme)
target_link_libraries(main sfml-graphics)

add_custom_target(SMFLCopyBinaries
	#debug version
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-graphics-d-2.dll	${CMAKE_BINARY_DIR}/Debug
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-system-d-2.dll	${CMAKE_BINARY_DIR}/Debug
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-window-d-2.dll	${CMAKE_BINARY_DIR}/Debug

	#Release version
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-graphics-2.dll	${CMAKE_BINARY_DIR}/Release
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-system-2.dll	${CMAKE_BINARY_DIR}/Release
	COMMAND ${CMAKE_COMMAND} -E copy ${SFML_DIR}/../../../bin/sfml-window-2.dll	${CMAKE_BINARY_DIR}/Release

	#Message
	COMMENT "Copying SFML binaries from '${SFML_DIR}/bin/' to '${CMAKE_BINARY_DIR}'" VERBATIM
)

add_dependencies(main SMFLCopyBinaries)