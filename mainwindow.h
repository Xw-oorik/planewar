#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QTimer>
#include <QList>
#include "config.h"
#include "enemyplane.h"
#include "bobom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PlaneMap;
class Plane;
class Bullet;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitWindow();
    void GameStart();
    void paintEvent(QPaintEvent *);
    void Updatepox();
    void ShowEnemyPlane();
    void CollisionDetection();
protected:
    void mouseMoveEvent(QMouseEvent *);//鼠标移动
    void keyPressEvent(QKeyEvent *event);//键盘控制
signals:

public slots:

private:
    Ui::MainWindow *ui;
    PlaneMap* mp{nullptr};
    QTimer* tim{nullptr};
    Plane* plane{nullptr};
    const static int m_step{20};//自家飞机 按键,图片步长

    static int enemyplane_record;
    EnemyPlane enemyarr[EmemyNum];  //敌机数组
    Bobom bob[BomNum];              //爆炸图片数组

};
#endif // MAINWINDOW_H
