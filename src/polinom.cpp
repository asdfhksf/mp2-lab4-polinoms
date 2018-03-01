#include "polinom.h"

wchar_t To_Uni_Degree(int de)
{
	switch (de)
	{
	case 0: return 0x2070;
	case 1: return 0x00B9;
	case 2: return 0x00B2;
	case 3: return 0x00B3;
	case 4: return 0x2074;
	case 5: return 0x2075;
	case 6: return 0x2076;
	case 7: return 0x2077;
	case 8: return 0x2078;
	case 9: return 0x2079;
	}
}

Polinom::Polinom()
{
	head = new Monom;

	head->data = 0;
	head->degree = -1;
	head->next = NULL;
}
Polinom::Polinom(const Polinom& Polinom2)
{
	head = NULL;
	Monom *tmp = Polinom2.head, *tmp1 = head;

	while (tmp != NULL)
	{
		if (tmp1 != NULL)
		{
			InsertAfter(tmp1, tmp->data, tmp->degree);
			tmp1 = tmp1->next;
		}
		else
		{
			tmp1 = new Monom;
			tmp1->next = NULL;
			tmp1->data = tmp->data;
			tmp1->degree = tmp->degree;
			head = tmp1;
		}
		tmp = tmp->next;
	}
}
Polinom::~Polinom()
{
	Clean();
}

void Polinom::InsertToTail(const DataType& d, const int de)
{
	Monom *tmp = head;

	if (tmp != NULL)
	{

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}


		tmp->next = new Monom;
		tmp->next->next = NULL;
		tmp->next->data = d;
		tmp->next->degree = de;

	}
	else
	{
		tmp = new Monom;
		tmp->next = NULL;
		tmp->data = d;
		tmp->next->degree = de;
		head = tmp;
	}
}
void Polinom::InsertAfter(Monom* monom, const DataType& d, const int de)
{
	Monom *tmp1 = monom, *tmp2;

	if (monom != NULL)
	{
		tmp2 = tmp1->next;

		tmp1->next = new Monom;
		tmp1->next->data = d;
		tmp1->next->degree = de;

		tmp1->next->next = tmp2;
	}
	else
	{
		if (head == NULL)
			throw - 1;
	}
}

Monom* Polinom::Search_Next(const DataType& d)
{
	Monom *tmp = head;

	while ((tmp != NULL) && (tmp->next->data != d))
	{
		tmp = tmp->next;
	}

	if (tmp != NULL)
	{
		return tmp;
	}
	else
		return NULL;
}
void Polinom::Clean()
{
	while (head != NULL)
	{
		Monom *tmp = head->next;
		delete head;
		head = tmp;
	}
	delete head;
}
int Polinom::GetSize()
{
	Monom *tmp = head;
	int s = 0;

	while (tmp != NULL)
	{
		s++;
		tmp = tmp->next;
	}

	return s;
}
Monom* Polinom::GetHead() const
{
	return head;
}

wostream& operator<<(wostream& wos, const Polinom& p)
{
	Monom *tmp = p.head->next;
	int x, y, z;
	char sign;

	_setmode(_fileno(stdout), _O_U16TEXT);

	if (tmp)
	{
		x = tmp->degree / 100;
		y = tmp->degree / 10 - 10 * x;
		z = tmp->degree - 100 * x - 10 * y;

		if (tmp->data > 0)
			sign = '+';
		else
			sign = '-';

		if (abs(tmp->data) != 1)
		{
			if (x > 1)
			{
				wos << tmp->data << "x" << To_Uni_Degree(x);
			}
			else
			{
				if (x == 1)
					wos << tmp->data << "x";
				else
				{
					if (x == 0)
						wos << tmp->data;
				}
			}
		}
		else
		{
			if (tmp->data == 1)
			{
				if (x > 1)
				{
					wos << "x" << To_Uni_Degree(x);
				}
				else
				{
					if (x == 1)
						wos << "x";
					else
					{
						if (x == 0)
							wos << "";
					}
				}

			}

			if (tmp->data != 1)
			{
				if (x > 1)
				{
					wos << "-" << "x" << To_Uni_Degree(x);
				}
				else
				{
					if (x == 1)
						wos << "-" << "x";
					else
					{
						if (x == 0)
							wos << "-";
					}
				}

			}
		}

		if (y > 1)
		{
			wos << "y" << To_Uni_Degree(y);
		}
		else
		{
			if (y == 1)
				wos << "y";
			else
			{
				if (y == 0)
					wos << "";
			}
		}

		if (z > 1)
		{
			wos << "z" << To_Uni_Degree(z);
		}
		else
		{
			if (z == 1)
				wos << "z";
			else
			{
				if (z == 0)
					wos << "";
			}
		}

		tmp = tmp->next;

		while (tmp != NULL)
		{
			x = tmp->degree / 100;
			y = tmp->degree / 10 - 10 * x;
			z = tmp->degree - 100 * x - 10 * y;

			if (tmp->data > 0)
				sign = '+';
			else
				sign = '-';

			if (abs(tmp->data) != 1)
			{
				if (x > 1)
				{
					wos << sign << abs(tmp->data) << "x" << To_Uni_Degree(x);
				}
				else
				{
					if (x == 1)
						wos << sign << abs(tmp->data) << "x";
					else
					{
						if (x == 0)
							wos << sign << abs(tmp->data);
					}
				}
			}
			else
			{
				if (tmp->data == 1)
				{
					if (x > 1)
					{
						wos << "x" << To_Uni_Degree(x);
					}
					else
					{
						if (x == 1)
							wos << "x";
						else
						{
							if (x == 0)
								wos << "";
						}
					}

				}

				if (tmp->data != 1)
				{
					if (x > 1)
					{
						wos << "-" << "x" << To_Uni_Degree(x);
					}
					else
					{
						if (x == 1)
							wos << "-" << "x";
						else
						{
							if (x == 0)
								wos << "-";
						}
					}

				}
			}

			if (y > 1)
			{
				wos << "y" << To_Uni_Degree(y);
			}
			else
			{
				if (y == 1)
					wos << "y";
				else
				{
					if (y == 0)
						wos << "";
				}
			}

			if (z > 1)
			{
				wos << "z" << To_Uni_Degree(z);
			}
			else
			{
				if (z == 1)
					wos << "z";
				else
				{
					if (z == 0)
						wos << "";
				}
			}

			tmp = tmp->next;
		}
	}
	else
		wos << "Zero polinom";

	_setmode(_fileno(stdout), _O_TEXT);
	return wos;
}

