#include <TPainel.h>

TPainel::TPainel(){
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

TPainel::~TPainel(){

}

void TPainel::setCor(QColor cor){
    this->cor = cor;
}

void TPainel::setH(int h){
   this->h = h;
}

void TPainel::setW(int w){
   this->w = w;
}

void TPainel::setX(int x){
   this->x = x;
}

void TPainel::setY(int y){
   this->y = y;
}

int TPainel::getH(){
   return this->h;
}

int TPainel::getW(){
   return this->w;
}

int TPainel::getX(){
   return this->x;
}

int TPainel::getY(){
   return this->y;
}

QColor TPainel::getCor(){
   return this->cor;
}

