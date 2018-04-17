#include <iostream>
#include <cstdlib>
#include <time.h>

#define procent 25

using namespace std;


//FUNKCJE MERGESORTA

int main()
{
    cout<<"SORTOWANIE PRZEZ SCALANIE - MERGESORT"<<endl;

    int rozmiary[5] = { 10, 20, 30, 40, 50}; //przykladowa tablica do testow na losowych wartosciach
    //int rozmiary[5] = { 10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic

    double czas;
    clock_t start, stop;

    start = clock();

    for (int k=0;k<5;k++)               //na liczbe tablic
    {
        cout << "Sortowanie dla tablicy "<<rozmiary[k]<<" elementow:"<<endl<<endl; //wyswietlenie jaka to tablica
        int *tab = new int[rozmiary[k]];    //utworzenie dynamicznej tablicy, przygotowanie do dodania 5 tablic o roznej ilosci elementow

        /***************PRZYPADKI*****************/

        //LOSOWE
        for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci losowych do tablicy
            tab[i]=rand()%100+1; //na razie dla czytelnosci zakres do 100

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

        //mergesort(,,); // wywolanie mergesorta

        //wyswietlanie tablicy posortowanej
        /*cout<<"TABLICA POSORTOWANA"<<endl;
        for (int i = 0; i<rozmiary[k]; i++)
        cout << tab[i] << " ";
        cout<<endl<<endl;*/

        stop = clock();
        czas = (double)(stop - start)/((CLOCKS_PER_SEC)/1000); //obliczenie czasu
        //cout << "Czas sortowania dla "<<rozmiary[k]<<" elementow: "<<czas<<".ms"<<endl<<endl; //czas sortowania w ms

    }







    system("pause");
    return 0;
}
