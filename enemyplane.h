#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>
#include <QRect>

class EnemyPlane
{
public:
    EnemyPlane();
    int& Getx(){return m_x;}
    int& Gety(){return m_y;}
    QRect& GetRect(){return m_rect;}
    QPixmap& GetPixmap(){return m_map;}
    bool& GetStatus(){return status;}
    void updatePostion();
private:
    int m_x;
    int m_y;
    QRect m_rect; //碰撞检测
    QPixmap m_map;
    bool status;
};

#endif // ENEMYPLANE_H
