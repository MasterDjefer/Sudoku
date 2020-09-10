#ifndef POSSIBILITY_H
#define POSSIBILITY_H
#include <QVector>
#include <QString>

class Possibility//class for searching possibility to input user choice
{
public:
    Possibility();
    bool checkPossibility(QVector<QString> vectorNumbers, int choosenCell, QString number);
    bool horizontal(QVector<QString> vectorNumbers, int choosenCell, QString number);
    bool vertical(QVector<QString> vectorNumbers, int choosenCell, QString number);
    bool block(QVector<QString> vectorNumbers, int choosenCell, QString number);
    int sverhRazum(int choosenCell);//karim's method
};

#endif // POSSIBILITY_H
