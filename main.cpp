#include <iostream>
#include <cstdlib>
#include <windows.h> //na potrzeby funkcji sleep w mainie

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
    void pop(); //usuwa pierwszy element kolejki
    void wyswietl(); //wyswietla priorytety kolejki bez wartosci
    void insert(T priorytet, T wartosc); //dodaje do kolejki w sposob nieposortowany
    void del(); //usuwa najnizszy priorytet
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
    while(head) pop();
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

    lista *p,*r;
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
	if (p) //jesli jest juz element do dodaje za nim
	{
		while(p->next) p=p->next;
		p->next =r;
	}
	else //jesli nie to nasz element jest glowa
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
    if(empty()) cout<<"KOLEJKA PUSTA!"<<endl; //jesli nie ma co usuwac to daje komunikat
    else
    {
        if(head) //jesi nie jest pusta
        for(p = head->next; p; p = p->next) //przeszukuje cala kolejke w petli
            if(p->priorytet < pmin->priorytet) //sprawdza mniejszy element
            {
                pmin=p; //przypisuje
            }
        cout<<"PRIORYTET DO USUNECIA: "<<pmin->priorytet<<endl; //daje znac ktory element trzeba usunac

        p = head;
        if(p==pmin || pmin==tail )
        {
            head=head->next; //jesli element to glowa lub ogon to usuwa
            delete pmin;
        }
        else
        {   //przeszukuje dopoki nie znajdzie elementu ktory ma usunac (element przypisany wyzej)
            while(p->next != pmin) p = p->next;
            p->next = pmin->next;
            delete pmin;
        }
    }
}



int main()
{
    cout<<"PROJEKT KOLEJKI PRIORYTETOWEJ"<<endl;
    cout<<"PO ZAKONCZENIU POKAZA SIE SYMULACJE SORTOWAN"<<endl<<endl;
    Sleep(500);

    Kolejka<int> KP;
    Kolejka<int> K;
    Kolejka<int> P;
    int i,x,wybor,priorytet,wartosc;


 do
    {
        cout<<endl;
        cout<<"1.DODAJ ZGODNIE Z PRIORYTETEM"<<endl;
        cout<<"2.USUN PIERWSZY ELEMENT"<<endl;
        cout<<"3.SPRAWDZ CZY KOLEJKA JEST PUSTA"<<endl;
        cout<<"4.SPRAWDZ PRIORYTET PIERWSZEGO ELEMENTU"<<endl;
        cout<<"5.SPRAWDZ WARTOSC PIERWSZEGO ELEMENTU"<<endl;
        cout<<"6.WYSWIETL PRIORYTETY KOLEJKI"<<endl;
        cout<<"7.KONIEC"<<endl<<endl;

        cout<<"WPROWADZ NUMER OPERACJI: ";
        cin>>wybor;
        switch(wybor)
        {
        case 1:
            cout<<"Wprowadz wartosc do kolejki: ";
            cin>>wartosc;
            cout<<"Wprowadz priorytet: ";
            cin>>priorytet;
            KP.push(priorytet,wartosc);
            Sleep(500);
            break;
        case 2:
            KP.pop();
            Sleep(500);
            break;
        case 3:
            if(KP.empty()) {cout<<"JEST PUSTA!"<<endl;}
            else {cout<<"NIE JEST PUSTA!"<<endl;}
            Sleep(500);
            break;
        case 4:
            x=KP.priofront();
            cout<<"PRIORYTET: "<<x<<endl;
            Sleep(500);
            break;
        case 5:
            x=KP.front();
            cout<<"WARTOSC: "<<x<<endl;
            Sleep(500);
            break;
        case 6:
            KP.wyswietl();
            Sleep(500);
            break;
        case 7:
            cout<<"KONIEC"<<endl<<endl<<"!Prosze poczekac na sortowania!"<<endl;
            Sleep(2000);
            break;
        default :
            cout<<"BLAD!!! WPROWADZ NUMER OPERACJI JESZCZE RAZ!!!"<<endl;
            Sleep(500);
            break;
        }
    }
    while(wybor !=7);


    //SYMULACJE SORTOWANIA

    cout<<endl<<"SORTOWANIE PRZEZ WSTAWIANIE"<<endl<<endl;

    K.push(7,2);
    K.wyswietl();
    K.push(4,1);
    K.wyswietl();
    K.push(8,5);
    K.wyswietl();
    K.push(2,3);
    K.wyswietl();
    K.push(5,1);
    K.wyswietl();
    K.push(3,2);
    K.wyswietl();
    K.push(9,3);
    K.wyswietl();
    for(i=0;!K.empty();i++)
    {
        K.pop();
        K.wyswietl();
    }
    cout<<endl<<endl;

    cout<<"SORTOWANIE PRZEZ WYBIERANIE"<<endl<<endl;

    P.insert(7,2);
    P.wyswietl();
    P.insert(4,1);
    P.wyswietl();
    P.insert(8,5);
    P.wyswietl();
    P.insert(2,3);
    P.wyswietl();
    P.insert(5,1);
    P.wyswietl();
    P.insert(3,2);
    P.wyswietl();
    P.insert(9,3);
    P.wyswietl();
    for(i=0;!P.empty();i++)
    {
        P.del();
        P.wyswietl();
    }

	system("PAUSE");
	return 0;
}
