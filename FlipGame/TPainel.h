#ifndef TPAINEL
#define TPAINEL

#include <QColor>

/**
 * @brief The TPainel class responsavel por armazenar as informações que serão pintadas como painel para
 * o menu
 */
class TPainel {

    int x;
    int y;
    int w;
    int h;
    QColor cor;

public:

    TPainel();

    ~TPainel();

    void setX(int x);

    void setY(int y);

    void setW(int w);

    void setH(int h);

    void setCor(QColor cor);

    int getX();

    int getY();

    int getW();

    int getH();

    QColor getCor();
};
#endif // TPAINEL

