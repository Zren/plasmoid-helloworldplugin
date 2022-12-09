#include "widgetitem.h"

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>

WidgetItem::WidgetItem(QObject *parent)
	: QObject(parent)
	, m_number(0)
{
	qDebug() << "WidgetItem() constructor";
}

WidgetItem::~WidgetItem() = default;

int WidgetItem::number() const
{
	return m_number;
}

void WidgetItem::setNumber(int number)
{
	if (number != m_number) {
		m_number = number;
		qDebug() << "setNumber" << m_number;
		Q_EMIT numberChanged();
	}
}

void WidgetItem::randomize()
{
	const int min = 0;
	const int max = 10000;
	int val = (QRandomGenerator::global()->bounded((max - min + 1)) + min);
	qDebug() << "randomize(" << min << "," << max << ") =" << val;
	setNumber(val);
}
