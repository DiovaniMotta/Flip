#include <TPlayer.h>
#pragma once
#ifndef TCOLISAO
#define TCOLISAO

class TColisao {

    int largura;
    int altura;
public:
    TColisao ();
    TColisao(int larg, int alt);
    ~TColisao();

    void setLargura(int larg);

    int getLargura();

    void setAltura(int alt);

    int getAltura();

    void dimensaoJanela(TPlayer* player);
};
#endif // TCOLISAO

