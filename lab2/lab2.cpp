#include <iostream>
#include "KomplexChislo.h"
int main()
{
	setlocale(LC_ALL, "Ru");
	Komplex_chislo chislo_1;
	Komplex_chislo chislo_2(5,3);
	Komplex_chislo chislo_3(0);
	chislo_1.Status();
	chislo_2.Status();
	chislo_3.Status();
	chislo_3 = chislo_1 - chislo_2;
	chislo_3.Status();
	Komplex_chislo chislo_4 = chislo_1 / chislo_2;
	chislo_4.Status();
}
