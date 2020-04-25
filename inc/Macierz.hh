#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include <math.h>
#include "Wektor.hh"
#include "LZespolona.hh"


template<class TYP,int ROZMIAR>
class Macierz {

  Wektor<TYP, ROZMIAR> tab[ROZMIAR];

public:

  Macierz();

  Macierz(Wektor<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> C);

  Macierz(Wektor<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> C, Wektor<TYP, ROZMIAR> D, Wektor<TYP, ROZMIAR> E);
  
  const Wektor<TYP, ROZMIAR>  & operator[] (int index) const;
  
  Wektor<TYP, ROZMIAR> & operator[] (int index);

  const TYP  & operator() (int index1, int index2) const;
  
  TYP & operator() (int index1, int index2);
  
  Macierz<TYP, ROZMIAR> operator +(const Macierz<TYP, ROZMIAR> & M);

  Macierz<TYP, ROZMIAR> operator -(const Macierz<TYP, ROZMIAR> & M);

  Macierz<TYP, ROZMIAR> operator *(const Macierz<TYP, ROZMIAR> & M);
  
  Macierz<TYP, ROZMIAR> operator *(TYP mnoznik);

  bool operator== (const Macierz<TYP, ROZMIAR> & M) const;
  
  bool operator!= (const Macierz<TYP, ROZMIAR> & M) const;

  Macierz<TYP, ROZMIAR> transponuj() const;

  TYP wyznacznik() const;
};

template<class TYP,int ROZMIAR>
TYP wyznacznik3(Macierz<TYP,ROZMIAR> tab);

template<class TYP,int ROZMIAR>
TYP wyznacznik4(Macierz<TYP,ROZMIAR> tab);

template<class TYP,int ROZMIAR>
TYP wyznacznik5(Macierz<TYP,ROZMIAR> tab);

template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac);

template<class TYP,int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac);

#endif
