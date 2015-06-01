#pragma once
#include <TPonto.h>
#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <QDebug>

#ifndef TTABULEIRO
#define TTABULEIRO
/**
 * Author : Diovani Bernardi da Motta
 * @brief The TTabuleiro class classe responsável por montar as informações que serão exibidas para o usuario em forma de
 * tabuleiro
 */
class TTabuleiro{

   TPlayer* player1;
   TPlayer* player2;
   TNivel1* nivel1;
   TNivel2* nivel2;

public:
    static const int DIMENSAO = 20;

    TTabuleiro(){
        this->player1 = new TPlayer();
        this->player2 = new TPlayer();
        this->nivel1 = new TNivel1();
        this->nivel2 = new TNivel2();
    }

    TTabuleiro(TPlayer* player1,TPlayer* player2){
        this->player1 = player1;
        this->player2 = player2;
        this->nivel1 = new TNivel1();
        this->nivel2 = new TNivel2();
    }

    ~TTabuleiro(){
        delete player1;
        delete player2;
        delete nivel1;
    }

    void setPlayer1(TPlayer* player1){
        this->player1 = player1;
    }

    TPlayer* getPlayer1(){
        return this->player1;
    }

    void setPlayer2(TPlayer* player2){
        this->player2 = player2;
    }

    TPlayer* getPlayer2(){
        return this->player2;
    }

    TPonto nivel(int x,int y){
       switch(player1->getNivel()){
            case TPlayer::NIVEL1:
                return nivel1->nivel(x,y);
            case TPlayer::NIVEL2:
                return nivel2->nivel(x,y);
            case TPlayer::NIVEL3:
                return nivel1->nivel(x,y);
            case TPlayer::NIVEL4:
                return nivel1->nivel(x,y);
            case TPlayer::NIVEL5:
                return nivel1->nivel(x,y);
       }
       return nivel(x,y);
    }
};

#endif // TTABULEIRO
