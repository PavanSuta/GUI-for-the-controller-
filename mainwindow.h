#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
void InitMainWindow();
void ReadFromXmlFile();
void DisplayNotInRange();
void UpdateSignalUsage();
void UpdateSignalsForNewlyCreatedGroup();
void CompairSignalsToEleminate();
void DisplayNoAssignment();
void ReadTheGroupContent();
//void WriteTheGroupContentIntoBuffer_ForFirstTime();








private slots:
void on_GroupNumber_returnPressed();
//void on_lineEdit_textEdited(QString );
void on_help_clicked();
void on_comboBox_activated(QString );
void on_DeleteCompleteTableItems_clicked();
void on_deletebutton_clicked();
void on_cancel_clicked();
void on_right_clicked();
void on_insertbutton_clicked();

void NokButtonIcon();
void OkButtonIcon();
void InformationButtonIcon();
void InsertButtonIcon();
void DeleteButtonIcon();
void HelpButtonIcon();
 void XmlWrite();
 void CloseMainWindow();
 //void EnterKeyPressed();

signals:




};



#endif // MAINWINDOW_H

