#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <sstream>
#include <QScrollArea>
#include"x_res.h""
#include <QLabel>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCursor>

#include <QApplication>
#include <QLabel>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class MyHighlighter : public QSyntaxHighlighter {
public:
    MyHighlighter(QTextDocument* parent = nullptr) : QSyntaxHighlighter(parent) {
        QTextCharFormat format;
        format.setForeground(QColor(255, 0, 0)); // set text color to red
        QRegularExpression pattern("\\bQt\\b"); // match "Qt" as a whole word
        highlightingRules.append(QPair<QRegularExpression, QTextCharFormat>(pattern, format));
    }

protected:
    void highlightBlock(const QString& text) {
        for (const auto& rule : highlightingRules) {
            QRegularExpressionMatchIterator matchIterator = rule.first.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                setFormat(match.capturedStart(), match.capturedLength(), rule.second);
            }
        }
    }

private:
    QVector<QPair<QRegularExpression, QTextCharFormat>> highlightingRules;
};




x_res *bu;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString file;

void MainWindow::on_pushButton_clicked()
{

        file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
        this->filename1 = file.toStdString();



}


void MainWindow::on_pushButton_2_clicked()
{

        file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
        this->filename2 = file.toStdString();


}

#include <sstream>

#include <sstream>

void output()
{
    std::cout << "cherif" << std::endl;
}

void MainWindow::on_pushButton_3_clicked()
{
    brute_force a(filename1,filename2);







    ui->label->setWordWrap(true);

    ui->label->setText("checking every sentence in file 1\n");
cout<<"sentence check: "<<endl;
    for (int j = 1; j <= a.number_of_phrases_filex(); j++)          // every phrase in filex vector
    {
        vector<logs> plagiarized;
cout<<"sentence : "<<j <<" of file x check "<<endl;
        for (int i = 1; i <= a.number_of_phrases_filey(); i++)
        {
           cout<<"checking with sentence: "<<i<<" of file y"<<endl;
            vector<char> temp = a.getsentence_filey(i);



            a.trial(temp, a.getsentence_filex(j),i,j,plagiarized);


            //if (tempI.size() > 0)
           // {
           //     ui->label->setText(ui->label->text()+QString("sentence: ") + QString::fromStdString(std::to_string(j)) + '\n');

           //     for (int z = 0; z < tempI.size(); z++)
           //     {
           //         ui->label->setText(ui->label->text()+QString("the phrase : (") + QString::fromStdString(tempI[z].text) +
            //                           QString(") is similar to a phrase in sentence: ") + QString::number(i) +
            //                           QString(" of the second file") + QString(" this phrase starts from word number: ") +
            //                           QString::number(tempI[z].index_x) + QString(" of the first file sentence and starts from the word: ") +
            //                           QString::number(tempI[z].index_y) + QString(" of the second file sentence") + QChar('\n'));
//
            //    }

           // }

        }
     a.push_storage(plagiarized);
    }

    ui->label_5->setWordWrap(true);

    for(int h=0;h<a.getfilex_vector().size();h++)
    {

        ui->label_5->setText(ui->label_5->text()+ a.getfilex_vector()[h]);
    }
    cout<<"sentences: "<<a.getstorage().size()<<endl;;
    // Create a new HTML string to hold the highlighted text
    QString htmlText = "<html>";
    // This variable tracks the current position in the original text for conversion
    int currentPosition = 0;

    for(int i = 0; i < a.getstorage().size(); i++)
    {
        cout << "sentence: " << i+1 << " has plagiarism phrases: " << a.getstorage().at(i).size() << endl;
        int sentenceStart = a.get_filex_sentences_index()[i];

        for(int j = 0; j < a.getstorage().at(i).size(); j++)
        {
          /*  int startIndex = sentenceStart + a.getstorage().at(i).at(j).start_x;
            int endIndex = startIndex + a.getstorage().at(i).at(j).text.length();

            cout << "start index: " << startIndex << endl;
            cout << "end index: " << endIndex << endl;

            // Create the HTML code for the highlighted text and append it to the HTML string
            htmlText += ui->label_5->text().mid(currentPosition, startIndex - currentPosition);
            htmlText += "<span style='background-color: yellow;'>";
            htmlText += ui->label_5->text().mid(startIndex, endIndex - startIndex);
            htmlText += "</span>";
            currentPosition = endIndex;
        }

        if (i < a.getstorage().size() - 1) {
            // Append the rest of the sentence after the last highlight
            int nextSentenceStart = a.get_filex_sentences_index()[i+1];
            htmlText += ui->label_5->text().mid(currentPosition, nextSentenceStart - currentPosition);
            currentPosition = nextSentenceStart;

       }
       */







               QString highlight = a.getstorage().at(i).at(j).text();

               // Replace the substring with HTML formatting to highlight it
               QRegularExpression re(highlight);
               QString labelText = ui->label_5->text();
               labelText.replace(re, "<span style='background-color: yellow'>" + highlight + "</span>");
               ui->label_5->setText(labelText);


    }

    // Append any remaining text to the HTML string after the last detected phrase
    htmlText += ui->label_5->text().mid(currentPosition);

    // Close the HTML string and set the label's text to the highlighted HTML string
    htmlText += "</html>";
    ui->label_5->setTextFormat(Qt::RichText);
    ui->label_5->setText(htmlText);





   /* for(int i=1;i<=a.number_of_phrases_filex();i++)
    {


            for(int j=0;j<a.getstorage().at(i).size();j++)
            {
                for(int k=0;k<a.getstorage().at(i).at(j).size();k++)
                {
                if(a.getstorage().at(i).at(j).at(k).index_x!=-999)
                {
                int startIndex=a.get_filex_sentences_index()[i-1]+a.getstorage().at(i).at(j).at(k).index_x;
                int endIndex=startIndex+a.getstorage().at(i).at(j).at(k).text.length();

                QString labelText = ui->label_5->text(); // get the text of label_2 widget


                // apply highlighting with span element and yellow background color to the specified section of text
                QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

                // combine the rest of the label text with the highlighted text
                QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

                ui->label_5->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
                ui->label_5->setText(finalText); // set the final text as the text of label_2 widget
                }
                }

            }

    }*/
}



void MainWindow::on_pushButton_4_clicked()
{
    QString labelText = ui->label_2->text(); // get the text of label_2 widget
    int startIndex = 2; // the start index of text to highlight
    int endIndex = 4; // the last index of text to highlight

    // apply highlighting with span element and yellow background color to the specified section of text
    QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

    // combine the rest of the label text with the highlighted text
    QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

    ui->label_2->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
    ui->label_2->setText(finalText); // set the final text as the text of label_2 widget


}





void MainWindow::on_pushButton_5_clicked()
{



}

