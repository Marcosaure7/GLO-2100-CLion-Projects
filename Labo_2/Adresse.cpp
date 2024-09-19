//
// Created by mag20 on 2024-09-17.
//

#include "Adresse.h"
#include "ContratException.h"
#include <string>

using namespace std;

Adresse::Adresse (const std::string& p_adresse)
: m_detailAdresse(p_adresse)
{
    PRECONDITION(!m_detailAdresse.empty());

    POSTCONDITION(m_detailAdresse == p_adresse);
    INVARIANTS();
}

void Adresse::asgAdresse(const std::string& adresse)
{
    PRECONDITION(!m_detailAdresse.empty());
    m_detailAdresse = adresse;
    POSTCONDITION(m_detailAdresse == adresse);
    INVARIANTS();
}

const std::string& Adresse::reqDetailAdresse() const
{
    return m_detailAdresse;
}

void Adresse::verifieInvariant() const
{
    INVARIANT(!m_detailAdresse.empty());
}


