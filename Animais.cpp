#include "Animais.h"

Animal::Animal(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : id(nid),
                                                                           saude(nsaude),
                                                                           tmp_vida(ntmp_vida),
                                                                           fome(nfome),
                                                                           peso(npeso)
{
    instantes = 0;
    IDMae = -1;
}

// char Animal::getLetra() const {};

// int Animal::mover(int fome) const {};

int Animal::getID() { return id; }

void Animal::setID(int n) { id = n; }

void Animal::setIDMae(int n) { IDMae = n; }

int Animal::getSaude() { return saude; }

void Animal::setSaude(int n) { saude = n; }

int Animal::getTmp_Vida() { return tmp_vida; }

void Animal::setTmp_Vida() { tmp_vida--; }

int Animal::getFome() { return fome; }

void Animal::setFome() { fome++; }

void Animal::setFome2(int n) { fome = fome - n; }

int Animal::getPeso() { return peso; }

void Animal::setPeso(int n) { peso = n; }

int Animal::getLinha() { return linha; }

void Animal::setLinha(int n) { linha = n; }

int Animal::getColuna() { return coluna; }

void Animal::setColuna(int n) { coluna = n; }

int Animal::getInstantes() { return instantes; }

void Animal::setInstantes() { instantes++; }

void Animal::setInstantes2(int n) { instantes = n; }

void Animal::MostraVector3()
{
    for (auto it : alimentosAnim)
    {
        cout << "TipoAlimento: " << it->getLetra() << endl
             << "ID: " << it->getID() << endl
             << "ValorNutritivo: " << it->getValor_Nut() << endl
             << "Toxicidade: " << it->getToxicidade() << endl
             << "Tmp_Vida: " << it->getTmp_Vida() << endl
             << endl;
    }
};

// ---- Coelho ----

char Coelho::getLetra() const { return 'C'; }

int Coelho::mover(int fome) const
{
    if (fome > 10 && fome <= 20)
    {
        return 1 + (rand() % 3);
    }
    else if (fome > 20)
    {
        return 1 + (rand() % 4);
    }
    else
    {
        return 1 + (rand() % 2);
    }
}

Coelho::Coelho(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : Animal(nid, nsaude, ntmp_vida, nfome, npeso) {}

// ---- Ovelha ----

char Ovelha::getLetra() const { return 'O'; }
int Ovelha::mover(int fome) const
{
    if (fome > 15)
    {
        return 1 + (rand() % 2);
    }
    else
    {
        return 1;
    }
}

Ovelha::Ovelha(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : Animal(nid, nsaude, ntmp_vida, nfome, npeso) {}

// ---- Lobo ----

char Lobo::getLetra() const { return 'L'; }
int Lobo::mover(int fome) const
{
    if (fome > 15)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

Lobo::Lobo(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : Animal(nid, nsaude, ntmp_vida, nfome, npeso) {}

// ---- Canguru ----

char Canguru::getLetra() const { return 'G'; }
int Canguru::mover(int fome) const { return 1; }

Canguru::Canguru(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : Animal(nid, nsaude, ntmp_vida, nfome, npeso) {}

// ---- Animal Misterio ----

char AnimMist::getLetra() const { return 'M'; }
int AnimMist::mover(int fome) const{ return 2 + (rand() % 3);}

AnimMist::AnimMist(int nid, int nsaude, int ntmp_vida, int nfome, int npeso) : Animal(nid, nsaude, ntmp_vida, nfome, npeso) {}