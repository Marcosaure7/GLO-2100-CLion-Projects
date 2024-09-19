/** 
 * \file:   main.cpp
 * \author: TE
 * \brief inspiré de : https://github.com/tvaira/cpp-moderne
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "Point.h"

using namespace std;

/*
 * 
 */
void demoDeplacement ();
void performance ();

int
main ()
{
  int choix;
  do
    {
      cout << "1 Déplacement, 2 performance, autre fin \n";
      cin>>choix;
      switch (choix)
        {
        case 1: demoDeplacement ();
          break;
        case 2: performance ();
          break;
        }
    }
  while (choix == 1 || choix == 2);

  return 0;
}

void
demoDeplacement ()
{
  Point p2, p3 (1., 1.), p4 (2.5, 2.5);
  cout << "p2 = " << p2 << endl;
  cout << "p3 = " << p3 << endl;
  cout << "p4 = " << p4 << endl;
  cout << endl;

  cout << "p2 = p3 + p4" << endl;
  p2 = p3 + p4; // move
  cout << "p2 = " << p2 << endl;
  cout << endl;

#ifdef MOVE
  cout << "p5 <- p2" << endl;
  Point p5 (move (p2)); // move
  cout << "p5 = " << p5 << endl;
  cout << endl;
#endif

  cout << "p3 <-> p4" << endl;
  Point::swap_v1 (p3, p4); // par copie
  cout << "p3 = " << p3 << endl;
  cout << "p4 = " << p4 << endl;
  cout << endl;

#ifdef MOVE
  cout << "p3 <-> p4" << endl;
  Point::swap_v2 (p3, p4); // move
  cout << "p3 = " << p3 << endl;
  cout << "p4 = " << p4 << endl;
  cout << endl;
#endif
//  cout << p2.reqX ();

}

void
performance ()
{
  Point::reset ();

  auto start = std::chrono::high_resolution_clock::now (); // démarrage chronomètre
  vector<Point> points;
  for (int i = 0; i < 1000000; ++i)
    {
      points.push_back (Point (i, i * 2));
    }
#ifdef MOVE
  vector<Point> courbe (move (points)); // test 2 : par déplacement
#else
  vector<Point> courbe (points); // test 1 : par copie
#endif
  reverse (courbe.begin (), courbe.end ());

  auto end = chrono::high_resolution_clock::now (); // arrêt chronomètre
  chrono::duration<double> elapsed = end - start; // calcul du temps
  // Affichage des résultats
  cout << "Duration : " << elapsed.count () << " s\n";
  cout << "Constructions : " << Point::constructions << "\n";
  cout << "Copies : " << Point::copies << "\n";
  cout << "Deplacements : " << Point::deplacements << "\n";
}
