//
// Created by mag20 on 2024-09-17.
//
#pragma once

template <typename pointer_type>
std::ostream& Util_pointeur<pointer_type>::print_pointer(std::ostream& os, const std::string& type_name,
    const pointer_type& ptr)
{
    os << "<" << type_name << " pointeur " << ptr << " valeur=" << *ptr << ">";
    return os;
}
