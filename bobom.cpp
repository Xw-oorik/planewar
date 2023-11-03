#include "bobom.h"

int Bobom::m_record=0;
Bobom::Bobom()
{
    //把爆炸图片先放到数组里面
    for(int i=1;i<=BomindexMax;++i)
    {
        QString str=QString(BomPath).arg(i);
        Bommaps.push_back(QPixmap(str));
    }
    m_x=0;
    m_y=0;
    m_index=0;
    m_notbobm=true;
}

void Bobom::updateinfor()
{
    if(m_notbobm){
        return;
    }
    m_record++;
    if(m_record<BomSPl){
        return ;
    }
    //到间隔时间了，该更新了
    m_record=0;//重置
    ++m_index;//下标更新

    if(m_index>BomindexMax-1){ //说明一轮图片播完了，重置到最开始的位置
        m_index=0;
        m_notbobm=true;
        return ;
    }
}
