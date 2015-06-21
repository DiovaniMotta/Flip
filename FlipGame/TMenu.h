#ifndef TMENU
#define TMENU
#include <QString>
#include <QFont>
#include <QColor>
#include <QPoint>
#include <QDebug>

#define MAPA01 "Mapa01"
#define MAPA02 "Mapa02"
#define MAPA03 "Mapa03"
#define MAPA04 "Mapa04"
#define MAPA05 "Mapa05"

#define PLAYER1_WINNER "Player 1 Winner!"
#define PLAYER2_WINNER "Player 2 Winner!"
/**
 * @brief The TMenu class classe responsavel por definir o objeto que será pintado no menu do usuário
 */
class TMenu {

    int x;
    int y;
    int w;
    int h;
    int nivel;
    QString nome;
    QFont fonte;
    QColor cor;
public:

    TMenu();

    ~TMenu();

    void setX(int x);

    void setY(int y);

    void setW(int w);

    void setH(int h);

    void setNome(QString nome);

    void setFont(QFont fonte);

    void setCor(QColor cor);

    int getX();

    int getY();

    int getW();

    int getH();

    int getNivel();

    void setNivel(int nivel);

    QString getNome();

    QFont getFont();

    QColor getCor();

    //verifica a regiao do click do mouse
    bool click(QPoint r);
};
#endif // TMENU

