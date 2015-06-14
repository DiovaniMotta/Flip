#ifndef TCOLISAO
#define TCOLISAO

#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TTabuleiro.h>
#include <TProjetil.h>
#include <TTiro.h>
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

    void colisao(TPlayer* player,TTiro* bomba,const int tipo);

    void colisao(TTiro* bomba);

    void colisao(TPlayer* player,TTiro* tiro);

    void colisao(TTiro* tiro1,TTiro* tiro2);

    void colisao(TTiro* tiro1,TProjetil* projetil);

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

    void setMedia(TMedia* midia);

    TMedia* getMedia();

private:

    TPonto nivel(TPlayer* player);

    TPonto nivel(TProjetil* projetil);

    TPonto nivel(TTiro* bomba);

    void repintar(TProjetil* projetil,TPonto ponto);

    void repintar(TTiro* bomba,TPonto ponto);
};
#endif // TCOLISAO

