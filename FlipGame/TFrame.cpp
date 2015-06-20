#include <TFrame.h>

/**
 * @brief TFrame::TFrame construtor da classe
 */
TFrame::TFrame () {
    setMinimumSize(800,600);
    setFrameStyle(QFrame::Box);
    QString titulo("FlipGame - Programação Gráfica I - Diovani Bernardi da Motta");
    setWindowTitle(titulo);
    setLineWidth(4);
    setMouseTracking(true);
    setFocus();
    rotacao = 0;
    _w_frame = 0;
    _h_frame = 0;
    tabuleiro = new TTabuleiro;
    tabuleiro->posicionar(TPlayer::NIVEL4);
    player1 = tabuleiro->getPlayer1();
    player2 = tabuleiro->getPlayer2();
    colisao = new TColisao;
    media = new TMedia;
    colisao->setTabuleiro(tabuleiro);
    colisao->setMedia(media);
    media->iniciar(TMedia::ABERTURA);
    iniciou = false;
    _w_frame = this->width();
    _h_frame = TUtils::dimensao(width(),TUtils::CINQUENTA_POR_CENTO);
    QTimer::singleShot((TIMER/FPS),this,SLOT(iniciar()));
}

/**
 * @brief TFrame::resizeEvent evento de redimensionamento da tela
 * @param event
 */
void TFrame::resizeEvent(QResizeEvent* event){
    QFrame::resizeEvent(event);
    colisao->setLargura(this->width());
    colisao->setAltura(this->height());
    _h_sz = TUtils::dimensao(height(),TUtils::CINCO_POR_CENTO);
    _w_sz = TUtils::dimensao(width(),TUtils::CINCO_POR_CENTO);
    _w_frame = this->width();
    _h_frame = TUtils::dimensao(height(),TUtils::CINQUENTA_POR_CENTO);
    TUtils::recalcular(player1,_w_sz,_h_sz);
    redimensionar(player1);
    TUtils::recalcular(player2,_w_sz,_h_sz);
    redimensionar(player2);
    if(iniciou)
        return;
    panel = tabuleiro->painel(_w_frame,_h_frame);
    tabuleiro->menu(_w_frame,_h_frame);
}

/**
 * @brief TFrame::paintEvent evento de repintura da tela
 * @param event
 */
void TFrame::paintEvent(QPaintEvent* event){
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::HighQualityAntialiasing,true);
    for(int x=0;x <TUtils::DIMENSAO;x++){
        for(int y=0; y<TUtils::DIMENSAO; y++){
            TPonto ponto = tabuleiro->nivel(x,y);
            painter.setPen(ponto.getCorBorda());
            painter.setBrush(ponto.getCorFundo());
            painter.drawRect((x * _w_sz),(y*_h_sz),_w_sz,_h_sz);
            ponto.setX((x * _w_sz));
            ponto.setY((y*_h_sz));
            ponto.setHeight(_h_sz);
            ponto.setWidht(_w_sz);
        }
    }
    //desenho do player 1;
    painter.setPen(player1->getBorda());
    painter.setBrush(player1->getFundo());
    painter.drawRect(player1->getX(),player1->getY(),player1->getLargura(),player1->getAltura());
    this->disparo(player1,&painter);
    // desenho a municao do player 1
    this->municao(player1,&painter);
    // desenho do player 2;
    painter.setPen(player2->getBorda());
    painter.setBrush(player2->getFundo());
    painter.drawRect(player2->getX(),player2->getY(),player2->getLargura(),player2->getAltura());
    this->disparo(player2,&painter);
    // desenho a municao do player 2
    this->municao(player2,&painter);
    //verifico se existem armas para serem desenhadas no tabuleiro
    this->armas(&painter);
    this->disparo(&painter);
    if(iniciou)
       return;
    painter.setBrush(panel->getCor());
    painter.setPen(panel->getCor());
    //desenho o painel inicial
    painter.drawRect(panel->getX(),panel->getY(),panel->getW(),panel->getH());
    //desenho o menu inicial
    for(int x = 0; x < tabuleiro->getMenus()->size(); x++){
        TMenu m = tabuleiro->getMenus()->at(x);
        painter.setBrush(m.getCor());
        painter.setPen(m.getCor());
        painter.setFont(m.getFont());
        painter.drawText(m.getX(),m.getY(),m.getNome());
    }
}

/**
 * @brief TFrame::keyPressEvent evento acionado ao pressionar uma tecla do teclado
 * @param event
 */
