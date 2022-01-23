#include "highlightdelegate.h"
#include <QColor>
#include <QPainter>
#include "battlecell.h"

#define HIDDEN_CELL_COLOR QColor::fromRgb(50,50,50)
#define SEA_COLOR QColor::fromRgb(0,0,200)
#define SHIP_COLOR QColor::fromRgb(200,0,0)


HighlightDelegate::HighlightDelegate(QObject *parent) : QItemDelegate(parent)
{

}

void HighlightDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    //check if the Cell should be revealed.
    if ( index.model()->data(index, Qt::UserRole).toBool())
    {
        if(index.data().canConvert<BattleCell*>()) {
            BattleCell* cell_ptr = qvariant_cast<BattleCell*>(index.data());
            //color the cell according to its type.
            switch(cell_ptr->getCellType()) {
                case BattleCell::CELL_TYPE::SHIP:
                painter->fillRect(option.rect,SHIP_COLOR);
                break;
                case BattleCell::CELL_TYPE::SEA:
                painter->fillRect(option.rect,SEA_COLOR);
                break;
            }
        }
    }
}
