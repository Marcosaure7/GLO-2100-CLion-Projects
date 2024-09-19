//
// Created by mag20 on 2024-09-18.
//

#include "Etudiant.h"
#include <sstream>
#include "ContratException.h"

Etudiant::Etudiant(const std::string& nom, int pts)
    : m_nom(nom), m_pts(pts)
{
    PRECONDITION (!nom.empty());
    PRECONDITION (pts > 0);
    POSTCONDITION (m_nom == nom);
    POSTCONDITION (m_pts == pts);
    INVARIANTS();
}

bool Etudiant::operator<(const Etudiant& etudiant) const
{
    return m_pts < etudiant.m_pts;
}

std::string Etudiant::reqEtudiantFormate () const
{
    return m_nom;
}

void Etudiant::verifieInvariant() const
{
    INVARIANT (!m_nom.empty());
    INVARIANT (m_pts > 0);
}
