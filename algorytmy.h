#ifndef ALGORYTMY_H_INCLUDED
#define ALGORYTMY_H_INCLUDED

#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include "strutury.h"

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> P3I;
#define mp make_pair

/*Struktura uzywana przez set porównywania
 *elementów przy sortowaniu
*/

struct str
{
  bool operator() (const P3I &a, const P3I &b)
  {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a<b;
  }
};

/*Funkcja Find
 *zwraca reprezentanta zbioru z a (reprezentatnt wskazuje na siebie)
 */
int Find(int a, int *Tab)
{
  return (Tab[a] == a) ? a : (Tab[a] = Find(Tab[a], Tab));
}

/*Funkcja Union
 *sprawdza czy dane wierzcho3ki nale?1 do jednego drzewa
 *je?eli nie to pod31cza mniejsze drzewo do wiekszego
 */
bool Union(int a, int b, int *Tab, int* ile)
{
  int fa = Find(a, Tab); // szuka reprezentanta zbioru zawieraj1cego element 'a'
  int fb = Find(b, Tab); // szuka reprezentanta zbioru zawieraj1cego element 'b'

  if (fa == fb) return false;
  if (ile[fa] <= ile[fb])
  {
    ile[fb] += ile[fa];
    Tab[fa] = fb;
  }
  else
  {
    ile[fa] += ile[fb];
    Tab[fa] = fb;
  }
  return true;
}

/*******************************************************************/
/*** Algorytm Prima ************************************************/
/*******************************************************************/
/*Tab - zawiera informacje czy dany wierzcho3ek by3 ju? odwiedzony
 *Krawedzie - kopiec zawierajacy krawedzie posortowane niemalej1co
 *Wynik - zawiera graf ktory jest minimalnym drzewem rozpinajacym
 *
 *algorytm przechodzi z jednego wierzcho3ka do drugiego, dodaj1c
 *do kopca krawedzie drugiego wierzcho3ka, i wybieraj1c najl?ejsz1
 *ze wszystkich dodaje kolejny wierzcho3ek, dopóki kopiec nie
 *jest pusty
 *******************************************************************/
template <typename TYP>
void Prim(int rozmiar, TYP Graf)
{
  TYP Wynik(rozmiar);                 //Struktura zawieraj1ca drzewo wynikowe
  bool *Tab = new bool[rozmiar + 1];  //Tablica wierzcho3ków ju?odwiedzonych
  for (int i = 0; i <= rozmiar; i++)
    Tab[i] = false;
  int koszt = 0;

  set<P3I, str> Krawedzie;
  Krawedzie.clear();

  P3I V;
  Krawedzie.insert(mp(0, mp(0, 1)));

  Tab[1] = true;
  int ind;
  while (!Krawedzie.empty())
  {
    V = *(Krawedzie.begin());
    Krawedzie.erase(Krawedzie.begin());
    ind = V.second.second;
    //dodaje do wynikowego grafu krawedY
    if (V.first != 0 && !Tab[ind])
    {
      Wynik.Dodaj_krawedz(ind, V.second.first, V.first);
      Tab[ind] = true;
      koszt += V.first;
    }
    //dodaje krawedzie wychodz1ce z danego wierzcho3ka (ind)
    int n = Graf.Rozmiar(ind);
    for (int i = 0; i <= n; i++)
      if (Graf.Waga(ind, i) != 0 && !Tab[Graf.Wezel(ind, i)])
        Krawedzie.insert(mp(Graf.Waga(ind, i), mp(ind, Graf.Wezel(ind, i))));
  }
  delete[] Tab;
  Krawedzie.clear();
  //Wynik.Wypisz();
  //cout << "   koszt wszystkich polaczen " << koszt << endl;
}

/*******************************************************************/
/*** Algorytm Kruskala *********************************************/
/*******************************************************************/
/*Tab - zawiera numer ojca danego wierzcho3ka w danym drzewie w lesie
 *ile - zawiera informacje o d3ugooci poddrzewa danego wierzcho3ka
 *Krawedzie - kopiec zawierajacy krawedzie posortowane niemalej1co
 *Wynik - zawiera graf ktory jest minimalnym drzewem rozpinajacym
 *
 *algorytm tworzy las pojedynczych wierzcho3ków, a nastepnie 31czy
 *poszczególne drzewa krawedziami o najl?ejszych wagach w jedno drzewo
 *u?ywaj1c struktury Union-Find, dopóki nie stworzy jednego drzewa
 *******************************************************************/
template <typename TYP>
void Krus(int rozmiar, TYP Graf)
{
  TYP Wynik(rozmiar);
  int koszt = 0;
  int *Tab = new int[rozmiar + 1];
  int *ile = new int[rozmiar + 1];
  for (int i = 0; i <= rozmiar; i++)
  {
    Tab[i] = i;
    ile[i] = 1;
  }

  set<P3I, str> Krawedzie;
  Krawedzie.clear();

  //int m=0;
  for (int i = 0; i<=Graf.Rozmiar(); i++)
  {
    for (int j = 0; j<=Graf.Rozmiar(i); j++)
      if (Graf.Waga(i, j)!=0)
        Krawedzie.insert(mp(Graf.Waga(i, j), mp(i, Graf.Wezel(i, j))));
  }

  P3I V;
  while (!Krawedzie.empty())
  {
    P3I V=*(Krawedzie.begin());
    Krawedzie.erase(Krawedzie.begin());
    if ( Union(V.second.first, V.second.second, Tab, ile) )
    {
      Wynik.Dodaj_krawedz(V.second.first, V.second.second, V.first);
      koszt += V.first;
    }
  }
  delete[] Tab;
  Krawedzie.clear();
  //Wynik.Wypisz();
  //cout << "   koszt wszystkich polaczen " << koszt << endl;
}

#endif // ALGORYTMY_H_INCLUDED

