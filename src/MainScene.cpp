#include "MainScene.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QVector>
#include "sol.h"
#include "mur.h"
#include <QString>
#include <QTime>
#include <QDebug>
#include "arrive.h"
#include "joueur.h"
#include "plafond.h"
MainScene::MainScene() {
    QString minuM = QString::number(minm);
    QString secoM = QString::number(sm);
    QString milisM = QString::number(milim);
    QString afficheurM = QString("temps : %1.%2.%3" ).arg(minuM).arg(secoM).arg(milisM);//set le meilleur temps
    meilleur =new QGraphicsTextItem(afficheurM);
    QString minu = QString::number(min);
    QString seco = QString::number(sec);
    QString milis = QString::number(mili);
    QString afficheur = QString("temps : %1.%2.%3" ).arg(minu).arg(seco).arg(milis); //set le temps actuel
    tempsactuel = new QGraphicsTextItem(afficheur);
    tempsactuel->setDefaultTextColor("white");


    this->background.load("panorama.jpg");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->timer = new QTimer(this);// lancement du timer connecter au uppdate
    this->timer->start(25);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));//fais la connection a la function uppdate

    this->planeItems.push_back(new joueur("personnage", "personnage.png"));




        joueur* personnage = this->planeItems[0];
        this->addItem(personnage);// creation et ajout des element de la map
        this->planeItems[0]->setPos(100,150);
        sol* plancher= new sol("sol.png");
        sol* plancherr= new sol("sol.png");
        plafond* plancherrr= new plafond("sol.png");
        plafond* plancherrrr= new plafond("sol.png");
        mur* murdufond= new mur("murdufond.png");
        this->addItem(murdufond);
        this->addItem((plancher));
        this->addItem((plancherr));

        this->addItem((plancherrr));
        this->addItem((plancherrrr));
        murdufond->setPos(0,0);
        plancher->setPos(0,670);
        plancherr->setPos(400,670);
        plancherrr->setPos(0,0);
        plancherrrr->setPos(400,0);



        arrive* ligne = new arrive("arriv.png");
       this->addItem(ligne);
       ligne->setPos(1250,65);
        mur* obstacle= new mur("mur.png");
       this->addItem(obstacle);
        obstacle->setPos(900,590);
        sol* murtop= new sol("hautdemur.png");
       this->addItem(murtop);
        murtop->setPos(900,580);
        mur* obstaclee= new mur("mur.png");
        this->addItem(obstaclee);
        obstaclee->setPos(500,590);
        sol* murtopp= new sol("hautdemur.png");
        this->addItem(murtopp);
        murtopp->setPos(500,580);
       this->addItem(tempsactuel);
       tempsactuel->setScale(5);
       tempsactuel->setPos(500,0);




}

void MainScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}


void MainScene::update() {//mise a jour et appel de certaine fonction

    joueur* planeItem = this->planeItems[0];
    planeItem->setFlag(QGraphicsItem::ItemIsFocusable);
    planeItem->setFocus();

        planeItem->move2();
    QGraphicsView * view = this->views().at(0);
    view->centerOn(planeItem);
    mili=mili+25;
    if(mili==1000)
    {
        sec++;
        mili=0;
        if (sec==60)
        {
            min++;
            sec=0;
        }
    }
    QString minu = QString::number(min);
    QString seco = QString::number(sec);
    QString milis = QString::number(mili);
    QString afficheur = QString("temps : %1.%2.%3" ).arg(minu).arg(seco).arg(milis);
    tempsactuel->setPlainText(afficheur);

    if(planeItem->colisionavecarrive())//si la colision avec la ligne d'arrivé est detecter
    {
        statu= true;// permet de detecter si la partie est finis
        gg = new QGraphicsTextItem("Vous avez gagné");//affichage du fait qu'on a gagné
        timer->stop();
        gg->setScale(5);
        this->addItem(gg);
        gg->setPos(0,0);
        gg->setDefaultTextColor("red");
        if(minm>min){//si on a été plus rapide que le meilleur temps (en minute)
            meilleurscore();
        }
        else if(minm==min){//si on a pris autant de minute que le meilleur temps
            if(sm>sec)//si on a été plus rapide que le meilleur temps (en seconde)
            {
                meilleurscore();
            }
            else if(sm==sec)//si on a pris autant de seconde que le meilleur temps
            {
                if(milim>mili)//si on a été plus rapide que le meilleur temps (milli s)
                {
                meilleurscore();
                } else {pasmeilleurscore();}
                //on a pas battu le meilleur temps
            }
            else{//si on apris plus de temps que le meilleur temps
            pasmeilleurscore();
            }
        }
        else{//si on apris plus de temps que le meilleur temps
        pasmeilleurscore();
        }
}


}

MainScene::~MainScene() {

    delete this->timer;

    for(joueur* planeItem : this->planeItems){
        delete planeItem;
    }
}

void MainScene::meilleurscore() {//fonction qui indique que l'on a fait le meilleur temps et change le meilleur temps avec le nouveau
    affichemeilleur = new QGraphicsTextItem("vous avez fais le meilleur temps");
    //this->addItem(meilleur);
    qDebug() <<"meilleur temsp"<<endl;
    this->addItem(affichemeilleur);
    affichemeilleur->setScale(5);
    affichemeilleur->setPos(0,600);
    affichemeilleur->setDefaultTextColor("orange");
    this->milim=mili;
    this->sm=sec;
    this->minm=min;
}

void MainScene::pasmeilleurscore() {//fonction qui affiche le fais qu'on ai pas fais le meilleur temps et affiche le meilleur temps
    affichemeilleur = new QGraphicsTextItem("le meilleur temps est");
    QString minuM = QString::number(minm);
    QString secoM = QString::number(sm);
    QString milisM = QString::number(milim);
    QString afficheurM = QString("temps : %1.%2.%3" ).arg(minuM).arg(secoM).arg(milisM);
    meilleur=new QGraphicsTextItem(afficheurM);
    this->addItem(meilleur);
    this->addItem(affichemeilleur);
    affichemeilleur->setScale(5);
    affichemeilleur->setPos(75,600);
    affichemeilleur->setDefaultTextColor("orange");
    meilleur->setScale(5);
    meilleur->setPos(600,600);
    meilleur->setDefaultTextColor("orange");

}

void MainScene::relance(bool stat) {
    if(stat)
    {

        this->removeItem(this->gg);
        this->removeItem(this->meilleur);
        this->removeItem(this->affichemeilleur);
        timer->start();

    }
    this->planeItems[0]->setPos(100,150);
    this->mili=0;
    this->sec=0;
    this->min=0;
    this->planeItems[0]->speedy=0;
    this->planeItems[0]->speedx=0;
}



