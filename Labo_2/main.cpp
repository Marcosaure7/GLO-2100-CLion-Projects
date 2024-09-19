/*
 * testPersonne.cpp
 *
 *      Author: T.E.
 */
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include "Personne.h"
#include "Adresse.h"
#include "Etudiant.h"
#include "Util_pointeur.h"

using namespace std;

int
main ()
{

  /*Personne moi ("Joe", "Bloe", Adresse ("ici"));
  cout << "moi : " << moi;

  Personne mover ("What's", "up", Adresse ("la"));
  cout << "mover : " << mover;

  cout << "Constructeur deplacement" << endl;
  mover = move (moi);
  cout << "mover : " << mover;

  cout << "copie" << endl;
  moi = mover;
  cout << "moi : " << moi;*/

    array<Etudiant, 8> resultats {
        {
            {"Albert", 3},
            {"Ben", 5},
            {"Christine", 2},
            {"Dan", 8}, // Dans a le + de pts
            {"Enchilada", 4},
            {"Francis", 1},
            {"Greg", 3},
            {"Hagrid", 5}
        }};

    Etudiant *etud_max = std::max_element(resultats.begin(), resultats.end());
    cout << etud_max->reqEtudiantFormate() << " est le meilleur eleve";

  return 0;
}

