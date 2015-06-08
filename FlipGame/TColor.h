#pragma once

#ifndef TCOLOR
#define TCOLOR

#include <TPonto.h>
#include <QObject>


class TColor : public QObject {

    Q_OBJECT

public:
    TColor ();

    static void preto(TPonto* ponto);

    static void branco(TPonto* ponto);

    static void cinza(TPonto* ponto);

    static bool equals(TPonto ponto,QColor cor);
};
#endif // TCOLOR

