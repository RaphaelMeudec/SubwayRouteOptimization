#include "resultwindow.h"
#include "renderarea.h"
#include <iostream>
#include <QVBoxLayout>
#include <QList>

using namespace std;

ResultWindow::ResultWindow(QString &itineraire, QString *stations_file, QString *lignes_file, int depart, int arrivee, QWidget *parent=0)
{
    /* Initialisation des widgets */
    Trajet = new QTextEdit();
    Trajet->setHtml(itineraire);
    Trajet->setReadOnly(true);
    close = new QPushButton("Fermer");
    print = new QPushButton("Imprimer");
    area = new RenderArea(parent);
    value = new QString(itineraire);


    /* Création du layout */
    QVBoxLayout *resultLayout = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    resultLayout->addWidget(Trajet);
    buttonsLayout->addWidget(print);
    buttonsLayout->addWidget(close);
    resultLayout->addLayout(buttonsLayout);
    resultLayout->addWidget(area);

    setLayout(resultLayout);
    //resize(400,600);
    this->setFixedSize(400,600);


    connect(close, SIGNAL(clicked()),this, SLOT(close()));
    connect(print, SIGNAL(clicked()), this, SLOT(Printwindow()));

}

void ResultWindow::Printwindow()
{
        QPrinter * imprimante = new QPrinter();
        QPrintDialog * dialogue = new QPrintDialog(imprimante, this);
        dialogue->setWindowTitle(tr("Imprimer le chemin"));
        QString str = Trajet->toPlainText();
        QString trajet_html;

        /* Intro du document */
        trajet_html += QString::fromStdString("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />");
        trajet_html += QString::fromStdString("<font face=\"Times New Roman\">");
        trajet_html += QString::fromStdString(" ");
        trajet_html += QString::fromStdString("<hr>");
        trajet_html += QString::fromStdString("<center> <B><font size=\"24\">Application ViaUnderground</font></B></center><br>");
        trajet_html += QString::fromStdString("<center> <B><font size=\"14\">développée par Mathilde, Junlin, Raphaël</font></B></center><br>");
        trajet_html += QString::fromStdString("<hr>");
        /* Fin d'introduction */

        /* Présentation du trajet */;
        trajet_html += QString::fromStdString("<br>");

        /* Parsing du QString value */
        QStringList list = value->split("<br>");
        QString str1 = list[0];
        QString str2 = list[1];

        /* Extraire noms des stations de départ et d'arrivée */
        QStringList list_copy = list;
        list_copy.pop_front();
        list_copy.pop_front();
        QString tmp_depart = list_copy[0];
        QStringList tmp_list = tmp_depart.split(" ");
        QString arrivee = tmp_list[0];
        int i = list_copy.size();
        for (int j=1; j<i-1; j++)
        {
            list_copy.pop_front();
        }
        QString tmp_arrivee = list_copy[0];
        QStringList tmp_list2 = tmp_arrivee.split(" ");
        QString depart = tmp_list2[0];




        /* Fin d'extraction */

        trajet_html += QString::fromStdString("<font size=12><center>");
        trajet_html += str1;
        list.pop_front();
        list.pop_front();
        trajet_html += QString::fromStdString(" minutes </center></font><br><br>");
        trajet_html += QString::fromStdString("<font size=12><center><U> ");
        trajet_html += QString::fromStdString("Station de départ:</U> ");
        trajet_html += depart;
        trajet_html += QString::fromStdString("</center></font><br>");
        trajet_html += QString::fromStdString("<br><font size=12><center><U>Station d'arrivée:</U> ");
        trajet_html += arrivee;
        trajet_html += QString::fromStdString("</center></font><br><br>");
        trajet_html += QString::fromStdString("<hr>");
        trajet_html += QString::fromStdString("<br>");
        trajet_html += QString::fromStdString("<U><font size=10>");
        trajet_html += str2;
        trajet_html += QString::fromStdString("</font></U><br>");

        QString tmp = list.join("<br>");
        trajet_html += QString::fromStdString("<br>");
        trajet_html += QString::fromStdString("<center>");
        trajet_html +=  tmp /*+ QString::fromStdString("<br>")*/;
        trajet_html += QString::fromStdString("</center>");
        /* Fin de description du trajet */

        trajet_html += QString::fromStdString("</font>");
        trajet_html += QString::fromStdString("<hr>");
        Trajet_html = new QTextEdit();
        Trajet_html->setHtml(trajet_html);
        if(dialogue->exec() == QDialog::Accepted)
        {
            Trajet_html->print(imprimante);
        }
}
