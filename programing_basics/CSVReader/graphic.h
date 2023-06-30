#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QGraphicsItem>
#include "sort.h"

class GraphItem : public QGraphicsItem
{
public:
    GraphItem(double *x, double *y, int size, QString xAxisLabel, QString yAxisLabel, QGraphicsItem *parent = nullptr);
    ~GraphItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double *m_x;
    double *m_y;
    int m_size;
    QString m_xAxisLabel;
    QString m_yAxisLabel;
};

#endif // GRAPHIC_H
