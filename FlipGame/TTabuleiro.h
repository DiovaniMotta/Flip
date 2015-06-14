#ifndef TTABULEIRO
#define TTABULEIRO

#include <TPonto.h>
#include <TPlayer.h>
#include <TNivel1.h>
#include <TNivel2.h>
#include <TNivel3.h>
#include <TNivel4.h>
#include <TNivel5.h>
#include <QKeyEvent>
#include <TUtils.h>
#include <TColor.h>
#include <TUtils.h>

#define TIMEOUT 200
#define TIME_OUT 800
/**
 * Author : Diovani Bernardi da Motta
 * @brief The TTabuleiro class classe responsável por montar as informações que serão exibidas para o usuario em forma de
 * tabuleiro
 */
class TTabuleiro {

   TPlayer* player1;
   TPlayer* player2;
   TNivel1* nivel1;
   TNivel2* nivel2;
   TNivel3* nivel3;
   TNivel4* nivel4;
   TNivel5* nivel5;
   int contadorX;
   int contadorY;
public:

    TTabuleiro();

    TTabuleiro(TPlayer* player1,TPlayer* player2);

    ~TTabuleiro();

    void setPlayer1(TPlayer* player1);

    TPlayer* getPlayer1();

    void setPlayer2(TPlayer* player2);

    TPlayer* getPlayer2();

    TPonto nivel(int x,int y);

    TNivel1* getNivel1();

    void setNivel1(TNivel1* nivel);

    TNivel2* getNivel2();

    void setNivel2(TNivel2* nivel);

    void setNivel3(TNivel3* nivel);

    TNivel3* getNivel3();

    void setNivel4(TNivel4* nivel);

    TNivel4* getNivel4();

    void setNivel5(TNivel5* nivel);

    TNivel5* getNivel5();

    void reposicionar(TPlayer* player1);

    void posicionar(const int nivel);

    void zerar(TPlayer* player);

    TTiro* bomba(TTiro* tiro);

    TTiro* raio(TTiro* tiro);

private:

    void tiros(TPonto* ponto,TTiro* bomba,int tipo);
};
#endif // TTABULEIRO
