#ifndef MINIZINC_H
#define MINIZINC_H

#include <QMainWindow>

namespace Ui {
class MiniZinc;
}

class MiniZinc : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniZinc(QWidget *parent = 0);
    ~MiniZinc();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MiniZinc *ui;
};

#endif // MINIZINC_H
