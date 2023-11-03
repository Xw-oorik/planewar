#include "plane.h"
#include "bullet.h"
#include "config.h"

int Plane::bullet_count=0;

Plane::Plane()
{
    m_pl.load(PlaneRec);

    //初始坐标
    px=(GAME_WIDTH-m_pl.width())*0.5;
    py=GAME_HEIGHT-m_pl.height();

    m_rect.setWidth(m_pl.width());
    m_rect.setHeight(m_pl.height());
    m_rect.moveTo(px,py);
}

void Plane::shoot()
{
    bullet_count++;
    //没有达到发射间隔
    if(bullet_count<BulletSPl){
        return ;
    }
    //达到发射间隔
    bullet_count=0;
    for(int i=0;i<BulletNum;++i)
    {
        if(bls[i].GetFree()){
            bls[i].GetFree()=false;
            bls[i].GetX()=px+m_rect.width()*0.5-20;
            bls[i].GetY()=py-25;
            break;
        }
    }
}
void Plane::setpox(int x,int y)
{
    px=x;
    py=y;
    m_rect.moveTo(px,py);
}
