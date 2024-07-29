#include "Alimentos.h"

Alimento::Alimento(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : id(nid),
                                                                                              tmp_vida(ntmp_vida),
                                                                                              valor_nut(nvalor_nut),
                                                                                              toxicidade(ntoxicidade),
                                                                                              cheiro(ncheiro)
{
    instantes = 0;
}

// char Alimento::getLetra() const {};

int Alimento::getID() { return id; }

void Alimento::setID(int n) { id = n; }

int Alimento::getTmp_Vida() { return tmp_vida; }

void Alimento::setTmp_Vida() { tmp_vida--; }

int Alimento::getValor_Nut() { return valor_nut; }

void Alimento::setMainValorNut(int n) { valor_nut = n; }

int Alimento::getValor_NutFixo() { return valor_nutFixo; }

void Alimento::setValor_NutFixo() { valor_nutFixo = valor_nut; }

int Alimento::getToxicidade() { return toxicidade; }

void Alimento::setMainToxicidade(int n) { toxicidade = n; }

string Alimento::getCheiro() { return cheiro; }

void Alimento::setCheiro(char n) { cheiro = n; }

int Alimento::getLinha() { return linha; }

void Alimento::setLinha(int n) { linha = n; }

int Alimento::getColuna() { return coluna; }

void Alimento::setColuna(int n) { coluna = n; }

int Alimento::getInstantes() { return instantes; }

void Alimento::setInstantes() { instantes++; }

// ---- Relva ----

char Relva::getLetra() const { return 'r'; }
int Relva::setToxicidade(int tox, int aux, int aux2) const
{
    tox = 0;
    return tox;
}

int Relva::setValor_Nut(int nut) const
{
    nut = 3;
    return nut;
}

Relva::Relva(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : Alimento(nid, ntmp_vida, nvalor_nut, ntoxicidade, ncheiro) {}

// ---- Cenoura ----

char Cenoura::getLetra() const { return 't'; }
int Cenoura::setToxicidade(int tox, int nutInic, int temp) const
{
    if (temp == 10 || temp == 20 || temp == 30)
        tox++;

    return tox;
}
int Cenoura::setValor_Nut(int nut) const
{
    nut = 4;
    return nut;
}

Cenoura::Cenoura(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : Alimento(nid, ntmp_vida, nvalor_nut, ntoxicidade, ncheiro) {}

// ---- Corpo ----

char Corpo::getLetra() const { return 'p'; }

int Corpo::setToxicidade(int tox, int nutInic, int temp) const
{
    if (nutInic * 2 > temp)
    {
        tox++;
    }
    return tox;
}

int Corpo::setValor_Nut(int nut) const
{
    if (nut != 0)
        nut--;

    return nut;
}

Corpo::Corpo(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : Alimento(nid, ntmp_vida, nvalor_nut, ntoxicidade, ncheiro) {}

// ---- Bife ----

char Bife::getLetra() const { return 'b'; }
int Bife::setToxicidade(int tox, int aux, int aux2) const
{
    tox = 2;
    return tox;
}
int Bife::setValor_Nut(int nut) const
{
    if (nut != 0)
        nut--;

    return nut;
}

Bife::Bife(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : Alimento(nid, ntmp_vida, nvalor_nut, ntoxicidade, ncheiro) {}

// ---- Alimento Misterio ----

char AlimMist::getLetra() const { return 'a'; }

int AlimMist::setToxicidade(int tox, int aux, int aux2) const
{
    tox = 5;

    return tox;
}
int AlimMist::setValor_Nut(int nut) const
{
    nut = 2;

    return nut;
}

AlimMist::AlimMist(int nid, int ntmp_vida, int nvalor_nut, int ntoxicidade, string ncheiro) : Alimento(nid, ntmp_vida, nvalor_nut, ntoxicidade, ncheiro) {}