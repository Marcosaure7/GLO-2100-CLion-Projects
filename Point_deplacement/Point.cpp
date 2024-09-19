/** 
 * \file   Point.cpp
 * \author TE
 * 
 */

#include "Point.h"

using namespace std;

int Point::constructions {0}; //pour la démo
int Point::copies {0};
int Point::deplacements {0};

Point::Point () : coordonnee (new Coordonnee ())
{
  ++constructions;
#ifdef COUT
  cout << "Constructeur par default " << __FUNCTION__ << " " << this << endl;
#endif
}

Point::Point (double x, double y) : coordonnee (new Coordonnee (x, y))
{
  ++constructions; //pour la démo
#ifdef COUT
  cout << "Constructeur avec paramatres " << __FUNCTION__ << " " << this << endl;
#endif
}

// Constructeur de copie

Point::Point (const Point & point) : coordonnee (new Coordonnee (point.coordonnee->x,
                                                                 point.coordonnee->y))
{
  ++copies; //pour la démo
#ifdef COUT
  cout << "copie " << __FUNCTION__ << " " << this << endl;
#endif
}

#ifdef MOVE
// Constructeur de déplacement (le "vol")

Point::Point (Point && point) noexcept : coordonnee (point.coordonnee)
{
  point.coordonnee = nullptr;
  ++deplacements; //pour la démo
#ifdef COUT
  cout << "deplacement " << __FUNCTION__ << " " << this << endl;
#endif
}
#endif

// Destructeur

Point::~Point ()
{
  if (coordonnee) delete coordonnee;
};

// Copie

Point & Point::operator= (const Point & point)
{
  if (this != &point)
    {
      delete coordonnee;
      coordonnee = new Coordonnee (point.coordonnee->x, point.coordonnee->y);
      ++copies;
#ifdef COUT
      cout << "copie " << __FUNCTION__ << " " << this << endl;
#endif
    }
  return *this;
}

#ifdef MOVE
// Déplacement

Point & Point::operator= (Point && point)
{
  if (this != &point)
    {
      delete coordonnee;
      coordonnee = point.coordonnee; // "vol"
      point.coordonnee = nullptr; // valide mais non spécifié
    }
  ++deplacements;
#ifdef COUT
  cout << "deplacement " << __FUNCTION__ << " " << this << endl;
#endif  

  return *this;
}
#endif

// Surcharge

ostream& operator<< (ostream& os, const Point & point)
{
  os << "<" << point.coordonnee->x << "," << point.coordonnee->y << ">";
  return os;
}

Point operator+ (const Point& p1, const Point & p2)
{
  Point p;
  p.coordonnee->x = p1.coordonnee->x + p2.coordonnee->x;
  p.coordonnee->y = p1.coordonnee->y + p2.coordonnee->y;
  return p;
}

void
Point::swap_v1 (Point& a, Point & b) // par copie
{
  Point tmp (a); // constructeur de copie
  a = b; // opérateur de copie
  b = tmp; // opérateur de copie
}

void
Point::swap_v2 (Point& a, Point & b) // par déplacement
{
  Point tmp (move (a));
  a = move (b);
  b = move (tmp);
}

// Accesseurs et mutateurs

double
Point::reqX () const
{
  return coordonnee->x;
}

void
Point::asgX (double x)
{
  this->coordonnee->x = x;
}

double
Point::reqY () const
{
  return coordonnee->y;
}

void
Point::asgY (double y)
{
  this->coordonnee->y = y;
}

void
Point::reset ()
{
  constructions = 0;
  copies = 0;
  deplacements = 0;
}