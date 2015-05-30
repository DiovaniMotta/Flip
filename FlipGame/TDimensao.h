#include <QDebug>
#include <QPoint>

/**
 * Classe responsavel por efetuar o calculo das posicoes dos objetos pontos
 * @brief The TDimensao class
 */
class TDimensao {

    int maxX;
    int maxY;
    int countX;
    int countY;

public:

    TDimensao () {
        this->countX = 0;
        this->countY = 0;
    }

    TDimensao (int x, int y) {
        this->maxX = x;
        this->maxY = y;
        this->countX = 0;
        this->countY = 0;
    }

    void setMaxX(int x){
        this->maxX = x;
    }

    int MaxX(){
        return this->maxX;
    }

    void setMaxY(int y){
        this->maxY = y;
    }

    int getMaxY(){
        return this->maxY;
    }

    QPoint* posicao(int size){
        QPoint* p = new QPoint;
        if(countX < maxX){
            int x = (countX * size);
            p->setX(x);
            int y = (countY * size);
            p->setY(y);
            countX++;
            return p;
        }
        countX = 0;
        if((countY + 1) < maxY){
          countY++;
        }
        return posicao(size);
    }
};
