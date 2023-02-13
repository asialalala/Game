#include "End.h"
#include "ui_End.h"
#include <stdlib.h>
#include <QString>
#include<QDebug>
End::End(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(&End::on_pushButton_clicked));

}

End::~End()
{
    delete ui;
}

void End::dashboard(int score)
{
    QString sentence;
    sentence = QString("Koniec rozgrywki! Dziękujemy za udział. Twój wynik to: %1. Aby wyjść z gry naciśnij OK.").arg(score);
    //sentence.append(static_cast<char>(score));
    qDebug() << sentence << score;
    ui->label = new QLabel(sentence, this);
    this->show();
}

void End::on_pushButton_clicked()
{
    exit(0);
}

