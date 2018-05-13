#include <iostream>

using namespace std;

class Macierz
{
private:
    int **macierz;
    int liczbaWierzcholkow;
public:
    Macierz(int liczbaWierzcholkow); //konstruktor
    ~Macierz();                     //destruktor
    int LiczbaWierzcholkow();       //zwraca liczbe wierzcholkow
    int zwrocWaga(int v1,int v2);   //zwraca wage
    void dodajWierzcholek(int v1, int v2, int waga); //dodaje wierzhcolek
    void wyswietl();    //wyswietla

};

Macierz::Macierz(int liczbaWierzcholkow)
{
    this->liczbaWierzcholkow = liczbaWierzcholkow;
    macierz = new int*[liczbaWierzcholkow]; //tworzy tablice

    for (int i=0;i<liczbaWierzcholkow;i++)
    {
        macierz[i] = new int[liczbaWierzcholkow]; //tworzy wiersze

        for(int j=0;j<liczbaWierzcholkow;j++)
            macierz[i][j] = 0; //wypelnienie macierzy zerami
    }
}

Macierz::~Macierz()
{
    //usuwa macierz
    for(int i=0;i<liczbaWierzcholkow;i++) delete[] macierz;

    delete macierz;
}

int Macierz::LiczbaWierzcholkow()
{
    return liczbaWierzcholkow; //zwraca liczbe wierzcholkow
}

int Macierz::zwrocWaga(int v1, int v2)
{
    return macierz[v1][v2]; //zwraca wage
}

void Macierz::dodajWierzcholek(int v1,int v2, int waga)
{
    macierz[v1][v2] = waga; //dodaje wage
}

void Macierz::wyswietl()
{
    cout<<"Reprezentacja macierzy sasiedztwa"<<endl;
    for (int i=0;i<liczbaWierzcholkow;i++)
    {
        for(int j=0;j<liczbaWierzcholkow;j++)
        {
            cout<<macierz[i][j]<<'\t';
        }
        cout<<endl;
    }
}

int main()
{
    Macierz(5).wyswietl();





    return 0;
}
