#ifndef BOBOM_H
#define BOBOM_H

#include <QVector>
#include <QPixmap>
#include <config.h>

class Bobom
{
public:
    Bobom();
    void updateinfor();
    bool& Getnotbobm(){return m_notbobm;}
    int& GetX(){return m_x;}
    int& GetY(){return m_y;}
    int& Getindex(){return m_index;}
    QVector<QPixmap>& GetBommaps(){return Bommaps;}
private:
    int m_x;
    int m_y;
    QVector<QPixmap> Bommaps;
    static int m_record;
    int m_index;//爆炸时加载的图片下标
    bool m_notbobm;//是否爆炸
};

#endif // BOBOM_H
