#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include <QAbstractListModel>
#include <vector>
#include <battlecell.h>


class BattleMap : public QAbstractListModel
{
    Q_OBJECT


public:

    //custom roles
    enum Roles {
        isClickable = Qt::UserRole +1,
        isRevealed
    };

    explicit BattleMap(const QString &filename, QObject *parent = nullptr);
    ~BattleMap();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int, QByteArray> roleNames() const override;


private:
    std::vector<BattleCell*> m_table;
signals:
    void cellStateChanged();
public slots:
    void onCellClicked(const int& index);
};

#endif // BATTLEMAP_H