void TFrame::keyPressEvent(QKeyEvent* event){
  QFrame::keyPressEvent(event);
  if(!iniciou)
    return;
  int acima =0;
  int abaixo = 0;
  int esquerda = 0;
  int direita = 0;
  switch(event->key()){
     //comandos de movimentação do player2
     case Qt::Key_Up:
        acima = player2->getPosY() - TPlayer::SALTOS;
        player2->setPosY(acima);
        player2->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player2);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_Down:
        abaixo = player2->getPosY() + TPlayer::SALTOS;
        player2->setPosY(abaixo);
        player2->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player2);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_Left:
        esquerda = player2->getPosX() - TPlayer::SALTOS;
        player2->setPosX(esquerda);
        player2->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player2);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_Right:
        direita = player2->getPosX() + TPlayer::SALTOS;
        player2->setPosX(direita);
        player2->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player2);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_End:
        if(!player2->isEmptyTiros())
            media->iniciar(TMedia::TIRO);
        player2->disparo();
        break;
     case Qt::Key_PageDown:
        if(!player2->isEmptyBombas())
            media->iniciar(TMedia::BOMBA);
        player2->disparo(TTiro::BOMBA);
        break;
     case Qt::Key_PageUp:
        if(!player2->isEmptyRaios())
            media->iniciar(TMedia::BOMBA);
        player2->disparo(TTiro::RAIO);
        break;
     //comandos de movimentação do player1
     case Qt::Key_W:
        acima = player1->getPosY() - TPlayer::SALTOS;
        player1->setPosY(acima);
        player1->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player1);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_S:
        abaixo = player1->getPosY() + TPlayer::SALTOS;
        player1->setPosY(abaixo);
        player1->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player1);
        //verifica a colisao entre ambos os players
        break;
     case Qt::Key_A:
        esquerda = player1->getPosX() - TPlayer::SALTOS;
        player1->setPosX(esquerda);
        player1->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player1);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_D:
        direita = player1->getPosX() + TPlayer::SALTOS;
        player1->setPosX(direita);
        player1->setUltimaPosicao(event->key());
        //verifica a colisao entre o player e o tabuleiro
        colisao->colisao(player1);
        //verifica a colisao entre ambos os players
        colisao->colisao();
        break;
     case Qt::Key_E:
        if(!player1->isEmptyTiros())
            media->iniciar(TMedia::TIRO);
        player1->disparo();
        break;
     case Qt::Key_Q:
        if(!player1->isEmptyBombas())
            media->iniciar(TMedia::BOMBA);
        player1->disparo(TTiro::BOMBA);
        break;
     case Qt::Key_Z:
        if(!player1->isEmptyRaios())
            media->iniciar(TMedia::BOMBA);
        player1->disparo(TTiro::RAIO);
        break;
    }
}

void TFrame::mousePressEvent(QMouseEvent *event){
    QFrame::mousePressEvent(event);
    if(iniciou)
      return;
    QPoint r = event->pos();
    for(int x=0; x<tabuleiro->getMenus()->size(); x++){
        TMenu m = tabuleiro->getMenus()->at(x);
        if(m.click(r)){
            tabuleiro->posicionar(m.getNivel());
            player1 = tabuleiro->getPlayer1();
            player2 = tabuleiro->getPlayer2();
            TUtils::recalcular(player1,_w_sz,_h_sz);
            redimensionar(player1);
            TUtils::recalcular(player2,_w_sz,_h_sz);
            redimensionar(player2);
            iniciou = true;
            return;
        }
    }
}

/**
 * @brief TFrame::iniciar slot tratador do evento de pintura de tela
 */
void TFrame::iniciar(){
    this->mover();
    this->disparo(player1);
    this->disparo(player2);
    media->sound();
    this->repaint();
    QTimer::singleShot((TIMER/FPS),this,SLOT(iniciar()));
}

/**
 * @brief TFrame::disparo efetua a pintura do disparo do projetil
 * @param player o jogador que efetuou o disparo
 * @param painter o objeto responsavel pela pintura na tela
 */
void TFrame::disparo(TPlayer *player,QPainter* painter){
    for(int x=0; x<TPlayer::TIROS; x++) {
        TProjetil projetil = player->getTiros()->at(x);
        //se o projetil foi disparado pelo player
        if(projetil.isAtivo()){
            painter->drawRect((projetil.getX() + (_w_sz/4)),(projetil.getY() + (_h_sz/4)),
                projetil.getLargura(),projetil.getAltura());
        }
    }
}

