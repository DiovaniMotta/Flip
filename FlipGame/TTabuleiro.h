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

   TPlayer* player;
   TNivel1* nivel1;
   TNivel2* nivel2;

public:
    static const int DIMENSAO = 20;

    TTabuleiro(){
        player = new TPlayer();
        nivel1 = new TNivel1();
    }

    TTabuleiro(TPlayer* player){
        this->player = player;
        nivel1 = new TNivel1();
    }

    ~TTabuleiro(){
        delete player;
        delete nivel1;
    }

    void setPlayer(TPlayer* player){
        this->player = player;
    }

    TPlayer* getPlayer(){
        return this->player;
    }

    TPonto nivel(int x,int y){
       switch(player->getNivel()){
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
