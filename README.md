# Mon premier jeu avec QT

## Introduction

>Un fabuleu jeu en QT qui consiste a aller le plus vite possible a la ligne d'arrivé, le meilleur score est enregistrer ce qui augmente l'envie d'aller toujours plus vite.
Les flèches directionnel gauche et droite font accéléré le personnage de manière linéaire. Flèche haut fait sauter le personnage enfin la flèche bas stop la vitesse horizontal pour faire des mouvements de précision.
<br>Voir ci dessous pour le fonctionnement des déplacements (la flèche gauche fais de même que la doite mais en sens contraire).

## Échantillons de code



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


## Installation



>
Tout d'abord assuré vous que Xming est allumé sur votre appareil.

Puis ,pour lancer ce fantastique jeu, vous devez compiler puis exécuter le code sur un compilateur Cmake. (cmake_minimum_required(VERSION 3.7))
Attention, pour la premiere utilisation vous devrez aussi edité le "run edit config",
dans ce dernier vous devrez ajouter a:
Working directory : "..\img"
Environment variables: "DISPLAY=:0.0".

Bon jeu a tous !

