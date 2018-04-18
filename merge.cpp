#include <iostream>
#include <cstdlib>
#include <time.h>

#define procent 25

using namespace std;

int *tmp; //tab pomocnicza

void merg(int tab[], int left, int center, int right) //funkcja scalajaca
{
    int i;
    i = left;        //lewy
    int j;
    j = center+1;    //srodek+1

    for(int i=left; i<=right; i++)
        tmp[i] = tab[i];            //kopuje do tab pomocniczej

    //scalanie z tab pomocniczej i zapisanie
    for (int k = left; k <= right; k++)
	if (i <= center)
	if (j <= right)
	if (tmp[j]<tmp[i])
		tab[k] = tmp[j++];
	else tab[k] = tmp[i++];
	else tab[k] = tmp[i++];
	else tab[k] = tmp[j++];
}

void mergesort(int tab[], int left, int right)
{
    int center = (right + left) / 2;
    if (right <= left) return;              //gdy mamy jeden element, to jest on juz posortowany

	mergesort(tab, left, center);           //tablica po lewej stronie
	mergesort(tab, center + 1, right);      //tablica po prawej stronie

	merg(tab, left, center, right);         //scalamy dwie juz posortowane tablice
}


int main()
{
    cout<<"SORTOWANIE PRZEZ SCALANIE - MERGESORT"<<endl;

    //int rozmiary[5] = { 10, 20, 30, 40, 50}; //przykladowa tablica do testow na losowych wartosciach
    int rozmiary[5] = { 10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic

    double czas;
    clock_t start, stop;

    start = clock();

    for (int k=0;k<5;k++)               //na liczbe tablic
    {
        //cout << "Sortowanie dla tablicy "<<rozmiary[k]<<" elementow:"<<endl<<endl; //wyswietlenie jaka to tablica
        int *tab;
        tab = new int[rozmiary[k]];    //utworzenie dynamicznej tablicy, przygotowanie do dodania 5 tablic o roznej ilosci elementow
        tmp = new int[rozmiary[k]];    //tablica pomocnicza tmp

        for(int j=0;j<100;j++)          //sto tablic
        {
             /***************PRZYPADKI*****************/

            //LOSOWE
            for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci losowych do tablicy
                tab[i]=rand(); //mozna dodac zakres

            //ODWROTNA KOLEJNOSC
            /*for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci w odwrotnej kolejnosci do tablicy
                tab[i]=rozmiary[k] - i;*/

            //PROCENT POSORTOWANIA
            /*for(int i=0; i<procent*rozmiary[k]/100; i++)    //procent posortowania
                tab[i]=i;
            for(int i=procent*rozmiary[k]/100; i<rozmiary[k]; i++)//wpisanie do reszty elementow
                tab[i]=rand();*/

            /***************************************/

            //wyswietlanie tablicy nieposortowanej
            /*cout<<"TABLICA NIEPOSORTOWANA"<<endl;
            for (int i = 0; i<rozmiary[k]; i++)
            cout << tab[i] << " ";
            cout<<endl<<endl;*/

            mergesort(tab, 0, rozmiary[k] - 1); // wywolanie mergesorta

            //wyswietlanie tablicy posortowanej
            /*cout<<"TABLICA POSORTOWANA"<<endl;
            for (int i = 0; i<rozmiary[k]; i++)
            cout << tab[i] << " ";
            cout<<endl<<endl;*/
        }

        stop = clock();
        czas = (double)(stop - start)/((CLOCKS_PER_SEC)/1000); //obliczenie czasu
        cout << "Czas sortowania dla "<<rozmiary[k]<<" elementow: "<<czas<<".ms"<<endl<<endl; //czas sortowania w ms

    }


    system("pause");
    return 0;
}

