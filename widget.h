#ifndef WIDGET_H
#define WIDGET_H
#include "map.h"
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget();
    ~Widget();

private:
    Map *mMap;

private:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // WIDGET_H
