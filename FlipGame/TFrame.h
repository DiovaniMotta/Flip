#pragma once
#include <QFrame>
#include <QPainter>
#include <TTabuleiro.h>
#include <TPlayer.h>
#include <QPushButton>
#include <QPalette>

#ifndef TFRAME
#define TFRAME

class TFrame : public QFrame {

    int _h_sz;
    int _w_sz;
    TTabuleiro* tabuleiro;
    TPlayer* player1;
    TPlayer* player2;
public:
    TFrame () {
        setMinimumSize(800,600);
        setFrameStyle(QFrame::Box);
        QString titulo("Flip - Programação Gráfica I - Diovani Bernardi da Motta");
        setWindowTitle(titulo);
        setLineWidth(4);
        setMouseTracking(true);
        setFocus();
        tabuleiro = new TTabuleiro;
        player1 = new TPlayer;
        player1->setNivel(TPlayer::NIVEL2);
        player1->setPosX(3);
        player1->setPosY(5);
        tabuleiro->setPlayer1(player1);
    }

    void resizeEvent(QResizeEvent* event){
        QFrame::resizeEvent(event);
        _h_sz = this->height()*0.05;
        _w_sz = this->width()*0.05;
    }

    void paintEvent(QPaintEvent* event){
        QFrame::paintEvent(event);
        QPainter painter(this);
        for(int x=0;x <TTabuleiro::DIMENSAO;x++){
            for(int y=0; y<TTabuleiro::DIMENSAO; y++){
                TPonto ponto = tabuleiro->nivel(x,y);
                painter.setPen(ponto.getCorBorda());
                painter.setBrush(ponto.getCorFundo());
                painter.drawRect((x * _w_sz),(y*_h_sz),_w_sz,_h_sz);
            }
         }
        painter.setPen(Qt::red);
        painter.setBrush(Qt::red);
        painter.drawRect((player1->getPosX() * _w_sz),(player1->getPosY() * _h_sz),_w_sz,_h_sz);
     }
};
#endif // TFRAME

