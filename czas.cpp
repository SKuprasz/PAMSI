#include <iostream>
#include <ctime>
#include <windows.h>

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





    return 0;
}
