//
// Created by Yuri on 22/02/2022.
//

#ifndef T4_TESTE2_PERSON_H
#define T4_TESTE2_PERSON_H
#include <QString>
#include <QTextStream>

using namespace std;

class Person {
protected:
    QString m_telefone,m_endereco;
public:
    void SetTelefone(QString telefone){m_telefone=telefone;}
    void SetEndereco(QString endereco){m_endereco=endereco;}

    QString GetTelefone(){return m_telefone;}
    QString GetEndereco(){return m_endereco;}


};
class PF: public Person
{

protected:
    QString m_nome,m_cpf,m_nomeMae;
public:
    PF(){};
    ~PF(){};
    void SetNome(QString nome){m_nome=nome;}
    void SetCPF(QString CPF){m_cpf=CPF;}
    void SetNomeMae(QString NomeMae){m_nomeMae=NomeMae;}

    QString GetNome(){return  m_nome;}
    QString GetCPF(){return  m_cpf;}
    QString  GetNomeMae(){return m_nomeMae;}

    QString CadastroPF()
    {

        QTextStream str;
        str<<m_endereco;
        str<<m_telefone;
        str<<m_nomeMae;
        str<<m_cpf;
        str<<GetNome();



        QString tmp;
        str>>tmp;


        return tmp;
    }


};
class PJ:public Person
{
private:
    QString m_RazaoSocial,m_CNPJ;
    size_t m_Capital;
public:
    PJ(){};
    ~PJ(){};

    void SetRazaoSocial(QString RazaoSocial){m_RazaoSocial=RazaoSocial;}
    void SetCNPJ(QString CNPJ){m_CNPJ=CNPJ;}
    void SetCapital(size_t Capital){m_Capital=Capital;}

    QString GetRazaoSocial(){return m_RazaoSocial;}
    QString GetCNPJ(){return m_CNPJ;}
    size_t GetCapital(){return m_Capital;}

    QString CadastroPJ()
    {
        QTextStream str;
        str<<GetRazaoSocial();
        str<<GetCNPJ();
        str<<GetTelefone();
        str<<GetEndereco();

        QString tmp;
        str>>tmp;
        return tmp;
    }




};


#endif //T4_TESTE2_PERSON_H
