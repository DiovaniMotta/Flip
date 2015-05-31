#include <QDebug>
#include <QPoint>
#include <QException>

#ifndef TDIMENSAO
#define TDIMENSAO

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
        this->maxX = 0;
        this->maxY = 0;
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

    int getMaxX(){
        return this->maxX;
    }

    void setMaxY(int y){
        this->maxY = y;
    }

    int getMaxY(){
        return this->maxY;
    }

    QPoint* posicao(int size){
        try
        {
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
        }
        catch(QException err)
        {
            qDebug()<<err.what();
        }
        return posicao(size);
    }
    /**
     * retorna a quantidade de colunas multiplicada pelo parametro informado
     * @brief valueX
     * @param mult
     * @return
     */
    int valueX(int mult){
        return (this->maxX * mult);
    }


    /**
     * retorna a quantidade de linhas multiplicada pelo parametro informado
     * @brief valueX
     * @param mult
     * @return
     */
    int valueY(int mult){
        return (this->maxY * mult);
    }

    /**
     * retorna a relação entre o numero de colunas, multiplicado pelo numero de linhas menos o parametro
     * @brief indexY
     * @param index
     * @return
     */
    int indexY(int index){
       return (maxX * (maxY - index));
    }

    /**
     * retornar a relação entre o numero de linhas multiplicado pelo numero de colunas menos o parametro
     * @brief indexX
     * @param index
     * @return
     */
    int indexX(int index){
        return (maxY * (maxX - index));
    }

    /**
     *  verifica em que coluna está sendo iterado
     * @brief column
     * @param x
     * @return
     */
    int column(int x){
        if(x < maxX){
           return 0;
        }
        return (int) (x % maxX);
    }


    /**
     *  verifica em que linha está sendo iterado
     * @brief column
     * @param x
     * @return
     */
    int row(int x){
        if(x < maxY){
           return 0;
        }
        return (int) (x % maxY);
    }

    /**
     * @brief centerColumn retorna a coluna central do tabuleiro
     * @return
     */
    int centerColumn(){
        if((maxX % 2)){
           int retorno = (int)(maxX / 2);
           return (retorno++);
        }
        return (maxX / 2);
    }

    /**
     * @brief centerRow retorna a linha central do tabuleiro
     * @return
     */
    int centerRow(){
        if((maxY % 2)){
           int retorno = (int)(maxY / 2);
           return (retorno++);
        }
        return (maxY / 2);
    }

    int array(int linha,int coluna){
      if((linha == 0) && (coluna == 0)){
         return 0;
      }
      if(coluna == maxX){
        return (maxX * linha);
      }
      if((linha == maxY) || (coluna == 0)){
        return ((maxX * coluna) + 1);
      }
      return ((maxX * linha) + coluna);
    }
};

#endif // TDIMENSAO
