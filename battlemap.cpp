#include "battlemap.h"
#include <QBrush>
#include <QDebug>
#include <QFile>

BattleMap::BattleMap(const QString &filename, QObject *parent)
    :  QAbstractTableModel(parent)
{
    QFile file(filename);
    m_rows = m_cols = 0;
    //read the file and populate the table
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while (!in.atEnd()) {
        QVector<BattleCell*> tmp;
        QString line = in.readLine();
        m_cols = line.length();
        for(const auto ch : line)
        {
            if (ch == '1')
                tmp.push_back(new BattleCell(BattleCell::CELL_TYPE::SHIP));

            if (ch == '0')
                tmp.push_back(new BattleCell(BattleCell::CELL_TYPE::SEA));
        }
        m_rows++;
        table.push_back(tmp);

        }
    }
    file.close();
}

BattleMap::~BattleMap()
{
   for(int ix = 0; ix < m_rows; ix++)
   {
        for(int iy = 0; iy < m_cols; iy++)
        {
           delete table[ix][iy];
        }
   }
}



int BattleMap::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
    return m_rows;

    return 0;
}

int BattleMap::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
    return m_cols;

    return 0;
}

QVariant BattleMap::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto cell_ptr = table.at(index.row()).at(index.column());

    switch(role)
    {
        case Qt::DisplayRole:
        return QVariant::fromValue(cell_ptr);
        case Qt::UserRole:
        return cell_ptr->isRevealed();
    default:
        return QVariant();
    }
}

Qt::ItemFlags BattleMap::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    const auto cell_ptr = table.at(index.row()).at(index.column());

    switch(cell_ptr->getCellType())
    {
        case BattleCell::CELL_TYPE::SEA:
        //Task says only "ship" cells are clickable which is questionable.
        //return Qt::NoItemFlags; <- to make them disabled.
        return Qt::ItemIsEnabled;
        case BattleCell::CELL_TYPE::SHIP:
        return Qt::ItemIsEnabled;
    }
    return QAbstractTableModel::flags(index);
}

void BattleMap::cellClicked(const QModelIndex &index)
{
    BattleCell* cell_ptr = table[index.row()][index.column()];
    if (cell_ptr->isRevealed())
        return;

    cell_ptr->reveal();
    qDebug() << this << "Cell (" << index.row() << index.column() << ") has been revealed";
    emit dataChanged(index,index);
}
