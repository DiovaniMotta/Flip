#pragma once

#include <iostream>
#include <QFrame>
#include <QPainter>
#include <TTabuleiro.h>
#include <TPlayer.h>
#include <QKeyEvent>
#include <TColisao.h>
#include <QTimer>
#include <TMedia.h>
#include <QDebug>
#include <TTiro.h>
#include <math.h>

#ifndef TFRAME
#define TFRAME

#define TIMER 1000
#define FPS 30

class TFrame : public QFrame {

    Q_OBJECT

    int _h_sz;
    int _w_sz;
    int _w_frame;
    int _h_frame;
    bool iniciou;// controla se o usuario iniciou o gameplayer ou nao

    TColisao* colisao;
    TTabuleiro* tabuleiro;
    TPainel* panel;
    TMedia* media;
    TPlayer* player1;
    TPlayer* player2;
    TTiro* bomber = NULL;
    TTiro* raio = NULL;

public:

    TFrame ();

    void resizeEvent(QResizeEvent* event);

    void paintEvent(QPaintEvent* event);

    void keyPressEvent(QKeyEvent* event);

    void mouseDoubleClickEvent(QMouseEvent *event);

private:

    void disparo(TPlayer* player,QPainter* painter);

    void disparo(TPlayer* player,TProjetil* projetil); // usado para verifica se houve a colisao entre o player e o projetil

    void redimensionar(TPlayer* player); // funcao responsavel por redimensionar o projetil disparado pelo player

    void armas(QPainter * painter); // responsavel por desenhar as armas adicionais que serão mostradas na tela

    void disparo(QPainter* painter); // responsavel por desenhar o disparo especiais feitos pelo player

    void disparo(TPlayer* player);

    void mover();

    void municao(TPlayer* player,QPainter* painter);

private slots:

    void iniciar();

};
#endif // TFRAME

