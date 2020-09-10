#ifndef MAP_H
#define MAP_H
#include "possibility.h"
#include "cell.h"
#include "file.h"
#include <QDebug>
#include <QVector>
#include <QLine>
#include <QRect>
#include <QString>

class Map
{
public:
    Map(int length);
    ~Map();
    QVector<QLine> getLines();
    QVector<QRect> getRects();
    QVector<QString> getNumbers();
    QVector<Cell*> getChangeAbles();
    void findRect(int x, int y);
    int choosenCell() const;
    void setNumber(int key);
    void setChosenCell(int index);
    void setRedCell(bool b);
    bool isRedCell();
    bool isFinish();

private:
    void addLines();
    void addRects();
    void setNumbers();
    void setChangeAbles();
    void setUnChangeAbles();

private:
    bool mRedCell;
    File mFile;
    Possibility mPossibility;
    const int mN;
    int mChoosenCell;
    const int mLength;
    QVector<Cell*> mVectorChangeAbles;
    QVector<QString> mVectorNumbers;
    QVector<QLine> mVectorLines;
    QVector<QRect> mVectorRects;
};

#endif // MAP_H
