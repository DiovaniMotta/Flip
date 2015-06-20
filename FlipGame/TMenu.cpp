#include <TMenu.h>

TMenu::TMenu(){
    this->h = 0;
    this->w = 0;
    this->x = 0;
    this->y =  0;
    this->nivel = 0;
}

TMenu::~TMenu(){

}

void TMenu::setH(int h){
   this->h = h;
}

void TMenu::setW(int w){
   this->w = w;
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

int TMenu::getNivel(){
    return this->nivel;
}

void TMenu::setNivel(int nivel){
    this->nivel = nivel;
}

/**
 * @brief TMenu::click método responsável por verificar se o click feito pelo mouse se
 * foi feito na regiao onde está pintado o menu
 * @param r um objeto contendo a localização de onde houve o clicke do mouse
 * @return verdadeiro se onde houve o clique existe um menu desenhado
 */
bool TMenu::click(QPoint r){
    if(r.x() < this->x)
       return false;
    int widht = (this->x + this->w);
    if(r.x() > widht)
       return false;
    if(r.y() > this->y)
       return false;
    int height = (this->y - this->h);
    if(r.y() < height)
       return false;
    return true;
}
