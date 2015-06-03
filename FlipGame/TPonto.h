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

    TPonto();

    TPonto(QColor corBorda,QColor corFundo);

    ~TPonto();

    void setCorFundo(QColor corFundo);

    QColor getCorFundo();

    void setCorBorda(QColor corBorda);

    QColor getCorBorda();
};
#endif // TPONTO

