#include "Wektor.hh"

using namespace std; 


template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor()
{
  tab[0]= 0.0;
  tab[1]= 0.0;
  tab[2]= 0.0;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(TYP xx,TYP yy,TYP zz) 
{
  tab[0]= xx;
  tab[1]= yy;
  tab[2]= zz;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR>::Wektor(TYP x1,TYP x2,TYP x3,TYP x4,TYP x5)
{
  tab[0]= x1;
  tab[1]= x2;
  tab[2]= x3;
  tab[3]= x4;
  tab[4]= x5;
}

template<class TYP,int ROZMIAR>
const TYP & Wektor<TYP, ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Index poza zakresem 5" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP,int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR) {
    cerr << "Index poza zakresem 5" << endl;
    exit(1);
  }
  return tab[index];
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator+ (const Wektor<TYP, ROZMIAR> &W2) const
{
  Wektor<TYP, ROZMIAR> wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]+W2[index];
    }
  return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator- (const Wektor<TYP, ROZMIAR> & W2) const
{
  Wektor<TYP, ROZMIAR> wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]-W2[index];
    }
  return wynik;
}

template<class TYP,int ROZMIAR>
TYP Wektor<TYP, ROZMIAR>::operator* (const Wektor<TYP, ROZMIAR> & W2) const
{
  TYP wynik;
  wynik=0;
  for  (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik+=tab[index]*W2[index];
    }
  return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator* (TYP l2) const
{
  Wektor<TYP, ROZMIAR> wynik;
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]*l2;
    }
  return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR>  Wektor<TYP, ROZMIAR>::operator/ (double l2) const
{
  Wektor<TYP, ROZMIAR> wynik;
  if(abs(l2)<0.00001)
    {
      cerr << "Dzielenie przez 0" << endl;
      exit(1);
    }
  for (int index = 0 ; index<ROZMIAR ;index++)
    {
      wynik[index]=tab[index]/l2;
    }
  return wynik;
}

template<class TYP,int ROZMIAR>
bool Wektor<TYP,ROZMIAR>::operator==(const Wektor<TYP,ROZMIAR> & W2)const
{
  for(int i=0;i<ROZMIAR;i++)
    if(abs(tab[i]-W2[i])>0.00001) 
      return false;
  return true;
}

template<class TYP,int ROZMIAR>
bool Wektor<TYP, ROZMIAR>::operator!=(const Wektor<TYP, ROZMIAR> & W2)const
{
  return !(*this == W2);
}


template<class TYP,int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;i++)
  Strm >> Wek[i];
  return Strm; 
}


template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek)
{
  for(int i=0;i<ROZMIAR;i++)
    {
    Strm << Wek[i]<< ' ';
    }

  Strm << endl;
    
  return Strm;
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> operator*(double l1, const Wektor<TYP, ROZMIAR> & W2)
{
 Wektor<TYP, ROZMIAR> wynik;
    for (int index = 0 ; index<ROZMIAR ;index++)
      {
	wynik[index]=l1*W2[index];
      }
    return wynik;
}



template class Wektor<double,3>;
template class Wektor<double,4>;
template class Wektor<double,5>;
template class Wektor<LZespolona,3>;
template class Wektor<LZespolona,4>;
template class Wektor<LZespolona,5>;

template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 3> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 4> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 5> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 5> &Wek);

template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 3> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 4> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 5> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 5> &Wek);


