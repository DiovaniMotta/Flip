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
    bool fimJogo;

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

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

    void setMedia(TMedia* midia);

    TMedia* getMedia();

    bool isFimJogo();

    void setFimJogo(bool fimJogo);

    void colisao(TPlayer* player);

    void colisao();

    void colisao(TProjetil* projetil);

    void colisao(TProjetil* projetil1,TProjetil* projetil2);

    bool colisao(TPlayer* player,TProjetil* projetil);

    void colisao(TPlayer* player,TTiro* bomba,const int tipo);

    void colisao(TProjetil* projetil,TTiro* bomba,bool isNull);

    void colisao(TTiro* tiro,TTiro* bomba,bool isNull);

    void colisao(TTiro* bomba);

    void colisao(TPlayer* player,TTiro* tiro);

    void colisao(TTiro* tiro1,TTiro* tiro2);

    void colisao(TTiro* tiro1,TProjetil* projetil);

    void colisao(QVector<TTiro>* tiros,TProjetil* projetil);

    void colisao(QVector<TTiro>* tiros1,QVector<TTiro>* tiros2);

    void colisao(QVector<TTiro>* tiros,TTiro* tiro);

    void colisao(QVector<TProjetil>* tiros1,QVector<TProjetil>* tiros2);

    void colisao(QVector<TProjetil>* v, TProjetil* projetil);

    void colisao(QVector<TProjetil> * l,TTiro* tiro);
private:

    TPonto nivel(TPlayer* player);

    TPonto nivel(TProjetil* projetil);

    TPonto nivel(TTiro* bomba);

    void repintar(TProjetil* projetil,TPonto ponto);

    void repintar(TTiro* bomba,TPonto ponto);    

    void repintar(TTiro* bomba);
};
#endif // TCOLISAO

