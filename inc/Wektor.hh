#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>
#include <math.h>
#include "LZespolona.hh"



  template<class TYP, int ROZMIAR>
class Wektor {

  TYP tab[ROZMIAR];
  
public:

  Wektor();

  Wektor(TYP xx,TYP yy,TYP zz);

  Wektor(TYP x1,TYP x2,TYP x3,TYP x4,TYP x5);

  const TYP &operator[] (int index) const;

  TYP &operator[] (int index);

  Wektor<TYP, ROZMIAR> operator+ (const Wektor<TYP, ROZMIAR> & W2) const;
  
  Wektor<TYP, ROZMIAR> operator- (const Wektor<TYP, ROZMIAR> & W2) const;

  TYP operator* (const Wektor<TYP, ROZMIAR> & W2) const;

  Wektor<TYP, ROZMIAR>  operator* (TYP l2) const;

  Wektor<TYP, ROZMIAR>  operator/ (double l2) const;
  
  bool operator==(const Wektor<TYP, ROZMIAR> & W2) const;

  bool operator!=(const Wektor<TYP, ROZMIAR> & W2)const;
};

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> operator*(double l1, const Wektor<TYP, ROZMIAR> & W2);
template<class TYP,int ROZMIAR>
std::istream& operator >> (std::istream &strm, Wektor<TYP, ROZMIAR> &Wek);
template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const Wektor<TYP, ROZMIAR> &Wek);


#endif
