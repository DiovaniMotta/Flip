#include <TMedia.h>

TMedia::TMedia(){
    bomba = new QMediaPlayer;
    tiro = new QMediaPlayer;
    tiro->setMedia(QUrl("qrc:/sounds/sons/tiro_simples.mp3"));
    abertura = new QMediaPlayer;
    abertura->setMedia(QUrl("qrc:/sounds/sons/abertura.mp3"));
    explosao = new QMediaPlayer;
    explosao->setMedia(QUrl("qrc:/sounds/sons/explosao.mp3"));
    bomba = new QMediaPlayer;
    bomba->setMedia(QUrl("qrc:/sounds/sons/bomba.mp3"));
    capturaTiro = new QMediaPlayer;
    capturaTiro->setMedia(QUrl("qrc:/sounds/sons/captura_tiro_especial.mp3"));
    colisao = new QMediaPlayer;
    colisao->setMedia(QUrl("qrc:/sounds/sons/colisao.mp3"));
}

TMedia::~TMedia(){
    delete tiro;
    delete bomba;
    delete abertura;
    delete capturaTiro;
    delete explosao;
    delete colisao;
}
/**
 * @brief TMedia::iniciar responsavel por iniciar a reprodução de um audio
 * @param value uma constante identificando qual será o som tocado
 */
void TMedia::iniciar(const int value){
    switch(value){
        case TMedia::ABERTURA:
            somAbertura();
            break;
        case TMedia::BOMBA:
            somBomba();
            break;
        case TMedia::EXPLOSAO:
            somExplosao();
            break;
        case TMedia::TIRO:
            somTiro();
            break;
        case TMedia::TIRO_ESPECIAL:
            somTiroEspecial();
            break;
        case TMedia::COLISAO:
            somColisao();
            break;
    }
}

/**
 * @brief TMedia::parar responsavel por parar a reprodução de um audio
 */
void TMedia::parar(){
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
}
/**
 * @brief TMedia::sound método responsavel por executar o som de abertura quando nenum som for executado
 */
void TMedia::sound(){
    if(explosao->state() == QMediaPlayer::PlayingState)
       return;
    if(tiro->state() == QMediaPlayer::PlayingState)
       return;
    if(abertura->state() == QMediaPlayer::PlayingState)
       return;
    if(bomba->state() == QMediaPlayer::PlayingState)
       return;
    if(capturaTiro->state() == QMediaPlayer::PlayingState)
       return;
    if(explosao->state() == QMediaPlayer::PlayingState)
       return;
    if(tiro->state() == QMediaPlayer::StoppedState)
       iniciar(TMedia::ABERTURA);
}

void TMedia::somAbertura(){
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(abertura->state() == QMediaPlayer::StoppedState){
        abertura->play();
    }
}

void TMedia::somBomba(){
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(bomba->state() == QMediaPlayer::StoppedState){
        bomba->play();
    }
}

void TMedia::somColisao(){
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(colisao->state() == QMediaPlayer::StoppedState){
        colisao->play();
    }
}

void TMedia::somExplosao(){
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(explosao->state() == QMediaPlayer::StoppedState){
        explosao->play();
    }
}

void TMedia::somTiro(){
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(capturaTiro->state() == QMediaPlayer::PlayingState){
        capturaTiro->setPosition(0);
        capturaTiro->stop();
    }
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(tiro->state() == QMediaPlayer::StoppedState){
        tiro->play();
    }
}

void TMedia::somTiroEspecial(){
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(abertura->state() == QMediaPlayer::PlayingState){
        abertura->setPosition(0);
        abertura->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
    if(colisao->state() == QMediaPlayer::PlayingState){
        colisao->setPosition(0);
        colisao->stop();
    }
    if(bomba->state() == QMediaPlayer::PlayingState){
        bomba->setPosition(0);
        bomba->stop();
    }
    if(capturaTiro->state() == QMediaPlayer::StoppedState){
        capturaTiro->play();
    }
}
