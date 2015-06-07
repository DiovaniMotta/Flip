#include <TPonto.h>

TPonto::TPonto(){
    this->x = 0;
    this->y = 0;
}

TPonto::TPonto(QColor corBorda,QColor corFundo){
    this->corBorda = corBorda;
    this->corFundo = corFundo;
    this->x = 0;
    this->y = 0;
}

TPonto::~TPonto(){
}

void TPonto::setCorFundo(QColor corFundo){
   this->corFundo = corFundo;
}

QColor TPonto::getCorFundo(){
   return this->corFundo;
}

void TPonto::setCorBorda(QColor corBorda){
   this->corBorda = corBorda;
}

QColor TPonto::getCorBorda(){
   return this->corBorda;
}

void TPonto::setX(int x){
    this->x = x;
}

int TPonto::getX(){
    return this->x;
}

void TPonto::setY(int y){
    this->y = y;
}

int TPonto::getY(){
   return this->y;
}

void TPonto::setHeight(int height){
    this->height = height;
}

int TPonto::getHeight(){
    return this->height;
}

void TPonto::setWidht(int widht){
   this->widht = widht;
}

int TPonto::getWidht(){
    return this->widht;
}

