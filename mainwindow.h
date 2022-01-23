#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void generateMap(const QString &map_name);
    class BattleMap* map;
    class BattleMapView* map_view;
    class QHBoxLayout* layout;
signals:
    void changeCellState(const QModelIndex &index);
private slots:
    void onCellClick(const QModelIndex &index);
};
#endif // MAINWINDOW_H
