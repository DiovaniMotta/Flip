#include <TTabuleiro.h>

TTabuleiro::TTabuleiro(){
    this->player1 = new TPlayer();
    this->player2 = new TPlayer();
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
    this->nivel3 = new TNivel3();
    this->nivel4 = new TNivel4();
    this->nivel5 = new TNivel5();
    this->contador = 0;
}

TTabuleiro::TTabuleiro(TPlayer* player1,TPlayer* player2){
    this->player1 = player1;
    this->player2 = player2;
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
    this->nivel3 = new TNivel3();
    this->nivel4 = new TNivel4();
    this->nivel5 = new TNivel5();
    this->contador = 0;
}

TTabuleiro::~TTabuleiro(){
    delete player1;
    delete player2;
    delete nivel1;
    delete nivel2;
    delete nivel3;
    delete nivel4;
    delete nivel5;
}

void TTabuleiro::setPlayer1(TPlayer* player1){
    this->player1 = player1;
}

TPlayer* TTabuleiro::getPlayer1(){
    return this->player1;
}

void TTabuleiro::setPlayer2(TPlayer* player2){
    this->player2 = player2;
}

TPlayer* TTabuleiro::getPlayer2(){
    return this->player2;
}

TNivel1* TTabuleiro::getNivel1(){
    return this->nivel1;
}

void TTabuleiro::setNivel1(TNivel1 *nivel){
    this->nivel1 = nivel;
}

TNivel2* TTabuleiro::getNivel2(){
    return this->nivel2;
}

void TTabuleiro::setNivel2(TNivel2 *nivel){
    this->nivel2 = nivel;
}

void TTabuleiro::setNivel3(TNivel3 *nivel){
    this->nivel3 = nivel;
}

TNivel3* TTabuleiro::getNivel3(){
    return this->nivel3;
}

void TTabuleiro::setNivel4(TNivel4 *nivel){
    this->nivel4 = nivel;
}

TNivel4* TTabuleiro::getNivel4(){
    return this->nivel4;
}

void TTabuleiro::setNivel5(TNivel5 *nivel){
    this->nivel5 = nivel;
}

TNivel5* TTabuleiro::getNivel5(){
    return this->nivel5;
}

/**
 * @brief TTabuleiro::nivel retorna o ponto que será desenhado na tela
 * @param x a posicao x iterada na matriz
 * @param y a posicao y iterada na matriz
 * @return um objeto contendo as cores de pintura da tela
 */
TPonto TTabuleiro::nivel(int x,int y){
   switch(player1->getNivel()){
        case TPlayer::NIVEL1:
            return nivel1->nivel(x,y);
        case TPlayer::NIVEL2:
            return nivel2->nivel(x,y);
        case TPlayer::NIVEL3:
            return nivel3->nivel(x,y);
        case TPlayer::NIVEL4:
            return nivel4->nivel(x,y);
        case TPlayer::NIVEL5:
            return nivel5->nivel(x,y);
   }
   return nivel(x,y);
}

void TTabuleiro::reposicionar(TPlayer *player){
    int acima =0;
    int abaixo = 0;
    int esquerda = 0;
    int direita = 0;
    switch(player->getUltimaPosicao()){
        //controla a colisao do player2
        case Qt::Key_Up:
            acima = player->getPosY() + TPlayer::SALTOS;
            player->setPosY(acima);
            break;
        case Qt::Key_Down:
            abaixo = player->getPosY() - TPlayer::SALTOS;
            player->setPosY(abaixo);
            break;
        case Qt::Key_Left:
            esquerda = player->getPosX() + TPlayer::SALTOS;
            player->setPosX(esquerda);
            break;
        case Qt::Key_Right:
            direita = player->getPosX() - TPlayer::SALTOS;
            player->setPosX(direita);
            break;
        //controla a colisao do player1
        case Qt::Key_W:
            acima = player->getPosY() + TPlayer::SALTOS;
            player->setPosY(acima);
            break;
        case Qt::Key_S:
            abaixo = player->getPosY() - TPlayer::SALTOS;
            player->setPosY(abaixo);
            break;
        case Qt::Key_A:
            esquerda = player->getPosX() + TPlayer::SALTOS;
            player->setPosX(esquerda);
            break;
        case Qt::Key_D:
            direita = player->getPosX() - TPlayer::SALTOS;
            player->setPosX(direita);
            break;
    }
}
/**
 * @brief TTabuleiro::posicionar metodo responsavel por posicionar os players de acordo
 * com a configuracao do tabuleiro feita
 * @param nivel
 */
