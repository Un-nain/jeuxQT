#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainScene.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QVector>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    MainScene* mainScene;

    QVector<QGraphicsView*> planeViews;
    QGraphicsView* mainView;
    QPushButton* btn;
    QHBoxLayout* layoutH;
    QVBoxLayout* layoutV;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() {};
public slots :
    void relancellejeu();

};

#endif // MAINWINDOW_H
