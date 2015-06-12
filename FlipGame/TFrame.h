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
#include <TBomba.h>

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
    TMedia* media;
    TPlayer* player1;
    TPlayer* player2;
    TBomba* bomber = NULL;
public:

    TFrame ();

    void resizeEvent(QResizeEvent* event);

    void paintEvent(QPaintEvent* event);

    void keyPressEvent(QKeyEvent* event);

private:

    void disparo(TPlayer* player,QPainter* painter);

    void disparo(TPlayer* player,TProjetil* projetil,QPainter* painter); // usado para verifica se houve a colisao entre o player e o projetil

    void redimensionar(TPlayer* player); // funcao responsavel por redimensionar o projetil disparado pelo player

    void armas(QPainter * painter); // responsavel por desenhar as armas adicionais que serão mostradas na tela

    void disparo(QPainter* painter); // responsavel por desenhar o disparo especiais feitos pelo player

    void disparoAcima(TBomba* bomba,QPainter* painter);

    void disparoAbaixo(TBomba* bomba,QPainter* painter);

    void disparoEsquerda(TBomba* bomba,QPainter* painter);

    void disparoDireita(TBomba* bomba,QPainter* painter);

    void disparo(TPlayer* player);

private slots:

    void iniciar();

    void parar();
};
#endif // TFRAME

