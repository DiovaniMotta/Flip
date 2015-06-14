#include <TTiro.h>

TTiro::TTiro(){
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
    this->visivel = false;
    this->ativo = false;
    this->colidiu = false;
    this->DESLOCAMENTO = 0;
}

TTiro::TTiro(int x, int y, int posX, int posY, bool visivel){
    this->x = x;
    this->y = y;
    this->posX = posX;
    this->posY = posY;
    this->visivel = visivel;
    this->ativo = false;
    this->direcao = 0;
    this->tipo = 0;
    this->count = 5;
    this->largura = 0;
    this->altura = 0;
    this->nivel = 0;
    this->colidiu = false;
    this->DESLOCAMENTO = 0;
}

TTiro::~TTiro(){

}

void TTiro::setX(int x){
    this->x = x;
}

void TTiro::setY(int y){
    this->y = y;
}

void TTiro::setPosX(int posX){
    this->posX = posX;
}

void TTiro::setPosY(int posY){
    this->posY = posY;
}

void TTiro::setVisivel(bool visivel){
    this->visivel = visivel;
}

int TTiro::getX(){
    return this->x;
}

int TTiro::getY(){
    return this->y;
}

int TTiro::getPosX(){
    return this->posX;
}

int TTiro::getPosY(){
    return this->posY;
}

bool TTiro::isVisivel(){
    return this->visivel;
}

void TTiro::setBorda(QColor borda){
    this->borda = borda;
}

void TTiro::setFundo(QColor fundo){
    this->fundo = fundo;
}

QColor TTiro::getBorda(){
    return this->borda;
}

QColor TTiro::getFundo(){
    return this->fundo;
}

void TTiro::setAtivo(bool ativo){
    this->ativo = ativo;
}

bool TTiro::isAtivo(){
    return this->ativo;
}

void TTiro::setDirecao(int direcao){
    this->direcao = direcao;
}

void TTiro::setTipo(int tipo){
    this->tipo = tipo;
}

int TTiro::getTipo(){
    return this->tipo;
}

int TTiro::getDirecao(){
    return this->direcao;
}

void TTiro::setLargura(int largura){
    this->largura = largura;
}

void TTiro::setAltura(int altura){
    this->altura = altura;
}

int TTiro::getAltura(){
    return this->altura;
}

int TTiro::getLargura(){
    return this->largura;
}

void TTiro::setNivel(int nivel){
    this->nivel = nivel;
}

int TTiro::getNivel(){
    return this->nivel;
}

void TTiro::setCorBordaJogador(QColor borda){
    this->corBordaJogador = borda;
}

void TTiro::setCorFundoJogador(QColor fundo){
    this->corFundoJogador = fundo;
}

QColor TTiro::getCorBordaJogador(){
    return this->corBordaJogador;
}

QColor TTiro::getCorFundoJogador(){
    return this->corFundoJogador;
}

bool TTiro::isColidiu(){
    return this->colidiu;
}

void TTiro::setColidiu(bool colidiu){
    this->colidiu = colidiu;
}

/**
 * @brief TBomba::deslocamento método responsavel por efetuar o calculo da variavel usada para o
 * deslocamento da bomba e atualizar as suas coordenadas x e y em relação ao tabuleiro
 * @param dimen a largura ou altura de cada objeto TPonto
 */
void TTiro::deslocamento(int dimen){
    DESLOCAMENTO = (dimen * PERCENTUAL);
    if(count == SALTO){
        switch(direcao){
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

void TTiro::reiniciar(){
    this->colidiu = true;
    this->ativo = false;
}
