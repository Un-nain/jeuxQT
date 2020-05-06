#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QGraphicsTextItem>

#include "joueur.h"

class MainScene : public QGraphicsScene {

    Q_OBJECT

private :
    QPixmap background;
    QTimer* timer;
    QVector<joueur*> planeItems;
    int mili=0;
    int sec=0;
    int min=0;
    QGraphicsTextItem* tempsactuel;
    QGraphicsTextItem* gg;
    QGraphicsTextItem* affichemeilleur;
    //QGraphicsTextItem* tempsactuel;
    int milim = 0;
    int sm = 0;
    int minm =100 ;
    QGraphicsTextItem* meilleur;
    void meilleurscore();
    void pasmeilleurscore();



public:
    MainScene();
    void drawBackground(QPainter* painter, const QRectF& rect);
    const QVector<joueur*>& getPlanes(){return planeItems;}

    virtual ~MainScene();
    bool statu=false;
    void relance(bool stat);

public slots :
    void update();





};

#endif // MYSCENE_H
