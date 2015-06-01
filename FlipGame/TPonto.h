#pragma once

#include <QColor>

#ifndef TPONTO
#define TPONTO
/**
 * Author : Diovani Bernardi da Motta
 * @brief The TPonto class classe responsável por representar cada ponto do tabuleiro
 */
class TPonto {

    QColor corFundo;
    QColor corBorda;

public:
    static const int dimensao = 50;

    TPonto(){

    }

    TPonto(QColor corBorda,QColor corFundo){
        this->corBorda = corBorda;
        this->corFundo = corFundo;
    }

    ~TPonto(){
    }

    void setCorFundo(QColor corFundo){
       this->corFundo = corFundo;
    }

    QColor getCorFundo(){
       return this->corFundo;
    }

    void setCorBorda(QColor corBorda){
       this->corBorda = corBorda;
    }

    QColor getCorBorda(){
       return this->corBorda;
    }
};
#endif // TPONTO

