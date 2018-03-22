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
    void push(T priorytet, T wartosc); //funckja dodaje do kolejki zgodnie z priorytetem
    int front(); //zwraca wartosc poczatku kolejki
    int priofront(); //zwraca priorytet poczatku kolejki
    void pop();
    void wyswietl();
    void insert(T priorytet, T wartosc); //dodaje do kolejki w sposob nieposortowany
    void del(); //usuwa najwyzszy priorytet
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

//USUWA PIERWSZY ELEMENT
template <typename T>
void Kolejka<T>::pop()
{
    if(head)
    {
      lista * p = head; //adres pierwszego elementu
      head = head -> next; //odlaczam pierwszy element
      cout<<"PRIORYTET DO USUNIECIA: "<<p->priorytet<<endl;
      delete p; //kasuje
    }
    else
    {
        cout<<"NIE MAM CO USUWAC!"<<endl;
    }
}

//WYSWIETLA PRIORYTETY KOLEJKI
template <typename T>
void Kolejka<T>::wyswietl()
{

    lista *p;
    p=head;
    if(head==NULL)
    {
        cout<<"KOLEJKA JEST PUSTA"<<endl;
    }
    else
    {
        cout<<"KOLEJKA: "<<endl;
        while(p!=NULL)
        {

            cout<<p->priorytet<<" ";
            p=p->next;
        }
            cout<<endl;
    }

}

//DODAJE ELEMENT DO KOLEJKI W SPOSOB NIEPOSORTOWANY
template <typename T>
void Kolejka<T>::insert(T priorytet, T wartosc)
{
	lista *p , *r;
	r = new lista;
	r->next =NULL;
	r->priorytet = priorytet;
	r->dana = wartosc;

	p=head;
	if (p)
	{
		while(p->next) p=p->next;
		p->next =r;
	}
	else
	{
		head = r;
	}

}

//USUWA NAJMNIEJSZY PRIORYTET
template <typename T>
void Kolejka<T>::del()
{
    lista * p, * pmin;
    pmin = head;
    if(empty()) cout<<"KOLEJKA PUSTA!"<<endl;
    else
    {
        if(head)
        for(p = head->next; p; p = p->next)
            if(p->priorytet < pmin->priorytet)
            {
                pmin=p;
            }
        cout<<"PRIORYTET DO USUNECIA: "<<pmin->priorytet<<endl;

        p = head;
        if(p==pmin || pmin==tail )
        {
            head=head->next;
            delete p;
        }
        else
        {
            while(p->next != pmin) p = p->next;
            p->next = pmin->next;
            delete pmin;
        }
    }
}



int main()
{
    Kolejka<int> K;
    Kolejka<int> P;
    int i;

    K.push(7,2);
    K.push(4,1);
    K.push(8,5);
    K.push(2,3);
    K.push(5,1);
    K.push(3,2);
    K.push(9,3);
    K.wyswietl();
    for(i=0;!K.empty();i++) K.pop();
    K.wyswietl();
    cout<<endl<<endl;


    P.insert(7,2);
    P.insert(4,1);
    P.insert(8,5);
    P.insert(2,3);
    P.insert(5,1);
    P.insert(3,2);
    P.insert(9,3);

    P.wyswietl();
    for(i=0;!P.empty();i++) P.del();
    P.wyswietl();


	system("PAUSE");
	return 0;
}
