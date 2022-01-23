#ifndef BATTLEMAPVIEW_H
#define BATTLEMAPVIEW_H

#include <QObject>
#include <QTableView>

class BattleMapView : public QTableView
{
    Q_OBJECT
public:
    BattleMapView(QWidget *parent);
    void setModel(QAbstractItemModel* model);
};

#endif // BATTLEMAPVIEW_H
