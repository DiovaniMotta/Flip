#pragma once
#include <TPonto.h>

#ifndef TCOLOR
#define TCOLOR
class TColor {

public:
    TColor ();

    static void preto(TPonto* ponto);

    static void branco(TPonto* ponto);

    static void cinza(TPonto* ponto);
};
#endif // TCOLOR

