#include "Connector.h"
#include <qdebug.h>
#include <QDebug>
#include "qxtglobalshortcut.h"
#include <QShortCut>
#include <qmessagebox.h>
#include "StartClickedThread.h"
Connector::Connector(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	p_st = new StartClickedThread;
	p_st->setConnectorPointer(this);
	init();
	// 全局快捷键
   // QxtGlobalShortcut* globalShortcut = new QxtGlobalShortcut(this);
   // bool ok = globalShortcut->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_Right));
	//bool ok = globalShortcut->setShortcut(QKeySequence(Qt::Key_F8));
	//if (ok) {
	//    qDebug() << u8"已注册改热键";
	//    connect(globalShortcut, &QxtGlobalShortcut::activated,
	//        [=]() {qDebug() << u8"shortcut activated"; });
	//}
	//else {
	//    qDebug() << u8"改热键已被注册";
	//}

	//// 本地快捷键
	//QShortcut* localShortcut = new QShortcut(this);
	//localShortcut->setKey(QKeySequence(Qt::CTRL + Qt::Key_Left));
	//connect(localShortcut, &QShortcut::activated, [=] {qDebug() << "localShortcut activated"; });
}

void Connector::KeyClicked()
{
	while (true)
	{

		if (ui.label_3->text() == u8"未启动")
		{
			return;
		}
		int c = ui.buttonGroup->checkedId();
		int sleepTime = ui.doubleSpinBox->value() * 1000;
		switch (c)
		{
		case 0:
			M.LeftMouseButtonPress();
			break;
		case 1:
			M.RightMouseButtonPress();
			break;
		case 2:
			M.LeftMouseButtonPress();
			Sleep(sleepTime);
			M.RightMouseButtonPress();
			break;
		default:
			break;
		}
		Sleep(sleepTime);
	}
}

void Connector::init()
{
	// 全局快捷键
	QxtGlobalShortcut* globalShortcut = new QxtGlobalShortcut(this);

	bool ok = globalShortcut->setShortcut(QKeySequence(Qt::Key_F8));
	if (ok)
	{
		connect(globalShortcut, SIGNAL(activated()),this,SLOT(slotStart()));
	}
	else {
		QMessageBox::critical(this, u8"错误!", u8"快捷键被占用!", QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::Ok);
		exit(1);
	}
	ui.buttonGroup->setId(ui.pushButton, 0);
	ui.buttonGroup->setId(ui.pushButton_2, 1);
	ui.buttonGroup->setId(ui.pushButton_3, 2);
}

void Connector::slotStart()
{
	if (ui.label_3->text()==u8"未启动")
	{
		ui.label_3->setText(u8"已启动");
		ui.label->setText(QCoreApplication::translate("ConnectorClass", "<html><head/><body><p><span style=\" font-size:14pt;\">F8\345\201\234\346\255\242\350\277\236\347\202\271</span></p></body></html>", nullptr));
		//ui.label->setText(u8"F8停止连点");
		ui.frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
		p_st->start();
	}
	else if(ui.label_3->text() == u8"已启动")
	{
		ui.label_3->setText(u8"未启动");
		ui.label->setText(QCoreApplication::translate("ConnectorClass", "<html><head/><body><p><span style=\" font-size:14pt;\">F8\345\220\257\345\212\250\350\277\236\347\202\271</span></p></body></html>", nullptr));
		//ui.label->setText(u8"F8启动连点");
		ui.frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
	}
}