/**
 * @brief TFrame::colisao verifica a colisao entre o player e o projetil
 * @param player o player que será verificado
 * @param projetil o projetil
 * @param painter o objeto responsavel pela pintura
 */
void TFrame::disparo(TPlayer* player, TProjetil* projetil){
    if(projetil->isAtivo()){
        if(colisao->colisao(player,projetil)){
            tabuleiro->zerar(player);
        }
    }
}

/**
 * @brief TFrame::redimensionar metodo responsavel por verificar se é necessário redimensionar o projetil
 * @param player o jogador avaliado
 */
void TFrame::redimensionar(TPlayer *player){
    for(int x=0; x<TPlayer::TIROS;x++) {
       TProjetil projetil = player->getTiros()->at(x);
       if(projetil.isAtivo()){
           TUtils::recalcular(&projetil,_w_sz,_h_sz);
           player->getTiros()->replace(x,projetil);
       }
    }
    /*
    for(int x=0; x<player->getBombas()->size(); x++){
        TTiro tiro = player->getBombas()->at(x);
        if(tiro.isAtivo()){
            if(!tiro.isColidiu()){
                TUtils::recalcular(&tiro,_w_sz,_h_sz);
                player->getBombas()->insert(x,tiro);
            }
        }
    }
    for(int x=0; x<player->getRaios()->size(); x++){
        TTiro tiro = player->getRaios()->at(x);
        if(tiro.isAtivo()){
            if(!tiro.isColidiu()){
                TUtils::recalcular(&tiro,_w_sz,_h_sz);
                player->getRaios()->insert(x,tiro);
            }
        }
    }*/
}

/**
 * @brief TFrame::armas método responsavel por desenhar as armas adicionais que serão mostradas na tela
 * @param painter o objeto responsavel pela pintura em tela
 */
void TFrame::armas(QPainter *painter){
    if(!iniciou)
      return;
    TTiro* b = tabuleiro->bomba(raio);
    if(b != NULL)
      bomber = b;
    if(bomber != NULL){
        if(bomber->isVisivel())
        {
            painter->setPen(bomber->getBorda());
            painter->setBrush(bomber->getFundo());
            bomber->setX(((bomber->getPosX() * _w_sz) + (_w_sz /4)));
            bomber->setY(((bomber->getPosY() * _h_sz) + (_h_sz /4)));
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawEllipse((bomber->getX()),bomber->getY(),rx,ry);
        }
    }
    TTiro* t = tabuleiro->raio(bomber);
    if(t != NULL)
      raio = t;
    if(raio != NULL){
        if(raio->isVisivel())
        {
            painter->setPen(raio->getBorda());
            painter->setBrush(raio->getFundo());
            raio->setX(((raio->getPosX() * _w_sz) + (_w_sz /4)));
            raio->setY(((raio->getPosY() * _h_sz) + (_h_sz /4)));
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawRect((raio->getX()),raio->getY(),rx,ry);
        }
    }
}

/**
 * @brief TFrame::disparo responsavel por efetuar a pintura dos disparos feitos pelo usuario dos tiros especiais
 */
void TFrame::disparo(QPainter* painter){
    //pinto os projeteis especiais disparados pelo player 1
    for(int x=0; x<player1->getBombas()->size(); x++){
        TTiro bomba = player1->getBombas()->at(x);
        if(bomba.isAtivo()){
            painter->setPen(bomba.getBorda());
            painter->setBrush(bomba.getFundo());
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawEllipse((bomba.getX()),bomba.getY(),rx,ry);
        }
    }
    //pinto os projeteis especiais disparados pelo player 1
    for(int x=0; x<player1->getRaios()->size(); x++){
        TTiro bomba = player1->getRaios()->at(x);
        if(bomba.isAtivo()){
            painter->setPen(bomba.getBorda());
            painter->setBrush(bomba.getFundo());
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawRect(bomba.getX(),bomba.getY(),rx,ry);
        }
    }
    //pinto os projeteis especiais disparados peloww player 2
    for(int x=0; x<player2->getBombas()->size(); x++){
        TTiro bomba = player2->getBombas()->at(x);
        if(bomba.isAtivo()){
            painter->setPen(bomba.getBorda());
            painter->setBrush(bomba.getFundo());
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawEllipse(bomba.getX(),bomba.getY(),rx,ry);
       }
    }
    //pinto os projeteis especiais disparados peloww player 2
    for(int x=0; x<player2->getRaios()->size(); x++){
        TTiro bomba = player2->getRaios()->at(x);
        if(bomba.isAtivo()){
            painter->setPen(bomba.getBorda());
            painter->setBrush(bomba.getFundo());
            int rx = (int)(_w_sz/2);
            int ry = (int)(_h_sz/2);
            painter->drawRect(bomba.getX(),bomba.getY(),rx,ry);
       }
    }
}

