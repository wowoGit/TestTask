#include "battlecell.h"
#include <QDebug>
#include <QModelIndex>

BattleCell::BattleCell(bool isClickable, QObject *parent) : QObject(parent), m_isClickable(isClickable)
{
    m_isRevealed = false;
}





bool BattleCell::isRevealed() const
{
    return m_isRevealed;
}

bool BattleCell::isClickable() const
{
    return m_isClickable;
}

void BattleCell::setRevealed(const bool reveal)
{
    if(m_isRevealed)
        return;

    qDebug() << this << "isRevealed set. Notifying about the state change...";
    m_isRevealed = reveal;
}
