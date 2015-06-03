#include <TPlayer.h>

TPlayer::TPlayer() {
    this->nivel = 1;
    this->posX = 0;
    this->posY = 0;
    this->ultimaPosicao = 0;
    this->largura = 0;
    this->altura = 0;
}

TPlayer::~TPlayer(){

}

int TPlayer::getNivel(){
    return this->nivel;
}

void TPlayer::setNivel(int nivel){
    this->nivel = nivel;
}

void TPlayer::setPosX(int posX){
    this->posX = posX;
}

void TPlayer::setPosY(int posY){
    this->posY = posY;
}

int TPlayer::getPosX(){
    return this->posX;
}

int TPlayer::getPosY(){
    return this ->posY;
}

void TPlayer::setUltimaPosicao(int ultima){
    this->ultimaPosicao = ultima;
}

int TPlayer::getUltimaPosicao(){
    return this->ultimaPosicao;
}

void TPlayer::setAltura(int altura){
    this->altura = altura;
}

int TPlayer::getAltura(){
    return this->altura;
}

void TPlayer::setLargura(int largura){
    this->largura = largura;
}

int TPlayer::getLargura(){
    return this->largura;
}

void TPlayer::setFundo(QColor fundo){
    this->fundo = fundo;
}

QColor TPlayer::getFundo(){
    return this->fundo;
}

void TPlayer::setBorda(QColor borda){
    this->borda = borda;
}

QColor TPlayer::getBorda(){
   return this->borda;
}

