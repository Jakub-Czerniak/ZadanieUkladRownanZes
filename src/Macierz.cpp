
#include "Macierz.hh"

using namespace std;



template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz()
{
  for(int i;i<ROZMIAR;i++)
    for(int k; k<ROZMIAR;k++)
      tab[i][k]=0;
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz(Wektor<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> C)
{
  tab[0]=A;
  tab[1]=B;
  tab[2]=C;
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR>::Macierz(Wektor<TYP, ROZMIAR> A, Wektor<TYP, ROZMIAR> B, Wektor<TYP, ROZMIAR> C, Wektor<TYP, ROZMIAR> D, Wektor<TYP, ROZMIAR> E)
{
  tab[0]=A;
  tab[1]=B;
  tab[2]=C;
  tab[3]=D;
  tab[4]=E;
}

template<class TYP,int ROZMIAR>
const Wektor<TYP, ROZMIAR> & Macierz<TYP, ROZMIAR>::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
       cerr << "Index poza zakresem 1" << endl;
       exit(1);
    }
  return tab[index];  
}

template<class TYP,int ROZMIAR>
Wektor<TYP, ROZMIAR> & Macierz<TYP, ROZMIAR>::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "Index poza zakresem 2" << endl;
      exit(1);
    }
  return tab[index];
}

template<class TYP,int ROZMIAR>
const TYP & Macierz<TYP, ROZMIAR>::operator() (int index1, int index2) const
{
  if (index1 < 0 || index1 >= ROZMIAR || index2 < 0 || index2 >= ROZMIAR)
    {
      cerr << "Index poza zakresem 3" << endl;
      exit(1);
    }
  return tab[index1][index2];
}

template<class TYP,int ROZMIAR>
TYP & Macierz<TYP, ROZMIAR>::operator() (int index1, int index2)
{
  if (index1 < 0 || index1 >= ROZMIAR || index2 < 0 || index2 >= ROZMIAR)
    {
      cerr << "Indeks poza zakresem 4" << endl;
      exit(1);
    }
  return tab[index1][index2];
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator +(const Macierz<TYP, ROZMIAR> & M)
{
  Macierz<TYP, ROZMIAR> wynik;
  for(int index=0;index<ROZMIAR;index++)
    {
      wynik[index]=tab[index]+M[index];
    }
  return wynik; 
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator -(const Macierz<TYP, ROZMIAR> & M)
{
  Macierz<TYP, ROZMIAR> wynik;
  for(int index=0;index<ROZMIAR;index++)
    {
      wynik[index]=tab[index]-M[index];
    }
  return wynik; 
}

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator *(const Macierz<TYP, ROZMIAR> & M)
  {
    Macierz<TYP, ROZMIAR> wynik;
    Macierz<TYP, ROZMIAR> MPom=M;

    MPom=MPom.transponuj();
    for(int i=0;i<ROZMIAR;i++)
      for(int k=0; k<ROZMIAR;k++)
	wynik(i,k)=tab[i]*MPom[k];
    
    return wynik;
  }

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::operator *(TYP mnoznik)
  {
    Macierz<TYP, ROZMIAR> wynik;
  for(int index=0;index<ROZMIAR;index++)
    wynik[index]=tab[index]*mnoznik;

  return wynik;
  }

template<class TYP,int ROZMIAR>
Macierz<TYP, ROZMIAR> Macierz<TYP, ROZMIAR>::transponuj() const
{
  Macierz<TYP, ROZMIAR> wynik;
  
  for(int i=0;i<ROZMIAR;i++)
    for(int k=0; k<ROZMIAR;k++)
      wynik(i,k)=tab[k][i];
    
  return wynik;
}

template<class TYP,int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::wyznacznik() const
{
  TYP wyzn;
  wyzn=0.0;
  Macierz<TYP,ROZMIAR> pomoc;
  int pk;  


  if(ROZMIAR==3)
    {
       wyzn=tab[0][0]*tab[1][1]*tab[2][2]+tab[0][1]*tab[1][2]*tab[2][0]+
	tab[0][2]*tab[1][0]*tab[2][1]-tab[2][0]*tab[1][1]*tab[0][2]-
	tab[2][1]*tab[1][2]*tab[0][0]-tab[2][2]*tab[1][0]*tab[0][1];
    }
  else
    {
      for(int n=0;n<ROZMIAR;n++)
	{
	  for(int w=1;w<ROZMIAR;w++)
	    {
	      pk=-1;
	      for(int k=0; k<ROZMIAR;k++)
		{
		  if(k!=n)
	       	    {
		      pk+=1;
       		      pomoc(w-1,pk)=tab[w][k];
		    }
		}
	    }
	  //	  wyzn=wyzn+pow(-1,n)*tab(0,n)*pomoc.wyznacznik;
	    cout<< pomoc <<"tablica"<< endl;
	    
	} 
    }
  
  return wyzn;
}

template<class TYP,int ROZMIAR>
bool Macierz<TYP, ROZMIAR>::operator== (const Macierz<TYP, ROZMIAR> & M) const
  {
  for(int index=0;index<ROZMIAR;index++)
    {
      if(tab[index]!=M[index])
	return false;
    }
  return true;
  }

template<class TYP,int ROZMIAR>
bool Macierz<TYP, ROZMIAR>::operator!= (const Macierz<TYP, ROZMIAR> & M) const
  {
 return !(*this == M);
  }



template<class TYP,int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac)
{
  for(int index=0;index<ROZMIAR;index++)
    {
      Strm >> Mac[index];
    }
  return Strm;
}


template<class TYP,int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac)
{
  for(int index=0;index<ROZMIAR;index++)
    {
      Strm << Mac[index];
    }
  return Strm;
}


