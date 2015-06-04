#ifndef TNIVEL1
#define TNIVEL1

#include <TColor.h>
#include <TPonto.h>

class TNivel1 {

protected:

  TPonto lista[20][20];

  void inicializar();

  void configurar();

public:

  TNivel1 ();

  TPonto nivel(int x, int y);

  void addPonto(int x, int y,TPonto ponto);

};
#endif // TNIVEL1

