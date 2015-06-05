#ifndef TMEDIA
#define TMEDIA

#include <QMediaPlayer>

class TMedia {

    QMediaPlayer* tiro;

    QMediaPlayer* abertura;

    QMediaPlayer* capturaTiro;

public:

    TMedia();

    ~TMedia();

    void iniciar();

    void parar();
};

#endif // TMEDIA

