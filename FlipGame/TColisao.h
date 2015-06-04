#pragma once
#ifndef TCOLISAO
#define TCOLISAO

#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TTabuleiro.h>


class TColisao {

    int largura;
    int altura;
    TNivel1* nivel1;
    TNivel2* nivel2;
    TTabuleiro* tabuleiro;

public:

    TColisao ();

    TColisao(int larg, int alt);

    TColisao(TTabuleiro* tabuleiro);

    ~TColisao();

    void setLargura(int larg);

    int getLargura();

    void setAltura(int alt);

    int getAltura();

    void colisao(TPlayer* player);

    TNivel1* getNivel1();

    void setNivel1(TNivel1* nivel);

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

private:

    TPonto nivel(TPlayer* player);
};
#endif // TCOLISAO

