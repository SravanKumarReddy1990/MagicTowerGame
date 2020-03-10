#include "mainwindow.cpp"
#include "database.cpp"
#include "view.cpp"
#include "player.cpp"
#include "cheat.cpp"
#include "role.h"
#include "keys.h"
#include "tools.h"
#include "monster.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardPaths>
#include <QDir>
// Declare global varible
DataBase db;
Player player;
Monster monsters[13];
Tools tools;
Keys keys;
int map[14][14][10];
int mode = 1;
static void connectToDatabase()
{
     qDebug() << "Connected Database" ;
    QSqlDatabase database = QSqlDatabase::database();
    if (!database.isValid()) {
        database = QSqlDatabase::addDatabase("QSQLITE");
        if (!database.isValid()){
            qFatal("Cannot add database: %s", qPrintable(database.lastError().text()));
        }
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    //qDebug() << writeDir.absolutePath() <<"hi";
    if (!writeDir.mkpath(".")){
        qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));
    }

    // Ensure that we have a writable location on all devices.
    const QString fileName = writeDir.absolutePath() + "/chat-database.sqlite3";
    // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
    database.setDatabaseName(fileName);
    if (!database.open()) {
        qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
        QFile::remove(fileName);
    }
}
// Main function
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

connectToDatabase();
    // Connect database
    db.Connect();

    // Add BGM
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/welcome.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *bgm = new QMediaPlayer();
    bgm->setPlaylist(playlist);
    bgm->play();


    // Main window
    MainWindow w;
    w.show();
    return a.exec();
}
