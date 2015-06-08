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

public:

    static const int TIRO = 0;
    static const int ABERTURA = 1;
    static const int BOMBA = 2;
    static const int EXPLOSAO = 3;

    TMedia();

    ~TMedia();

    void iniciar(const int value);

    void parar();
};

#endif // TMEDIA

