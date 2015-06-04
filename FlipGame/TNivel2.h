#ifndef TNIVEL2
#define TNIVEL2

#include <TPonto.h>
#include <TColor.h>

class TNivel2 {

protected:

  TPonto lista[20][20];

  void inicializar();

  void configurar();

public:

  TNivel2 ();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

};
#endif // TNIVEL2


