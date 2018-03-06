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





int main()
{
	cout << "KOLEJKA PRIORYTETOWA" << endl;

    Kolejka K;
    int priorytet,wartosc;
    priorytet = 2;
    wartosc = 5;
    K.push(priorytet,wartosc);

    if(K.empty()==true) cout<<"pusta"<<endl;
    else cout<<"nie jest pusta"<<endl;






	system("PAUSE");
	return 0;
}

