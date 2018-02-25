#include <cstdio>
#include "polinom.h"



int To_Common_Degree(int x, int y, int z)
{
	return 100 * x + 10 * y + z;
}



void main()
{
	Polinom p1, p2, p3;
	int r;
	double d;
	int x, y, z, de;
	Monom *tmp_curr, *tmp_prev;

	do
	{
		cout << "Enter value" << endl;
		cin >> d;

		cout << "Enter X degree" << endl;
		cin >> x;

		cout << "Enter Y degree" << endl;
		cin >> y;

		cout << "Enter Z degree" << endl;
		cin >> z;

		if (d != 0)
		{
			de = To_Common_Degree(x, y, z);
			tmp_prev = p1.Search_De(de);

			p1.InsertAfter(tmp_prev, d, de);
			tmp_curr = tmp_prev->next;

			p1.Similar_Terms(tmp_prev, tmp_curr);
		}

		cout << "Repeat?" << endl;
		cout << "1 - Yes	2 - No" << endl << endl;
		cin >> r;

	} while (r == 1);

	cout << p1 << endl;

	do
	{
		cout << "Enter value" << endl;
		cin >> d;

		cout << "Enter X degree" << endl;
		cin >> x;

		cout << "Enter Y degree" << endl;
		cin >> y;

		cout << "Enter Z degree" << endl;
		cin >> z;

		if (d != 0)
		{
			de = To_Common_Degree(x, y, z);
			tmp_prev = p2.Search_De(de);

			p2.InsertAfter(tmp_prev, d, de);
			tmp_curr = tmp_prev->next;

			p2.Similar_Terms(tmp_prev, tmp_curr);
		}

		cout << "Repeat?" << endl;
		cout << "1 - Yes	2 - No" << endl << endl;
		cin >> r;

	} while (r == 1);

	cout << p2 << endl << endl << endl;

	//p2.InsertToTaip(9, 900), p2.InsertToTaip(7, 700);
	//p1.InsertToTaip(8, 800), p1.InsertToTaip(6, 600);
	//p1.InsertToTaip(3, 525), p1.InsertToTaip(-5, 433), p1.InsertToTaip(7, 351);
	//p2.InsertToTaip(4, 326), p2.InsertToTaip(-6, 218);
	//p1.InsertToTaip(3, 525), p1.InsertToTaip(-5, 433), p1.InsertToTaip(7, 351);
	//p2.InsertToTaip(4, 726), p2.InsertToTaip(-6, 618);
	//p1.InsertToTaip(3, 525), p1.InsertToTaip(-5, 433), p1.InsertToTaip(7, 351);
	//p2.InsertToTaip(4, 525), p2.InsertToTaip(5, 433);
	//p1.InsertToTaip(7, 751), p1.InsertToTaip(3, 525), p1.InsertToTaip(-5, 433);
	//p2.InsertToTaip(4, 626), p2.InsertToTaip(-6, 218);
	//p1.InsertToTaip(7, 751), p1.InsertToTaip(3, 525), p1.InsertToTaip(-5, 433);
	//p2.InsertToTaip(-7, 751), p2.InsertToTaip(-3, 525), p2.InsertToTaip(5, 433);

	p3.Plus_New(p1, p2);
	p1.Plus(p2);

	cout << "Addition with the creation of a new polynomial" << endl << p3 << endl << endl;
	cout << "Addition without creating a new polynomial" << endl << p1 << endl << endl;
}