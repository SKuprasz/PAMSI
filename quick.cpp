#include <iostream>
#include <cstdlib>
#include <time.h>

#define procent 25 //procent poczatkowo posortowanych danych

using namespace std;

void quicksort(int tab[], int left, int right)
{
    int i, j, pivot;
    i=left;                         //element lewy
    j=right;                        //element prawy
    pivot=tab[(left+right)/2];      //piwot, element srodkowy

    do
	{
		while (tab[i]<pivot)        //szukamy elementu wiekszego niz piwota
            i++;
		while (tab[j]>pivot)        //szukamy elementu mniejszego od piwota
            j--;
        if(i <= j)                 //jesli liczniki sie nie minely to zamien
		{
			swap(tab[i], tab[j]);   //swap zamienia wartosci elementow tablic
			i++;
			j--;
		}
	} while(i <= j);

	if(left<j) quicksort(tab, left, j);     //wywolanie quicksorta dla pierwszej czesci tablicy
	if(right>i) quicksort(tab, i, right);   //wywolanie quicksorta dla drugiej czesci tablicy
}



int main()
{
    cout<<"SORTOWANIE SZYBKIE - QUICKSORT"<<endl;

    //int rozmiary[5] = { 100, 200, 300, 400, 500}; //przykladowa tablica do testow na losowych wartosciach
    int rozmiary[5] = { 10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic

    double czas;
    clock_t start, stop;

    start = clock();

    for (int k=0;k<5;k++)               //na liczbe tablic
    {
        cout << "Sortowanie dla tablicy "<<rozmiary[k]<<" elementow:"<<endl<<endl; //wyswietlenie jaka to tablica
        int *tab = new int[rozmiary[k]];    //utworzenie dynamicznej tablicy, przygotowanie do dodania 5 tablic o roznej ilosci elementow

        /***************PRZYPADKI*****************/

        //LOSOWE
        /*for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci losowych do tablicy
            tab[i]=rand()%100+1; //na razie dla czytelnosci zakres do 100*/

        //ODWROTNA KOLEJNOSC
        /*for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci w odwrotnej kolejnosci do tablicy
            tab[i]=rozmiary[k] - i;*/

        //PROCENT POSORTOWANIA
        for(int i=0; i<procent*rozmiary[k]/100; i++)    //procent posortowania
            tab[i]=i;
        for(int i=procent*rozmiary[k]/100; i<rozmiary[k]; i++)
            tab[i]=rand();                          //wpisanie do reszty elementow
        /***************************************/

        //wyswietlanie tablicy nieposortowanej
        /*cout<<"TABLICA NIEPOSORTOWANA"<<endl;
        for (int i = 0; i<rozmiary[k]; i++)
        cout << tab[i] << " ";
        cout<<endl<<endl;*/

        quicksort(tab,0,rozmiary[k]-1); // wywolanie quicksorta

        //wyswietlanie tablicy posortowanej
        /*cout<<"TABLICA POSORTOWANA"<<endl;
        for (int i = 0; i<rozmiary[k]; i++)
        cout << tab[i] << " ";
        cout<<endl<<endl;*/

        stop = clock();
        czas = (double)(stop - start)/((CLOCKS_PER_SEC)/1000); //obliczenie czasu
        cout << "Czas sortowania dla "<<rozmiary[k]<<" elementow: "<<czas<<".ms"<<endl<<endl; //czas sortowania w ms

    }


    system("pause");
    return 0;
}

