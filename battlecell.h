#ifndef BATTLECELL_H
#define BATTLECELL_H

#include <QMetaType>
#include <QObject>

class BattleCell : public QObject
{
    Q_OBJECT
public:
    enum CELL_TYPE {SEA = 0, SHIP = 1};
    BattleCell(QObject * parent = nullptr);
    BattleCell(CELL_TYPE type);
    CELL_TYPE getCellType() const;
    bool isRevealed() const;
    void reveal();

signals:
    void stateChanged();

private slots:
    void onCellClick();

private:
    CELL_TYPE m_type;
    bool m_isRevealed;
};
Q_DECLARE_METATYPE(BattleCell)

#endif // BATTLECELL_H
