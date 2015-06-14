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
    delete media;
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
    if(player->getPosX() == TUtils::DIMENSAO){
        tabuleiro->reposicionar(player);
        return;
    }
    if(player->getPosY() == TUtils::DIMENSAO){
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
        media->parar();
        projetil->reiniciar();
        media->iniciar(TMedia::ABERTURA);
        return;
    }
    if(ponto.getCorFundo().operator ==(projetil->getCorFundo())){
        media->parar();
        media->iniciar(TMedia::TIRO);
        this->repintar(projetil,ponto);
        return;
    }
    if(projetil->getPosX() < 0){
        media->parar();
        media->iniciar(TMedia::ABERTURA);
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosY() < 0){
        media->parar();
        media->iniciar(TMedia::ABERTURA);
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosX() == TUtils::DIMENSAO){
        media->parar();
        media->iniciar(TMedia::ABERTURA);
        projetil->reiniciar();
        return;
    }
    if(projetil->getPosY() == TUtils::DIMENSAO){
        media->parar();
        media->iniciar(TMedia::ABERTURA);
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
 * @brief TColisao::nivel retorna um objeto TPonto em relação a posicao atual do projetil especial arremessado pelo player
 * @param bomba um objeto bomba contendo as informações sobre o posicionamento
 * @return um objeto TPonto contendo as informações sobre a cor usada naquele determinado ponto
 */
TPonto TColisao::nivel(TTiro *bomba){
    switch(bomba->getNivel()){
        case TPlayer::NIVEL1:
            return tabuleiro->getNivel1()->nivel(bomba->getPosX(),bomba->getPosY());
        case TPlayer::NIVEL2:
            return tabuleiro->getNivel2()->nivel(bomba->getPosX(),bomba->getPosY());
        case TPlayer::NIVEL3:
            return tabuleiro->getNivel3()->nivel(bomba->getPosX(),bomba->getPosY());
        case TPlayer::NIVEL4:
            return tabuleiro->getNivel4()->nivel(bomba->getPosX(),bomba->getPosY());
        case TPlayer::NIVEL5:
            return tabuleiro->getNivel5()->nivel(bomba->getPosX(),bomba->getPosY());
    }
    return nivel(bomba);
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
 * @brief TColisao::repintar responsavel por repintar um ponto da tela quando houve a colisao
 * @param bomba o objeto que colidiu
 * @param ponto o ponto da tela onde houve a colisao
 */
void TColisao::repintar(TTiro* bomba, TPonto ponto){
    ponto.setCorBorda(bomba->getCorFundoJogador());
    ponto.setCorFundo(bomba->getCorBordaJogador());
    switch(bomba->getNivel()){
        case TPlayer::NIVEL1:
            tabuleiro->getNivel1()->addPonto(bomba->getPosX(),bomba->getPosY(),ponto);
            break;
        case TPlayer::NIVEL2:
            tabuleiro->getNivel2()->addPonto(bomba->getPosX(),bomba->getPosY(),ponto);
            break;
        case TPlayer::NIVEL3:
            tabuleiro->getNivel3()->addPonto(bomba->getPosX(),bomba->getPosY(),ponto);
            break;
        case TPlayer::NIVEL4:
            tabuleiro->getNivel4()->addPonto(bomba->getPosX(),bomba->getPosY(),ponto);
            break;
        case TPlayer::NIVEL5:
            tabuleiro->getNivel5()->addPonto(bomba->getPosX(),bomba->getPosY(),ponto);
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
            media->parar();
            media->iniciar(TMedia::EXPLOSAO);
            projetil->reiniciar();
            media->parar();
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
            media->parar();
            projetil1->reiniciar();
            projetil2->reiniciar();
        }
    }
}

/**
 * @brief TColisao::colisao método responsavel por implementar a colisao entre o player e um objeto bomba
 * @param player o player avaliado
 * @param bomba o objeto bomba
 * @param tipo o tipo de objetos que será recolhido
 */
void TColisao::colisao(TPlayer *player, TTiro* bomba,const int tipo){
    if(bomba == NULL){
        return;
    }
    if(!bomba->isVisivel()){
        return;
    }
    if(player->getPosX() == bomba->getPosX()){
        if(player->getPosY() == bomba->getPosY()){
            switch(tipo){
                case TTiro::RAIO:
                    player->addRaio(bomba);
                    bomba->setVisivel(false);
                    break;
                case TTiro::BOMBA:
                    player->addBomba(bomba);
                    bomba->setVisivel(false);
                    break;
            }
        }
    }
}

/**
 * @brief TColisao::colisao método responsavel por efetuar o controle da colisao entre o projetil especial disparado
 * pelo player e o tabuleiro
 * @param bomba
 */
void TColisao::colisao(TTiro *bomba){
    if(!bomba->isAtivo())
        return;
    TPonto ponto = this->nivel(bomba);
    if(ponto.getCorFundo().operator ==(Qt::gray)){
        bomba->reiniciar();
        return;
    }
    if(bomba->getPosX() < 0){
        bomba->setAtivo(false);
        return;
    }
    if(bomba->getPosY() < 0){
        bomba->setAtivo(false);
        return;
    }
    if(bomba->getPosX() == TUtils::DIMENSAO){
        bomba->setAtivo(false);
        return;
    }
    if(bomba->getPosY() == TUtils::DIMENSAO){
        bomba->setAtivo(false);
        return;
    }
    if(ponto.getCorFundo().operator ==(bomba->getCorFundoJogador())){
        this->repintar(bomba,ponto);
        return;
    }
}

/**
 * @brief TColisao::colisao método responsavel por validar a colisao entre o tiro e o projetil disparo pelo
 * player
 * @param tiro1 o tiro especial disparado pelo player
 * @param projetil o projetil dispardo pelo player
 */
void TColisao::colisao(TTiro *tiro1, TProjetil *projetil){
    if(!tiro1->isAtivo())
        return;
    if(!projetil->isAtivo())
        return;
    if(tiro1->getPosX() == projetil->getPosX()){
        if(tiro1->getPosY() == projetil->getPosY()){
            projetil->reiniciar();
            tiro1->reiniciar();
        }
    }
}

/**
 * @brief TColisao::colisao método responsavel por verificar a colisao entre os tipos de tiros especiais
 * @param tiros1 a lista de objetos tiros contidas pelo player 1
 * @param tiros2 a lista de objetos tiros contidas pelo player 2
 */
void TColisao::colisao(QVector<TTiro> *tiros1, QVector<TTiro> *tiros2){
    if(tiros1->isEmpty())
        return;
    if(tiros2->isEmpty())
        return;
    for(int x=0; x<tiros1->size(); x++){
        TTiro tiro1 = tiros1->at(x);
        if(tiro1.isAtivo()){
            for(int y=0; y<tiros2->size();y++){
                TTiro tiro2 = tiros2->at(y);
                if(tiro2.isAtivo()){
                    this->colisao(&tiro1,&tiro2);
                    tiros2->replace(y,tiro2);
                }
             }
             tiros1->replace(x,tiro1);
        }
    }
}

/**
 * @brief TColisao::colisao método responsavel por validar a colisao entre os tiros especiais dos players
 * @param tiro1 o tiro especial dispardo pelo player1
 * @param tiro2 o tiro especial dispardo pelo player2
 */
void TColisao::colisao(TTiro *tiro1, TTiro *tiro2){
    if(!tiro1->isAtivo())
        return;
    if(!tiro2->isAtivo())
        return;
    if(tiro1->getPosX() == tiro2->getPosX()){
        if(tiro1->getPosY() == tiro2->getPosY()){
            tiro1->reiniciar();
            tiro2->reiniciar();
        }
    }
}

/**
 * @brief TColisao::colisao método responsavel por verificar a colisao entre o player e o tiro especial feito
 * pelo outro player
 * @param player o player que será verificado a colisao
 * @param tiro o tiro disparado pelo player oposto
 */
void TColisao::colisao(TPlayer *player, TTiro *tiro){
    if(player->getPosX() == tiro->getPosX()){
        if(player->getPosY() == tiro->getPosY()){
            tabuleiro->zerar(player);
            tiro->reiniciar();
        }
    }
}

void TColisao::colisao(QVector<TTiro> *tiros, TProjetil *projetil){
    for(int x=0; x<tiros->size(); x++){
        TTiro tiro = tiros->at(x);
        this->colisao(&tiro,projetil);
        tiros->replace(x,tiro);
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

void TColisao::setMedia(TMedia *midia){
    this->media = midia;
}

TMedia* TColisao::getMedia(){
    return this->media;
}
