#pragma once

#include <QMainWindow>

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
};

