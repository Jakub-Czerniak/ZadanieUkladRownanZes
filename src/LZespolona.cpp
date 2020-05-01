#include<iostream>
#include <math.h>
#include "LZespolona.hh"

using namespace std;


LZespolona::LZespolona()
{  
  re=0;
  im=0;
}

LZespolona::LZespolona(double arg1, double arg2)
{  
  re=arg1;
  im=arg2;
}


 LZespolona LZespolona::operator=(const double  Skl2)
{
  re=Skl2;
  im=0;

return *this;
}

LZespolona LZespolona::operator+=(const LZespolona & Skl2)
{
  re+=Skl2.re;
  im+=Skl2.im;
  return *this;
}

LZespolona LZespolona::operator +(const LZespolona & Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator -(const LZespolona & Skl2) const
{
  LZespolona Wynik;

  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator *(const LZespolona & Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = re*Skl2.re-im*Skl2.im;
  Wynik.im = re*Skl2.im+im*Skl2.re;
  return Wynik;
}

LZespolona LZespolona:: operator *(const double Skl2)const
{
  LZespolona  Wynik;

  Wynik.re = re*Skl2;
  Wynik.im = im*Skl2;
  return Wynik;
}


LZespolona LZespolona::operator /(const double Skl2) const
{
  LZespolona Wynik;
  if(Skl2!=0)
    {
  Wynik.re = re/Skl2;
  Wynik.im = im/Skl2;
    }
  else
    {
      cerr<<"Dzielenie przez 0 jest niedozwolone.";
      exit(1);
    }
  return Wynik;
}

LZespolona LZespolona::operator /(const LZespolona & Skl2) const
{
  LZespolona Wynik;
  Wynik= *this *Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}

bool LZespolona::operator ==(const LZespolona & Skl2) const
{
  if(abs(re-Skl2.re)<0.00001 && abs(im-Skl2.im)<0.00001)
    return true;
  return false;
}

bool LZespolona::operator != (const LZespolona & Skl2) const
{
  return !(*this==Skl2);
}


LZespolona Sprzezenie(const LZespolona & Skl1) 
{
  LZespolona Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=(-Skl1.im);
  return Wynik;
}

  
double Modul2(const LZespolona & Skl1) 
{
  double Wynik;
  Wynik=Skl1.re*Skl1.re+Skl1.im*Skl1.im;
  return Wynik;
}

double abs(const LZespolona & Skl1)
{
  double wynik;
  wynik=pow(Modul2(Skl1),0.5);
  return wynik;
}

std::istream & operator >>(std::istream &wejsc, LZespolona &Skl)
{
  char znak;
  
  wejsc>>znak;
  if(znak != '(')
    wejsc.setstate(std::ios::failbit);
  wejsc>>Skl.re>>Skl.im>>znak;
  if(znak != 'i')
    wejsc.setstate(std::ios::failbit);
  wejsc>>znak;
  if (znak != ')')
    wejsc.setstate(std::ios::failbit);
  return wejsc;
}

std::ostream & operator <<(std::ostream &wyjsc, LZespolona Skl)
{
  wyjsc<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";
  return wyjsc;
}
