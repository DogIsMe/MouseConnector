#pragma once

#include <QtWidgets/QWidget>
#include "ui_Connector.h"
#include "MouseCtrl.h"

class StartClickedThread;
class Connector : public QWidget
{
    Q_OBJECT

public:
    Connector(QWidget *parent = Q_NULLPTR);
public slots:
    void slotStart();
public:
    void KeyClicked();
private:
    void init();

private:
    Ui::ConnectorClass ui;
    MouseCtrl M;
    StartClickedThread* p_st;
};
