#pragma once

#include <iostream>
#include <QFrame>
#include <QPainter>
#include <TTabuleiro.h>
#include <TPlayer.h>
#include <QKeyEvent>
#include <TColisao.h>
#include <QTimer>

#ifndef TFRAME
#define TFRAME

#define TIMER 1000
#define FPS 30

class TFrame : public QFrame {

    Q_OBJECT

    int _h_sz;
    int _w_sz;

    TColisao* colisao;
    TTabuleiro* tabuleiro;

    TPlayer* player1;
    TPlayer* player2;

public:

    TFrame ();

    void resizeEvent(QResizeEvent* event);

    void paintEvent(QPaintEvent* event);

    void keyPressEvent(QKeyEvent* event);

private slots:

    void iniciar();

    void parar();
};
#endif // TFRAME

