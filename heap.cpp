#include <iostream>
#include <cstdlib>
#include <time.h>

#define procent 25 //procent poczatkowo posortowanych danych

using namespace std;

/*Funkcja ktora przesuwa elementy do kiedy wlasciwosci kopca nie zostana przywrocone
jesli wartosc macierzysta jest mniejsza to jest zmieniana na najwieksze dziecko, mov od move-przesun*/

void mov(int tab[], int size, int l)
{
	int i, j, x;
	i = l;
	j = 2 * i + 1;
	x = tab[i];
	while (j < size)
	{
		if (j <size - 1)
		if (tab[j] < tab[j + 1])
			++j;
		if (x >= tab[j])
			break;
		tab[i] = tab[j];
		i = j;
		j = 2 * i + 1;

	}
	tab[i] = x;
}


/*Funkcja tworzaca kopiec.
tab[] - tablica, gdzie tworzony jest kopiec
size - rozmiar tablicy*/


void build_heap(int tab[], int size)
{
	int l = size / 2;
	while (l)
	{
		--l;
		mov(tab, size, l);
	}
}

//funkcja sortujaca kopiec
void heapsort(int tab[], int size)
{
	int r = size;
	build_heap(tab, size);

	while (r > 1)
	{
		int tmp = tab[0];
		--r;
		tab[0] = tab[r];
		tab[r] = tmp;
		mov(tab, r, 0);
	}
}


int main()
{
    cout<<"SORTOWANIE PRZEZ KOPCOWANIE - HEAPSORT"<<endl;

    //int rozmiary[5] = { 10, 20, 30, 40, 50}; //przykladowa tablica do testow na losowych wartosciach
    int rozmiary[5] = { 10000, 50000, 100000, 500000, 1000000}; //rozmiary tablic

    double czas;
    clock_t start, stop;

    start = clock();

    for (int k=0;k<5;k++)               //na liczbe roznych tablic po kolei
    {
        //cout << "Sortowanie dla tablicy "<<rozmiary[k]<<" elementow:"<<endl<<endl; //wyswietlenie jaka to tablica

        for(int j=0;j<100;j++)
        {
            int *tab = new int[rozmiary[k]];    //utworzenie dynamicznej tablicy, przygotowanie do dodania 5 tablic o roznej ilosci elementow

            /***************PRZYPADKI*****************/

            //LOSOWE
            /*for(int i=0; i<rozmiary[k]; i++)    //wczytanie wartosci losowych do tablicy
                tab[i]=rand(); // zakres*/

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

            heapsort(tab,rozmiary[k]); // wywolanie heapsorta

            //wyswietlanie tablicy posortowanej
            /*cout<<"TABLICA POSORTOWANA"<<endl;
            for (int i = 0; i<rozmiary[k]; i++)
            cout << tab[i] << " ";
            cout<<endl<<endl;*/
        }

        stop = clock();
        czas = (double)(stop - start)/((CLOCKS_PER_SEC)/1000); //obliczenie czasu
        cout << "Czas sortowania dla "<<rozmiary[k]<<" elementow: "<<czas<<".ms"<<endl<<endl; //czas sortowania w ms
        cout << "Czas sredni: "<<czas/100<<".ms"<<endl;

    }


    system("pause");
    return 0;
}
