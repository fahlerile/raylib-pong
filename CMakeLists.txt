# cmake .. -D CMAKE_C_COMPILER=x86_64-w64-mingw32-gcc -D CMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++

cmake_minimum_required(VERSION 3.18.4)
project(raylib-pong)

set(
	SOURCES
	src/main.cpp
	src/utils.cpp
	src/Entity.cpp
	src/Pong.cpp
	src/Ball.cpp
)

add_executable(pong ${SOURCES})

target_include_directories(pong PUBLIC lib/include)
target_include_directories(pong PUBLIC src/include)

find_library(
	RAYLIB_LIB
	NAMES raylib
	HINTS "${CMAKE_SOURCE_DIR}/lib"
	NO_DEFAULT_PATH
)
if(NOT RAYLIB_LIB)
  	message(FATAL_ERROR "Raylib library is not found")
endif()

target_link_libraries(
	pong
	${RAYLIB_LIB}
	Winmm
)
