#include <TProjetil.h>

TProjetil::TProjetil(){
    this->posX = 0;
    this->posY = 0;
    this->largura = 0;
    this->altura =0;
    this->x =0;
    this->y =0;
    this->ativo = false;
}

TProjetil::TProjetil(int x, int y, int posX, int posY, int largura, int altura){
    this->posX = posX;
    this->posY = posY;
    this->largura = largura;
    this->altura = altura;
    this->x = x;
    this->y = y;
    this->ativo = false;
}

TProjetil::~TProjetil(){

}

void TProjetil::setAltura(int altura){
    this->altura = altura;
}

void TProjetil::setLargura(int largura){
    this->largura = largura;
}

void TProjetil::setPosX(int posX){
    this->posX = posX;
}

void TProjetil::setPosY(int posY){
    this->posY = posY;
}

void TProjetil::setX(int x){
    this->x = x;
}

void TProjetil::setY(int y){
    this->y = y;
}

int TProjetil::getAltura(){
    return this->altura;
}

int TProjetil::getLargura(){
    return this->largura;
}

int TProjetil::getPosX(){
    return this->posX;
}

int TProjetil::getPosY(){
    return this->posY;
}

int TProjetil::getX(){
    return this->x;
}

int TProjetil::getY(){
    return this->y;
}

void TProjetil::setAtivo(bool ativo){
    this->ativo = ativo;
}

bool TProjetil::isAtivo(){
    return this->ativo;
}
