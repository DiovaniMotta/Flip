#ifndef TNIVEL
#define TNIVEL

#include <TPonto.h>
#include <TColor.h>

class TNivel {

protected:

  TPonto lista[20][20];

  void inicializar();

public:
  TNivel ();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);
};
#endif // TNIVEL
