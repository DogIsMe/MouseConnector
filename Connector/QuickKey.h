#pragma once
#include <qobject.h>

class QuickKey:public QObject
{
	Q_OBJECT
public:
	QuickKey(QObject* parent = nullptr);
	virtual ~QuickKey();

};

