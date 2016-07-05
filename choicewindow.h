#ifndef CHOICEWINDOW_H
#define CHOICEWINDOW_H

#include <QPushButton>
#include <QComboBox>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

class choicewindow : public QWidget
{
    Q_OBJECT

public:
    choicewindow();

private:
    QLabel *logo_img;
    QComboBox *choix;
    QPushButton *charger;
    QPushButton *fermer;

private slots:
    void chargerdata();
};

#endif // CHOICEWINDOW_H
