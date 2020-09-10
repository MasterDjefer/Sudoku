#include "widget.h"

Widget::Widget()
{
    this->setFixedSize(500, 500);
    mMap = new Map(this->width());
}

Widget::~Widget()
{
    delete mMap;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::blue, 2));
    painter.drawRects(mMap->getRects());

    painter.setPen(QPen(Qt::blue, 6));
    painter.drawLines(mMap->getLines());

    if (mMap->choosenCell() != -1)//paint choosen cell
    {
        if (mMap->isRedCell())
        {
            painter.setPen(QPen(Qt::red, 5));
        }
        else
        {
            painter.setPen(QPen(Qt::yellow, 5));
        }
        painter.drawRect(mMap->getRects().at(mMap->choosenCell()));
        mMap->setRedCell(false);
    }


    int size = this->width() / 10 + this->width() / 100;
    painter.setFont(QFont("Times", 20));
    for (int i = 0; i < mMap->getRects().size(); ++i)//paint number on map
    {
        if (mMap->getChangeAbles().at(i)->isChangeAble())//paint users numbers
        {
            painter.setPen(QPen(Qt::green));
            painter.drawText(mMap->getRects().at(i).x(), mMap->getRects().at(i).y(), size, size,
                             Qt::AlignCenter, mMap->getNumbers().at(i));
        }
        else
        {
            painter.setPen(QPen(Qt::black));//paint current numbers
            painter.drawText(mMap->getRects().at(i).x(), mMap->getRects().at(i).y(), size, size,
                             Qt::AlignCenter, mMap->getNumbers().at(i));
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() >= 49 && event->key() <= 57)
    {
        mMap->setNumber(event->key());
    }
    else
    if (mMap->choosenCell() != -1)//all move on map
    {
        if (event->key() == Qt::Key_Right)
        {
            if (mMap->choosenCell() % 9 != 8)
                mMap->setChosenCell(mMap->choosenCell() + 1);
        }
        else
        if (event->key() == Qt::Key_Left)
        {
            if (mMap->choosenCell() % 9 != 0)
                mMap->setChosenCell(mMap->choosenCell() - 1);
        }
        else
        if (event->key() == Qt::Key_Down)
        {
            if (mMap->choosenCell() < 72)
                mMap->setChosenCell(mMap->choosenCell() + 9);
        }
        else
        if (event->key() == Qt::Key_Up)
        {
            if (mMap->choosenCell() > 8)
                mMap->setChosenCell(mMap->choosenCell() - 9);
        }
    }



    this->update();

    if (mMap->isFinish())
    {
        QMessageBox message;
        message.setText("Congratulation! You won!");
        message.exec();
        this->close();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    mMap->findRect(event->x(), event->y());//find choosen cell
    this->update();
}

