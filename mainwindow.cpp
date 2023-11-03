#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QRect>
#include <QMediaPlayer>
#include "planemap.h"
#include "plane.h"
#include "bullet.h"


int MainWindow::enemyplane_record=0;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , mp(new PlaneMap())
    , plane(new Plane())
{
    ui->setupUi(this);
    InitWindow();
    GameStart();


}
void MainWindow::InitWindow()
{
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(":/img/8.jpg"));

}

void MainWindow::GameStart()
{
    tim=new QTimer(this);
    tim->setInterval(Timer_time);
    tim->start();
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl::fromEncoded(backgroupmusic));
    player->setVolume(35);
    player->play();

    connect(tim,&QTimer::timeout,this,[&](){
        ShowEnemyPlane(); //敌机出场
        Updatepox(); //更新坐标
        update(); //画图
        CollisionDetection();//碰撞检测
    });
}
void MainWindow::Updatepox()
{
    mp->MapPoxChange();
    plane->shoot();//发射子弹
    //计算所有非空闲的子弹坐标
    for(int i=0;i<BulletNum;++i)
    {
        if(!plane->GetBulletArr()[i].GetFree()){
            plane->GetBulletArr()[i].SetPostion();//更新坐标
        }
    }
    //更新非空闲的敌机的坐标
    for(int i=0;i<EmemyNum;++i)
    {
        if(!enemyarr[i].GetStatus())
        {
            enemyarr[i].updatePostion();//更新坐标
        }
    }
    //爆炸更新
    for(int i=0;i<BomNum;++i)
    {
        if(!bob[i].Getnotbobm())
        {
            bob[i].updateinfor();
        }
    }
}

void MainWindow::ShowEnemyPlane()
{
    ++enemyplane_record;
    if(enemyplane_record<EmemySPl){
        return ;
    }
    enemyplane_record=0;
    //到达发射时间间隔
    for(int i=0;i<EmemyNum;++i)
    {
        if(enemyarr[i].GetStatus())
        {
            enemyarr[i].GetStatus()=false;
            enemyarr[i].Getx()=QRandomGenerator::global()->bounded(0,GAME_WIDTH-enemyarr[i].GetRect().width());
            enemyarr[i].Gety()=-enemyarr[i].GetRect().height();
            break;
        }
    }
}

void MainWindow::CollisionDetection()
{
    //碰撞检测
    //在运行的飞机和每一个发出去的子弹都要做对比
    for(int i=0;i<EmemyNum;++i)
    {
        if(enemyarr[i].GetStatus()){
            continue;
        }
        for(int j=0;j<BulletNum;++j)
        {
            if(plane->GetBulletArr()[j].GetFree())
            {
                continue;
            }
            if(enemyarr[i].GetRect().intersects(plane->GetBulletArr()[j].GetRect()))
            {
                enemyarr[i].GetStatus()=true;
                plane->GetBulletArr()[j].GetFree()=true;
                //播放爆炸效果
                for(int k=0;k<BomNum;++k)
                {
                    if(bob[k].Getnotbobm()){
                        QMediaPlayer * player = new QMediaPlayer;
                        player->setMedia(QUrl::fromEncoded(bobmmusic));
                        player->setVolume(15);
                        player->play();
                        bob[k].Getnotbobm()=false;
                        bob[k].GetX()=enemyarr[i].Getx();
                        bob[k].GetY()=enemyarr[i].Gety();
                        break;
                    }
                }
            }
        }
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int m_x=event->x()-plane->GetRect().width()*0.5;
    int m_y=event->y()-plane->GetRect().height()*0.5;
    //边界控制
    if(m_x<=0){
        m_x=0;
    }
    else if(m_x>=GAME_WIDTH-plane->GetRect().width()){
        m_x=GAME_WIDTH-plane->GetRect().width();
    }
    if(m_y<=0){
        m_y=0;
    }
    else if(m_y>=GAME_HEIGHT-plane->GetRect().height()){
        m_y=GAME_HEIGHT-plane->GetRect().height();
    }
    plane->setpox(m_x,m_y);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int m_x=plane->Getx();
    int m_y=plane->Gety();
    switch (event->key()) {
    case Qt::Key_Up:
        m_y=(m_y-m_step)<=0?0:m_y-m_step;
        break;
    case Qt::Key_Down:
        m_y=(m_y+m_step+plane->GetRect().height())>=GAME_HEIGHT?GAME_HEIGHT-plane->GetRect().height():m_y+m_step;
        break;
    case Qt::Key_Left:
        m_x=m_x-m_step<=0?0:m_x-m_step;
        break;
    case Qt::Key_Right:
        m_x=m_x+m_step+plane->GetRect().width()>=GAME_WIDTH?GAME_WIDTH-plane->GetRect().width():m_x+m_step;
        break;
    }
    plane->setpox(m_x,m_y);
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    //画地图
    painter.drawPixmap(0,mp->GetMp1Pox(),mp->GetMp1());
    painter.drawPixmap(0,mp->GetMp2Pox(),mp->GetMp2());
    //画飞机
    painter.drawPixmap(plane->Getx(),plane->Gety(),plane->Getpl());
    //画子弹
    for(int i=0;i<BulletNum;++i){
        if(!plane->GetBulletArr()[i].GetFree()){
            painter.drawPixmap(plane->GetBulletArr()[i].GetX(),plane->GetBulletArr()[i].GetY(),plane->GetBulletArr()[i].GetPixMap());
        }
    }
    //画敌机
    for(int i=0;i<EmemyNum;++i){
        if(!enemyarr[i].GetStatus()){
            painter.drawPixmap(enemyarr[i].Getx(),enemyarr[i].Gety(),enemyarr[i].GetPixmap());
        }
    }
    //画爆炸
    for(int i=0;i<BomNum;++i)
    {
        if(!bob[i].Getnotbobm())
        {
            painter.drawPixmap(bob[i].GetX(),bob[i].GetY(),bob[i].GetBommaps()[bob[i].Getindex()]);
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
    delete plane;
    delete mp;
    delete tim;
}

