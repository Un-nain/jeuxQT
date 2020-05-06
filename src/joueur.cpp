#include "joueur.h"
#include "Utils.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPointF>
#include "sol.h"
#include <typeinfo>
#include <QList>
#include <QVector>
#include "mur.h"
#include "arrive.h"
#include "plafond.h"
void joueur::move2() {
    setPos(x()+this->speedx,y()+this->speedy );//deplacer le personnage de sa vitesse en x et y
    if((speedy!=0)||!colisionavecsol()){//rentre dans la boucle si le personnage touche le sol ou sa vitesse est != 0
            if(speedy<10)speedy=speedy+3;
        if (colisionavecsol())//si le personnge touche le sol set la vitesse vertical a 0

            speedy=0;

    }
    if(colisionavecmur()){//rentre dans la boucle si le personnage touche un mur
        speedx=0;
        setPos(x()+(direction*2),y());//deplace le personnage d'un coté du mur
    }
    if(colisionaveplafond()){//rentre dans la boucle si le personnage touche un plafond
        speedy=3;
        //setPos(x()+(direction*2),y());//renvois le personage vers le bas
    }
    qDebug () << "12" << endl;


}
void joueur::keyPressEvent(QKeyEvent * event){//se declange si l'un des touches est appuyé

    if (event->key()== Qt::Key_Left)
    {
        speedx=speedx-1;

    }
    if (event->key()== Qt::Key_Right) {
        speedx = speedx + 1;
    }
    if (event->key()== Qt::Key_Up)
    {
        if(speedy==0)speedy = speedy -30;
    }
    if (event->key()== Qt::Key_Down)
    {
        speedx=0;
    }


    if(speedx>0)direction=-1;
    if(speedx<0)direction=1;
    qDebug () << "test " <<this->pos() << this->speedx << this->speedy << endl;
}

bool joueur::colisionavecsol() {//retourne true si le joueur touche un sol
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(sol))
        {return true;}}
    return false;
}
bool joueur::colisionavecmur() {//retourne true si le joueur touche un mur
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(mur))
        {return true;}}
    return false;
}
bool joueur::colisionavecarrive() {//retourne true si le joueur touche une ligne d'arrivé
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(arrive))
        {return true;}}
    return false;
}
bool joueur::colisionaveplafond() {//retourne true si le joueur touche le plafond
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(plafond))
        {return true;}}
    return false;
}