#ifndef TNIVEL4
#define TNIVEL4
#include <TColor.h>
#include <TPonto.h>
#include <TPlayer.h>
#include <TUtils.h>

class TNivel4 {

   TPlayer* player1;
   TPlayer* player2;

protected:

  TPonto lista[TUtils::DIMENSAO][TUtils::DIMENSAO];

  void inicializar();

  void configurar();

public:

  TNivel4 ();

  ~TNivel4();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

  void players();

  void setPlayer1(TPlayer* player1);

  void setPlayer2(TPlayer* player2);

  TPlayer* getPlayer1();

  TPlayer* getPlayer2();

  void zerar(TPlayer* player);
};
#endif // TNIVEL4

