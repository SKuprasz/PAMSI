#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <cstdlib>

#include "strutury.h" //zmienic nazwe macierz na gicie

using namespace std;

//mierzenie czasu

LARGE_INTEGER startTimer()
{
  LARGE_INTEGER start;
  DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
  QueryPerformanceCounter(&start);
  SetThreadAffinityMask(GetCurrentThread(), oldmask);
  return start;
}
LARGE_INTEGER stopTimer()
{
  LARGE_INTEGER stop;
  DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
  QueryPerformanceCounter(&stop);
  SetThreadAffinityMask(GetCurrentThread(), oldmask);
  return stop;
}

void Tworz_dane()
{

  int k = 0, w = 0,a,b;
  double x=0;
  for (int i = 1; i <= 1; i++)
  {
    if (i == 1) {  w = 10; }
    if (i == 2) {  w = 50; }
    if (i == 3) {  w = 100; }
    if (i == 4) {  w = 500; }
    if (i == 5) {  w = 1000; }
    for (int j = 1; j <= 4; j++)
    {
      cout <<endl<< i << " "<<j<<endl;
      ofstream StrWy;
      StrWy.open("Dane\\dane0_10.txt");
      if (!StrWy.is_open())
        cerr << "Blad wczytania pliku wyjsciowego" << endl;
      if (j == 1) x = 0.25;
      if (j == 2) x = 0.50;
      if (j == 3) x = 0.75;
      if (j == 4) x = 1;

      int ile=100;
      while (ile--)
      {
        //cout<<ile<<endl;
        k = (x*w*(w - 1)) / 2;
        StrWy << w << endl << k << endl;
        Macierz Graf(w);
        for (int z = 2; z <= w; z++)
        {
          Graf.Dodaj_krawedz(z-1, z, 1);
          StrWy << z-1 << " " << z << endl;
          k--;
        }
        srand(time(NULL)*ile*100);
        while (k--)
        {
          a=0; b=0;
          while (Graf.Waga(a,b) != 0 || a == b)
          {
            a = rand() % w + 1;
            b = rand() % w + 1;
          }
          Graf.Dodaj_krawedz(a,b,1);
          StrWy << a <<" "<< b << endl;
        }
      }
    }
  }
}


int main()
{

    Macierz *m = new Macierz(3);
    m->Dodaj_krawedz(1,2,5);
    m->Dodaj_krawedz(0,2,6);
    m->Dodaj_krawedz(0,1,2);

    m->Wypisz();

    cout<<endl<<endl;

    Lista_sasiedztwa *l = new Lista_sasiedztwa(3);
    l->Dodaj_krawedz(1,2,5);
    l->Dodaj_krawedz(0,2,6);
    l->Dodaj_krawedz(0,1,2);

    l->Wypisz();

    Tworz_dane();



    return 0;
}

