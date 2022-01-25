
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "battlemap.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);


    QQmlApplicationEngine engine;

    BattleMap map("../TestTask/map.txt");
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("mapmodel",&map);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url] (QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
