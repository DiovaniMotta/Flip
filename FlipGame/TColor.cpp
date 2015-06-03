#include <TColor.h>

TColor::TColor () {

}

void TColor::preto(TPonto* ponto){
    ponto->setCorBorda(Qt::white);
    ponto->setCorFundo(Qt::black);
}

void TColor::branco(TPonto* ponto){
    ponto->setCorBorda(Qt::black);
    ponto->setCorFundo(Qt::white);
}

void TColor::cinza(TPonto* ponto){
    ponto->setCorBorda(Qt::gray);
    ponto->setCorFundo(Qt::gray);
}
