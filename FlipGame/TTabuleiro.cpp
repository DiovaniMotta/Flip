#include <TTabuleiro.h>

TTabuleiro::TTabuleiro(){
    this->player1 = new TPlayer();
    this->player2 = new TPlayer();
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
    this->nivel3 = new TNivel3();
    this->nivel4 = new TNivel4();
    this->nivel5 = new TNivel5();
    this->menus = new QVector<TMenu>();
    this->contadorX = 0;
    this->contadorY = 0;
    this->INDEX = 0;
}

TTabuleiro::TTabuleiro(TPlayer* player1,TPlayer* player2){
    this->player1 = player1;
    this->player2 = player2;
    this->nivel1 = new TNivel1();
    this->nivel2 = new TNivel2();
    this->nivel3 = new TNivel3();
    this->nivel4 = new TNivel4();
    this->nivel5 = new TNivel5();
    this->menus = new QVector<TMenu>();
    this->contadorX = 0;
    this->contadorY = 0;
    this->INDEX = 0;
}

TTabuleiro::~TTabuleiro(){
    delete player1;
    delete player2;
    delete nivel1;
    delete nivel2;
    delete nivel3;
    delete nivel4;
    delete nivel5;
    delete menus;
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

QVector<TMenu>* TTabuleiro::getMenus(){
    return this->menus;
}

void TTabuleiro::setMenus(QVector<TMenu>* m){
    this->menus = m;
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
TTiro* TTabuleiro::bomba(TTiro* tiro){
    TTiro* b = NULL;
    contadorX++;
    if(contadorX >= TIMEOUT){
        int x = 0;
        int y = 0;
        if(INDEX < MAX_INDEX){
           x = TUtils::randomize(TUtils::DIMENSAO);
           y = TUtils::randomize(TUtils::DIMENSAO);
           INDEX++;
        }else {
           x = TUtils::randomize(TUtils::MEDIA_DIMENSAO);
           y = TUtils::randomize(TUtils::MEDIA_DIMENSAO);
           INDEX = 0;
        }
        bool retorno = false;
        b = new TTiro;
        TPonto ponto;
        switch(player1->getNivel()){
            case TPlayer::NIVEL1:
                ponto = nivel1->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return bomba(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return bomba(tiro);
                contadorX = 0;
                tiros(&ponto,b,TTiro::BOMBA);
                return b;
            case TPlayer::NIVEL2:
                ponto = nivel2->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return bomba(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return bomba(tiro);
                contadorX = 0;
                tiros(&ponto,b,TTiro::BOMBA);
                return b;
            case TPlayer::NIVEL3:
                ponto = nivel3->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return bomba(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return bomba(tiro);
                contadorX = 0;
                tiros(&ponto,b,TTiro::BOMBA);
                return b;
            case TPlayer::NIVEL4:
                ponto = nivel4->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return bomba(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                    return bomba(tiro);
                contadorX = 0;
                tiros(&ponto,b,TTiro::BOMBA);
                return b;
            case TPlayer::NIVEL5:
                ponto = nivel5->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return bomba(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                    return bomba(tiro);
                contadorX = 0;
                tiros(&ponto,b,TTiro::BOMBA);
                return b;
        }
    }
    return b;
}

/**
 * @brief TTabuleiro::bomba metodo responsavel por configurar a localizacao de um
 * objeto TTiro que será pintada  na tela
 * @param ponto o ponto onde deve ser pintado o objeto bomba
 * @param bomba o objeto que será pintado no ponto
 * @param uma constante identificando o tipo de tiro
 */
void TTabuleiro::tiros(TPonto *ponto, TTiro *bomba,int tipo){
    bomba->setPosX(ponto->getX());
    bomba->setPosY(ponto->getY());
    bomba->setVisivel(true);
    switch(tipo){
        case TTiro::RAIO:
            bomba->setBorda(Qt::red);
            bomba->setFundo(Qt::red);
            break;
        case TTiro::BOMBA:
            bomba->setBorda(Qt::green);
            bomba->setFundo(Qt::green);
            break;
    }
}

/**
 * @brief TTabuleiro::bomba retorna um objeto tiro que será pintado em algum lugar do tabuleiro
 * @return null caso não tenha sido possivel gerar o objeto bomba e diferente de nulo se foi possivel
 */
TTiro* TTabuleiro::raio(TTiro* tiro){
    TTiro* b = NULL;
    contadorY++;
    if(contadorY >= TIME_OUT){
        int x = TUtils::randomize(TUtils::DIMENSAO);
        int y = TUtils::randomize(TUtils::DIMENSAO);
        bool retorno = false;
        b = new TTiro;
        TPonto ponto;
        switch(player1->getNivel()){
            case TPlayer::NIVEL1:
                ponto = nivel1->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return raio(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return raio(tiro);
                contadorY = 0;
                tiros(&ponto,b,TTiro::RAIO);
                return b;
            case TPlayer::NIVEL2:
                ponto = nivel2->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return raio(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return raio(tiro);
                contadorY = 0;
                tiros(&ponto,b,TTiro::RAIO);
                return b;
            case TPlayer::NIVEL3:
                ponto = nivel3->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return raio(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return raio(tiro);
                contadorY = 0;
                tiros(&ponto,b,TTiro::RAIO);
                return b;
            case TPlayer::NIVEL4:
                ponto = nivel4->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return raio(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return raio(tiro);
                contadorY = 0;
                tiros(&ponto,b,TTiro::RAIO);
                return b;
            case TPlayer::NIVEL5:
                ponto = nivel5->nivel(x,y);
                retorno = TColor::equals(ponto,Qt::gray);
                if(retorno)
                   return raio(tiro);
                retorno = TUtils::existe(tiro,ponto);
                if(retorno)
                   return raio(tiro);
                contadorY = 0;
                tiros(&ponto,b,TTiro::RAIO);
                return b;
        }
    }
    return b;
}

/**
 * @brief TTabuleiro::menu método responsavel por retornar uma lista de objetos TMenu que serão pintados na tela
 * @param w a largura da tela
 * @param h a altura da tela
 * @return um objeto do tipo QVector contendo menus do tipo TMenu
 */
QVector<TMenu>* TTabuleiro::menu(int w, int h){
    menus->clear();
    TMenu menu1;
    TMenu menu2;
    TMenu menu3;
    TMenu menu4;
    TMenu menu5;
    QFont font;
    font.setBold(true);
    font.setPointSize(20);
    QFontMetrics metrics(font);
    menu1.setFont(font);
    menu1.setCor(Qt::black);
    menu1.setNome(QString(MAPA01));
    menu1.setX(TUtils::dimensao(w,2,50));
    menu1.setY(TUtils::dimensao(panel,1,TUtils::VINTE_POR_CENTO));
    menu1.setH(metrics.height());
    menu1.setW(metrics.maxWidth());
    menu1.setNivel(TPlayer::NIVEL1);
    menu2.setFont(font);
    menu2.setCor(Qt::black);
    menu2.setNome(QString(MAPA02));
    menu2.setX(TUtils::dimensao(w,2,50));
    menu2.setY(TUtils::dimensao(panel,2,TUtils::VINTE_POR_CENTO));
    menu2.setH(metrics.height());
    menu2.setW(metrics.maxWidth());
    menu2.setNivel(TPlayer::NIVEL2);
    menu3.setFont(font);
    menu3.setCor(Qt::black);
    menu3.setNome(QString(MAPA03));
    menu3.setX(TUtils::dimensao(w,2,50));
    menu3.setY(TUtils::dimensao(panel,3,TUtils::VINTE_POR_CENTO));
    menu3.setH(metrics.height());
    menu3.setW(metrics.maxWidth());
    menu3.setNivel(TPlayer::NIVEL3);
    menu4.setFont(font);
    menu4.setCor(Qt::black);
    menu4.setNome(QString(MAPA04));
    menu4.setX(TUtils::dimensao(w,2,50));
    menu4.setY(TUtils::dimensao(panel,4,TUtils::VINTE_POR_CENTO));
    menu4.setH(metrics.height());
    menu4.setW(metrics.maxWidth());
    menu4.setNivel(TPlayer::NIVEL4);
    menu5.setFont(font);
    menu5.setCor(Qt::black);
    menu5.setNome(QString(MAPA05));
    menu5.setX(TUtils::dimensao(w,2,50));
    menu5.setY(TUtils::dimensao(panel,5,TUtils::VINTE_POR_CENTO));
    menu5.setH(metrics.height());
    menu5.setW(metrics.maxWidth());
    menu5.setNivel(TPlayer::NIVEL5);
    menus->append(menu1);
    menus->append(menu2);
    menus->append(menu3);
    menus->append(menu4);
    menus->append(menu5);
    return menus;
}

/**
 * @brief TTabuleiro::painel método responsável por retornar um painel que será pintado na tela para a exibição
 * dos menus
 * @param w a largura da tela
 * @param h a altura da tela
 * @return um ponteiro para um objeto TPainel
 */
TPainel* TTabuleiro::painel(int w, int h){
    panel = new TPainel;
    panel->setX(0);
    panel->setY((h/2));
    panel->setH(h);
    panel->setW(w);
    panel->setCor(Qt::white);
    return panel;
}
