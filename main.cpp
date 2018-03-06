#include <iostream>
#include <cstdlib>

using namespace std;


struct lista		//elementy listy
{
	lista * next;
	int priorytet;
	int dana;
};

//PRZEROBIÆ NA SZABLON !!

class Kolejka		//klasa kolejka
{
private:
	lista * head;	//pierwszy element
	lista * tail;	//ostatni element

public:
	Kolejka();	//konstruktor
	~Kolejka();	//destruktor
    bool empty(); //funkcja sprawdza czy pusta
    void push(int priorytet, int wartosc); //funckja dodaje do kolejki
    int front(); //zwraca wartosc poczatku kolejki
    int priofront(); //zwraca priorytet poczatku kolejki
};

//**********************************//
//METODY

//KONSTRUKTOR - TWORZY PUSTA KOLEJKE
Kolejka::Kolejka()
{
	head = tail = NULL;
}

//DESTRUKTOR
Kolejka::~Kolejka()
{
 //Pozniej dodam jak napisze pop
}

//SPRAWDZA CZY PUSTA
bool Kolejka::empty()
{
    if(!head)
        return true;
    else
        return false;
}

//DODAJE ELEMENT DO KOLEJKI ZGODNIE Z PRIORYTETEM
void Kolejka::push(int priorytet, int wartosc)
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
int Kolejka::front()
{
        if(head) return head->dana; //zwroc wartosc head
        else return 0;
}

//ZWRACA PRIORYTET POCZATKU KOLEJKI
int Kolejka::priofront()
{
        if(head) return head->priorytet; //zwroc priorytet head
        else return 0;
}


int main()
{
	cout << "KOLEJKA PRIORYTETOWA" << endl;

    Kolejka K;
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





	system("PAUSE");
	return 0;
}