Monom* Polinom::Search_De(int de)
{
	if (GetSize() > 1)
	{
		Monom *tmp = head;

		while (tmp->next && (tmp->next->degree >= de))
			tmp = tmp->next;

		return tmp;
	}
	else
	{
		return head;
	}
}
void Polinom::Similar_Terms(Monom* prev, Monom* curr)
{
	if (curr->degree == prev->degree)
	{
		prev->data += curr->data;
		prev->next = curr->next;

		delete curr;

		if (prev->data == 0)
		{
			prev = Search_Next(0);
			prev->next = prev->next->next;
		}
	}
}

void Polinom::Plus(Polinom l1)
{
	Monom *prev1 = GetHead(), *curr1 = GetHead()->next, *next1 = GetHead()->next->next;
	Monom* prev2 = l1.GetHead(), *curr2 = l1.GetHead()->next, *next2 = l1.GetHead()->next->next;
	int de1, de2;

	while (curr1 || curr2)
	{
		if (curr1)
			de1 = curr1->degree;
		else
			de1 = -1;

		if (curr2)
			de2 = curr2->degree;
		else
			de2 = -1;

		if (de1 > de2)
		{
			while (next1 && (de2 <= next1->degree))
			{
				next1 = next1->next;
				curr1 = curr1->next;
				prev1 = prev1->next;

				de1 = curr1->degree;
			}

			if (de1 != de2)
			{
				curr1->next = curr2;
				if (curr2)
					curr2->next = next1;

				curr2 = next2;
				if (next2)
					next2 = next2->next;
				if (prev2->next)
					prev2->next = prev2->next->next;

				curr1 = next1;
				if (next1)
					next1 = next1->next;
				if (prev1->next)
					prev1 = prev1->next->next;
			}
		}
		else
		{
			if (de1 < de2)
			{
				if (de1 != de2)
				{
					prev1->next = curr2;
					if (curr2)
						curr2->next = curr1;

					curr2 = next2;
					if (next2)
						next2 = next2->next;
					if (prev2->next)
						prev2->next = prev2->next->next;

					prev1 = prev1->next;
				}
			}
			else
			{
				curr1->data += curr2->data;

				if (curr1->data == 0)
				{
					Monom* zero = Search_Next(0);

					zero->next = zero->next->next;
				}

				curr2 = next2;
				if (next2)
					next2 = next2->next;
				if (prev2->next)
					prev2->next = prev2->next->next;
			}
		}
	}
	l1.GetHead()->next = NULL;
}
void Polinom::Plus_New(const Polinom l1, const Polinom l2)
{
	Monom *curr1 = l1.GetHead()->next, *curr2 = l2.GetHead()->next;
	Monom *tmp_curr, *tmp_prev;
	int de, de1, de2;
	double d;

	while (curr1 || curr2)
	{
		if (curr1)
			de1 = curr1->degree;
		else
			de1 = -1;

		if (curr2)
			de2 = curr2->degree;
		else
			de2 = -1;

		if (de1 > de2)
		{
			de = de1;
			d = curr1->data;

			curr1 = curr1->next;
		}
		else
		{
			if (de1 < de2)
			{
				de = de2;
				d = curr2->data;

				curr2 = curr2->next;
			}
			else
			{
				de = de1;
				d = curr1->data + curr2->data;

				curr1 = curr1->next;
				curr2 = curr2->next;
			}
		}

		if (d != 0)
		{
			tmp_prev = Search_De(de);

			InsertAfter(tmp_prev, d, de);
			tmp_curr = tmp_prev->next;

			Similar_Terms(tmp_prev, tmp_curr);
		}
	}
}