#include <iostream>
#include <cstdlib>

using namespace std;


struct lista		//elementy listy
{
	lista * next;
	int piorytet;
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

}



int main()
{
	cout << "KOLEJKA PRIORYTETOWA" << endl;









	system("PAUSE");
	return 0;
}
