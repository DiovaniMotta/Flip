#include <TColisao.h>
#include <QDebug>

TColisao::TColisao(){
    largura = 0;
    altura = 0;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
}

TColisao::TColisao(int larg, int alt){
    largura = larg;
    altura = alt;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
}

TColisao::~TColisao(){
    delete nivel1;
    delete nivel2;
}

bool TColisao::colisao(TPlayer *player){

    return true;
}

int TColisao::getLargura(){
    return largura;
}

void TColisao::setAltura(int alt){
    altura = alt;
}

int TColisao::getAltura(){
   return altura;
}

void TColisao::setLargura(int larg){
    largura = larg;
}

TNivel1* TColisao::getNivel1(){
    return this->nivel1;
}

void TColisao::setNivel1(TNivel1 *nivel1){
    this->nivel1 = nivel1;
}

TTabuleiro* TColisao::getTabuleiro(){
    return this->tabuleiro;
}

void TColisao::setTabuleiro(TTabuleiro *tabuleiro){
    this->tabuleiro = tabuleiro;
}
