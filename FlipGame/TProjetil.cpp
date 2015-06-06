#include <TProjetil.h>

TProjetil::TProjetil(){
    this->posX = 0;
    this->posY = 0;
    this->largura = 0;
    this->altura =0;
    this->x =0;
    this->y =0;
    this->count = 0;
    this->ultimaPosicao = 0;
    this->ativo = false;
}

TProjetil::TProjetil(int x, int y, int posX, int posY, int largura, int altura){
    this->posX = posX;
    this->posY = posY;
    this->largura = largura;
    this->altura = altura;
    this->x = x;
    this->y = y;
    this->count = 0;
    this->ultimaPosicao = 0;
    this->ativo = false;
}

TProjetil::~TProjetil(){

}

void TProjetil::reiniciar(){
    this->posX = -1;
    this->posY = -1;
    this->largura = 0;
    this->altura =0;
    this->x =0;
    this->y =0;
    this->count = 0;
    this->ultimaPosicao = 0;
    this->ativo = false;
}

/**
 * @brief TProjetil::deslocamento método responsavel por efetuar o calculo da variavel usada para o
 * deslocamento do projetil e atualizar as suas coordenadas x e y em relação ao tabuleiro
 * @param dimen a largura ou altura de cada objeto TPonto
 */
void TProjetil::deslocamento(int dimen){
    DESLOCAMENTO = (dimen * PERCENTUAL_DESLOCAMENTO);
    if(count == SALTOS){
        switch(ultimaPosicao){
            case Qt::Key_Up:
            case Qt::Key_W:
                this->posY--;
                break;
            case Qt::Key_Down:
            case Qt::Key_S:
                this->posY++;
                break;
            case Qt::Key_Left:
            case Qt::Key_A:
                this->posX--;
                break;
            case Qt::Key_Right:
            case Qt::Key_D:
                this->posX++;
                break;
            default:
                this->posX--;
                break;
        }
        count = 0;
    }
    count++;
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

void TProjetil::setCorBorda(QColor borda){
   this->borda = borda;
}

void TProjetil::setCorFundo(QColor fundo){
    this->corFundo = fundo;
}

QColor TProjetil::getCorBorda(){
    return this->borda;
}

QColor TProjetil::getCorFundo(){
    return this->corFundo;
}

void TProjetil::setUltimaPosicao(int ultimaPosicao){
    this->ultimaPosicao = ultimaPosicao;
}

int TProjetil::getUltimaPosicao(){
    return this->ultimaPosicao;
}

void TProjetil::setNivel(int nivel){
    this->nivel = nivel;
}

int TProjetil::getNivel(){
    return this->nivel;
}
