#ifndef TCOLISAO
#define TCOLISAO

#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TTabuleiro.h>
#include <TProjetil.h>
#include <TBomba.h>
#include <TMedia.h>
#include <QDebug>

class TColisao {

    int largura;
    int altura;
    TTabuleiro* tabuleiro;
    TMedia* media;

public:

    TColisao ();

    TColisao(int larg, int alt);

    TColisao(TTabuleiro* tabuleiro);

    ~TColisao();

    void setLargura(int larg);

    int getLargura();

    void setAltura(int alt);

    int getAltura();

    void colisao(TPlayer* player);

    void colisao();

    void colisao(TProjetil* projetil);

    void colisao(TProjetil* projetil1,TProjetil* projetil2);

    bool colisao(TPlayer* player,TProjetil* projetil);

    void colisao(TPlayer* player,TBomba* bomba);

    void colisao(TBomba* bomba);

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

    void setMedia(TMedia* midia);

    TMedia* getMedia();

private:

    TPonto nivel(TPlayer* player);

    TPonto nivel(TProjetil* projetil);

    TPonto nivel(TBomba* bomba);

    void repintar(TProjetil* projetil,TPonto ponto);
};
#endif // TCOLISAO

