//
// Created by mag20 on 2024-09-19.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
class Saison
{
public:
    Saison (const std::string& p_nom, double p_temperature)
    : m_nom (p_nom), m_temperatureMoyenne (p_temperature) { };
    //private:
    std::string m_nom;
    double m_temperatureMoyenne;
};
int
main ()
{
    std::array<Saison, 4> saisons {
    {
        { "Printemps", 285.0},
        { "Eter", 296.0},
        { "Automne", 288.0},
        { "Hiver", 263.0}
    }};
    /*
    * utiliser sort ici
    */
    std::sort(saisons.begin(), saisons.end(), [](const Saison& a, const Saison& b)
        {return a.m_temperatureMoyenne < b.m_temperatureMoyenne; });


    for (const auto& saison : saisons)
    {
        std::cout << saison.m_nom << '\n';
    }
    return 0;
}