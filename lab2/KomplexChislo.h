#pragma once
#include <iostream>
#include <string>

using namespace std;



class class_Atribut {
    double deistvit, mnimoe;
    friend void input(class_Atribut&);
    friend void output(class_Atribut&);
    friend class Komplex_chislo;
    friend ostream& operator << (ostream&, const class_Atribut&);
    friend istream& operator >> (istream&, class_Atribut&);
public:
    class_Atribut() {}
    class_Atribut(double deistvit, double mnimoe) : deistvit(deistvit), mnimoe(mnimoe) {}
};

class Komplex_chislo {
    class_Atribut chislo;
public:
    Komplex_chislo() 
    {
        cin >> chislo;
    }
    Komplex_chislo(double a, double b = 0) : chislo(class_Atribut(a, b)) {}
    Komplex_chislo operator - (Komplex_chislo chislo_2)
    {
        double deistvit = chislo.deistvit - chislo_2.chislo.deistvit;
        double mnimoe = chislo.mnimoe - chislo_2.chislo.mnimoe;
        return Komplex_chislo(deistvit, mnimoe);
    }
    Komplex_chislo operator / (Komplex_chislo chislo_2)
    {
        double a = chislo.deistvit, b = chislo.mnimoe;
        double c = chislo_2.chislo.deistvit, d = chislo_2.chislo.mnimoe;
        double deistvit = (a * c + b * d) / (c * c + d * d);
        double mnimoe = (b * c - a * d) / (c * c + d * d);
        return Komplex_chislo(deistvit, mnimoe);
    }
    void Status()
    {
        cout << chislo;
    }
};

void input(class_Atribut& chislo)
{
    cin >> chislo.deistvit >> chislo.mnimoe;
}
void output(class_Atribut& chislo)
{
    cout << "(" << chislo.deistvit << ", "
        << chislo.mnimoe << ")\n";
}

ostream& operator << (ostream& os, const class_Atribut& chislo)
{
    return os << "(" << chislo.deistvit << ", "<< chislo.mnimoe << ")\n";
}

istream& operator >> (istream& os, class_Atribut& chislo)
{
    cout << "¬ведите комплексное число\n";
    cout << "   действительна€ часть = "; os >> chislo.deistvit;
    cout << "   мнима€ часть = "; os >> chislo.mnimoe;
    return os;
}