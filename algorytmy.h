#ifndef ALGORYTMY_H_INCLUDED
#define ALGORYTMY_H_INCLUDED

#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include "strutury.h"

using namespace std;

#ifndef ALGORYTMY_H_INCLUDED
#define ALGORYTMY_H_INCLUDED

#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include "strutury.h"

using namespace std;




/*** Algorytm Prima ************************************************/

template <typename TYP>
void Prim(int rozmiar, TYP Graf)
{
  TYP Wynik(rozmiar);                 //Struktura zawieraj�ca drzewo wynikowe
  bool *Tab = new bool[rozmiar + 1];  //Tablica wierzcho�k�w ju�odwiedzonych
  for (int i = 0; i <= rozmiar; i++)
    Tab[i] = false;
  int koszt = 0;

 
}


#endif // ALGORYTMY_H_INCLUDED
