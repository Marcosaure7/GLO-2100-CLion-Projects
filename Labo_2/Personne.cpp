//
// Created by mag20 on 2024-09-17.
//

#include <ContratException.h>
#include <Personne.h>
#include <sstream>

using namespace std;

Personne::Personne (const string& p_nom, const string& p_prenom, const Adresse& p_adresse)
    : m_nom (p_nom), m_prenom (p_prenom), m_adresse (new Adresse(p_adresse))
{
    PRECONDITION(!p_nom.empty());
    PRECONDITION(!p_prenom.empty());

    POSTCONDITION(m_nom == p_nom);
    POSTCONDITION(m_prenom == p_prenom);
    POSTCONDITION(m_adresse->reqDetailAdresse() == p_adresse.reqDetailAdresse());
    INVARIANTS();
}

Personne::Personne (const Personne& p_personne)
    : m_nom (p_personne.reqNom()), m_prenom (p_personne.reqPrenom()),
    m_adresse (new Adresse(p_personne.reqAdresse()))
{
    POSTCONDITION (m_nom == p_personne.reqNom());
    POSTCONDITION (m_prenom == p_personne.reqPrenom());
    POSTCONDITION (m_adresse->reqDetailAdresse()
                    == p_personne.m_adresse->reqDetailAdresse());
    INVARIANTS();
}

Personne::Personne (Personne&& p_personne) noexcept
    : m_nom (std::move (p_personne.m_nom)), m_prenom (std::move (p_personne.m_prenom)),
      m_adresse(new Adresse(p_personne.reqAdresse()))
{
    p_personne.m_adresse = nullptr;
    INVARIANTS();
}

Personne::~Personne()
{
    if (m_adresse) delete m_adresse;
}

Personne& Personne::operator= (const Personne& p_personne)
{
    if (this != &p_personne)
    {
        m_nom = p_personne.reqNom();
        m_prenom = p_personne.reqPrenom();
        m_adresse = new Adresse(p_personne.reqAdresse());
        INVARIANTS();
    }

    return *this;
}

Personne& Personne::operator= (Personne&& p_personne) noexcept
{
    if (this != &p_personne)
    {
        delete m_adresse;

        m_nom = std::move (p_personne.m_nom);
        m_prenom = std::move (p_personne.m_prenom);
        m_adresse = new Adresse(p_personne.reqAdresse());

        p_personne.m_adresse = nullptr;
        INVARIANTS();
    }

    return *this;
}


const string& Personne::reqNom () const
{
    return m_nom;
}

const string& Personne::reqPrenom () const
{
    return m_prenom;
}

const Adresse& Personne::reqAdresse() const
{
    return *m_adresse;
}

void Personne::asgAdresse(const Adresse& p_adresse)
{
    m_adresse = (new Adresse(p_adresse));
    POSTCONDITION(m_adresse->reqDetailAdresse() == p_adresse.reqDetailAdresse());
    INVARIANTS();
}

string Personne::reqPersonneFormate() const
{
    ostringstream os;
    os << "Nom : " << reqNom() << ", Prenom : " << reqPrenom() << "\n"
    << "Adresse : " << m_adresse << " " << m_adresse->reqDetailAdresse() << "\n"
    << endl;

    return os.str();
}

std::ostream& operator<<(std::ostream& os, const Personne& p_personne)
{
    os << p_personne.reqPersonneFormate();
    return os;
}

void Personne::verifieInvariant() const
{
    INVARIANT(!m_nom.empty());
    INVARIANT(!m_prenom.empty());
}
