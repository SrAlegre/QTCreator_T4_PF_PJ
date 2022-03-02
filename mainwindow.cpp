#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->PFBox->setHidden(true);
    ui->PJBox->setHidden(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddPFButto_clicked()
{
    ui->PJBox->setHidden(true);
    ui->PFBox->setHidden(false);
}


void MainWindow::on_AddPJButton_clicked()
{
    ui->PJBox->setHidden(false);
    ui->PFBox->setHidden(true);
}


void MainWindow::on_VectorButton_2_clicked()
{


    if(ui->PFBox->isVisible())
    {
        PF tmp;
        tmp.SetNome(ui->NomelineEdit->text());
        tmp.SetCPF(ui->CPF_lineEdit->text());
        tmp.SetNomeMae(ui->NomeMaelineEdit->text());
        tmp.SetTelefone(ui->Telefone_lineEdit->text());
        tmp.SetEndereco(ui->Endereco_lineEdit->text());

        ui->NomelineEdit->clear();
        ui->CPF_lineEdit->clear();
        ui->NomeMaelineEdit->clear();
        ui->NomeMaelineEdit->clear();
        ui->Telefone_lineEdit->clear();
        ui->Endereco_lineEdit->clear();

        pessoa.push_back(tmp);
    }
    else if(ui->PJBox->isVisible())
    {
        PJ tmp;
        tmp.SetRazaoSocial(ui->RazaolineEdit->text());
        tmp.SetCNPJ(ui->CNPJlineEdit->text());
        tmp.SetTelefone(ui->PJTelefonelineEdit->text());
        tmp.SetEndereco(ui->PJEnderecolineEdit->text());
        tmp.SetCapital(ui->CapitallineEdit->text().toULongLong());


        ui->RazaolineEdit->clear();
        ui->CNPJlineEdit->clear();
        ui->PJTelefonelineEdit->clear();
        ui->PJEnderecolineEdit->clear();
        ui->CapitallineEdit->clear();

        pessoaJ.push_back(tmp);
    }

    ui->listWidget->clear();
    for(size_t i=0;i<pessoa.size();i++)
    {
        ui->listWidget->addItem(pessoa.at(i).GetNome());
    }

    for(size_t i=0;i<pessoaJ.size();i++)
    {
        ui->listWidget->addItem(pessoaJ.at(i).GetRazaoSocial());
    }

}


void MainWindow::on_SalvarButton_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Salvar"),QString(),tr("*.txt"));
    QFile file(fileName);
    if(!fileName.isEmpty())
    {
        if(!file.open(QIODevice::WriteOnly))
        {}
        else
        {
            QTextStream stream(&file);

            for(size_t i=0;i<pessoa.size();i++)
            {
               //stream<<pessoa.at(i).CadastroPF();
               stream<<pessoa.at(i).GetNome()<<"\n";
               stream<<pessoa.at(i).GetNomeMae()<<"\n";
               stream<<pessoa.at(i).GetCPF()<<"\n";
               stream<<pessoa.at(i).GetTelefone()<<"\n";
               stream<<pessoa.at(i).GetEndereco()<<"\n";

            }
          for(size_t i=0;i<pessoaJ.size();i++)
          {
               //stream<<pessoaJ.at(i).CadastroPJ();
              stream<<pessoaJ.at(i).GetRazaoSocial()<<"\n";
              stream<<pessoaJ.at(i).GetCNPJ()<<"\n";
              stream<<pessoaJ.at(i).GetTelefone()<<"\n";
              stream<<pessoaJ.at(i).GetEndereco()<<"\n";
              stream<<pessoaJ.at(i).GetCapital()<<"\n";
           }



            stream.flush();
            file.close();

        }

    }



}


void MainWindow::on_pushButton_clicked()
{

    size_t q= ui->listWidget->currentRow();

    QString p = ui->listWidget->currentItem()->text();

    if(pessoa.size()>q)
    {
        if(p==pessoa.at(q).GetNome())
        {
            pessoa.erase(pessoa.begin()+q);
            delete ui->listWidget->currentItem();
        }




    }
    else if(pessoaJ.size()>q)
    {
        if(p==pessoaJ.at(q).GetRazaoSocial())
        {
            pessoaJ.erase(pessoaJ.begin()+q);
            delete ui->listWidget->currentItem();
        }
    }


}


void MainWindow::on_actionSobre_triggered()
{
    Sobre s;
    s.setModal(true);
    s.exec();

}


void MainWindow::on_actionSalvar_triggered()
{
    on_SalvarButton_clicked();
}

