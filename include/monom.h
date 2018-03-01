#include <iostream>
#include <io.h>
#include <fcntl.h>
typedef double DataType;

struct Monom
{
	DataType data;
	int degree;
	Monom* next;

	Monom(DataType d = 0, Monom* n = NULL, int de = 0);
	Monom(const Monom& Monom2);
};