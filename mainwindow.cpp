#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "battlemap.h"
#include <QtDebug>
#include "highlightdelegate.h"
#include "battlemapview.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //create the model and the view instances
    ui->setupUi(this);
    map = new BattleMap("test.txt",this);
    map_view = new BattleMapView(this);
    map_view->setModel(map);
    this->setFixedSize(map_view->sizeHint());
    //connecting cell click event to the model slot
    map_view->connect(map_view,&QTableView::pressed,this,&MainWindow::onCellClick);
    connect(this,&MainWindow::changeCellState,map,&BattleMap::cellClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
    delete map_view;
}


void MainWindow::onCellClick(const QModelIndex &index)
{
    qDebug() << this << "Cell Clicked (" << index.row() << index.column() << ")";
    emit changeCellState(index);
}






