#ifndef TNIVEL1
#define TNIVEL1

#include <TColor.h>
#include <TPonto.h>
#include <TPlayer.h>

class TNivel1 {

    TPlayer* player1;
    TPlayer* player2;
    static const int DIMENSAO = 20;
protected:

  TPonto lista[DIMENSAO][DIMENSAO];

  void inicializar();

  void configurar();

public:

  TNivel1 ();

  ~TNivel1();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

  void players();

  void setPlayer1(TPlayer* player1);

  void setPlayer2(TPlayer* player2);

  TPlayer* getPlayer1();

  TPlayer* getPlayer2();

  void zerar(TPlayer* player);
};
#endif // TNIVEL1

