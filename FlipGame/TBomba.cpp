#include <TBomba.h>

TBomba::TBomba(){
    this->x = 0;
    this->y = 0;
    this->posX = 0;
    this->posY = 0;
    this->visivel = false;
}

TBomba::TBomba(int x, int y, int posX, int posY, bool visivel){
    this->x = x;
    this->y = y;
    this->posX = posX;
    this->posY = posY;
    this->visivel = visivel;
}

TBomba::~TBomba(){

}

void TBomba::setX(int x){
    this->x = x;
}

void TBomba::setY(int y){
    this->y = y;
}

void TBomba::setPosX(int posX){
    this->posX = posX;
}

void TBomba::setPosY(int posY){
    this->posY = posY;
}

void TBomba::setVisivel(bool visivel){
    this->visivel = visivel;
}

int TBomba::getX(){
    return this->x;
}

int TBomba::getY(){
    return this->y;
}

int TBomba::getPosX(){
    return this->posX;
}

int TBomba::getPosY(){
    return this->posY;
}

bool TBomba::isVisivel(){
    return this->visivel;
}

void TBomba::setBorda(QColor borda){
    this->borda = borda;
}

void TBomba::setFundo(QColor fundo){
    this->fundo = fundo;
}

QColor TBomba::getBorda(){
    return this->borda;
}

QColor TBomba::getFundo(){
    return this->fundo;
}
