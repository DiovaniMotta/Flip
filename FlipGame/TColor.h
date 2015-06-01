#pragma once
#include <TPonto.h>

#ifndef TCOLOR
#define TCOLOR
class TColor {

public:
    TColor () {}

    static void preto(TPonto* ponto){
        ponto->setCorBorda(Qt::white);
        ponto->setCorFundo(Qt::black);
    }

    static void branco(TPonto* ponto){
        ponto->setCorBorda(Qt::black);
        ponto->setCorFundo(Qt::white);
    }

    static void cinza(TPonto* ponto){
        ponto->setCorBorda(Qt::gray);
        ponto->setCorFundo(Qt::gray);
    }
};
#endif // TCOLOR

