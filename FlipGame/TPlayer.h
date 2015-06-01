#include <QColor>

#pragma once

#ifndef TPLAYER
#define TPLAYER
/**
 * Classe responsavel por armazenar as informações do player que está no jogo
 * @brief The TPlayer class
 */
class TPlayer {

  int nivel;
  int posX;
  int posY;
  QColor fundo;
  QColor borda;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    TPlayer() {
        this->nivel = 1;
        this->posX = 0;
        this->posY = 0;
    }

    int getNivel(){
        return this->nivel;
    }

    void setNivel(int nivel){
        this->nivel = nivel;
    }

    void setPosX(int posX){
        this->posX = posX;
    }

    void setPosY(int posY){
        this->posY = posY;
    }

    int getPosX(){
        return this->posX;
    }

    int getPosY(){
        return this ->posY;
    }
    void setFundo(QColor fundo){
        this->fundo = fundo;
    }

    QColor getFundo(){
        return this->fundo;
    }

    void setBorda(QColor borda){
        this->borda = borda;
    }

    QColor getBorda(){
       return this->borda;
    }

};
#endif // TPLAYER
