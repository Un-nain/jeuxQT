#include <QHBoxLayout>
#include <QDebug>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* parent1 = new QWidget(parent);
    layoutH= new QHBoxLayout();//crée un layout horizontal
    layoutV= new QVBoxLayout();//crée un layout vertical
    btn=new QPushButton();
    btn->setText("relancer le jeu");
    connect(btn,SIGNAL(clicked()),this,SLOT(relancellejeu()));

    layoutH->addWidget(btn);//ajoute le btn dans le layout horizontal (dans le but de l'avoir en haut de la fenetre)
    layoutV->addLayout(layoutH);

    parent1->setLayout(layoutV);//ajoute les layouts dans le layout "principal"

    this->mainScene = new MainScene();

    const QVector<joueur*>& planes = this->mainScene->getPlanes();

    for(joueur* plane : planes){

        QGraphicsView* planeView = new QGraphicsView();
        planeView->setScene(mainScene);
        planeView->resize(300, 300);
        planeView->setWindowTitle(plane->getDescription());
        planeView->setWindowFlags(static_cast<QFlag>(QGraphicsItem::ItemIsFocusable));
        planeView->show();

    }


    mainView = new QGraphicsView();
    mainView->setScene(mainScene);
    mainView->scale(0.69, 0.5);
    this->setCentralWidget(parent1);
    this->setWindowTitle("bobspeedrun");
    this->resize(900,400 );
    layoutV->addWidget(mainView);// ajoute la vue graphique dans le layout princiapl

}

void MainWindow::relancellejeu() {//est lancé quand le boutons est clické permet de relancer le jeu depuis sa situation initial
//appel le relanceur
mainScene->relance(mainScene->statu);//statu permet de savoir si les éléments d'affichages supplémentaires sont a suprimé
qDebug() << "2222222222222222222222" << endl;
}

