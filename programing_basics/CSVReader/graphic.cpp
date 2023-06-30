#include "graphic.h"
#include <QPainter>
#include <QFont>
#include <algorithm>
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

    std::sort(m_y, m_y + m_size);
    double min_y = m_y[0];
    double max_y = m_y[m_size - 1];
    double median_y = m_y[m_size / 2];

    QPen labelPen;
    labelPen.setWidth(1);
    QFont labelFont = painter->font();
    labelFont.setPointSize(10);
    painter->setFont(labelFont);

    labelPen.setColor(Qt::red);
    painter->setPen(labelPen);
    painter->drawText(QPointF(50, 550 - (min_y - min_y) * 500 / (max_y - min_y)), "min");

    labelPen.setColor(Qt::green);
    painter->setPen(labelPen);
    painter->drawText(QPointF(550, 550 - (max_y - min_y) * 500 / (max_y - min_y)), "max");

    labelPen.setColor(Qt::yellow);
    painter->setPen(labelPen);
    painter->drawText(QPointF(50, 550 - (median_y - min_y) * 500 / (max_y - min_y)), "med");

    QPen linePen;
    linePen.setWidth(1);
    linePen.setStyle(Qt::DashLine);

    linePen.setColor(Qt::red);
    painter->setPen(linePen);
    QPointF p1(50, 550 - (min_y - min_y) * 500 / (max_y - min_y));
    QPointF p2(550, 550 - (min_y - min_y) * 500 / (max_y - min_y));
    painter->drawLine(p1, p2);

    linePen.setColor(Qt::green);
    painter->setPen(linePen);
    p1 = QPointF(50, 550 - (max_y - min_y) * 500 / (max_y - min_y));
    p2 = QPointF(550, 550 - (max_y - min_y) * 500 / (max_y - min_y));
    painter->drawLine(p1, p2);

    linePen.setColor(Qt::yellow);
    painter->setPen(linePen);
    p1 = QPointF(50, 550 - (median_y - min_y) * 500 / (max_y - min_y));
    p2 = QPointF(550, 550 - (median_y - min_y) * 500 / (max_y - min_y));
    painter->drawLine(p1, p2);

    QPen pen(Qt::white);
    pen.setWidth(2);
    painter->setPen(pen);
    for (int i = 0; i < m_size - 1; i++) {
        QPointF p1(50 + (m_x[i] - m_x[0]) * 500 / (m_x[m_size - 1] - m_x[0]), 550 - (m_y[i] - min_y) * 500 / (max_y - min_y));
        QPointF p2(50 + (m_x[i + 1] - m_x[0]) * 500 / (m_x[m_size - 1] - m_x[0]), 550 - (m_y[i + 1] - min_y) * 500 / (max_y - min_y));
        painter->drawLine(p1, p2);
    }
}
