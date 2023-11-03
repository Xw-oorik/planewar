#ifndef PLANEMAP_H
#define PLANEMAP_H

#include <QPixmap>

class PlaneMap
{
public:
    PlaneMap();

    void MapPoxChange();
    int GetMp1Pox(){return mp1_poxy;}
    int GetMp2Pox(){return mp2_poxy;}
    QPixmap& GetMp1(){return mp1;}
    QPixmap& GetMp2(){return mp2;}
private:
    QPixmap mp1;
    QPixmap mp2;

    int mp1_poxy;
    int mp2_poxy;

    int mp_speed_time;

};

#endif // PLANEMAP_H
