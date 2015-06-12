#include <TPlayer.h>

TPlayer::TPlayer() {
    this->nivel = 1;
    this->posX = 0;
    this->posY = 0;
    this->ultimaPosicao = 0;
    this->largura = 0;
    this->altura = 0;
    this->ultimaPosicao = 0;
    this->projetil = new TProjetil;
    this->bombas = new QVector<TBomba>();
    this->i = -1;
    this->j = -1;
    this->countBomba = 0;
    this->tiros = new QVector<TProjetil>();
    for(int x=0; x<5; x++){
        TProjetil projetil;
        tiros->append(projetil);
    }
}

TPlayer::~TPlayer(){
    delete projetil;
    delete bombas;
    delete tiros;
}

int TPlayer::getNivel(){
    return this->nivel;
}

void TPlayer::setNivel(int nivel){
    this->nivel = nivel;
}

void TPlayer::setPosX(int posX){
    this->posX = posX;
}

void TPlayer::setPosY(int posY){
    this->posY = posY;
}

int TPlayer::getPosX(){
    return this->posX;
}

int TPlayer::getPosY(){
    return this ->posY;
}

void TPlayer::setUltimaPosicao(int ultima){
    this->ultimaPosicao = ultima;
}

int TPlayer::getUltimaPosicao(){
    return this->ultimaPosicao;
}

void TPlayer::setAltura(int altura){
    this->altura = altura;
}

int TPlayer::getAltura(){
    return this->altura;
}

void TPlayer::setLargura(int largura){
    this->largura = largura;
}

int TPlayer::getLargura(){
    return this->largura;
}

void TPlayer::setFundo(QColor fundo){
    this->fundo = fundo;
}

QColor TPlayer::getFundo(){
    return this->fundo;
}

void TPlayer::setBorda(QColor borda){
    this->borda = borda;
}

QColor TPlayer::getBorda(){
   return this->borda;
}

void TPlayer::setX(int x){
    this->x = x;
}

int TPlayer::getX(){
    return this->x;
}

void TPlayer::setY(int y){
    this->y = y;
}

int TPlayer::getY(){
    return this->y;
}

void TPlayer::setProjetil(TProjetil *projetil){
    this->projetil = projetil;
}

TProjetil* TPlayer::getProjetil(){
    return this->projetil;
}

void TPlayer::setBombas(QVector<TBomba>* b){
    this->bombas = b;
}

QVector<TBomba>* TPlayer::getBombas(){
  return this->bombas;
}

QVector<TProjetil>* TPlayer::getTiros(){
    return this->tiros;
}

void TPlayer::setTiros(QVector<TProjetil> *projeteis){
    this->tiros = projeteis;
}

/**
 * @brief TPlayer::disparo responsavel por configurar os valores usados para o objeto projetil
 */
void TPlayer::disparo(){
    int largura = (this->largura /2);
    int altura = (this->altura/2);
    projetil->setAltura(altura);
    projetil->setAtivo(true);
    projetil->setLargura(largura);
    projetil->setUltimaPosicao(this->ultimaPosicao);
    projetil->setPosX(this->posX);
    projetil->setPosY(this->posY);
    projetil->setX(x);
    projetil->setY(y);
    projetil->setX(this->x);
    projetil->setY(this->y);
    projetil->setCorBorda(this->borda);
    projetil->setCorFundo(this->fundo);
    projetil->setNivel(this->nivel);
}

/**
 * @brief TPlayer::addBomba adiciona um objeto do tipo bomba a lista de bombas do usuario
 * @param bomba o objeto a ser adicionado
 */
void TPlayer::addBomba(TBomba* bomba){
    this->countBomba++;
    if(!bomba->isVisivel()){
       return;
    }
    TBomba b;
    b.setFundo(this->borda);
    b.setBorda(this->fundo);
    b.setBorda(bomba->getBorda());
    b.setFundo(bomba->getFundo());
    b.setPosX(bomba->getPosX());
    b.setPosY(bomba->getPosY());
    b.setVisivel(false);
    b.setX(bomba->getX());
    b.setY(bomba->getY());
    b.setNivel(this->nivel);
    b.setAtivo(false);
    this->bombas->append(b);
}

/**
 * @brief TPlayer::disparo método responsavel por efetuar o disparo das munições especiais
 * @param tipo o tipo de disparo
 */
void TPlayer::disparo(const int tipo){
    switch(tipo){
        case TBomba::DUPLO:
            i++;
            duplo();
            break;
        case TBomba::TRIPLO:
            j++;
            triplo();
            break;
    }
}

/**
 * @brief TPlayer::duplo método responsavel por configurar um objeto  bomba que será usado pelo player
 */
void TPlayer::duplo(){
    qDebug()<<"Duplo";
    qDebug()<<i;
    qDebug()<<bombas->size();
    if(bombas->size() == 0){
        return;
    }
    if(i >= countBomba){
        return;
    }
    if(i < 0)
        return;

    TBomba b = bombas->at(i);
    int largura = (this->largura /2);
    int altura = (this->altura/2);
    b.setAltura(altura);
    b.setLargura(largura);
    b.setX(((this->posX * this->largura) + (this->largura /4)));
    b.setY(((this->posY * this->altura) + (this->altura /4)));
    b.setPosX(this->posX);
    b.setPosY(this->posY);
    switch(this->ultimaPosicao)
    {
        case Qt::Key_A:
        case Qt::Key_D:
        case Qt::Key_Left:
        case Qt::Key_Right:
            if(this->posX < (20 - 1)){
                b.setPosX2((this->posX + 1));
            }
            else
            {
                b.setPosX2((this->posX - 1));
            }
            b.setPosY2((this->posY + 1));
            break;
        case Qt::Key_W:
        case Qt::Key_S:
        case Qt::Key_Up:
        case Qt::Key_Down:
            if(this->posY < (20 - 1)){
                b.setPosY2((this->posY + 1));
            }
            else
            {
                b.setPosY2((this->posY - 1));
            }
            b.setPosX2((this->posX + 1));
            break;
    }
    b.setX2(((b.getPosX2() * this->largura) + (this->largura /4)));
    b.setY2(((b.getPosY2() * this->altura) + (this->altura /4)));
    b.setFundo(this->fundo);
    b.setBorda(this->borda);
    b.setAtivo(true);
    b.setVisivel(true);
    b.setDirecao(this->ultimaPosicao);
    b.setTipo(TBomba::DUPLO);
    bombas->insert(i,b);
}

/**
 * @brief TPlayer::duplo método responsavel por configurar um objeto  bomba que será usado pelo player
 */
void TPlayer::triplo(){

}
