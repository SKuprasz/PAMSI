#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>

#include "strutury.h" //zmienic nazwe macierz na gicie
#include "algorytmy.h"

using namespace std;

void Tworz_dane()
{

    int k = 0, w = 0,a,b;
    for (int i = 3; i <= 3; i++)
    {
        if (i == 1) {  w = 10; }
        if (i == 2) {  w = 50; }
        if (i == 3) {  w = 100; }
        if (i == 4) {  w = 500; }
        if (i == 5) {  w = 1000; }

        ofstream StrWy;
        StrWy.open("Dane\\dane.txt");
        if (!StrWy.is_open())
        cerr << "Blad wczytania pliku wyjsciowego" << endl;

        //zmiana gestosci grafu
        //float x=0.25;
        //float x=0.50;
        //float x=0.75;
        float x=1;

        cout <<endl<< i << " "<<x<<endl;


        k = (x*w*(w - 1)) / 2;
        cout<<k<<endl;
        StrWy << w << endl << k << endl;
        int licznik=0;
        while (licznik < k)
        {
            a = rand() % w + 1;
            b = rand() % w + 1;
            if(a==b) b=rand() % w + 1;

            StrWy << a <<" "<< b << endl;
            licznik++;
       }

    }
}


int main()
{
    Tworz_dane();
    srand(time(NULL));


    ofstream StrWy;
    StrWy.open("wynikiK3M1.txt");
    if (!StrWy.is_open())
        cerr << "Blad wczytania pliku wyjsciowego" << endl;

    string nazwa = "Dane\\dane.txt";
    ifstream StrWe;
    StrWe.open("Dane\\dane.txt");
    if (!StrWe.is_open())
        cerr<<"Blad wczytania pliku wejsciowego"<<endl;

    int rozmiar, l_polaczen;
    int waga, numer1, numer2;

    double czas;
    clock_t start, stop;

    start = clock();

    for (int k=0;k<100;k++)
    {
        while (!StrWe.ios::eof())
        {
            StrWe >> rozmiar >> l_polaczen;

            //Lista_sasiedztwa Graf(rozmiar);
            Macierz Graf(rozmiar);

            for (int i = 0; i<l_polaczen; i++)
            {
                StrWe>>numer1>>numer2;
                waga = rand()%200+1;
                Graf.Dodaj_krawedz(numer1, numer2, waga);
            }


            Prim(rozmiar, Graf);
            //Krus(rozmiar, Graf);



        }


    }

    stop = clock();
    czas = (double)(stop - start)/((CLOCKS_PER_SEC)/1000); //obliczenie czasu

    StrWy << "Czas sredni: "<<czas/100<<".ms"<<endl;
    system("pause");
    return 0;
}

