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
/**
 * @brief TColor::equals verifica se em um determinado ponto da tela a cor de fundo é igual
 * a cor repassada por parametro
 * @param ponto o ponto da tela que sera avaliado
 * @param cor a cor que desejo verificar
 * @return verdadeiro se a cor informada no parametro for igual a cor de fundo do ponto e falso caso nao seja
 */
bool TColor::equals(TPonto ponto, QColor cor){
    if(ponto.getCorFundo().operator ==(cor)){
        return true;
    }
    return false;
}
