#pragma once

#include <QMainWindow>
#include <QGraphicsScene>

#include "tank.h"

namespace Ui {
class TanksWindow;
}

class TanksWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit TanksWindow(QWidget *parent = 0);
	~TanksWindow();

private:
	Ui::TanksWindow *ui;
	QGraphicsScene *scene;
};

