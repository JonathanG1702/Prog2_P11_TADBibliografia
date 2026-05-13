cmake_minimum_required(VERSION 4.2)
project(P11_TADBibliografia)

set(CMAKE_CXX_STANDARD 20)

add_executable(P11_TADBibliografia main.cpp
        usaLibro.cpp
        Libro.cpp
        Bibliografia.cpp
        TADBibliografia.h
        TADLibro.h
        usaBibliografia.cpp
        extraBibliografia.cpp)
