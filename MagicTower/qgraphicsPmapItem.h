#ifndef QGRAPHICSPIXMAPITEM_H
#define QGRAPHICSPIXMAPITEM_H
#include<QGraphicsPixmapItem>
#include<QMessageBox>
#include<QGraphicsView>
#include <QDebug>
class QGRAPHICSPMAPITEM: public QGraphicsPixmapItem {
 public:
  QGRAPHICSPMAPITEM(QString name, QGraphicsScene *scene,QPixmap pixmap): QGraphicsPixmapItem(pixmap) {
    //  pixmap.
      setPixmap(pixmap);
      setVisible(true);
     // setParentItem(pixmap);
      scene->addItem(this);
     // scene->addPixmap(pixmap);
     // setFlag(QGraphicsItem::ItemIsMovable);
      qDebug() << name ;
       qDebug("file name \n") ;

  };

  ~QGRAPHICSPMAPITEM() {
  };

  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

    QMessageBox::information(NULL, "Information!", "Mouse release Detected!");
  };

};

#endif // QGRAPHICSPIXMAPITEM_H
