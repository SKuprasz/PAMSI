#ifndef STRUTURY_H_INCLUDED
#define STRUTURY_H_INCLUDED

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Macierz
{
private:
    int **macierz;
    int L_wezlow;
public:
    Macierz(int rozmiar); //konstruktory
    Macierz(const Macierz &M);
    ~Macierz();                     //destruktor

    void Dodaj_krawedz(int const &a, int const &b, int const &waga); //dodaje krawedz
    void Wypisz(); //wypisuje
    int Rozmiar (int const &i) const; //zwraca iczbe wezlow
    int Rozmiar () const;
    int Waga  (int const &a, int const &b) const; //zwraca wage
    int Wezel (int const &a, int const & b) const; //zwraca b , wezel
};

 Macierz::Macierz(int rozmiar)
  {
    macierz=new int*[rozmiar+1];
    L_wezlow=rozmiar;
    for (int i = 0; i <= rozmiar; i++)
    {
      macierz[i] = new int[rozmiar+1];
      for (int j = 0; j <= rozmiar; j++)
        macierz[i][j] = 0;
    }
  }

  Macierz::Macierz(const Macierz &M)
  {
    L_wezlow = M.Rozmiar(0);
    macierz = new int*[L_wezlow + 1];
    for (int i = 0; i <= L_wezlow; i++)
    {
      macierz[i] = new int[L_wezlow + 1];
      for (int j = 0; j <= L_wezlow; j++)
        macierz[i][j] = M.Waga(i,j);
    }
  }

  Macierz::~Macierz()
  {
    if (L_wezlow!=0)
	    for (int i = 0; i <= L_wezlow; i++)
	      delete [] macierz[i];
	  delete [] macierz;

  }

void Macierz::Dodaj_krawedz(int const &a, int const &b, int const &waga)
{
  macierz[a][b]=waga;
  macierz[b][a]=waga;
}

void Macierz::Wypisz()
{
  cout<<"Reprezentacja macierzy sasiedztwa"<<endl;
  cout<<"   ";
  for (int i = 1; i < L_wezlow; i++)
  {
	cout.fill(' ');
	cout.width(5);
	cout<<left<<i;
  }
  cout<<endl;
  for (int i = 0; i < L_wezlow; i++)
  {
	cout<<" "<<i<<" ";
    for (int j = 0; j < L_wezlow; j++)
    {
	  cout.fill(' ');
	  cout.width(5);
      cout <<left<< macierz[i][j];
	}
    cout << endl;
  }
}

int Macierz::Rozmiar(int const &i)	const
{
	return L_wezlow;
}

int Macierz::Rozmiar() const
{
	return L_wezlow;
}

int Macierz::Waga(int const &a, int const &b) const
{
	return macierz[a][b];
}

int Macierz::Wezel(int const &a, int const &b) const
{
	return b;
}



class Lista_sasiedztwa
{
private:
  vector<vector<pair<int, int> > > Lista;
  int L_wezlow;
public:
  Lista_sasiedztwa(); //konstruktory
  Lista_sasiedztwa(int rozmiar);
  Lista_sasiedztwa(const Lista_sasiedztwa &L);
  ~Lista_sasiedztwa(); //destruktor


  void Dodaj_krawedz(int const &a, int const &b, int const &waga);
  void Wypisz();
  int Rozmiar(int const &i) const;
  int Rozmiar() const;
  int Waga(int const &a, int const &b) const;
  int Wezel(int const &a, int const & b) const;
};

Lista_sasiedztwa::Lista_sasiedztwa()
{
    L_wezlow = 0;
}

Lista_sasiedztwa::Lista_sasiedztwa(int rozmiar)
  {
    L_wezlow=rozmiar;
    vector <pair<int, int> > P;
    for (int i = 0; i<=rozmiar; i++)
      Lista.push_back(P);
  }

Lista_sasiedztwa::Lista_sasiedztwa(const Lista_sasiedztwa &L)
  {
    L_wezlow = L.Rozmiar();
    vector <pair<int, int> > P;
    for (int i = 0; i <= L_wezlow; i++)
      Lista.push_back(P);

    for (int i = 0; i <= L_wezlow; i++)
      for (int j=0;j<L.Rozmiar(i);j++)
        Lista[i].push_back( make_pair(L.Wezel(i, j), L.Waga(i,j)) );

  }

Lista_sasiedztwa::~Lista_sasiedztwa()
{
    if (!Lista.empty())
      for (int i = 0; i<=L_wezlow; i++)
        Lista[i].clear();
    Lista.clear();
}


void Lista_sasiedztwa::Dodaj_krawedz (int const &a, int const &b, int const &waga)
{
  int x = max(a, b);
  while (x >= Lista.size())
  {
    vector <pair<int, int> > P;
    Lista.push_back(P);
  }
  if (a == b) return;
  Lista[a].push_back(make_pair(b, waga));
  Lista[b].push_back(make_pair(a, waga));
  L_wezlow = Lista.size()-1;
}

void Lista_sasiedztwa::Wypisz()
{
    cout<<"Reprezentacja listy sasiedztwa"<<endl;
  for (int i = 1; i < Lista.size(); i++)
  {
    cout << " " << i << " : ";
    for (int j = 0; j < Lista[i].size(); j++)
	{
      cout <<left<< " [ " << Lista[i][j].first << " | " ;
	  cout.width(3);
	  cout.fill(' ');
	  cout<<left<< Lista[i][j].second<<" ], ";
    }
    cout << endl;
  }
}

int Lista_sasiedztwa::Rozmiar(int const &i)	const
{
	return Lista[i].size()-1;
}

int Lista_sasiedztwa::Rozmiar()	const
{
	return Lista.size()-1;
}

int Lista_sasiedztwa::Waga(int const &a, int const &b) const
{
	return Lista[a][b].second;
}

int Lista_sasiedztwa::Wezel(int const &a, int const &b) const
{
	return Lista[a][b].first;
}


#endif // STRUTURY_H_INCLUDED

