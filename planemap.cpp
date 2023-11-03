#include "planemap.h"
#include "config.h"

PlaneMap::PlaneMap()
{
    //init
    mp1.load(PLane_MAP);
    mp2.load(PLane_MAP);
    mp1_poxy = -GAME_HEIGHT;
    mp2_poxy = 0;
    mp_speed_time=PLane_Map_Speed;
}

void PlaneMap::MapPoxChange()
{
    mp1_poxy += mp_speed_time;
    if(mp1_poxy>=0){
        mp1_poxy = -GAME_HEIGHT;
    }
    mp2_poxy += mp_speed_time;
    if(mp2_poxy>=GAME_HEIGHT){
        mp2_poxy = 0;
    }
}
