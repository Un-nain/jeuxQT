//
// Created by gagna on 26/04/2020.
//

#ifndef TP4_SOL_H
#define TP4_SOL_H

#include <QGraphicsItem>
class sol : public QGraphicsPixmapItem{
public:
    sol(QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)){

    }
};


#endif //TP4_SOL_H
