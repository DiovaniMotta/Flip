#include <TDimensao.h>
#include <TPonto.h>
#include <TCor.h>
#include <QException>

#ifndef TNIVEL1
#define TNIVEL1

/**
 * Diovani Bernardi da Motta
 * @brief The TExtra class responsável por efetuar os calculos usados para a montagem do tabuleiro
 */
class TNivel1 {

protected:
    int tamanho;
    int metade;
    int columnMin;
    int columnMax;
    int rowMin;
    int rowMax;
    int originRowMin;
    int originColumnMin;
    TDimensao* dimensao;
    TCor* cor;

public:
    TNivel1 () {
       this->tamanho = 0;
       this->dimensao = new TDimensao;
       this->metade = (int) (tamanho / 2);
       this->cor = cor;
       this->columnMin = 0;
       this->columnMax = 0;
       this->rowMin = 0;
       this->rowMax = 0;
       this->originRowMin = 0;
       this->originColumnMin = 0;
    }

    TNivel1(TDimensao* dim){
        this->dimensao = dim;
        this->columnMin = (dimensao->centerColumn() - 3);
        this->columnMax = (dimensao->centerColumn() + 3);
        this->rowMin = (dimensao->centerRow() - 3);
        this->rowMax = (dimensao->centerRow() + 3);
        this->originRowMin = rowMin;
        this->originColumnMin = columnMin;
    }

    TNivel1(int tam){
      this->tamanho = tam;
      this->metade = (int) (tamanho / 2);
      this->cor = cor;
      this->columnMin = 0;
      this->columnMax = 0;
      this->rowMin = 0;
      this->rowMax = 0;
      this->originRowMin = 0;
      this->originColumnMin = 0;
    }

    ~TNivel1(){
        delete cor;
        delete dimensao;
    }

    void setTamanho(int tam){
        this->tamanho = tam;
        this->metade = (int) (this->tamanho / 2);
    }

    int getTamanho(){
        return this->tamanho;
    }

    void setDimensao(TDimensao* dimensao){
        this->dimensao = dimensao;
        this->columnMin = (dimensao->centerColumn() - 3);
        this->columnMax = (dimensao->centerColumn() + 3);
        this->rowMin = (dimensao->centerRow() - 3);
        this->rowMax = (dimensao->centerRow() + 3);
        this->originRowMin = rowMin;
        this->originColumnMin = columnMin;
    }

    TDimensao* getDimensao(){
        return this->dimensao;
    }

    void setCor(TCor* cor){
        this->cor = cor;
    }

    TCor* getCor(){
        return this->cor;
    }

    /**
     *
     * @brief a verifica se o indice iterado está dentro das duas primeiras linhas
     * @param index o indice iterado
     * @param ponto o objeto ponto iterado
     */
    void inicio(const int index, TPonto* ponto){
        try
        {
            if(index < dimensao->valueX(2))
            {
                ponto->setCorFundo(QColor(Qt::gray));
                ponto->setCorBorda(cor->cor(QColor(Qt::gray)));
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }
    /**
     * @brief b verifica se o indice iterado deve ser pintado de branco
     * @param index o indice iterado
     * @param ponto o objeto ponto iterado
     */
    void branco(const int index, TPonto* ponto){
        try
        {
            if((index < metade) && (index >= dimensao->valueX(2)))
            {
                int coluna = (dimensao->getMaxX() - 2);
                if((dimensao->column(index) < 2) || (dimensao->column(index) >= coluna))
                {
                    ponto->setCorFundo(QColor(Qt::gray));
                    ponto->setCorBorda(cor->cor(QColor(Qt::gray)));
                }
                else
                {
                    ponto->setCorFundo(QColor(Qt::black));
                    ponto->setCorBorda(cor->cor(QColor(Qt::black)));
                }
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    /**
     * @brief c verifica se a posicao deve ser pintada de preto
     * @param index o indice iterado
     * @param ponto o objeto iterado
     */
    void preto(const int index, TPonto* ponto){
        try
        {
            if((index >= metade) && (index < dimensao->indexY(2)))
            {
                int coluna = (dimensao->getMaxX() - 2);
                if((dimensao->column(index) < 2) || (dimensao->column(index) >= coluna))
                {
                    ponto->setCorFundo(QColor(Qt::gray));
                    ponto->setCorBorda(cor->cor(QColor(Qt::gray)));
                }
                else
                {
                    ponto->setCorFundo(QColor(Qt::white));
                    ponto->setCorBorda(cor->cor(QColor(Qt::white)));
                 }
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }

    /**
     * @brief d responsável por pintar de cinza as duas ultimas linhas do tabuleiro
     * @param index o indice iterado
     * @param ponto o objeto iterado
     */
    void fim(const int index, TPonto* ponto){
        try
        {
            if(index >= dimensao->indexY(2))
            {
                ponto->setCorFundo(QColor(Qt::gray));
                ponto->setCorBorda(cor->cor(QColor(Qt::gray)));
            }
        }
        catch(QException exception)
        {
            qDebug()<<exception.what();
        }
    }


    /**
     * @brief d responsável por pintar ao centro do tabuleiro um retangulo cinza
     * @param index o indice iterado
     * @param ponto o objeto iterado
     */
    void centro(const int index, TPonto* ponto){
       try
       {
         if(index == dimensao->array(rowMin,columnMin))
         {
             ponto->setCorFundo(QColor(Qt::gray));
             ponto->setCorBorda(cor->cor(QColor(Qt::gray)));
             if((columnMin + 1) < columnMax){
                columnMin++;
                return;
             }
             columnMin = originColumnMin;
             if((rowMin + 1) < rowMax){
                rowMin++;
                return;
             }
         }
       }
       catch(QException exception)
       {
            qDebug()<<exception.what();
       }
    }

};
#endif // TNIVEL1

