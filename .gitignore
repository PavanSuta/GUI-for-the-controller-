#include <QtGui>
#include <QTextBrowser>
#include<QFile>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "newdialogwindow.h"
#include "dialog.h"
#include "ProgrammableInputOutputMacro.h"
#include<sstream>
#include<iostream>
#include "Group.h"
#include "string.h"
#include<QDomNode>
#include<QDomDocument>
#include <qdom.h>
#include <qfile.h>



//Array of Pointers to store the Address of each Object that is dynamically created
Group *GroupAddress [16] ={};
//Single dimentional Array to store the row count
int TotalSignalCounts[16]={};
char  TemporaryBuffer[Four][MaxCharLength];//Buffer to read data

int PreviousGroupNumber = 1;
int PresentGroupNumber = 1;
Group *ObjectForEachGroup;//Dynamic allocation of memory to a instance of a class


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    InitMainWindow();
    ReadFromXmlFile();





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitMainWindow()
{
    OkButtonIcon();
    NokButtonIcon();
    HelpButtonIcon();
    InformationButtonIcon();
    InsertButtonIcon();
    DeleteButtonIcon();

}


void MainWindow::OkButtonIcon()
{
    ui->right->setIcon(QIcon(OkIconAddress));
    ui->right->setIconSize(QSize(OkIconLength ,OkIconBreadth));

}

void MainWindow::NokButtonIcon()
{
    ui->cancel->setIcon(QIcon(NokIconAddress));
    ui->cancel->setIconSize(QSize(NokIconLength,NokIconBreadth));

}
void MainWindow::HelpButtonIcon()
{
    ui->help->setIcon(QIcon(HelpIconAddress));
    ui->help->setIconSize(QSize(HelpIconLength,HelpIconBreadth));

}

void MainWindow::InformationButtonIcon()
{
    ui->information->setIcon(QIcon(InformationIconAddress));
    ui->information->setIconSize(QSize(InformationIconLength,InformationIconBreadth));

}

void MainWindow::InsertButtonIcon()
{
    ui->insertbutton->setIcon(QIcon(InsertIconAddress));
    ui->insertbutton->setIconSize(QSize(InsertIconLength,InsertIconBreadth));

}

void MainWindow::DeleteButtonIcon()
{
    ui->deletebutton->setIcon(QIcon(DeleteIconAddress));
    ui->deletebutton->setIconSize(QSize(DeleteIconLength,DeleteIconBreadth));

}





void MainWindow::on_right_clicked()
{
    NewDialogWindow ObjectOfRightButton;

    QObject::connect(&ObjectOfRightButton,SIGNAL(SignalForXmlWrite()),this,SLOT(XmlWrite()));

    ObjectOfRightButton.exec();

}



void MainWindow::on_cancel_clicked()
{
    Dialog ObjectOfCancelButton;
    QObject::connect(&ObjectOfCancelButton,SIGNAL(ToCloseMainWindow()),this,SLOT(CloseMainWindow()));
    ObjectOfCancelButton.exec();




}

