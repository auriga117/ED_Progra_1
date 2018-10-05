#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    SimpleList<string> *list = new SimpleList<string>();
    list->insertAtTail("teemo");
    list->insertAtTail("aatrox");
    list->insertAtTail("ashe");
    list->insertAtTail("kalista");
    list->insertAtTail("ahri");
    list->insertAtTail("akali");
    list->insertAtTail("veigar");
    list->print();
    InsertionSort(list);
    list->print();
}

template <typename T>
void MainWindow::GenerateBoxes(SimpleList<T>* list)
{
    QBrush redBrush(Qt::white);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    int size = list->getSize();
    for(int i = 0; i< size; i++)
    {
        std::string str = std::to_string(list->getPos(i)->getDato());
        QString qstr = QString::fromStdString(str);
        rectangle = scene->addRect(i*50, 0, 30, 90, outlinePen, redBrush);
        rectangles.push_back(rectangle);
        text = scene->addText(qstr, QFont("Arial",12));
        text->setPos(QPointF(i*50,-30));
        texts.push_back(text);
    }
}
void MainWindow::Swap(int pos1, int pos2)
{
    int dif = (max(pos1,pos2) - min(pos1,pos2))*50;
    QTimeLine *timer = new QTimeLine(1000);
    timer->setFrameRange(0,100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation2 = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation3 = new QGraphicsItemAnimation;
    QGraphicsItemAnimation *animation4 = new QGraphicsItemAnimation;
    rectangle = rectangles[pos1];
    rectangle2 = rectangles[pos2];
    text = texts[pos1];
    text2 = texts[pos2];
    animation->setItem(rectangle);
    animation->setTimeLine(timer);
    animation2->setItem(rectangle2);
    animation2->setTimeLine(timer);

    animation3->setItem(text);
    animation3->setTimeLine(timer);
    animation4->setItem(text2);
    animation4->setTimeLine(timer);
    timer->start();
    for (int i = 0, j = 0; i <= dif; ++i, --j)
    {
        animation->setPosAt(i/500.0, QPointF(i,0));
        animation2->setPosAt(i/500.0, QPointF(j,0));
    }
    for (int i = 0; i<=50; ++i)
    {
        animation3->setPosAt(i/500.0, QPointF(i*pos2,-30));
        animation4->setPosAt(i/500.0, QPointF(i*pos1,-30));
    }
    QGraphicsRectItem *temp = rectangle;
    rectangle = rectangle2;
    rectangle2 = temp;
    QGraphicsTextItem *temp2 = text;
    text = text2;
    text2 = temp2;
    //timer->stop();
}
MainWindow::~MainWindow()
{
    delete ui;
}



// SORTINGS ALGORITMS


/* INSERTION SORT */
template <class T>
void MainWindow::InsertionSort(SimpleList<T>* arr)
{
    int i, j;
    T actual;

    for (i = 1; i < arr->getSize(); i++) {
        actual = arr->getPos(i)->getDato();
        for (j = i; j > 0 && arr->getPos(j-1)->getDato() > actual; j--) {
            arr->getPos(j)->setDato(arr->getPos(j-1)->getDato());
        }
        arr->getPos(j)->setDato(actual);
    }
}

void MainWindow::on_btnRandonInt_clicked()
{
    srand(time(NULL)); //AGREGAR EL RANGO ALEATORIO
    int rango = 10;
    int valor;
    int sup = 1000; //limite sup que hay que ponerle un get de un spinbox
    int inf = 1; //limite inf que hay que ponerle un get de un spinbox
    for(int i = 0; i<rango;i++)
    {
        valor = rand() % sup + inf;
        list->insertAtHead(valor);
    }
    GenerateBoxes(list);
}

void MainWindow::on_btnQuick_clicked()
{
    list->print();
    //QuickSort(list,0,list->getSize()-1);
    //RadixSort(list);
    MergeSort(list, 0, list->getSize()-1);
    list->print();
}
