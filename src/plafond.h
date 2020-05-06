//
// Created by gagna on 06/05/2020.
//

#ifndef TP4_PLAFOND_H
#define TP4_PLAFOND_H


#include <qstring.h>
#include <QGraphicsItem>
class plafond : public QGraphicsPixmapItem{
public:
    plafond(QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName="sol.png")){

    }
};


#endif //TP4_PLAFOND_H
