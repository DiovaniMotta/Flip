#ifndef TCOLISAO
#define TCOLISAO

#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TTabuleiro.h>
#include <TProjetil.h>
#include <QDebug>

class TColisao {

    int largura;
    int altura;
    TTabuleiro* tabuleiro;

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

    void colisao(TProjetil* projetil);

    void colisao(TProjetil* projetil1,TProjetil* projetil2);

    bool colisao(TPlayer* player,TProjetil* projetil);

    void colisao();

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

private:

    TPonto nivel(TPlayer* player);

    TPonto nivel(TProjetil* projetil);

    void repintar(TProjetil* projetil,TPonto ponto);
};
#endif // TCOLISAO

