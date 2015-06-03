#include <TPonto.h>

TPonto::TPonto(){

}

TPonto::TPonto(QColor corBorda,QColor corFundo){
    this->corBorda = corBorda;
    this->corFundo = corFundo;
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
