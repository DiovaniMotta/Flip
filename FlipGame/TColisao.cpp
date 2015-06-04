#include <TColisao.h>
#include <QDebug>

TColisao::TColisao(){
    largura = 0;
    altura = 0;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
}

TColisao::TColisao(int larg, int alt){
    largura = larg;
    altura = alt;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
}

TColisao::~TColisao(){
    delete nivel1;
    delete nivel2;
    delete tabuleiro;
}
/**
 * @brief TColisao::colisao metodo responsavel por verificar a colisao entre o player e o tabuleiro
 * @param player o objeto player que contem as informações de posicionamento
 */
void TColisao::colisao(TPlayer *player){
    TPonto ponto = this->nivel(player);
    if(ponto.getCorFundo().operator ==(Qt::gray)){
        tabuleiro->reposicionar(player);
        return;
    }
    if(ponto.getCorFundo().operator ==(player->getFundo())){
        tabuleiro->reposicionar(player);
        return;
    }
}
/**
 * @brief TColisao::nivel retorna um objeto TPonto em relação a posicao atual do player
 * @param player um objeto player contendo as informações sobre o posicionamento
 * @return um objeto TPonto contendo as informações sobre a cor usada naquele determinado ponto
 */
TPonto TColisao::nivel(TPlayer *player){
    switch(player->getNivel()){
        case TPlayer::NIVEL1:
            return nivel1->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL2:
            return nivel2->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL3:
            return nivel3->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL4:
            return nivel4->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL5:
            return nivel5->nivel(player->getPosX(),player->getPosY());
    }
    return nivel(player);
}

int TColisao::getLargura(){
    return largura;
}

void TColisao::setAltura(int alt){
    altura = alt;
}

int TColisao::getAltura(){
   return altura;
}

void TColisao::setLargura(int larg){
    largura = larg;
}

TNivel1* TColisao::getNivel1(){
    return this->nivel1;
}

void TColisao::setNivel1(TNivel1 *nivel1){
    this->nivel1 = nivel1;
}

TTabuleiro* TColisao::getTabuleiro(){
    return this->tabuleiro;
}

void TColisao::setTabuleiro(TTabuleiro *tabuleiro){
    this->tabuleiro = tabuleiro;
}
