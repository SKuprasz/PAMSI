#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <tchar.h>
#include <windows.h>
#include <list>
#define MAX 100
#define CZYWYNIKI 1
#define NIESKON 99999
#define MAXI 2147483647
#include <vector>

using namespace std;

class wierzcholek
{
public:
	wierzcholek *n;			// wskaznik na nastepnik
	int indeks;
	int waga;
};

class krawedzie
{
public:
	int p;
	int n;
	int waga;

	krawedzie(): p(-1), n(-1), waga(-1) {}
};

class lista
{
public:
	wierzcholek *w;

	void dodaj(int indeks, int waga);
	void wypisz();
    void wypisz_do_pliku(std::ofstream& p);

};

class graf_lista
{
public:
	int v;							// liczba wierzcholkow
	lista **list;

	graf_lista():v(0){}
	graf_lista(int s): v(s){list = new lista*[s];}

	void wypisz();
    void wypisz_do_pliku(std::ofstream& p);

};

class graf_macierz
{
public:
	int v;				// liczba wierzcholkow
	int **macierz_wag;			// reprezentacja macierzy jako tab dwuwymiarowej liczb calkowitych

	graf_macierz();
	graf_macierz(int ile);	// konstruktor tworzacy macierz ile x ile
	graf_macierz(int **tab, int rozmiar); // konstruktor tworzacy macierz na podstawie dolaczonej tablicy

	void wyczysc();				// wyzerowanie macierzy
	void wypisz();
    void wypisz_do_pliku(std::ofstream& p);

};


void lista::wypisz_do_pliku(ofstream& p)
{
	wierzcholek *tmp = w;
	while(tmp!=NULL)
	{
		p << " -> " << tmp->indeks << " = " << tmp->waga << " ";
		tmp=tmp->n;
	}
}

graf_macierz::graf_macierz()
{
	v=1;
	macierz_wag = new int*[1];
	macierz_wag[0] = new int[1];
}

graf_macierz::graf_macierz(int ile)
{
	v = ile;
	macierz_wag = new int*[ile];
	for(int i=0; i < ile; i++)
		macierz_wag[i]= new int[ile];

	for(int i=0; i<v; i++)
		for(int j=i; j<v; j++)
			macierz_wag[i][j]=macierz_wag[j][i]=0;
}

graf_macierz::graf_macierz(int **tab, int rozmiar)
{
	v = rozmiar;
	macierz_wag = new int*[rozmiar];
	for(int i=0; i < rozmiar; i++)
		macierz_wag[i]= new int[rozmiar];

	for(int i=0; i<rozmiar; i++)
		for(int j=0; j<rozmiar; j++)
			macierz_wag[i][j]=tab[i][j];
}


void graf_macierz::wypisz()
{
    for (int i=0; i<v; i++ )
	{
        for (int j=0; j<v; j++ )
            cout << macierz_wag[i][j]<<" ";
		cout << macierz_wag << endl;
		cout << endl;
	}
	cout << endl;
}



void graf_macierz::wyczysc()
{
	for(int i=0; i<v; i++)
		for(int j=i; j<v; j++)
			macierz_wag[i][j]=macierz_wag[j][i]=0;
}


void graf_macierz::wypisz_do_pliku(ofstream& p)
{
	p << "Macierz sasiedztwa: " << endl << endl;
    for (int i=0; i<v; i++ )
	{
        for (int j=0; j<v; j++ )
            p << macierz_wag[i][j]<<" ";
		p << endl;
	}
	p << endl;
}



void lista::dodaj(int indeks, int waga)
{
	wierzcholek *tmp;
	tmp = new wierzcholek;
	tmp->n = w;
	tmp->indeks = indeks;
	tmp->waga = waga;
	w=tmp;
}

void lista::wypisz()
{
	wierzcholek *tmp = w;
	while(tmp!=NULL)
	{
		cout << tmp->indeks << "=" << tmp->waga << " ";
		tmp=tmp->n;
	}
}

void graf_lista::wypisz()
{
	for(int i=0;i<v;i++)
	{
		cout<<endl<<i<<"->";
		list[i]->wypisz();
	}

	cout << endl;
}

void graf_lista::wypisz_do_pliku(ofstream& p)
{
	p << "Lista sasiedztwa: " << endl;
	for(int i=0;i<v;i++)
	{
		p<<endl<<i;
		list[i]->wypisz_do_pliku(p);
	}

	p << endl << endl;
}





int main()
{




    return 0;
}



