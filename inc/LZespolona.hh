#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


struct  LZespolona {
  double   re;    
  double   im;    



  LZespolona ();
  LZespolona (double arg1, double arg2);

  void operator = (const double & Skl2);
  void operator += (const LZespolona & Skl2);
  LZespolona  operator + (const LZespolona & Skl2)const;
  LZespolona  operator - (const LZespolona & Skl2)const;
  LZespolona  operator *(const LZespolona & Skl2)const;
  LZespolona  operator *(const double Skl2)const;
  LZespolona  operator /(const LZespolona & Skl2)const;
  LZespolona  operator /(double  Skl2)const;
  bool operator ==(const LZespolona & Skl2)const;
  bool operator != (const LZespolona & Skl2)const;
};

LZespolona Sprzezenie(const LZespolona & Skl1);
double Modul2(const LZespolona & Skl1);
double abs(const LZespolona & Skl1);
std::istream & operator >>(std::istream &wejsc, LZespolona &Skl);
std::ostream & operator <<(std::ostream &wyjsc, LZespolona Skl);
#endif
