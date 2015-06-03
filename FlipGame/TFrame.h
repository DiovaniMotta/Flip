#pragma once
#include <QFrame>
#include <QPainter>
#include <TTabuleiro.h>
#include <TPlayer.h>
#include <QKeyEvent>
#include <TColisao.h>

#ifndef TFRAME
#define TFRAME

class TFrame : public QFrame {

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
};
#endif // TFRAME

