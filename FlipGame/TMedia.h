#ifndef TMEDIA
#define TMEDIA

#include <QMediaPlayer>
#include <QObject>

class TMedia : public QObject {

    Q_OBJECT

    QMediaPlayer* tiro;
    QMediaPlayer* abertura;
    QMediaPlayer* capturaTiro;
    QMediaPlayer* bomba;
    QMediaPlayer* explosao;
    QMediaPlayer* colisao;

public:

    static const int TIRO = 0;
    static const int ABERTURA = 1;
    static const int BOMBA = 2;
    static const int EXPLOSAO = 3;
    static const int TIRO_ESPECIAL = 4;
    static const int COLISAO = 5;

    TMedia();

    ~TMedia();

    void iniciar(const int value);

    void parar();

    void sound();

private:

    void somTiro();

    void somAbertura();

    void somBomba();

    void somExplosao();

    void somTiroEspecial();

    void somColisao();

};

#endif // TMEDIA

