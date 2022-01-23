#include "battlemapview.h"
#include "highlightdelegate.h"
#include <QHeaderView>

BattleMapView::BattleMapView(QWidget *parent) : QTableView(parent)
{

    this->setItemDelegate(new HighlightDelegate(this));

    this->horizontalHeader()->setDefaultSectionSize(50);
    this->verticalHeader()->setDefaultSectionSize(50);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->setSelectionMode(QAbstractItemView::NoSelection);
}

void BattleMapView::setModel(QAbstractItemModel *model)
{
    // set model source and resize the view.
    this->QTableView::setModel(model);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    this->adjustSize();
}
