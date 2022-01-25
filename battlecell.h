#ifndef BATTLECELL_H
#define BATTLECELL_H

#include <QMetaType>
#include <QObject>

class BattleCell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isClickable READ isClickable CONSTANT)
    Q_PROPERTY(bool isRevealed READ isRevealed WRITE setRevealed)
public:
    BattleCell(bool isClickable = false, QObject * parent = nullptr);
    bool isRevealed() const;
    bool isClickable() const;
    void setRevealed(const bool reveal);

private:
    const bool m_isClickable;
    bool m_isRevealed;
};

#endif // BATTLECELL_H
