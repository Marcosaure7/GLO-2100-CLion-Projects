//
// Created by mag20 on 2024-09-18.
//

#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <string>


class Etudiant {
public:
    Etudiant() = delete;
    Etudiant (const std::string& nom, int pts);

    bool operator< (const Etudiant& etudiant) const;
    std::string reqEtudiantFormate () const;

private:
    std::string m_nom;
    int m_pts;
    void verifieInvariant () const;
};



#endif //ETUDIANT_H
