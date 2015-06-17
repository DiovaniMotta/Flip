#include <TMenu.h>

TMenu::TMenu(){
    this->h = 0;
    this->w = 0;
    this->x = 0;
    this->y =  0;
}

TMenu::~TMenu(){

}

void TMenu::setH(int h){
   this->h = h;
}

void TMenu::setW(int w){
   this->y = y;
}

void TMenu::setX(int x){
    this->x = x;
}

void TMenu::setY(int y){
    this->y = y;
}

int TMenu::getH(){
   return this->h;
}

int TMenu::getW(){
    return this->w;
}

int TMenu::getX(){
   return this->x;
}

int TMenu::getY(){
   return this->y;
}

void TMenu::setFont(QFont fonte){
    this->fonte = fonte;
}

void TMenu::setNome(QString nome){
    this->nome = nome;
}

QString TMenu::getNome(){
    return this->nome;
}

QFont TMenu::getFont(){
    return this->fonte;
}

QColor TMenu::getCor(){
    return this->cor;
}

void TMenu::setCor(QColor cor){
   this->cor = cor;
}
