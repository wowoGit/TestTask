#include <QtDebug>
#include <QFile>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlightdelegate.h"
#include "battlemap.h"
#include "battlemapview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QString map_name = "map.txt";
    generateMap(map_name);

    //create the model and the view instances
    map = new BattleMap(map_name,this);
    map_view = new BattleMapView(this);
    map_view->setModel(map);
    this->setFixedSize(map_view->sizeHint());


    //connecting cell click event to the model slot
    map_view->connect(map_view,&QTableView::pressed,this,&MainWindow::onCellClick);
    connect(this,&MainWindow::changeCellState,map,&BattleMap::cellClicked);
}

MainWindow::~MainWindow()
{
    delete map;
    delete map_view;
}

void MainWindow::generateMap(const QString &map_name)
{
    QFile file(map_name);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        qErrnoWarning("Could not create map!");

    if (file.canReadLine()) // if map has been created before;
        return;
    QString map;
    map.append("0011110010\n");
    map.append("1000000010\n");
    map.append("1011000010\n");
    map.append("1000000000\n");
    map.append("1000000000\n");
    map.append("0011110001\n");
    map.append("1000000011\n");
    map.append("0000000010\n");
    map.append("1111100010\n");
    map.append("0000000010\n");
    file.write(map.toStdString().c_str(),map.length());
    file.close();
}


void MainWindow::onCellClick(const QModelIndex &index)
{
    qDebug() << this << "Cell Clicked (" << index.row() << index.column() << ")";
    emit changeCellState(index);
}






