#include "battlecell.h"

BattleCell::BattleCell(QObject *parent) : QObject(parent)
{
    m_type = CELL_TYPE::SEA;
    m_isRevealed = false;
}

BattleCell::BattleCell(CELL_TYPE type) : m_type(type), m_isRevealed(false)
{
    switch (type)
    {
        case CELL_TYPE::SEA:
        break;
        case CELL_TYPE::SHIP:
        break;
    }
}

BattleCell::CELL_TYPE BattleCell::getCellType() const
{
    return m_type;
}


void BattleCell::onCellClick()
{
    m_isRevealed = true;
}

bool BattleCell::isRevealed() const
{
    return m_isRevealed;
}

void BattleCell::reveal()
{
   m_isRevealed = true;
}
