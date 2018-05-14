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


class Lista
{
public:
    struct Element
    {
        int wierzcholek;
        int waga;
        Element *nastepny;
    };

    Element **lista;
    int liczbaWierzcholkow;

    Lista(int liczbaWierzcholkow); //konstruktor
    ~Lista();                     //destruktor
    int LiczbaWierzcholkow();       //zwraca liczbe wierzcholkow
    int zwrocWaga(int v1,int v2);   //zwraca wage
    void dodajWierzcholek(int v1, int v2, int waga); //dodaje wierzhcolek
    void wyswietl();    //wyswietla


};

Lista::Lista(int liczbaWierzcholkow)
{

}

Lista::~Lista()
{

}

int Lista::LiczbaWierzcholkow()
{
    return liczbaWierzcholkow;
}

int Lista::zwrocWaga(int v1,int v2)
{
    if(lista[v1] == NULL)
    {
        return 0;           //jesli nie ma elementu
    }
    else                    //jesli jest
    {
        bool jest = false; //ustawiaomy na false
        Element *next = lista[v1];  //elementy
        Element *position = NULL;
        do
        {
            position = next;
            next = next->nastepny;
            if(position->wierzcholek == v2)
            {
                jest = true;
                break;
            }
        } while (next!=NULL); //do kiedy nastepny nie null

        if(jest) return position -> waga; //zwroc wage
        else return 0;

    }
}

void Lista::dodajWierzcholek(int v1, int v2, int waga)
{

}

void Lista::wyswietl()
{
    cout<<"Reprezentacja listty sasiedztwa"<<endl;
    for(int i=0; i<liczbaWierzcholkow;i++)
    {
        if(lista[i] != NULL)
        {
            Element *next = lista[i]; //elementy
            Element *position = NULL;
            do
            {
                position = next;
                next = next->nastepny; //ustawiony na nastepny w petli
                cout << i << "->";
                cout<<position->wierzcholek<<" $ "<<position->waga<<" "; //wyswietlenie wagi i wierzcholka
            } while(next != NULL);  //do kiedy nastepny nie jest null
        }
        cout<<endl;
    }
}



int main()
{
    Macierz(5).wyswietl();





    return 0;
}
