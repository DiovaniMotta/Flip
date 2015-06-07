#ifndef TBOMBA
#define TBOMBA

#include <QColor>

class TBomba {

    int x;
    int y;
    int posX;
    int posY;
    bool visivel;
    QColor fundo;
    QColor borda;

public:

    TBomba ();

    TBomba(int x, int y, int posX, int posY,bool visivel);

    ~TBomba();

    void setX(int x);

    void setY(int y);

    void setPosX(int posX);

    void setPosY(int posY);

    void setVisivel(bool visivel);

   int getX();

   int getY();

   int getPosX();

   int getPosY();

   bool isVisivel();

   void setFundo(QColor fundo);

   void setBorda(QColor borda);

   QColor getFundo();

   QColor getBorda();

};
#endif // TBOMBA

