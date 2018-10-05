#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simplelist.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <vector>
#include "windows.h"
#include "movement.h"
#include <time.h>
#include <QPropertyAnimation>
#include <QThread>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    template<class T>
    void GenerateBoxes(SimpleList<T> list);
    void Swap(int pos1, int pos2);
    template<class T>
    void QuickSort(SimpleList<T> arr, int low, int high);
    template<class T>
    int partition(SimpleList<T> arr, int low, int high);
    void printmoves();
    template<class T>
    void BubbleSort(SimpleList<T> arr);
    void move();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    vector<QGraphicsRectItem*> rectangles;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *rectangle2;
    QGraphicsTextItem *text;
    QGraphicsTextItem *text2;
    vector<QGraphicsTextItem*> texts;
    QGraphicsItemAnimation *animation;
    SimpleList<int> list;
    vector<movement> movements;
    vector<movement> movementsDone;
};

#endif // MAINWINDOW_H
