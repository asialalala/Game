#ifndef END_H
#define END_H

#include <QDialog>
#include<QLabel>

namespace Ui {
class End;
}

class End : public QDialog
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();
    void dashboard(int score);

private slots:
    void on_pushButton_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
