#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH  480 //宽度
#define GAME_HEIGHT 800  //高度
#define GAME_TITLE  "飞机大战"

#define PLane_MAP ":/img/1.jpg"
#define PLane_Map_Speed 2    //地图滚动的浮动
#define Timer_time 10        //定时器刷新频率

#define PlaneRec ":/img/10.png" //飞机
#define BulletRec ":/img/13.png" //子弹

#define BulletNum 30  //子弹数量
#define BulletSPl 20  //子弹发射间隔

#define EmemyNum 20  //飞机数量
#define EmemySpeed 5
#define EmemySPl 30  //间隔
#define EmemyPath ":/img/6.png"

#define BomPath ":/img/2-%1.png"
#define BomNum 20
#define BomSPl 3
#define BomindexMax 7

#define backgroupmusic "qrc:/img/ocean.mp3"
#define bobmmusic "qrc:/img/4-1.mp3"
#endif // CONFIG_H
