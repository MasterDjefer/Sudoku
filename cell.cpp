#include "cell.h"

Cell::Cell() : mChangeable(true)
{
}

Cell::Cell(bool c) : mChangeable(c)
{
}

bool Cell::isChangeAble() const
{
    return mChangeable;
}

void Cell::setChangeable(bool c)
{
    mChangeable = c;
}


