#ifndef PLANE_H
#define PLANE_H

#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "Utils.h"

#include "sol.h"
class joueur : public QGraphicsPixmapItem {


private :
    QString description="personnage.png";


public:
    int speedx=0;

    int speedy=0;
    float direction=0;
    void keyPressEvent(QKeyEvent * event);
    joueur(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description) {

    }
    void move2();
    bool colisionaveplafond();

    const QString &getDescription() const { return this->description; }
    bool colisionavecsol();
    bool colisionavecmur();
    bool colisionavecarrive();
};

#endif // PLANE_H
