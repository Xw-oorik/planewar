#include "enemyplane.h"
#include "config.h"

EnemyPlane::EnemyPlane()
{
    m_map.load(EmemyPath);

    m_x=0;
    m_y=0;
    m_rect.setWidth(m_map.width());
    m_rect.setHeight(m_map.height());
    m_rect.moveTo(m_x,m_y);
    status=true;
}

void EnemyPlane::updatePostion()
{
    //空闲
    if(status){
        return ;
    }
    m_y+=EmemySpeed; //敌机坐标改变
    m_rect.moveTo(m_x,m_y);
    if(m_y>=GAME_HEIGHT){//超出屏幕，重置
        status=true;
    }
}
