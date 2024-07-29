#ifndef ALIMENTOS_H
#define ALIMENTOS_H

#include <iostream>

using namespace std;

class Alimento
{
private:
    int id;
    int tmp_vida;
    char letra;
    int valor_nut;
    int valor_nutFixo;
    int toxicidade;
    string cheiro;
    int linha;
    int coluna;
    int instantes;

public:
    Alimento(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro);

    virtual char getLetra() const = 0;
    virtual int setToxicidade(int n, int aux, int aux2) const = 0;
    virtual int setValor_Nut(int n) const = 0;

    int getID();
    void setID(int n);

    int getTmp_Vida();
    void setTmp_Vida();

    int getValor_Nut();
    void setMainValorNut(int n);

    int getValor_NutFixo();
    void setValor_NutFixo();

    int getToxicidade();
    void setMainToxicidade(int n);

    string getCheiro();
    void setCheiro(char n);

    int getLinha();
    void setLinha(int n);

    int getColuna();
    void setColuna(int n);

    int getInstantes();
    void setInstantes();
};

class Relva : public Alimento
{
public:
    char getLetra() const override;
    int setToxicidade(int tox, int aux, int aux2) const override;
    int setValor_Nut(int nut) const override;

    Relva(int nid, int ntmp_vida = 20, int nvalor_nut = 3, int ntoxicidade = 0, string ncheiro = "ErvaVerdura");
};

class Cenoura : public Alimento
{
public:
    char getLetra() const override;
    int setToxicidade(int tox, int nutInic, int temp) const override;
    int setValor_Nut(int nut) const override;

    Cenoura(int nid, int ntmp_vida = -1, int nvalor_nut = 4, int ntoxicidade = 0, string ncheiro = "Verdura");
};

class Corpo : public Alimento
{
public:
    char getLetra() const override;
    int setToxicidade(int tox, int nutInic, int temp) const override;
    int setValor_Nut(int nut) const override;

    Corpo(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro = "Carne");
};

class Bife : public Alimento
{
public:
    char getLetra() const override;
    int setToxicidade(int tox, int aux, int aux2) const override;
    int setValor_Nut(int nut) const override;

    Bife(int nid, int ntmp_vida = 30, int nvalor_nut = 10, int ntoxicidade = 2, string ncheiro = "CarneKetchup");
};

class AlimMist : public Alimento
{
public:
    char getLetra() const override;
    int setToxicidade(int tox, int aux, int aux2) const override;
    int setValor_Nut(int nut) const override;

    AlimMist(int nid, int ntmp_vida = 10, int nvalor_nut = 2, int ntoxicidade = 5, string ncheiro = "Doce");
};

#endif
