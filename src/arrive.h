//
// Created by gagna on 02/05/2020.
//

#ifndef TP4_ARRIVE_H
#define TP4_ARRIVE_H
#include <QGraphicsItem>
#include <QString>
class arrive : public QGraphicsPixmapItem{
public:
arrive(QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName="arriv.png")){

}
};


#endif //TP4_ARRIVE_H