/**
 * @brief TFrame::disparo metodo responsavel por verificar se os disparos especiais foram feitos pelo usuario
 * @param player o jogador que será avaliado
 */
void TFrame::disparo(TPlayer* player){
    for(int x=0; x <TPlayer::TIROS;x++){
        TProjetil projetil = player->getTiros()->at(x);
        //se o projetil foi disparado pelo player
        if(projetil.isAtivo()){
            int acima = 0;
            int abaixo = 0;
            int esqueda  = 0;
            int direita = 0;
            //verifico qual foi a ultima direção tomanda
            switch(projetil.getUltimaPosicao()){
                case Qt::Key_Up:
                case Qt::Key_W:
                    projetil.deslocamento(_h_sz);
                    acima = (projetil.getY() -  projetil.DESLOCAMENTO);
                    projetil.setY(acima);
                    break;
                case Qt::Key_Down:
                case Qt::Key_S:
                    projetil.deslocamento(_h_sz);
                    abaixo = (projetil.getY() + projetil.DESLOCAMENTO);
                    projetil.setY(abaixo);
                    break;
                case Qt::Key_Left:
                case Qt::Key_A:
                    projetil.deslocamento(_w_sz);
                    esqueda = (projetil.getX() - projetil.DESLOCAMENTO);
                    projetil.setX(esqueda);
                    break;
                case Qt::Key_Right:
                case Qt::Key_D:
                    projetil.deslocamento(_w_sz);
                    direita = (projetil.getX() + projetil.DESLOCAMENTO);
                    projetil.setX(direita);
                    break;
                default:
                    projetil.deslocamento(_h_sz);
                    esqueda = (projetil.getX() - projetil.DESLOCAMENTO);
                    projetil.setX(esqueda);
                    break;
            }
            if(projetil.getX() < 0){
                projetil.reiniciar();
            }
            if(projetil.getY() < 0){
                projetil.reiniciar();
            }
            colisao->colisao(&projetil);
            player->getTiros()->replace(x,projetil);
        }
    }
    //verifico se o player disparo alguma bomba
    for(int x=0; x< player->getBombas()->size(); x++){
        TTiro bomba = player->getBombas()->at(x);
        if(bomba.isAtivo()){
            int disparo = 0;
            switch(bomba.getDirecao()){
                case Qt::Key_Up:
                case Qt::Key_W:
                    bomba.deslocamento(_h_sz);
                    disparo = (bomba.getY() - bomba.DESLOCAMENTO);
                    bomba.setY(disparo);
                    break;
                case Qt::Key_Down:
                case Qt::Key_S:
                    bomba.deslocamento(_h_sz);
                    disparo = (bomba.getY() + bomba.DESLOCAMENTO);
                    bomba.setY(disparo);
                    break;
                case Qt::Key_Left:
                case Qt::Key_A:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() - bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
                    break;
                case Qt::Key_Right:
                case Qt::Key_D:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() + bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
                    break;
                default:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() - bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
            }
            colisao->colisao(&bomba);
            colisao->colisao(player1,&bomba);
            colisao->colisao(player2,&bomba);
            player->getBombas()->replace(x,bomba);
       }
   }
    //verifico se o player disparo alguma bomba
    for(int x=0; x< player->getRaios()->size(); x++){
        TTiro bomba = player->getRaios()->at(x);
        if(bomba.isAtivo()){
            int disparo = 0;
            switch(bomba.getDirecao()){
                case Qt::Key_Up:
                case Qt::Key_W:
                    bomba.deslocamento(_h_sz);
                    disparo = (bomba.getY() - bomba.DESLOCAMENTO);
                    bomba.setY(disparo);
                    break;
                case Qt::Key_Down:
                case Qt::Key_S:
                    bomba.deslocamento(_h_sz);
                    disparo = (bomba.getY() + bomba.DESLOCAMENTO);
                    bomba.setY(disparo);
                    break;
                case Qt::Key_Left:
                case Qt::Key_A:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() - bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
                    break;
                case Qt::Key_Right:
                case Qt::Key_D:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() + bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
                    break;
                default:
                    bomba.deslocamento(_w_sz);
                    disparo = (bomba.getX() - bomba.DESLOCAMENTO);
                    bomba.setX(disparo);
            }
            colisao->colisao(&bomba);
            colisao->colisao(player1,&bomba);
            colisao->colisao(player2,&bomba);
            player->getRaios()->replace(x,bomba);
       }
   }
}

