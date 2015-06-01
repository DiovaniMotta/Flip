#pragma once
#include <QWidget>

#ifndef TPLAYER
#define TPLAYER
/**
 * Classe responsavel por armazenar as informações do player que está no jogo
 * @brief The TPlayer class
 */
class TPlayer : public QWidget {

  int nivel;

public:

    static const int NIVEL1 = 1;
    static const int NIVEL2 = 2;
    static const int NIVEL3 = 3;
    static const int NIVEL4 = 4;
    static const int NIVEL5 = 5;

    TPlayer() {
        this->nivel = 1;
    }

    int getNivel(){
        return this->nivel;
    }

    void setNivel(int nivel){
        this->nivel = nivel;
    }
};
#endif // TPLAYER
