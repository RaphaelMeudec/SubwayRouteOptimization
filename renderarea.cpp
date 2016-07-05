#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
     : QWidget(parent)
 {
     shape = Polygon;
     antialiased = false;
     transformed = false;
     pixmap.load(":/images/qt-logo.png");

     setBackgroundRole(QPalette::Base);
     setAutoFillBackground(true);
 }

 QSize RenderArea::minimumSizeHint() const
 {
     return QSize(100, 100);
 }

 QSize RenderArea::sizeHint() const
 {
     return QSize(400, 200);
 }

 void RenderArea::setShape(Shape shape)
 {
     this->shape = shape;
     update();
 }

 void RenderArea::setPen(const QPen &pen)
 {
     this->pen = pen;
     update();
 }

 void RenderArea::setBrush(const QBrush &brush)
 {
     this->brush = brush;
     update();
 }

 void RenderArea::setAntialiased(bool antialiased)
 {
     this->antialiased = antialiased;
     update();
 }

 void RenderArea::setTransformed(bool transformed)
  {
      this->transformed = transformed;
      update();
  }

  void RenderArea::paintEvent(QPaintEvent * /* event */)
  {
      static const QPoint points[4] = {
          QPoint(10, 80),
          QPoint(20, 10),
          QPoint(80, 30),
          QPoint(90, 70)
      };

      QRect rect(10, 20, 80, 60);

      QPainterPath path;
      path.moveTo(20, 80);
      path.lineTo(20, 30);
      path.cubicTo(80, 0, 50, 50, 80, 80);

      //int startAngle = 20 * 16;
      //int arcLength = 120 * 16;

      QPainter painter(this);
      painter.setPen(pen);
      painter.setBrush(brush);
      if (antialiased)
          painter.setRenderHint(QPainter::Antialiasing, true);
      painter.drawLine(1,1,15,15);

  }

