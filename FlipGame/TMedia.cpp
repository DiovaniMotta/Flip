#include <TMedia.h>

TMedia::TMedia(){
    bomba = new QMediaPlayer;
    tiro = new QMediaPlayer;
    //tiro->setMedia(QUrl("qrc:/sounds/sons/tiro_simples.mp3"));
    abertura = new QMediaPlayer;
    //abertura->setMedia(QUrl("qrc:/sounds/sons/abertura.mp3"));
    explosao = new QMediaPlayer;
    //explosao->setMedia(QUrl("qrc:/sounds/sons/explosao.mp3"));
    capturaTiro = new QMediaPlayer;
    //capturaTiro->setMedia(QUrl("qrc:/sounds/sons/captura_tiro_especial.mp3"));
}

TMedia::~TMedia(){
    delete tiro;
    delete bomba;
    delete abertura;
    delete capturaTiro;
    delete explosao;
}
/**
 * @brief TMedia::iniciar responsavel por iniciar a reprodução de um audio
 * @param value uma constante identificando qual será o som tocado
 */
void TMedia::iniciar(const int value){
    switch(value){
        case TMedia::ABERTURA:
            if(explosao->state() == QMediaPlayer::PlayingState){
                explosao->setPosition(0);
                explosao->stop();
            }
            if(capturaTiro->state() == QMediaPlayer::PlayingState){
                capturaTiro->setPosition(0);
                capturaTiro->stop();
            }
            if(abertura->state() == QMediaPlayer::StoppedState){
                abertura->play();
            }
            if(tiro->state() == QMediaPlayer::PlayingState){
                tiro->setPosition(0);
                tiro->stop();
            }
            break;
        case TMedia::BOMBA:
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
            if(tiro->state() == QMediaPlayer::StoppedState){
                tiro->play();
            }
            break;
        case TMedia::EXPLOSAO:
            if(explosao->state() == QMediaPlayer::StoppedState){
                explosao->play();
            }
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
            break;
        case TMedia::TIRO:
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
            if(tiro->state() == QMediaPlayer::StoppedState){
                tiro->play();
            }
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
    if(explosao->state() == QMediaPlayer::PlayingState){
        explosao->setPosition(0);
        explosao->stop();
    }
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
}
