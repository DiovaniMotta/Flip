#ifndef TNIVEL2
#define TNIVEL2

#include <TPonto.h>
#include <TColor.h>
#include <TPlayer.h>

class TNivel2 {

   TPlayer* player1;
   TPlayer* player2;

  static const int DIMENSAO = 20;

protected:

  TPonto lista[20][20];

  void inicializar();

  void configurar();

public:

  TNivel2 ();

  ~TNivel2();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

  void players();

  void setPlayer1(TPlayer* player1);

  void setPlayer2(TPlayer* player2);

  TPlayer* getPlayer1();

  TPlayer* getPlayer2();

  void zerar(TPlayer* player);
};
#endif // TNIVEL2


