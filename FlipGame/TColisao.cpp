#include <TColisao.h>
#include <QDebug>

TColisao::TColisao(){
    largura = 0;
    altura = 0;
}

TColisao::TColisao(int larg, int alt){
    largura = larg;
    altura = alt;
}

TColisao::~TColisao(){
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
        qDebug()<<"Colisao->";
        qDebug()<<"PosX ->";
        qDebug()<<projetil->getPosX();
        qDebug()<<"PosY ->";
        qDebug()<<projetil->getPosY();
        projetil->reiniciar();
        return;
    }
    if(ponto.getCorFundo().operator ==(projetil->getCorFundo())){
        this->repintar(projetil,ponto);
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
            return tabuleiro->getNivel1()->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL2:
            return tabuleiro->getNivel2()->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL3:
            return tabuleiro->getNivel3()->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL4:
            return tabuleiro->getNivel4()->nivel(player->getPosX(),player->getPosY());
        case TPlayer::NIVEL5:
            return tabuleiro->getNivel5()->nivel(player->getPosX(),player->getPosY());
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
            return tabuleiro->getNivel1()->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL2:
            return tabuleiro->getNivel2()->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL3:
            return tabuleiro->getNivel3()->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL4:
            return tabuleiro->getNivel4()->nivel(projetil->getPosX(),projetil->getPosY());
        case TPlayer::NIVEL5:
            return tabuleiro->getNivel5()->nivel(projetil->getPosX(),projetil->getPosY());
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
            tabuleiro->getNivel1()->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL2:
            tabuleiro->getNivel2()->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL3:
            tabuleiro->getNivel3()->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL4:
            tabuleiro->getNivel4()->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
        case TPlayer::NIVEL5:
            tabuleiro->getNivel5()->addPonto(projetil->getPosX(),projetil->getPosY(),ponto);
            break;
    }
}

/**
 * @brief TColisao::colisao verifica a colisao entre o player e o projetil
 * @param player o player que será verificado
 * @param projetil o projetil que será avalidao
 * @return um dado boleano informando sobre a colisao
 */
bool TColisao::colisao(TPlayer* player,TProjetil* projetil){
    if(player->getPosX() == projetil->getPosX()){
        if(player->getPosY() == projetil->getPosY()){
            projetil->reiniciar();
            return true;
        }
    }
    return false;
}

/**
 * @brief TColisao::colisao verifica a colisao entre os players
 */
void TColisao::colisao(){
     TPlayer* player1 = this->tabuleiro->getPlayer1();
     TPlayer* player2 = this->tabuleiro->getPlayer2();
     // reposiciona o player1 um se caso o mesmo estiver na mesma posicao que o player2
     if(player1->getPosX() == player2->getPosX()){
         if(player1->getPosY() == player2->getPosY()){
             tabuleiro->reposicionar(player1);
         }
     }
     // reposiciona o player2 um se caso o mesmo estiver na mesma posicao que o player1
     if(player2->getPosX() == player1->getPosX()){
         if(player2->getPosY() == player1->getPosY()){
             tabuleiro->reposicionar(player2);
         }
     }
}

/**
 * @brief TColisao::colisao método responsável por verificar a colisao entre os dois projetils
 * @param projetil1 o projetil disparado pelo player 1
 * @param projetil2 o projetil disparado pelo player 2
 */
void TColisao::colisao(TProjetil *projetil1, TProjetil *projetil2){
    if(!projetil1->isAtivo()){
        return;
    }
    if(!projetil2->isAtivo()){
        return;
    }
    //se houver colisao entre os projeteis
    if(projetil1->getPosX() == projetil2->getPosX()){
        if(projetil1->getPosY() == projetil2->getPosY()){
            projetil1->reiniciar();
            projetil2->reiniciar();
        }
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

TTabuleiro* TColisao::getTabuleiro(){
    return this->tabuleiro;
}

void TColisao::setTabuleiro(TTabuleiro *tabuleiro){
    this->tabuleiro = tabuleiro;
}


