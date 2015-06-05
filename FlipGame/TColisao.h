#ifndef TCOLISAO
#define TCOLISAO

#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TTabuleiro.h>
#include <TProjetil.h>

class TColisao {

    int largura;
    int altura;
    TNivel1* nivel1;
    TNivel2* nivel2;
    TNivel3* nivel3;
    TNivel4* nivel4;
    TNivel5* nivel5;
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

    TNivel1* getNivel1();

    void setNivel1(TNivel1* nivel1);

    TNivel2* getNivel2();

    void setNivel2(TNivel2* nivel2);

    TNivel3* getNivel3();

    void setNivel3(TNivel3* nivel3);

    TNivel4* getNivel4();

    void setNivel4(TNivel4* nivel4);

    TNivel5* getNivel5();

    void setNivel5(TNivel5* nivel5);

    TTabuleiro* getTabuleiro();

    void setTabuleiro(TTabuleiro* tabuleiro);

private:

    TPonto nivel(TPlayer* player);

    TPonto nivel(TProjetil* projetil);

    void repintar(TProjetil* projetil,TPonto ponto);
};
#endif // TCOLISAO

