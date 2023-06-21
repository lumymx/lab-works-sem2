#include "graphic.h"
#include <QPainter>
#include <QFont>
#include <cstdlib>

GraphItem::GraphItem(double *x, double *y, int size, QString xAxisLabel, QString yAxisLabel, QGraphicsItem *parent)
    : QGraphicsItem(parent), m_size(size), m_xAxisLabel(xAxisLabel), m_yAxisLabel(yAxisLabel)
{
    m_x = (double*)malloc(size * sizeof(double));
    m_y = (double*)malloc(size * sizeof(double));
    if (!m_x || !m_y) {
        qFatal("Failed to allocate memory");
        return;
    }

    for (int i = 0; i < size; i++) {
        m_x[i] = x[i];
        m_y[i] = y[i];
    }

    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

GraphItem::~GraphItem() {
    free(m_x);
    free(m_y);
}

QRectF GraphItem::boundingRect() const {
    return QRectF(0, 0, 600, 600);
}

void GraphItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawLine(QPointF(50, 550), QPointF(550, 550));
    painter->drawLine(QPointF(50, 550), QPointF(50, 50));

    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);
    painter->drawText(QPointF(275, 585), m_xAxisLabel);
    painter->drawText(QPointF(10, 300), m_yAxisLabel);

    QPen pen(Qt::red);
    pen.setWidth(2);
    painter->setPen(pen);
    for (int i = 0; i < m_size - 1; i++) {
        QPointF p1(50 + (m_x[i] - m_x[0]) * 500 / (m_x[m_size - 1] - m_x[0]), 550 - (m_y[i] - m_y[0]) * 500 / (m_y[m_size - 1] - m_y[0]));
        QPointF p2(50 + (m_x[i + 1] - m_x[0]) * 500 / (m_x[m_size - 1] - m_x[0]), 550 - (m_y[i + 1] - m_y[0]) * 500 / (m_y[m_size - 1] - m_y[0]));
        painter->drawLine(p1, p2);
    }
}
