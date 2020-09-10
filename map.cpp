#include "map.h"

Map::Map(int length) : mLength(length), mChoosenCell(40), mN(9), mRedCell(false)
{
    addLines();
    addRects();
    setNumbers();
    setChangeAbles();
    setUnChangeAbles();
}

Map::~Map()
{
    while (mVectorChangeAbles.size() > 0)
    {
        Cell *c = mVectorChangeAbles.back();
        delete c;
        mVectorChangeAbles.pop_back();
    }
}

void Map::addLines()
{
    mVectorLines.push_back(QLine(0, mLength / 3, mLength, mLength / 3));
    mVectorLines.push_back(QLine(0, mLength / 3 * 2, mLength, mLength / 3 * 2));
    mVectorLines.push_back(QLine(mLength / 3, 0, mLength / 3, mLength));
    mVectorLines.push_back(QLine(mLength / 3 * 2, 0, mLength / 3 * 2, mLength));

    mVectorLines.push_back(QLine(0, 0, mLength, 0));
    mVectorLines.push_back(QLine(0, mLength, mLength, mLength));
    mVectorLines.push_back(QLine(0, 0, 0, mLength));
    mVectorLines.push_back(QLine(mLength, 0, mLength, mLength));
}

void Map::addRects()
{
    double x = 0.0;
    double y = 0.0;
    double inc = mLength / 9.0;
    double size1 = 0.0;
    double size2 = 0.0;

    for (int i = 0; i < mN; ++i)
    {
        for (int j = 0; j < mN; ++j)
        {
            mVectorRects.push_back(QRect(x + size1, y + size2, inc, inc));
            size1 += inc;
        }
        size1 = 0.0;
        size2 += inc;
    }
}

void Map::setNumbers()
{
    for (int i = 0; i < mN * mN; ++i)
    {
        mVectorNumbers.push_back(QString(""));
    }
}

void Map::setChangeAbles()
{
    for (int i = 0; i < mN * mN; ++i)
    {
        mVectorChangeAbles.push_back(new Cell(true));
    }
}

void Map::setUnChangeAbles()
{
    for (int i = 0; i < mFile.getUnChangeAbleNumbers().size(); ++i)
    {
        if (mFile.getUnChangeAbleNumbers().at(i) != "")
        {
            mVectorNumbers[i] = mFile.getUnChangeAbleNumbers().at(i);
            mVectorChangeAbles.at(i)->setChangeable(false);
        }
    }
}

QVector<QLine> Map::getLines()
{
    return mVectorLines;
}

QVector<QRect> Map::getRects()
{
    return mVectorRects;
}

QVector<QString> Map::getNumbers()
{
    return mVectorNumbers;
}

QVector<Cell*> Map::getChangeAbles()
{
    return mVectorChangeAbles;
}

void Map::findRect(int x, int y)
{
    for (int i = 0; i < mVectorRects.size(); ++i)
    {
        if (x >= mVectorRects.at(i).x() && x <= mVectorRects.at(i).x() + mVectorRects.at(i).width() &&
            y >= mVectorRects.at(i).y() && y <= mVectorRects.at(i).y() + mVectorRects.at(i).width())
        {
            mChoosenCell = i;
            return;
        }
    }
    mChoosenCell = -1;
}

int Map::choosenCell() const
{
    return mChoosenCell;
}

void Map::setNumber(int key)
{
    if (mVectorChangeAbles[mChoosenCell]->isChangeAble())
    {
        if (QString::number(key - '0') == mVectorNumbers[mChoosenCell])
            mVectorNumbers[mChoosenCell] = "";
        else
        if (mPossibility.checkPossibility(mVectorNumbers, mChoosenCell,
                                                    QString::number(key - '0')))
        {
            mVectorNumbers[mChoosenCell] = QString::number(key - '0');
        }
        else
        {
            mRedCell = true;
        }
    }
}

void Map::setChosenCell(int index)
{
    mChoosenCell = index;
}

void Map::setRedCell(bool b)
{
    mRedCell = b;
}

bool Map::isRedCell()
{
    return mRedCell;
}

bool Map::isFinish()
{
    for (int i = 0; i < mVectorNumbers.size(); ++i)
    {
        if (mVectorNumbers.at(i) == "")
        {
            return false;
        }
    }
    return true;
}
