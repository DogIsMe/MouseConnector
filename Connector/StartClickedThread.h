#pragma once

#include <QThread>

class Connector;
class StartClickedThread : public QThread
{
	Q_OBJECT

public:
	StartClickedThread(QObject *parent=nullptr);
	~StartClickedThread();
	void setConnectorPointer(Connector*);
	void run() override;
private:
	Connector* p;
};
