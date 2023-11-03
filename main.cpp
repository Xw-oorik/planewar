#include "mainwindow.h"

#include <QApplication>


//有个非常大的代码规范问题，，很多类的成员都设置的是私有，为了能拿到具体成员，并做修改
//直接用返回类型引用去操作的，，这样不安全
//正确的应该是设置set去做修改，get去拿结果就行
//而不是通过一个函数，引用去既能拿结果，也可以去做修改，功能上暂时没问题
//但是这种写法很不好，，我也懒得改了
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
