cmake_minimum_required(VERSION 3.29)
project(Labo_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(SOURCES Adresse.h
    Adresse.cpp
    Personne.h
    Personne.cpp
    Util_pointeur.h
    Util_pointer.hpp
    ContratException.h
    ContratException.cpp
    main.cpp
        Etudiant.cpp
        Etudiant.h
        # Saison.cpp
)

add_executable(Labo_2 ${SOURCES})
