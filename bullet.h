#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QRect>

class Bullet
{
public:
    Bullet();
    void SetPostion();
    int& GetX(){return m_x;}
    int& GetY(){return m_y;}
    QRect& GetRect(){return m_rect;}
    QPixmap& GetPixMap(){return m_bullet_res;}
    bool& GetFree(){return m_isfree;}
private:
    int m_x;
    int m_y;
    QRect m_rect;
    QPixmap m_bullet_res;
    bool m_isfree;
    const static int m_speed{5};
};

#endif // BULLET_H
