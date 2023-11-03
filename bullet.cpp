#include "bullet.h"
#include "config.h"


Bullet::Bullet()
{
    m_bullet_res.load(BulletRec);
    m_x=(GAME_WIDTH-m_bullet_res.width())*0.5;
    m_y=GAME_HEIGHT;
    m_rect.setWidth(m_bullet_res.width());
    m_rect.setHeight(m_bullet_res.height());
    m_rect.moveTo(m_x,m_y);
    m_isfree=true;

}

void Bullet::SetPostion()
{
    if(m_isfree==true){
        return ;
    }
    else{
        m_y-=m_speed;
        m_rect.moveTo(m_x,m_y);
        if(m_y<=-m_bullet_res.height()){
            m_isfree=true;
        }
    }
}
