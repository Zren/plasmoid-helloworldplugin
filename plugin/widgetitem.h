#pragma once

#include <QObject>

class WidgetItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)

public:
	explicit WidgetItem(QObject *parent = nullptr);
	~WidgetItem() override;

	int number() const;
	void setNumber(int number);

	Q_INVOKABLE void randomize();

Q_SIGNALS:
	void numberChanged();

private:
	int m_number;
};
