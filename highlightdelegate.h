#ifndef HIGHLIGHTDELEGATE_H
#define HIGHLIGHTDELEGATE_H
#include <QItemDelegate>

class HighlightDelegate : public QItemDelegate
{
public:
    HighlightDelegate(QObject *parent);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // HIGHLIGHTDELEGATE_H
