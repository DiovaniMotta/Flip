#include <TPlayer.h>

TPlayer::TPlayer() {
    this->nivel = 1;
    this->posX = 0;
    this->posY = 0;
    this->ultimaPosicao = 0;
    this->largura = 0;
    this->altura = 0;
    this->ultimaPosicao = 0;
    this->bombas = new QVector<TTiro>();
    this->raios = new QVector<TTiro>();
    this->i = -1;
    this->j = -1;
    this->l = -1;
    this->indexBombas = -1;
    this->indexRaios = -1;
    this->tiros = new QVector<TProjetil>();
    for(int x=0; x<TIROS; x++){
        TProjetil projetil;
        tiros->append(projetil);
    }
}

TPlayer::~TPlayer(){
    delete raios;
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

void TPlayer::setBombas(QVector<TTiro>* b){
    this->bombas = b;
}

QVector<TTiro>* TPlayer::getBombas(){
  return this->bombas;
}

QVector<TProjetil>* TPlayer::getTiros(){
    return this->tiros;
}

void TPlayer::setTiros(QVector<TProjetil> *projeteis){
    this->tiros = projeteis;
}

void TPlayer::setRaios(QVector<TTiro> *b){
    this->raios = b;
}

QVector<TTiro>* TPlayer::getRaios(){
    return this->raios;
}

/**
 * @brief TPlayer::disparo responsavel por configurar os valores usados para o objeto projetil
 */
void TPlayer::disparo(){
    i++;
    if(i >= TIROS)
        return;
    TProjetil projetil = tiros->at(i);
    int largura = (this->largura /2);
    int altura = (this->altura/2);
    projetil.setAltura(altura);
    projetil.setAtivo(true);
    projetil.setLargura(largura);
    projetil.setUltimaPosicao(this->ultimaPosicao);
    projetil.setPosX(this->posX);
    projetil.setPosY(this->posY);
    projetil.setX(x);
    projetil.setY(y);
    projetil.setX(this->x);
    projetil.setY(this->y);
    projetil.setCorBorda(this->borda);
    projetil.setCorFundo(this->fundo);
    projetil.setNivel(this->nivel);
    tiros->replace(i,projetil);
}

/**
 * @brief TPlayer::addBomba adiciona um objeto do tipo bomba a lista de bombas do usuario
 * @param bomba o objeto a ser adicionado
 */
void TPlayer::addBomba(TTiro* bomba){
    this->l++;
    if(!bomba->isVisivel()){
       return;
    }
    TTiro b;
    b.setCorBordaJogador(this->borda);
    b.setCorFundoJogador(this->fundo);
    b.setBorda(bomba->getBorda());
    b.setFundo(bomba->getFundo());
    b.setPosX(bomba->getPosX());
    b.setPosY(bomba->getPosY());
    b.setVisivel(false);
    b.setColidiu(false);
    b.setX(bomba->getX());
    b.setY(bomba->getY());
    b.setNivel(this->nivel);
    b.setAtivo(false);
    this->bombas->insert(l,b);
    indexBombas = TControle::posicionar(bombas,indexBombas);
}

/**
 * @brief TPlayer::addRaio adiciona um objeto do tipo bomba a lista de bombas do usuario
 * @param bomba o objeto a ser adicionado
 */
void TPlayer::addRaio(TTiro* bomba){
    this->j++;
    if(!bomba->isVisivel()){
       return;
    }
    TTiro b;
    b.setCorBordaJogador(this->borda);
    b.setCorFundoJogador(this->fundo);
    b.setBorda(bomba->getBorda());
    b.setFundo(bomba->getFundo());
    b.setPosX(bomba->getPosX());
    b.setPosY(bomba->getPosY());
    b.setColidiu(false);
    b.setVisivel(false);
    b.setX(bomba->getX());
    b.setY(bomba->getY());
    b.setNivel(this->nivel);
    b.setAtivo(false);
    this->raios->insert(j,b);
    indexRaios = TControle::posicionar(raios,indexRaios);
}

/**
 * @brief TPlayer::disparo responsavel por efetuar o disparo de um tipo especial
 * @param valor uma constaten representando qual o tipo de tiro se deseja disparar
 */
void TPlayer::disparo(const int valor){
    switch(valor){
        case TTiro::RAIO:
            raio();
            break;
        case TTiro::BOMBA:
            bomba();
            break;
    }
}

/**
 * @brief TPlayer::raio responsavel por configurar o disparo especial feito pelo player
 */
void TPlayer::raio(){
    if(indexRaios < 0)
        return;
    if(indexRaios >= raios->size())
       return;
    TTiro tiro = raios->at(indexRaios);
    tiro.setAtivo(true);
    tiro.setNivel(this->nivel);
    tiro.setPosX(this->posX);
    tiro.setPosY(this->posY);
    tiro.setX(((this->posX * this->largura) + (largura/4)));
    tiro.setY(((this->posY * this->altura) + (altura/4)));
    tiro.setLargura((largura/2));
    tiro.setAltura((largura/2));
    tiro.setDirecao(ultimaPosicao);
    raios->replace(indexRaios,tiro);
    indexRaios++;
}
/**
 * @brief TPlayer::bomba responsavel por configurar o disparo especial feito pelo player
 */
void TPlayer::bomba(){
    if(indexBombas < 0)
        return;
    if(indexBombas >= bombas->size())
       return;
    TTiro tiro = bombas->at(indexBombas);
    tiro.setAtivo(true);
    tiro.setNivel(this->nivel);
    tiro.setPosX(this->posX);
    tiro.setPosY(this->posY);
    tiro.setX(((this->posX * this->largura) + (largura/4)));
    tiro.setY(((this->posY * this->altura) + (altura/4)));
    tiro.setLargura((largura/2));
    tiro.setAltura((largura/2));
    tiro.setDirecao(ultimaPosicao);
    bombas->replace(indexBombas,tiro);
    indexBombas++;
}
