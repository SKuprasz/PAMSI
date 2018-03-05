#include <iostream>
#include <cstdlib>

using namespace std;


struct lista		//elementy listy
{
	lista * next;
	int priorytet;
	int dana;
};

class Kolejka		//klasa kolejka
{
private:
	lista * head;	//pierwszy element
	lista * tail;	//ostatni element

public:
	Kolejka();	//konstruktor
	~Kolejka();	//destruktor
    bool empty(); //funkcja sprawdza czy pusta
    void push(int p, int v); //funckja dodaje do kolejki
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

bool Kolejka::empty()
{
    if(!head)
        return true;
    else
        return false;
}

void Kolejka::push(int pr, int v)
{
 /*
    lista *p , *r;
    p = new lista;
    p->next = NULL;
    p->priorytet = pr;
    p->dana = v;

    if(!head) head = tail = p; //jesli jest pusta to wstawiamy
    else if(head->pr < priorytet)
    {
        //czy najwyzszy priorytet i wstawiamy
    }
    else
    {
        //sprawdzamy nizsze priorytety i wstawiamy przed element o nizszym niz nasz
    }
    */
}


int main()
{
	cout << "KOLEJKA PRIORYTETOWA" << endl;

    Kolejka K;
    if(K.empty()==true) cout<<"pusta"<<endl;








	system("PAUSE");
	return 0;
}
