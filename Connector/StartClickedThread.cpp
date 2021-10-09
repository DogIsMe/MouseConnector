#include "StartClickedThread.h"
#include "Connector.h"

StartClickedThread::StartClickedThread(QObject *parent)
	: QThread(parent),p(nullptr)
{

}

StartClickedThread::~StartClickedThread()
{
}

void StartClickedThread::setConnectorPointer(Connector* c)
{
	p = c;
}

void StartClickedThread::run()
{
	p->KeyClicked();
}
