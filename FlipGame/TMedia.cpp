#include <TMedia.h>

TMedia::TMedia(){
    tiro = new QMediaPlayer;
    tiro->setMedia(QUrl("qrc:/sounds/sons/tiro_simples.mp3"));
}

TMedia::~TMedia(){
    delete tiro;
}

void TMedia::iniciar(){
   if(tiro->state() == QMediaPlayer::StoppedState){
        tiro->play();
   }
}

void TMedia::parar(){
    if(tiro->state() == QMediaPlayer::PlayingState){
        tiro->setPosition(0);
        tiro->stop();
    }
}