/**
 * @brief TFrame::mover método responsável por efetuar o incremento das variaveis do jogo
 */
void TFrame::mover(){
    //atualizo as coordenadas x e y do player 1
    player1->setX((player1->getPosX() * _w_sz));
    player1->setY((player1->getPosY() * _h_sz));
    // desenho o disparo do player1
    this->disparo(player1);
    for(int x=0; x<TPlayer::TIROS; x++){
        TProjetil projetil = player2->getTiros()->at(x);
        // verifica a colisao entre o player 1 e o projetil do player 2
        this->disparo(player1,&projetil);
        colisao->colisao(&projetil,bomber,true);
        colisao->colisao(&projetil,raio,true);
        colisao->colisao(player1->getBombas(),&projetil);
        colisao->colisao(player1->getRaios(),&projetil);
        player2->getTiros()->replace(x,projetil);
    }
    // verifico se o player 1 e um objeto bomba estão na mesma posicao
    colisao->colisao(player1,bomber,TTiro::BOMBA);
    colisao->colisao(player1,raio,TTiro::RAIO);
    //atualizo as coordenadas x e y do player 2
    player2->setX((player2->getPosX() * _w_sz));
    player2->setY((player2->getPosY() * _h_sz));
    //desenho o disparo do player2
    this->disparo(player2);
    for(int x=0; x<TPlayer::TIROS; x++){
        TProjetil projetil = player1->getTiros()->at(x);
        // verifica a colisao entre o player 2 e o projetil do player 1
        this->disparo(player2,&projetil);
        colisao->colisao(&projetil,bomber,true);
        colisao->colisao(&projetil,raio,true);
        colisao->colisao(player2->getBombas(),&projetil);
        colisao->colisao(player2->getRaios(),&projetil);
        player1->getTiros()->replace(x,projetil);
    }
    for(int x=0; x<TPlayer::TIROS; x++){
        TProjetil projetil1 = player1->getTiros()->at(x);
        TProjetil projetil2 = player2->getTiros()->at(x);
        //verifico a colisao entre os projeteis
        colisao->colisao(&projetil1,&projetil2);
        player1->getTiros()->replace(x,projetil1);
        player2->getTiros()->replace(x,projetil2);
    }
    //verifico se o player 2 pegou algum tiro especial
    colisao->colisao(player2,bomber,TTiro::BOMBA);
    colisao->colisao(player2,raio,TTiro::RAIO);
    // verifico se houve colisao entre os tiros especiais disparados pelos players
    colisao->colisao(player1->getBombas(),player2->getBombas());
    colisao->colisao(player1->getRaios(),player2->getRaios());
    colisao->colisao(player1->getBombas(),player2->getRaios());
    colisao->colisao(player1->getRaios(),player2->getBombas());
    colisao->colisao(player1->getBombas(),bomber);
    colisao->colisao(player1->getBombas(),raio);
    colisao->colisao(player2->getBombas(),bomber);
    colisao->colisao(player2->getBombas(),raio);
}

/**
 * @brief TFrame::municao método responsavel por pintar no player as munições disponiveis para o
 * o usuário
 * @param player o player que terá suas munições pintadas
 * @param painter o objeto responsavel por pintar os elementos da janela
 */
void TFrame::municao(TPlayer *player, QPainter *painter){
    double raio = 0;
    double radiano  = 0;
    double rx = 0;
    double ry = 0;
    int graus = 72;
    for(int x=0; x< TPlayer::TIROS; x++){
        TProjetil projetil = player->getTiros()->at(x);
        if(projetil.isDisparou()){
            painter->setBrush(player->getFundo());
            painter->setPen(player->getFundo());
        } else {
            painter->setBrush(player->getBorda());
            painter->setPen(player->getBorda());
        }
        raio = (_h_sz / 3.5);
        radiano = (graus * (M_PI/180));
        rx = ((cos(radiano) * raio) + player->getX() + (player->getLargura()/2.5));
        ry = ((sin(radiano) * raio) + player->getY() + (player->getAltura()/2.5));
        rotacao++;
        if(rotacao > MAX)
            rotacao = 0;
        painter->drawEllipse(rx,ry,(player->getLargura()* 0.2),(player->getAltura() * 0.1));
        graus += 72;
        graus %= 370;
     }
}
