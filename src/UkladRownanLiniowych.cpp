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
 

  Wyz=wyznacznik5(A);
  Wyz1=wyznacznik5(Mac1);
  Wyz2=wyznacznik5(Mac2);
  Wyz3=wyznacznik5(Mac3);
  Wyz4=wyznacznik5(Mac4);
  Wyz5=wyznacznik5(Mac5);

  
  X1=Wyz1/Wyz;
  X2=Wyz2/Wyz;
  X3=Wyz3/Wyz;
  X4=Wyz4/Wyz;
  X5=Wyz5/Wyz;

  Wektor<TYP, ROZMIAR> wynik(X1,X2,X3,X4,X5);
  
  return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> UklRowL<TYP, ROZMIAR>::Oblicz() const //metoda Cramera
{
  TYP Wyz, WyzX, WyzY, WyzZ;
  TYP X, Y, Z;
  Macierz<TYP, ROZMIAR> MacX, MacY, MacZ;
  
  MacX=A.transponuj();
  MacX[0]=B;
  MacX=MacX.transponuj();

  MacY=A.transponuj();
  MacY[1]=B;
  MacY=MacY.transponuj();

  MacZ=A.transponuj();
  MacZ[2]=B;
  MacZ=MacZ.transponuj();


  Wyz=A.wyznacznik();
  WyzX=MacX.wyznacznik();
  WyzY=MacY.wyznacznik();
  WyzZ=MacZ.wyznacznik();
  
  X=WyzX/Wyz;
  Y=WyzY/Wyz;
  Z=WyzZ/Wyz;

  Wektor<TYP, ROZMIAR> wynik(X,Y,Z);
  
  return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> WBledu(Macierz<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> X)
{
  Wektor<TYP, ROZMIAR>  wynik;

  for(int w=0;w<ROZMIAR;w++)
    for(int k=0;k<ROZMIAR;k++)
      wynik[w]=wynik[w]+A(w,k)*X[k];

  for(int w=0;w<ROZMIAR;w++)
    wynik[w]=wynik[w]-B[w];
  
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

  

template class UklRowL<double,3>;
template class UklRowL<double,5>;
template std::istream &operator >> (std::istream &strm, UklRowL<double, 5> &U);
template std::ostream& operator << (std::ostream &strm, const UklRowL<double, 5> &U);
template Wektor<double, 3> WBledu(Macierz<double, 3> A, Wektor<double, 3> B, Wektor<double, 3> X);

template class UklRowL<LZespolona,3>;
template class UklRowL<LZespolona,5>;
template std::istream &operator >> (std::istream &strm, UklRowL<LZespolona, 5> &U);
template std::ostream& operator << (std::ostream &strm, const UklRowL<LZespolona, 5> &U);
