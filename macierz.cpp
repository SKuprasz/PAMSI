#include <iostream>
#include <math.h>
#include <cstdlib>

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
    void wypelnij(Macierz &macierz, int g); //wypelnienie dana gestoscia
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

void Macierz::wypelnij(Macierz &macierz, int g)
{
    //gestosc procentowa
    float gestosc = (float)g / 100;
    //maksymalna ilosc krawedzi
    int maxliczbaKrawedzi = gestosc*((macierz.liczbaWierzcholkow*(macierz.liczbaWierzcholkow - 1)) / 2);
    int licznik = 0; //licznik

    for(int i=0; i<macierz.liczbaWierzcholkow; i++)
    {
        //czy wszystkie wierzcholki polaczone
        int losowaWaga = (rand()%49+1); //losowa 1-50

        macierz.dodajWierzcholek(i, (i+1)%macierz.liczbaWierzcholkow, losowaWaga);
        licznik++;
    }

    while(licznik < maxliczbaKrawedzi)
    {
        //pozostale krawedzie
        int losowaWaga, losowyV1, losowyV2;
        do
        {
            losowaWaga = (rand()%49 +1);
            losowyV1 = rand() % macierz.liczbaWierzcholkow;
            losowyV2 = rand() % macierz.liczbaWierzcholkow;
            //w przypadku wylosowania takich samych v1,v2
            if(losowyV1 == losowyV2) losowyV2 = rand() % macierz.liczbaWierzcholkow;
        }
        while(macierz.zwrocWaga(losowyV1,losowyV2) != 0);
        //jezeli krawedz juz nie istniala to dodajemy i zwiekszamy liczbik
        macierz.dodajWierzcholek(losowyV1, losowyV2, losowaWaga);
        licznik++;
    }
    macierz.wyswietl(); //wyswietl wynik wypelnienia
}


class Lista
{
public:
    struct Element      //element listy
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
    void wypelnij(Lista &lista, int g); //wypelnienie dana gestoscia

};

Lista::Lista(int liczbaWierzcholkow)
{
    this->liczbaWierzcholkow = liczbaWierzcholkow;
    lista = new Element*[liczbaWierzcholkow]; //tworzy tabice list sasiedztwa

    for(int i=0;i<liczbaWierzcholkow;i++)
    {
        lista[i] = NULL; //wypelnia tablice nullem
    }
}

Lista::~Lista()
{
    for(int i=0; i<liczbaWierzcholkow;i++)
    {
        if(lista[i] != NULL) //jesli nie jest null
        {
            Element *pozycja = lista[i]; //ustawia na liscie
            do
            {
                Element *next = pozycja->nastepny;
                delete pozycja; //usuwa pozycje
                pozycja = next;
            } while(pozycja != NULL);
        }
    }
    delete[] lista;
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
    if(lista[v1] == NULL)
    {
        lista[v1] = new Element;
        lista[v1] -> wierzcholek = v2;
        lista[v1] -> waga = waga;
        lista[v1] -> nastepny = NULL;
    }
    else
    {
        //bool powtorzenie = false;
        Element *next = lista[v1];
        Element *buf = NULL;
        do
        {
            buf = next;
            next = next->nastepny;

            if(buf->wierzcholek == v2)
            {
                //powtorzenie = true;
                break;
            }
        } while(next != NULL);

        Element *nowy = new Element;
        nowy->wierzcholek = v2;
        nowy->waga = waga;
        nowy->nastepny = NULL;
        buf->nastepny = nowy;
    }
}

void Lista::wyswietl()
{
    cout<<"Reprezentacja listy sasiedztwa"<<endl;
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

void Lista::wypelnij(Lista &lista, int g)
{
    //gestosc procentowa
    float gestosc = (float)g / 100;
    //maksymalna ilosc krawedzi
    int maxliczbaKrawedzi = gestosc*((lista.liczbaWierzcholkow*(lista.liczbaWierzcholkow - 1)) / 2);
    int licznik = 0; //licznik

    for(int i=0; i<lista.liczbaWierzcholkow; i++)
    {
        //czy wszystkie wierzcholki polaczone
        int losowaWaga = (rand()%49+1); //losowa 1-50

        lista.dodajWierzcholek(i, (i+1)%lista.liczbaWierzcholkow, losowaWaga);
        licznik++;
    }

    while(licznik < maxliczbaKrawedzi)
    {
        //pozostale krawedzie
        int losowaWaga, losowyV1, losowyV2;
        do
        {
            losowaWaga = (rand()%49 +1);
            losowyV1 = rand() % lista.liczbaWierzcholkow;
            losowyV2 = rand() % lista.liczbaWierzcholkow;
            //w przypadku wylosowania takich samych v1,v2
            if(losowyV1 == losowyV2) losowyV2 = rand() % lista.liczbaWierzcholkow;
        }
        while(lista.zwrocWaga(losowyV1,losowyV2) != 0);
        //jezeli krawedz juz nie istniala to dodajemy i zwiekszamy liczbik
        lista.dodajWierzcholek(losowyV1, losowyV2, losowaWaga);
        licznik++;
    }
    lista.wyswietl(); //wyswietl wynik wypelnienia
}




int main()
{

   /* Macierz *m = new Macierz(3);
    m->dodajWierzcholek(0,1,5);
    m->dodajWierzcholek(0,2,6);
    m->dodajWierzcholek(1,0,2);
    m->dodajWierzcholek(1,2,5);
    m->dodajWierzcholek(2,0,3);
    m->dodajWierzcholek(2,1,9);
    m->wyswietl();*/

    Lista *l = new Lista(3);
    l->dodajWierzcholek(0,1,5);
    l->dodajWierzcholek(0,2,6);
    l->dodajWierzcholek(1,0,2);
    l->dodajWierzcholek(1,2,5);
    l->dodajWierzcholek(2,0,3);
    l->dodajWierzcholek(2,1,9);
    l->dodajWierzcholek(0,0,0);
    l->dodajWierzcholek(1,1,0);
    l->dodajWierzcholek(2,2,0);
    l->wyswietl();

    int lwierzcholkow,g;

    cout << "Podaj ilosc wierzcholkow: ";
    cin >> lwierzcholkow;
    cout << endl << "Podaj gestosc w %: ";
    cin >> g;
    Macierz *macierz = NULL;
    macierz = new Macierz(lwierzcholkow);
    macierz->wypelnij(*macierz, g);

    cout << "Podaj ilosc wierzcholkow: ";
    cin >> lwierzcholkow;
    cout << endl << "Podaj gestosc w %: ";
    cin >> g;
    Lista *lista = NULL;
    lista = new Lista(lwierzcholkow);
    lista->wypelnij(*lista, g);



    return 0;
}
