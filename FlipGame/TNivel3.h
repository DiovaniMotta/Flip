#ifndef TNIVEL3
#define TNIVEL3

#include <TColor.h>
#include <TPonto.h>
#include <TPlayer.h>

class TNivel3 {

  TPlayer* player1;
  TPlayer* player2;

  static const int DIMENSAO = 20;

protected:

  TPonto lista[20][20];

  void inicializar();

  void configurar();

public:

  TNivel3 ();

  ~TNivel3();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

  void players();

  void setPlayer1(TPlayer* player1);

  void setPlayer2(TPlayer* player2);

  TPlayer* getPlayer1();

  TPlayer* getPlayer2();

};
#endif // TNIVEL3

