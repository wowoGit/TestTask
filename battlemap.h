#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include <QAbstractTableModel>
#include <QVector>
#include <battlecell.h>


class BattleMap : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BattleMap(QString filename, QObject *parent = nullptr);
    ~BattleMap();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

private:
    int m_rows, m_cols;
    QVector<QVector<BattleCell*>> table;
signals:
    void changeCellState();
public slots:
    void cellClicked(const QModelIndex &index);
};

#endif // BATTLEMAP_H
