#include "battlemap.h"
#include <QDebug>
#include <QFile>

BattleMap::BattleMap(const QString &filename, QObject *parent)
    :  QAbstractListModel(parent)
{
    QFile file(filename);
    //read file and populate the table
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);

        while (!in.atEnd()) {
        QString line = in.readLine();
        for(const auto &ch : line)
        {
            BattleCell* new_cell = nullptr;
            if (ch == '1')
                                       //isClickable
                new_cell = new BattleCell(true,this);

            if (ch == '0')
                                       //isClickable
                new_cell = new BattleCell(false,this);

            if(new_cell != nullptr)
            {
                m_table.push_back(new_cell);
            }
        }

        }
    }
    file.close();
}

BattleMap::~BattleMap()
{
   for(uint32_t ix = 0; ix < m_table.size(); ix++)
   {
       delete m_table[ix];
   }
}



int BattleMap::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return m_table.size();

}


QVariant BattleMap::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto cell_ptr = m_table.at(index.row());

    switch(role)
    {
        case isClickable:
        return cell_ptr->isClickable();
        case isRevealed:
        return cell_ptr->isRevealed();
    default:
        return QVariant();
    }
}

Qt::ItemFlags BattleMap::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)



    return Qt::NoItemFlags;
}

QHash<int, QByteArray> BattleMap::roleNames() const
{
    //Custom role binding.
    QHash<int,QByteArray> roles {
        {isClickable,"isClickable"},
        {isRevealed,"isRevealed"}
    };
    return roles;
}

void BattleMap::onCellClicked(const int &index)
{
    qDebug() << this << "Cell is clicked. setting isRevealed property if needed...";
    if (m_table.at(index)->isRevealed() == false){

    m_table.at(index)->setProperty("isRevealed",true);

    qDebug() << this << "Cell is Revealed. notifying view...";
    emit dataChanged(createIndex(int(index),0),createIndex(int(index),0));
    }
}
