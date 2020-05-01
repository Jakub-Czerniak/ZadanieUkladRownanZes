#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "LZespolona.hh"
#include "Wektor.hh"
#include "Macierz.hh"



template<class TYP,int ROZMIAR>
class UklRowL {

  Macierz<TYP, ROZMIAR> A;
  Wektor<TYP, ROZMIAR> B;
  
  public:
  
  UklRowL();

  UklRowL(const Macierz<TYP, ROZMIAR> &Mac, const Wektor<TYP, ROZMIAR> &Wek);

  Macierz<TYP, ROZMIAR> get_A() const;
  
  Wektor<TYP, ROZMIAR> get_B() const;

  void set_A(const Macierz<TYP, ROZMIAR> AA);

  void set_B(const Wektor<TYP, ROZMIAR> BB);

 /* Wektor<TYP, ROZMIAR> Oblicz() const;*/

  Wektor<TYP, ROZMIAR> ObliczPiaSt() const;
};

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> WBledu(Macierz<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> X);

template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const UklRowL<TYP, ROZMIAR> &U);

template<class TYP,int ROZMIAR>
std::istream &operator >> (std::istream &strm, UklRowL<TYP, ROZMIAR> &U);
#endif
