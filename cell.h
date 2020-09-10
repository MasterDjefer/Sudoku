#ifndef CELL_H
#define CELL_H

class Cell//show us whether cells can be changed
{
public:
    Cell();
    Cell(bool c);
    bool isChangeAble() const;
    void setChangeable(bool c);

private:
    bool mChangeable;
};

#endif // CELL_H
