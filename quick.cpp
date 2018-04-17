#include <iostream>
#include <cstdlib>

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
        if (i <= j)                 //jesli liczniki sie nie minely to zamien
		{
			swap(tab[i], tab[j]);   //swap zamienia wartosci elementow tablic
			i++;
			j--;
		}
	} while (i <= j);

	if(left<j) quicksort(tab, left, j);     //wywolanie quicksorta dla pierwszej czesci tablicy
	if(right>i) quicksort(tab, i, right);   //wywolanie quicksorta dla drugiej czesci tablicy
}



int main()
{
    cout<<"SORTOWANIE SZYBKIE - QUICKSORT"<<endl;

    int rozmiary[5] = { 10, 20, 30, 40, 50}; //przykladowa tablica do testow na losowych wartosciach
    for (int k=0;k<5;k++)               //na liczbe tablic
    {
        cout << "Sortowanie dla tablicy "<<rozmiary[k]<<" elementow:"<<endl<<endl; //wyswietlenie jaka to tablica
        int *tab = new int[rozmiary[k]];    //utworzenie dynamicznej tablicy, przygotowanie do dodania 5 tablic o roznej ilosci elementow

        for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci losowych do tablicy
        tab[i]=rand()%100+1; //dla czytelnosci zakres do 100

        //wyswietlanie tablicy nieposortowanej
        cout<<"TABLICA NIEPOSORTOWANA"<<endl;
        for (int i = 0; i<rozmiary[k]; i++)
        cout << tab[i] << " ";
        cout<<endl<<endl;

        quicksort(tab,0,rozmiary[k]-1); // wywolanie quicksorta

        //wyswietlanie tablicy posortowanej
        cout<<"TABLICA POSORTOWANA"<<endl;
        for (int i = 0; i<rozmiary[k]; i++)
        cout << tab[i] << " ";
        cout<<endl<<endl;
    }




    system("pause");
    return 0;
}