template<class TYP,int ROZMIAR>
TYP wyznacznik3(const Macierz<TYP,ROZMIAR> tab)
{
  TYP wyzn;

  wyzn=tab(0,0)*tab(1,1)*tab(2,2)+tab(0,1)*tab(1,2)*tab(2,0)+
    tab(0,2)*tab(1,0)*tab(2,1)-tab(2,0)*tab(1,1)*tab(0,2)-
    tab(2,1)*tab(1,2)*tab(0,0)-tab(2,2)*tab(1,0)*tab(0,1);
  
  return wyzn;
}


template<class TYP,int ROZMIAR>
TYP wyznacznik4(const Macierz<TYP,ROZMIAR> tab) 
{
  TYP wyzn;
  wyzn=0.00;
  Macierz<TYP,ROZMIAR> pomoc;
  int pk;  

  
  for(int n=0;n<4;n++)
    {
      for(int w=1;w<4;w++)
	    {
	      pk=-1;
	      for(int k=0; k<4;k++)
		{
		  if(k!=n)
	       	    {
		      pk+=1;
       		      pomoc(w-1,pk)=tab(w,k);
		    }
		}
	    }
      wyzn+=tab(0,n)*pow(-1,n)*wyznacznik3(pomoc);
    }

  return wyzn;
}


template<class TYP,int ROZMIAR>
TYP wyznacznik5(const Macierz<TYP,ROZMIAR> tab)
{
  TYP wyzn;
  wyzn= 0.0;
  Macierz<TYP,ROZMIAR> pomoc;
  int pk;
  
   for(int n=0;n<5;n++)
    {
      for(int w=1;w<5;w++)
	    {
	      pk=-1;
	      for(int k=0; k<5;k++)
		{
		  if(k!=n)
	       	    {
		      pk+=1;
       		      pomoc(w-1,pk)=tab(w,k);
		    }
		}
	    }
      wyzn+=tab(0,n)*pow(-1,n)*wyznacznik4(pomoc);
    }
  return wyzn;
}


template class Macierz<double,3>;
template class Macierz<double,4>;
template class Macierz<double,5>;
template double wyznacznik5(Macierz<double,5>);
template double wyznacznik5(Macierz<double,3>);
template double wyznacznik4(Macierz<double,4>);
template double wyznacznik3(Macierz<double,3>);
template std::istream& operator >> (std::istream &Strm, Macierz<double,4> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<double,4> &Mac);
template std::istream& operator >> (std::istream &Strm, Macierz<double,5> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<double,5> &Mac);
template std::istream& operator >> (std::istream &Strm, Macierz<double,3> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<double,3> &Mac);

template class Macierz<LZespolona,3>;
template class Macierz<LZespolona,4>;
template class Macierz<LZespolona,5>;
template LZespolona wyznacznik5(Macierz<LZespolona,5>);
template LZespolona wyznacznik5(Macierz<LZespolona,3>);
template LZespolona wyznacznik4(Macierz<LZespolona,4>);
template LZespolona wyznacznik3(Macierz<LZespolona,3>);
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,4> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,4> &Mac);
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,5> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,5> &Mac);
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,3> &Mac);template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,3> &Mac);
