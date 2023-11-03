#ifndef PLANE_H
#define PLANE_H

#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"

class Bullet;
class Plane
{
public:
    Plane();
    void shoot();
    void setpox(int x,int y);
    int& Getx(){return px;}
    int& Gety(){return py;}
    QPixmap& Getpl(){return m_pl;}
    QRect& GetRect(){return m_rect;}
    Bullet* GetBulletArr(){return bls;}
private:
    int px;
    int py;
    QRect m_rect; //碰撞的那个框
    QPixmap m_pl;
    Bullet bls[BulletNum]; //弹夹
    static int bullet_count;  //子弹发射记录
};

#endif // PLANE_H
