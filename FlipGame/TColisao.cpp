#include <TColisao.h>
#include <QDebug>

TColisao::TColisao(){
    largura = 0;
    altura = 0;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
    nivel3 = new TNivel3;
    nivel4 = new TNivel4;
    nivel5 = new TNivel5;
}

TColisao::TColisao(int larg, int alt){
    largura = larg;
    altura = alt;
    nivel1 = new TNivel1;
    nivel2 = new TNivel2;
    nivel3 = new TNivel3;
    nivel4 = new TNivel4;
    nivel5 = new TNivel5;
}

TColisao::~TColisao(){
    delete nivel1;
    delete nivel2;
    delete nivel3;
    delete nivel4;
    delete nivel5;
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
    if(player->getPosX() < 0){
        tabuleiro->reposicionar(player);
        return;
    }
    if(player->getPosY() < 0){
        tabuleiro->reposicionar(player);
        return;
    }
    if(player->getPosX() == TTabuleiro::DIMENSAO){
        tabuleiro->reposicionar(player);
        return;
    }
    if(player->getPosY() == TTabuleiro::DIMENSAO){
        tabuleiro->reposicionar(player);
        return;
    }
}

/**
 * @brief TColisao::colisao metodo responsavel por verificar a colisao entre o projetil e o tabuleiro
 * @param player o objeto player que contem as informações de posicionamento
 */
void TColisao::colisao(TProjetil* projetil){
    TPonto ponto = this->nivel(projetil);
    if(ponto.getCorFundo().operator ==(Qt::gray)){
        projetil->reiniciar();
        return;
    }
    if(ponto.getCorFundo().operator ==(projetil->getCorFundo())){
        this->repintar(projetil,ponto);
        //projetil->reiniciar();
        return;
    }
    if(projetil->getPosX() < 0){
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosY() < 0){
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosX() == TTabuleiro::DIMENSAO){
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosY() == TTabuleiro::DIMENSAO){
        projetil->reiniciar();
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

/**
 * @brief TColisao::nivel retorna um objeto TPonto em relação a posicao atual do projetil
 * @param projetil um objeto projeitl contendo as informações sobre o posicionamento
 * @return um objeto TPonto contendo as informações sobre a cor usada naquele determinado ponto
 */
TPonto TColisao::nivel(TProjetil *projetil){
    switch(projetil->getNivel()){
        case TPlayer::NIVEL1:
            return nivel1->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL2:
            return nivel2->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL3:
            return nivel3->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL4:
            return nivel4->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL5:
            return nivel5->nivel(projetil->getPosX(),projetil->getPosY());
    }
    return nivel(projetil);
}

/**
 * @brief TColisao::repintar metodo responsavel por repintar um ponto da tela quando ocorrer uma colisao
 * entre o projetil e o tabuleiro
 * @param projetil
 * @param ponto
 */
void TColisao::repintar(TProjetil *projetil, TPonto ponto){
    ponto.setCorBorda(projetil->getCorFundo());
    ponto.setCorFundo(projetil->getCorBorda());
    switch(projetil->getNivel()){
        case TPlayer::NIVEL1:
            nivel1->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL2:
            nivel2->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL3:
            nivel3->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL4:
            nivel4->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL5:
            nivel5->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
    }
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

TNivel2* TColisao::getNivel2(){
    return this->nivel2;
}

void TColisao::setNivel2(TNivel2 *nivel2){
    this->nivel2 = nivel2;
}

TNivel3* TColisao::getNivel3(){
    return this->nivel3;
}

void TColisao::setNivel3(TNivel3 *nivel3){
    this->nivel3 = nivel3;
}

TNivel4* TColisao::getNivel4(){
    return this->nivel4;
}

void TColisao::setNivel4(TNivel4 *nivel4){
    this->nivel4 = nivel4;
}

TNivel5* TColisao::getNivel5(){
    return this->nivel5;
}

void TColisao::setNivel5(TNivel5 *nivel5){
    this->nivel5 = nivel5;
}

TTabuleiro* TColisao::getTabuleiro(){
    return this->tabuleiro;
}

void TColisao::setTabuleiro(TTabuleiro *tabuleiro){
    this->tabuleiro = tabuleiro;
    this->nivel1 = this->tabuleiro->getNivel1();
    this->nivel2 = this->tabuleiro->getNivel2();
    this->nivel3 = this->tabuleiro->getNivel3();
    this->nivel4 = this->tabuleiro->getNivel4();
    this->nivel5 = this->tabuleiro->getNivel5();
}


