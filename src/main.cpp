#include <iostream>
#include <fstream>
#include <iomanip> 
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;



int main()
{
  Macierz<LZespolona,5> A;
  Wektor<LZespolona,5> B; 
  Wektor<LZespolona,5> Rozw;
  Wektor<LZespolona,5> WBlad;
  ifstream plik;

  plik.open("daneZes");
  plik >> A >> B;
  cout << "Macierz:" << endl; 
  cout << A; 
  cout << "Wektor wyrazow wolnych:" << endl;
  cout << B;
  UklRowL<LZespolona,5> Rown(A,B);
  Rozw=Rown.ObliczPiaSt();
  cout << "Rozwiazanie x = (x1, x2, x3, x4, x5):" << endl;
  cout << fixed << setprecision(2) << Rozw;
  WBlad=WBledu(A,B,Rozw);
  cout << "Wektor bledu: Ax-b  =" << endl;
  cout << scientific << setprecision(1) << WBlad << endl;

  
  cout << endl << " Konczenie dzialania programu programu " << endl << endl;
}
