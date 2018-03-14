#include <iostream>
#include <cstdlib>


using namespace std;


struct lista		//elementy listy
{
	lista * next;
	int priorytet;
	int dana;
};


template <typename T>
class Kolejka		//klasa kolejka
{
private:
	lista * head;	//pierwszy element
	lista * tail;	//ostatni element

public:
	Kolejka();	//konstruktor
	~Kolejka();	//destruktor
    bool empty(); //funkcja sprawdza czy pusta
    void push(T priorytet, T wartosc); //funckja dodaje do kolejki
    int front(); //zwraca wartosc poczatku kolejki
    int priofront(); //zwraca priorytet poczatku kolejki
    void pop();
};

//**********************************//
//METODY

//KONSTRUKTOR - TWORZY PUSTA KOLEJKE
template <typename T>
Kolejka<T>::Kolejka()
{
	head = tail = NULL;
}

//DESTRUKTOR
template <typename T>
Kolejka<T>::~Kolejka()
{

}

//SPRAWDZA CZY PUSTA
template <typename T>
bool Kolejka<T>::empty()
{
    if(!head)
        return true;
    else
        return false;
}

//DODAJE ELEMENT DO KOLEJKI ZGODNIE Z PRIORYTETEM
template <typename T>
void Kolejka<T>::push(T priorytet, T wartosc)
{

    lista *p , *r;
    p = new lista;
    p->next = NULL;
    p->priorytet = priorytet;
    p->dana = wartosc;

    if(!head) head = tail = p; //jesli jest pusta to wstawiamy
    else if(head->priorytet < priorytet)    //sprawdzamy czy element ma najwyzszy priorytet
    {
        p->next = head;     //wstawiamy element na poczatek listy
        head = p;
    }
    else    //sprawdzamy nizsze priorytety i wstawiamy przed nie
    {
        r=head; //sprawdzamy od poczatku
        while((r->next)&&(r->next->priorytet >= priorytet))
            r=r->next; //wstawiam na poczatek listy
        p->next = r->next; //wstawiamy przed element r->next
        r->next = p;
        if(!p->next) tail = p; //jesli jest na koncu to tail
    }

}

//ZWRACA WARTOSC POCZATKU KOLEJKI
template <typename T>
int Kolejka<T>::front()
{
        if(head) return head->dana; //zwroc wartosc head
        else return 0;
}

//ZWRACA PRIORYTET POCZATKU KOLEJKI
template <typename T>
int Kolejka<T>::priofront()
{
        if(head) return head->priorytet; //zwroc priorytet head
        else return 0;
}

template <typename T>
void Kolejka<T>::pop()
{
    if(head)
    {
      lista * p = head; //adres pierwszego elementu
      head = head -> next; //odlaczam pierwszy element
      delete p; //kasuje
    }
    else
    {
        cout<<"NIE MAM CO USUWAC!"<<endl;
    }
}

int main()
{
	cout << "KOLEJKA PRIORYTETOWA" << endl;

    Kolejka<int> K;
    int priorytet,wartosc;
    int p,w;

    priorytet = 2;
    wartosc = 5;
    K.push(priorytet,wartosc);

    if(K.empty()==true) cout<<"pusta"<<endl;
    else cout<<"nie jest pusta"<<endl;

    p=K.priofront();
    w=K.front();
    cout<<"Priorytet: "<<p<<endl;
    cout<<"Wartosc: "<<w<<endl;

    priorytet = 12;
    wartosc = 1;
    K.push(priorytet,wartosc);

    p=K.priofront();
    w=K.front();
    cout<<"Priorytet: "<<p<<endl;
    cout<<"Wartosc: "<<w<<endl;

//Funkcje empty,push,front i priofront dzialaja ! :)

    K.pop();
    K.pop();

    if(K.empty()==true) cout<<"pusta"<<endl;
    else cout<<"nie jest pusta"<<endl;
//Funkcja pop przetestowana - usuwa, a jak nie ma co to wyswietla
    K.pop();

    priorytet = 12;
    wartosc = 5;
    K.push(priorytet,wartosc);
    priorytet = 10;
    wartosc = 8;
    K.push(priorytet,wartosc);
    priorytet = 22;
    wartosc = 7;
    K.push(priorytet,wartosc);
    priorytet = 30;
    wartosc = 6;
    K.push(priorytet,wartosc);
    priorytet = 15;
    wartosc = 500;
    K.push(priorytet,wartosc);
    priorytet = 41;
    wartosc = 18;
    K.push(priorytet,wartosc);

    cout<<endl<<"WYSWIETL KOLEJKE:"<<endl;
    cout<<"Priorytet:   Wartosc: "<<endl;

    for (int i=0; !K.empty(); i++)
    {
        cout<<"   "<<K.priofront()<<"          "<<K.front()<<endl;
        K.pop();
    }

//Funkcje przetestowane - dzialaja

	system("PAUSE");
	return 0;
}
