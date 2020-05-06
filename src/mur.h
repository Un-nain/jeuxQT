//
// Created by gagna on 29/04/2020.
//

#ifndef TP4_MUR_H
#define TP4_MUR_H

#include <qstring.h>
#include <QGraphicsItem>
class mur : public QGraphicsPixmapItem{
public:
    mur(QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)){

    }
};


#endif //TP4_MUR_H