void TTabuleiro::posicionar(const int nivel){
    switch(nivel){
        case TPlayer::NIVEL1:
          nivel1->players();
          player1 = nivel1->getPlayer1();
          player2 = nivel1->getPlayer2();
          break;
       case TPlayer::NIVEL2:
          nivel2->players();
          player1 = nivel2->getPlayer1();
          player2 = nivel2->getPlayer2();
          break;
       case TPlayer::NIVEL3:
          nivel3->players();
          player1 = nivel3->getPlayer1();
          player2 = nivel3->getPlayer2();
          break;
       case TPlayer::NIVEL4:
          nivel4->players();
          player1 = nivel4->getPlayer1();
          player2 = nivel4->getPlayer2();
          break;
       case TPlayer::NIVEL5:
          nivel5->players();
          player1 = nivel5->getPlayer1();
          player2 = nivel5->getPlayer2();
          break;
    }
}

/**
 * @brief TTabuleiro:: metodo responsavel por zerar o tabuleiro quando houver um vencededor
 * @param player o jogador derrotado
 */
void TTabuleiro::zerar(TPlayer *player){
    switch(player->getNivel()){
        case TPlayer::NIVEL1:
            nivel1->zerar(player);
            break;
        case TPlayer::NIVEL2:
            nivel2->zerar(player);
            break;
        case TPlayer::NIVEL3:
            nivel3->zerar(player);
            break;
        case TPlayer::NIVEL4:
            nivel4->zerar(player);
            break;
        case TPlayer::NIVEL5:
            nivel4->zerar(player);
            break;
    }
}

/**
 * @brief TTabuleiro::bomba retorna um objeto bomba que será pintado em algum lugar do tabuleiro
 * @return null caso não tenha sido possivel gerar o objeto bomba e diferente de nulo se foi possivel
 */
TBomba* TTabuleiro::bomba(){
    TBomba* b = NULL;
    contador++;
    qDebug()<<contador;
    if(contador >= TIMEOUT){
        int x = TUtils::randomize(TTabuleiro::DIMENSAO);
        int y = TUtils::randomize(TTabuleiro::DIMENSAO);
        bool retorno = false;
        b = new TBomba;
        TPonto ponto;
        switch(player1->getNivel()){
            case TPlayer::NIVEL1:
                ponto = nivel1->nivel(x,y);
                ponto.setX(x);
                ponto.setY(y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno){
                   return bomba();
                }
                contador = 0;
                bomba(&ponto,b);
                break;
            case TPlayer::NIVEL2:
                ponto = nivel2->nivel(x,y);
                ponto.setX(x);
                ponto.setY(y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno){
                   return bomba();
                }
                contador = 0;
                bomba(&ponto,b);
                break;
            case TPlayer::NIVEL3:
                ponto = nivel3->nivel(x,y);
                ponto.setX(x);
                ponto.setY(y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno){
                   return bomba();
                }
                contador = 0;
                bomba(&ponto,b);
                break;
            case TPlayer::NIVEL4:
                ponto = nivel4->nivel(x,y);
                ponto.setX(x);
                ponto.setY(y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno){
                   return bomba();
                }
                contador = 0;
                bomba(&ponto,b);
                break;
            case TPlayer::NIVEL5:
                ponto = nivel5->nivel(x,y);
                ponto.setX(x);
                ponto.setY(y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno){
                   qDebug()<<"é cinza";
                   return bomba();
                }
                contador = 0;
                bomba(&ponto,b);
                break;
        }
    }
    return b;
}

/**
 * @brief TTabuleiro::bomba metodo responsavel por configurar a localizacao de um
 * objeto TBomba que será pintada  na tela
 * @param ponto o ponto onde deve ser pintado o objeto bomba
 * @param bomba o objeto que será pintado no ponto
 */
void TTabuleiro::bomba(TPonto *ponto, TBomba *bomba){
    bomba->setPosX(ponto->getX());
    bomba->setPosY(ponto->getY());
    bomba->setVisivel(true);
    bomba->setBorda(Qt::red);
    bomba->setFundo(Qt::red);
}
