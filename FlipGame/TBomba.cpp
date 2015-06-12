#include <TBomba.h>

TBomba::TBomba(){
    this->x = 0;
    this->y = 0;
    this->posX = 0;
    this->posY = 0;
    this->direcao = 0;
    this->tipo = 0;
    this->count = 5;
    this->largura = 0;
    this->altura = 0;
    this->nivel = 0;
    this->x2 = 0;
    this->y2 = 0;
    this->visivel = false;
    this->ativo = true;
}

TBomba::TBomba(int x, int y, int posX, int posY, bool visivel){
    this->x = x;
    this->y = y;
    this->posX = posX;
    this->posY = posY;
    this->visivel = visivel;
    this->ativo = true;
    this->direcao = 0;
    this->tipo = 0;
    this->count = 5;
    this->largura = 0;
    this->altura = 0;
    this->nivel = 0;
    this->x2 = 0;
    this->y2 = 0;
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

void TBomba::setAtivo(bool ativo){
    this->ativo = ativo;
}

bool TBomba::isAtivo(){
    return this->ativo;
}

void TBomba::setDirecao(int direcao){
    this->direcao = direcao;
}

void TBomba::setTipo(int tipo){
    this->tipo = tipo;
}

int TBomba::getTipo(){
    return this->tipo;
}

int TBomba::getDirecao(){
    return this->direcao;
}

void TBomba::setLargura(int largura){
    this->largura = largura;
}

void TBomba::setAltura(int altura){
    this->altura = altura;
}

int TBomba::getAltura(){
    return this->altura;
}

int TBomba::getLargura(){
    return this->largura;
}

void TBomba::setNivel(int nivel){
    this->nivel = nivel;
}

int TBomba::getNivel(){
    return this->nivel;
}

void TBomba:: setPosX2(int posX2){
    this->posX2 = posX2;
}

void TBomba::setPosY2(int posY2){
    this->posY2 = posY2;
}


int TBomba::getPosX2(){
    return this->posX2;
}

int TBomba::getPosY2(){
    return this->posY2;
}

void TBomba::setX2(int x2){
    this->x2 = x2;
}

void TBomba::setY2(int y2){
    this->y2 = y2;
}


int TBomba::getX2(){
    return this->x2;
}

int TBomba::getY2(){
    return this->y2;
}

/**
 * @brief TBomba::deslocamento método responsavel por efetuar o calculo da variavel usada para o
 * deslocamento da bomba e atualizar as suas coordenadas x e y em relação ao tabuleiro
 * @param dimen a largura ou altura de cada objeto TPonto
 */
void TBomba::deslocamento(int dimen){
    DESLOCAMENTO = (dimen * PERCENTUAL);
    if(count == SALTO){
        switch(direcao){
            case Qt::Key_Up:
            case Qt::Key_W:
                this->posY--;
                this->posY2--;
                break;
            case Qt::Key_Down:
            case Qt::Key_S:
                this->posY++;
                this->posY2++;
                break;
            case Qt::Key_Left:
            case Qt::Key_A:
                this->posX--;
                this->posX2--;
                break;
            case Qt::Key_Right:
            case Qt::Key_D:
                this->posX++;
                this->posX2++;
                break;
            default:
                this->posX--;
                this->posX2--;
                break;
        }
        count = 0;
    }
    count++;
}