void MainWindow::on_insertbutton_clicked()
{

    if(ui->tableWidget->rowCount()!=0)
    {
        if(strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment")==false)
            ui->tableWidget->setRowCount(0);
    }


    int CurrentRow = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(CurrentRow+1);
    //ui->ModuleSelectButton->currentText();



    QTableWidgetItem * ModuleName = new QTableWidgetItem(ui->ModuleSelectButton->currentText() + " " + ui->ToolRange->text());

    ui->tableWidget->setItem(CurrentRow,ModuleColumn,ModuleName);



    QTableWidgetItem * SignalName = new QTableWidgetItem(ui->SignalSelectButton->currentText());

    ui->tableWidget->setItem(CurrentRow,SignalColumn,SignalName);

    QTableWidgetItem * Input = new QTableWidgetItem("6");

    ui->tableWidget->setItem(CurrentRow,InputColumn,Input);

    QTableWidgetItem * IoNumber = new QTableWidgetItem(ui->IoPinNumber->text());

    ui->tableWidget->setItem(CurrentRow,OutputColumn,IoNumber);


    ui->SignalSelectButton->removeItem(ui->SignalSelectButton->currentIndex());




}





void MainWindow::on_deletebutton_clicked()
{

    if(ui->tableWidget->rowCount()!=0)
    {
        if((strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment")!=0))
        {
            int i= ui->tableWidget->currentRow();
            if(i!=-1)
            {
                QString str = ui->tableWidget->item(ui->tableWidget->currentRow(),1)->text();
                //ui->lineEdit_2->setText(s);
                ui->SignalSelectButton->addItem(str);

                if(ui->tableWidget->rowCount()!=0)
                    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
            }

        }
        // else

        // {
        //  if(ui->tableWidget->rowCount()!=0)
        // {
        // ui->tableWidget->removeRow(ui->tableWidget->currentRow());


        // }



        // }
    }




}



void MainWindow::on_DeleteCompleteTableItems_clicked()

{
    if(ui->tableWidget->rowCount()!=0)
    {

        if((strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment")!=0)&&(ui->tableWidget->rowCount()!=0))
        {
            int RowCntInDel= ui->tableWidget->rowCount();
            int m=0;
            for(m=0;m<RowCntInDel;m++)
            {
                QString str=ui->tableWidget->item(m,1)->text();
                ui->SignalSelectButton->addItem(str);

            }
            ui->tableWidget->setRowCount(0);

        }



        //        else

        //        {
        //            if(ui->tableWidget->rowCount()!=0)
        //            {
        //                ui->tableWidget->setRowCount(0);
        //            }



        //        }
    }


}









void MainWindow::on_comboBox_activated(QString )
{
    QStringList Group,TM;
    // {
    ui->SignalSelectButton->clear();
    if(ui->comboBox->currentIndex()==1)
    {
        TM<<"FINDINI"<<"OTINI";
        ui->SignalSelectButton->addItems(TM);
    }
    else
    {
        Group<<"Ext.App.Sel.0"<<"Ext.App.Sel.1"<<"Ext.App.Sel.2"<<"Ext.App.Sel.3"<<"Ext.App.Sel.4"<<"Ext.App.Sel.5";

        ui->SignalSelectButton->addItems(Group);
    }



    int t=0;
    int j=0;
    int k=ui->tableWidget->rowCount();

    for(t=0;t<k;t++)
    {
        QString str1=ui->tableWidget->item(t,1)->text();
        //ui->lineEdit_2->setText(str1);
        for(j=0;j<6;j++)

        {
            QString str2=ui->SignalSelectButton->itemText(j);
            //ui->lineEdit_2->setText(str2);
            int f = strcmp(str1.toAscii(),str2.toAscii());

            if(!f)
                ui->SignalSelectButton->removeItem(j);

        }

    }





}

void MainWindow::on_help_clicked()
{
    /*QTextBrowser * obj = new QTextBrowser;

    QFile file(HelpTextAddress);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))

    {
        QTextStream in(&file);
        QString line;
        while(!in.atEnd())
        {
            line=in.readAll();
        }
        obj->setText(line);
        obj->show();
        file.close();
    } */

    QFile file(HelpTextAddress);
    QTextBrowser *HelpText=new QTextBrowser;
    if(file.open(QFile::ReadOnly))
    {
        QTextStream in(&file);
        QString line;
        while(!in.atEnd())
        {
            line=in.readAll();
        }
        HelpText->setText(line);
        HelpText->show();


    }
    file.close();

}





void MainWindow::ReadFromXmlFile()
{
    QDomDocument GroupRoot;
    char Temp_Buffer[4][20]={};

    int Gr_Number=0;

    QFile file("c:/hello1/New1.xml");

    file.open(QIODevice::ReadOnly);
    GroupRoot.setContent(&file);



    QDomElement RootElement=GroupRoot.documentElement();//root node---GroupRoot
    QDomNode n = RootElement.firstChild();//Group 1 node(child)


    QString NodeElement=n.nodeName().right(2);//GroupNumber=1;

    if((NodeElement.toAscii()=="p1")||(NodeElement.toAscii()=="p2")||(NodeElement.toAscii()=="p3")||(NodeElement.toAscii()=="p4")||(NodeElement.toAscii()=="p5")||NodeElement.toAscii()=="p6"||(NodeElement.toAscii()=="p7")||(NodeElement.toAscii()=="p8")||(NodeElement.toAscii()=="p9"))

    {
        QString NodeElement=n.nodeName().right(1);
        Gr_Number=NodeElement.toInt();


    }

    else
    {

        Gr_Number=NodeElement.toInt();
    }


    int FlagForFirstTime=1;




    while(!n.isNull())
    {
        Group *ObjectForEachGroup=new Group;//Dynamic allocation of memory to a instance of a class for other Groups
        GroupAddress[Gr_Number]=ObjectForEachGroup;



        QDomNode t=n.firstChild();
        int RowNumber=0;
        while(!t.isNull())
        {
            int i=0;
            for(i=0;i<=3;i++)
            {
                QDomElement module=t.toElement();
                QString DataName=module.text();
                strncpy(Temp_Buffer[i],DataName.toAscii(),20);
                t=t.nextSibling();
            }
            ObjectForEachGroup->WriteIntoBuffer(Temp_Buffer[0],Temp_Buffer[1],Temp_Buffer[2],Temp_Buffer[3],RowNumber);
            RowNumber++;
        }

        TotalSignalCounts[Gr_Number]=RowNumber;



        if((FlagForFirstTime)&&(Gr_Number==1))
        {

            int IncRowCnt=0;
            ui->tableWidget->setRowCount(RowNumber);

            while(RowNumber)
            {
                //Here the data is read from the Buffer into the tableWidget corresponding to it's group
                RowNumber--;
                ObjectForEachGroup->ReadFromBuffer(IncRowCnt,Temp_Buffer);
                QTableWidgetItem *Item1=new QTableWidgetItem(Temp_Buffer[0]);
                ui->tableWidget->setItem(IncRowCnt,ModuleColumn,Item1);
                QTableWidgetItem *Item2=new QTableWidgetItem(Temp_Buffer[1]);
                ui->tableWidget->setItem(IncRowCnt,SignalColumn,Item2);
                QTableWidgetItem *Item3=new QTableWidgetItem(Temp_Buffer[2]);
                ui->tableWidget->setItem(IncRowCnt,InputColumn,Item3);
                QTableWidgetItem *Item4=new QTableWidgetItem(Temp_Buffer[3]);
                ui->tableWidget->setItem(IncRowCnt,OutputColumn,Item4);

                IncRowCnt++;

            }
            FlagForFirstTime=0;


        }


        n=n.nextSibling();
        QString NodeElement=n.nodeName().right(2);//GroupNumber after the first Group
        if((NodeElement.toAscii()=="p1")||(NodeElement.toAscii()=="p2")||(NodeElement.toAscii()=="p3")||(NodeElement.toAscii()=="p4")||(NodeElement.toAscii()=="p5")||NodeElement.toAscii()=="p6"||(NodeElement.toAscii()=="p7")||(NodeElement.toAscii()=="p8")||(NodeElement.toAscii()=="p9"))

        {
            QString NodeElement=n.nodeName().right(1);
            Gr_Number=NodeElement.toInt();


        }

        else
        {

            Gr_Number=NodeElement.toInt();
        }



    }

    file.close();



}














void MainWindow::XmlWrite()

{


    QFile file("C:/hello1/New1.xml");

    file.open(QFile::WriteOnly);
    int k=0;
    QDomDocument GroupRoot;

    QDomElement Root = GroupRoot.createElement("Rootnode");
    GroupRoot.appendChild(Root);
    const int Indent=100;
    for(k=1;k<=16;k++)
    {

        int Row=TotalSignalCounts[k];
        Group *PointerForDom=GroupAddress[k];
        if((PointerForDom!=NULL)&&(Row!=NULL))
        {

            char  TemporaryBuffer[Four][MaxCharLength];//Buffer to read data

            char modulex[MaxCharLengthofModule];
            char signalx[MaxCharLengthofSignal];
            char inputx[MaxCharLengthofInput];
            char outputx[MaxCharLengthofOutput];
            int RowcntforXml=0;
            QString gname="Group";
            QString temp = QString::number(k);
            gname=gname+temp;


            // file.open(QFile::Append);



            QDomElement Group1 = GroupRoot.createElement(gname);

            Root.appendChild(Group1);



            for(RowcntforXml=0;RowcntforXml<Row;RowcntforXml++)
            {
                QString module="module";
                temp = QString::number(RowcntforXml);
                module=module+temp;

                PointerForDom->ReadFromBuffer(RowcntforXml,TemporaryBuffer);

                strncpy(modulex,TemporaryBuffer[0],20);
                strncpy(signalx,TemporaryBuffer[1],20);
                strncpy(inputx,TemporaryBuffer[2],20);
                strncpy(outputx,TemporaryBuffer[3],20);


                QDomElement nmodule = GroupRoot.createElement(module);
                QDomElement signal = GroupRoot.createElement("signal");
                QDomElement Input = GroupRoot.createElement("Input");
                QDomElement Output = GroupRoot.createElement("Output");

                QDomText module1 = GroupRoot.createTextNode(modulex);
                QDomText signal1 = GroupRoot.createTextNode(signalx);
                QDomText Input1= GroupRoot.createTextNode(inputx);
                QDomText Output1 = GroupRoot.createTextNode(outputx);

                Group1.appendChild(nmodule);
                Group1.appendChild(signal);
                Group1.appendChild(Input);
                Group1.appendChild(Output);
                nmodule.appendChild(module1);
                signal.appendChild(signal1);
                Input.appendChild(Input1);
                Output.appendChild(Output1);


            }





        }
    }
    QTextStream out(&file);
    GroupRoot.save(out, Indent);
    file.close();




}




/*void MainWindow::on_lineEdit_textEdited(QString)
{

   //char GroupAddress [16] ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                       // NULL,NULL,NULL,NULL,NULL,NULL};

QKeyEvent *p;
//QString str = QString::number(p->key());
//ui->lineEdit_2->setText(str);
if(p->key()== 13)
{
    ui->lineEdit_2->insert("Pa");
}
else
{
    ui->lineEdit_2->insert("Ga");
}

}*/







//The controll is given to this function when the user enters the group number in the LineEdit and presses
//the enter key in the keyboard

//void MainWindow::WriteTheGroupContentIntoBuffer_ForFirstTime()
//{


//}

inline void MainWindow::ReadTheGroupContent()
{
    ui->tableWidget->clearContents();

    int SignalCount=0;
    ObjectForEachGroup=GroupAddress[PresentGroupNumber];

    int TotalSignalCount=TotalSignalCounts[PresentGroupNumber];

    ui->tableWidget->setRowCount(TotalSignalCount);

    while(TotalSignalCount)
    {
        //Here the data is read from the Buffer into the tableWidget corresponding to it's group
        //untill the TotalSignalCount is Zero
        RowsInTable--;
        ObjectForEachGroup->ReadFromBuffer(SignalCount,TemporaryBuffer);
        QTableWidgetItem *Item1=new QTableWidgetItem(TemporaryBuffer[0]);
        ui->tableWidget->setItem(SignalCount,ModuleColumn,Item1);
        QTableWidgetItem *Item2=new QTableWidgetItem(TemporaryBuffer[1]);
        ui->tableWidget->setItem(SignalCount,SignalColumn,Item2);
        QTableWidgetItem *Item3=new QTableWidgetItem(TemporaryBuffer[2]);
        ui->tableWidget->setItem(SignalCount,InputColumn,Item3);
        QTableWidgetItem *Item4=new QTableWidgetItem(TemporaryBuffer[3]);
        ui->tableWidget->setItem(SignalCount,OutputColumn,Item4);


        SignalCount++;

    }
}



//This functin is used to display "No Assignment" in table of a group if no signal is assigned
//or all the signals has been deleted in that group.


inline void MainWindow::DisplayNoAssignment()
{
    if(ui->tableWidget->rowCount()!=0)
        ui->tableWidget->clearContents();
    QTableWidgetItem *Item=new QTableWidgetItem("No Assignment");
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0,ModuleColumn,Item);

}










inline void MainWindow::DisplayNotInRange()
{
    ui->lineEdit->setText("1");
    QString MessageText="The Expected range is  1 to 16";
    //Displays the message if the Range is above 16 or less than 1
    QMessageBox::information(this, "Caption", MessageText);

}

inline void MainWindow::CompairSignalsToEleminate()
{
    if(((strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment"))!=0)&&(ui->tableWidget->rowCount()!=0))
    {

        int CountSignals=0;//Count Signals from TableWidget
        int NumberOfSignalsInComboCount=0;//Count Signals from DropDown
        int TotalSignalCounts=ui->tableWidget->rowCount();

        for(CountSignals=0;CountSignals<TotalSignalCounts;CountSignals++)
        {
            QString SignalSelected=ui->tableWidget->item(CountSignals,1)->text();

            for(NumberOfSignalsComboCount=0;NumberOfSignals<MaxSignal;NumberOfSignalsInComboCount++)

            {
                QString SignalInDropDown=ui->SignalSelectButton->itemText(NumberOfSignalsInComboCount);

                int CompairedValue = strcmp(SignalSelected.toAscii(),SignalInDropDown.toAscii());

                if(!CompairedValue)
                    ui->SignalSelectButton->removeItem(NumberOfSignalsInComboCount);
            }

        }



    }
}

inline void MainWindow::UpdateSignalsForNewlyCreatedGroup()
{
    QStringList Group,TM;
    ui->SignalSelectButton->clear();
    if(ui->comboBox->currentIndex()==1)
    {
        TM<<TMSignals;
        ui->SignalSelectButton->addItems(TM);
    }
    else
    {
        Group<<GroupSignals;

        ui->SignalSelectButton->addItems(Group);
    }

}


inline void MainWindow::UpdateSignalUsage()
{
    if(GroupAddress[PresentGroupNumber]!=NULL)
    {
        QStringList Group,TM;
        ui->SignalSelectButton->clear();
        if(ui->comboBox->currentIndex()==1)
        {
            TM<<TMSignals;
            ui->SignalSelectButton->addItems(TM);
        }
        else
        {
            Group<<GroupSignals
            ui->SignalSelectButton->addItems(Group);
        }

        CompairSignalsToEleminate();
    }

    else
    {
        UpdateSignalsForNewlyCreatedGroup();
    }
}



void MainWindow::on_GroupNumber_returnPressed()
{
    int RangeValue=ui->lineEdit->text().toInt();
    if((RangeValue >= 1)&&(RangeValue <= 16))//To check the Range value of the group
    {

        char ModuleName[MaxCharLengthofModule];
        char SignalName[MaxCharLengthofSignal];
        char InputNumber[MaxCharLengthofInput];
        char OutputNumber[MaxCharLengthofOutput];
        PreviousGroupNumber=PresentGroupNumber;
        PresentGroupNumber=GroupNumber;
        int TotalSignalCount = ui->tableWidget->rowCount();
        TotalSignalCounts[PreviousGroupNumber]=TotalSignalCount;

        //To dynamically create an object of Group type and write the data into the class buffer
        if(((GroupAddress[PreviousGroupNumber]==NULL)&&(ui->tableWidget->rowCount()!=0)&&(strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment")))==true)
        {
            ObjectForEachGroup=new Group;//Dynamic memory allocation to the members of the class Group
            GroupAddress[PreviousGroupNumber]=ObjectForEachGroup;
            int SignalIncrementIndexForGroup=0;
            int SignalCount=0;
            //The data from the tableWidget corresponding to it's group is written into the buffer here for
            //the first time when the group is created

            for(SignalCount=0;SignalCount<TotalSignalCount;SignalCount++)
            {
                strncpy(ModuleName,ui->tableWidget->item(SignalCount,ModuleColumn)->text().toAscii(),MaxCharLength);
                strncpy(SignalName,ui->tableWidget->item(SignalCount,SignalColumn)->text().toAscii(),MaxCharLength);
                if(!ui->tableWidget->item(SignalCount,InputColumn))
                {
                    strncpy(InputNumber,"\0",MaxCharLength);
                }
                else
                {
                    strncpy(InputNumber,ui->tableWidget->item(SignalCount,InputColumn)->text().toAscii(),MaxCharLength);
                }
                if(!ui->tableWidget->item(SignalCount,OutputColumn))
                {
                    strncpy(OutputNumber,"\0",MaxCharLength);
                }
                else
                {
                    strncpy(OutputNumber,ui->tableWidget->item(SignalCount,OutputColumn)->text().toAscii(),MaxCharLength);
                }
                ObjectForEachGroup->WriteIntoBuffer(ModuleName,SignalName,InputNumber,OutputNumber,SignalIncrementIndexForGroup);
                SignalIncrementIndexForGroup++;
            }
        }

        //To write the data into the class buffer of a group type for which object has already been dynamically created
        else if((((ui->tableWidget->rowCount()!=0)&&(strcmp(ui->tableWidget->item(0,0)->text().toAscii(),"No Assignment")))==true))
        {
            ObjectForEachGroup=GroupAddress[PreviousGroupNumber];

            int SignalIncrementIndexForGroup=0;
            int SignalCount=0;
            //The data from the tableWidget corresponding to it's group is is written into the buffer here
            //when the group has been already created

            for(SignalCount=0;SignalCount<TotalSignalCount;SignalCount++)
            {
                strncpy(ModuleName,ui->tableWidget->item(SignalCount,ModuleColumn)->text().toAscii(),MaxCharLength);
                strncpy(SignalName,ui->tableWidget->item(SignalCount,SignalColumn)->text().toAscii(),MaxCharLength);
                if(!ui->tableWidget->item(SignalCount,InputColumn))

                {
                    strncpy(InputNumber,"\0",MaxCharLength);

                }
                else
                {

                    strncpy(InputNumber,ui->tableWidget->item(SignalCount,InputColumn)->text().toAscii(),MaxCharLength);
                }
                if(!ui->tableWidget->item(SignalCount,OutputColumn))
                {
                    strncpy(OutputNumber,"\0",MaxCharLength);
                }
                else
                {
                    strncpy(OutputNumber,ui->tableWidget->item(SignalCount,OutputColumn)->text().toAscii(),MaxCharLength);
                }

                ObjectForEachGroup->WriteIntoBuffer(ModuleName,SignalName,InputNumber,OutputNumber,SignalIncrementIndexForGroup);
                SignalIncrementIndexForGroup++;
            }
        }

        if((GroupAddress[PresentGroupNumber]==NULL)||(TotalSignalCounts[PresentGroupNumber]==0))
        {
            DisplayNoAssignment();
        }

        else
        {
            ReadTheGroupContent();
        }
    }

    else
    {
        DisplayNotInRange();
    }

    UpdateSignalUsage();
}









void MainWindow::CloseMainWindow()
{
    QWidget::close();

}










