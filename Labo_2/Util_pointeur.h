//
// Created by mag20 on 2024-09-17.
//

#ifndef UTIL_POINTEUR_H
#define UTIL_POINTEUR_H
#include <ostream>
#include <string>


template <typename pointer_type>
class Util_pointeur {
public:
    std::ostream& print_pointer (std::ostream& os, const std::string& type_name, const pointer_type& ptr);
};

#include "Util_pointer.hpp"

#endif //UTIL_POINTEUR_H
