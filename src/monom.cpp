#include "monom.h"

Monom::Monom(DataType d, Monom* n, int de)
{
	data = d;
	next = n;
	degree = de;
}

Monom::Monom(const Monom& Monom2)
{
	data = Monom2.data;
	next = Monom2.next;
	degree = Monom2.degree;
}