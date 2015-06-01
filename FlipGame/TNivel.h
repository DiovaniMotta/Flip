#pragma once
#include <TPonto.h>
#include <TTabuleiro.h>

#ifndef TNIVEL
#define TNIVEL

class TNivel {

protected:

    TPonto lista[20][20];

    void inicializar(){
        for(int x=0; x<20; x++){
            for(int y=0; y< 20; y++){
                TPonto ponto;
                ponto.setCorBorda(Qt::white);
                ponto.setCorFundo(Qt::black);
                lista[x][y] = ponto;
            }
        }
    }

public:
    TNivel () {}

    TPonto nivel(int x, int y){
        return lista[x][y];
    }
};
#endif // TNIVEL



