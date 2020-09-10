#include "possibility.h"

Possibility::Possibility()
{
}

bool Possibility::checkPossibility(QVector<QString> vectorNumbers, int choosenCell, QString number)
{
    if (vertical(vectorNumbers, choosenCell, number) && horizontal(vectorNumbers, choosenCell, number)
            && block(vectorNumbers, choosenCell, number))
        return true;
    return false;
}

bool Possibility::horizontal(QVector<QString> vectorNumbers, int choosenCell,
                                             QString number)
{
    int a = (choosenCell / 9) * 9;
    int b = a + 9;

    for (int i = a; i < b; ++i)
    {
        if (vectorNumbers.at(i) == number)
        {
            return false;
        }
    }
    return true;
}

bool Possibility::vertical(QVector<QString> vectorNumbers, int choosenCell, QString number)
{
    int a = choosenCell;
    while (a >= 9)
    {
        a = a - 9;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (vectorNumbers.at(a) == number)
        {
            return false;
        }
        a += 9;
    }
    return true;
}

bool Possibility::block(QVector<QString> vectorNumbers, int choosenCell, QString number)
{
    int normal = sverhRazum(choosenCell);
    /*int normal = 0;
    if ((choosenCell >= 0 && choosenCell <= 2) || (choosenCell >= 9 && choosenCell <= 11) ||
            (choosenCell >= 18 && choosenCell <= 20))
        normal = 0;
    else
    if ((choosenCell >= 3 && choosenCell <= 5) || (choosenCell >= 12 && choosenCell <= 14) ||
            (choosenCell >= 21 && choosenCell <= 23))
        normal = 3;
    else
    if ((choosenCell >= 6 && choosenCell <= 8) || (choosenCell >= 15 && choosenCell <= 17) ||
            (choosenCell >= 24 && choosenCell <= 26))
        normal = 6;
    else
    if ((choosenCell >= 27 && choosenCell <= 29) || (choosenCell >= 36 && choosenCell <= 38) ||
            (choosenCell >= 45 && choosenCell <= 47))
        normal = 27;
    else
    if ((choosenCell >= 30 && choosenCell <= 32) || (choosenCell >= 39 && choosenCell <= 41) ||
            (choosenCell >= 48 && choosenCell <= 50))
        normal = 30;
    else
    if ((choosenCell >= 33 && choosenCell <= 35) || (choosenCell >= 42 && choosenCell <= 44) ||
            (choosenCell >= 51 && choosenCell <= 53))
        normal = 33;
    else
    if ((choosenCell >= 54 && choosenCell <= 56) || (choosenCell >= 63 && choosenCell <= 65) ||
            (choosenCell >= 72 && choosenCell <= 74))
        normal = 54;
    else
    if ((choosenCell >= 57 && choosenCell <= 59) || (choosenCell >= 66 && choosenCell <= 68) ||
            (choosenCell >= 75 && choosenCell <= 77))
        normal = 57;
    else
    if ((choosenCell >= 60 && choosenCell <= 62) || (choosenCell >= 69 && choosenCell <= 71) ||
            (choosenCell >= 88 && choosenCell <= 80))
        normal = 60;*/



    for (int i = 0; i < 3; ++i)
    {
        for (int j = normal; j < normal + 3; ++j)
        {
            if (vectorNumbers.at(j) == number)
            {
                return false;
            }
        }
        normal += 9;
    }

    return true;
}

int Possibility::sverhRazum(int choosenCell)
{
    int a=choosenCell;
    int b=a/27;
    int c=b*27;
    int d=a/3;
    int e=d*3;
    int k=e%9;
    int s=c+k;
    return s;
}
