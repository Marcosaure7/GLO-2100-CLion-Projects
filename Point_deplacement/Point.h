/** 
 * \file   Point.h
 * \author TE
 *
 */

#ifndef POINT_H
#define POINT_H
#include <iostream>

//#define COUT
#define MOVE

class Point
{
  struct Coordonnee;

public:
  // Constructeurs

  Point ();
  Point (double x, double y);
  Point (const Point& point); // copie
#ifdef MOVE
  Point (Point&& point) noexcept; // déplacement
#endif
  // Destructeur
  ~Point ();

  // Accesseurs et mutateurs
  double reqX () const;
  void asgX (double x);
  double reqY () const;
  void asgY (double y);

  // Surcharge
  Point& operator= (const Point& point); // copie
#ifdef MOVE
  Point& operator= (Point&& point); // déplacement
#endif
  friend std::ostream& operator<< (std::ostream& os, const Point& point);
  friend Point operator+ (const Point& p1, const Point& p2);

  // Services (exemples)
  static void swap_v1 (Point& a, Point& b);
  static void swap_v2 (Point& a, Point& b);

  // Comptage
  static int constructions;
  static int copies;
  static int deplacements;
  static void reset ();

private:

  struct Coordonnee
  {

    Coordonnee () : x (0.), y (0.) { };

    Coordonnee (double x, double y) : x (x), y (y) { };
    double x;
    double y;
  };
  Coordonnee *coordonnee;
};

#endif /* POINT_H */

