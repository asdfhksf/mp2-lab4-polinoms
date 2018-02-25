#include <iostream>
#include "monom.h"
using namespace std;

typedef double DataType;

class Polinom
{
	Monom* head;
public:
	Polinom();
	Polinom(const Polinom& Polinom2);
	~Polinom();

	void InsertToTail(const DataType& d, const int de);
	void InsertAfter(Monom* Monom, const DataType& d, const int de);
	
	Monom* Search_Next(const DataType& d);
	void Clean();
	int GetSize();
	Monom* GetHead() const;

	friend ostream& operator<<(ostream& os, const Polinom& l);

	Monom* Search_De(int de);

	void Similar_Terms(Monom* prev, Monom* curr);

	void Plus(Polinom l1);
	void Plus_New(const Polinom l1, const Polinom l2);
};
