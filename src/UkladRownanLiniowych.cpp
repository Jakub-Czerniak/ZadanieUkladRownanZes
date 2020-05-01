#include "UkladRownanLiniowych.hh"
using namespace std;


template<class TYP,int ROZMIAR>
UklRowL<TYP, ROZMIAR>::UklRowL()
{
  A=Macierz<TYP, ROZMIAR> ();
  B=Wektor<TYP, ROZMIAR> ();
}
template<class TYP,int ROZMIAR>
UklRowL<TYP, ROZMIAR>::UklRowL(const Macierz<TYP, ROZMIAR> &Mac, const Wektor<TYP, ROZMIAR>  &Wek)
{
  A=Mac;
  B=Wek;
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> UklRowL<TYP, ROZMIAR>::get_A() const
{
  Macierz<TYP, ROZMIAR> Mac;
  Mac=A;
  
  return Mac;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> UklRowL<TYP, ROZMIAR>::get_B() const
{
  Wektor<TYP, ROZMIAR> Wek;
  Wek=B;
  
  return Wek;
}

template<class TYP,int ROZMIAR>
void UklRowL<TYP, ROZMIAR>::set_A(const Macierz<TYP, ROZMIAR> AA)
{
  A=AA;
}

template<class TYP,int ROZMIAR>
void UklRowL<TYP, ROZMIAR>::set_B(const Wektor<TYP, ROZMIAR> BB)
{
  B=BB;
}


template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> UklRowL<TYP, ROZMIAR>::ObliczPiaSt() const //metoda Cramera
{
  TYP Wyz, Wyz1, Wyz2, Wyz3, Wyz4, Wyz5;
  TYP X1, X2, X3, X4, X5;
  Macierz<TYP, ROZMIAR> Mac1, Mac2, Mac3, Mac4, Mac5;
  
  
  Mac1=A.transponuj();
  Mac1[0]=B;
  Mac1=Mac1.transponuj();

  Mac2=A.transponuj();
  Mac2[1]=B;
  Mac2=Mac2.transponuj();

  Mac3=A.transponuj();
  Mac3[2]=B;
  Mac3=Mac3.transponuj();
  
  Mac4=A.transponuj();
  Mac4[3]=B;
  Mac4=Mac4.transponuj();

  Mac5=A.transponuj();
  Mac5[4]=B;
  Mac5=Mac5.transponuj();
 

  Wyz=wyznacznik(A,5);
  Wyz1=wyznacznik(Mac1,5);
  Wyz2=wyznacznik(Mac2,5);
  Wyz3=wyznacznik(Mac3,5);
  Wyz4=wyznacznik(Mac4,5);
  Wyz5=wyznacznik(Mac5,5);

  
  X1=Wyz1/Wyz;
  X2=Wyz2/Wyz;
  X3=Wyz3/Wyz;
  X4=Wyz4/Wyz;
  X5=Wyz5/Wyz;

  Wektor<TYP, ROZMIAR> wynik(X1,X2,X3,X4,X5);
  
  return wynik;
}


template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> WBledu(Macierz<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> X)
{
  Wektor<TYP, ROZMIAR>  wynik;

wynik=A*X-B;   
  
  return wynik;
}


template<class TYP,int ROZMIAR>
std::istream &operator >> (std::istream &strm, UklRowL<TYP, ROZMIAR> &U)
{
  Macierz<TYP, ROZMIAR>  pomA;
  Wektor<TYP, ROZMIAR>  pomB;

  strm >> pomA >> pomB;
  U.set_A(pomA);
  U.set_B(pomB);

  return strm;
}


template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const UklRowL<TYP, ROZMIAR> &U)
{
  strm << U.get_A() << U.get_B();

  return strm;
}

  


template class UklRowL<double,5>;
template Wektor<double, 5> WBledu(Macierz<double, 5> A, Wektor<double, 5> B, Wektor<double, 5> X);
template std::istream &operator >> (std::istream &strm, UklRowL<double, 5> &U);
template std::ostream& operator << (std::ostream &strm, const UklRowL<double, 5> &U);

template class UklRowL<LZespolona,5>;
template Wektor<LZespolona, 5> WBledu(Macierz<LZespolona, 5> A, Wektor<LZespolona, 5> B, Wektor<LZespolona, 5> X);
template std::istream &operator >> (std::istream &strm, UklRowL<LZespolona, 5> &U);
template std::ostream& operator << (std::ostream &strm, const UklRowL<LZespolona, 5> &U);
