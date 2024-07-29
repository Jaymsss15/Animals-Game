#ifndef ANIMAIS_H
#define ANIMAIS_H

#include <iostream>
#include <vector>
#include "Alimentos.h"

using namespace std;

class Animal
{
private:
    int id;
    int IDMae;
    char letra;
    int saude;
    int tmp_vida;
    int fome;
    int peso;
    int linha;
    int coluna;
    int instantes;

    vector<Alimento *> alimentosAnim;

public:
    Animal(int nid, int nsaude, int ntmp_vida, int nfome, int npeso);

    void AdicionaVector3(Alimento *b) { alimentosAnim.push_back(b); };
    void MostraVector3();

    virtual char getLetra() const = 0;
    virtual int mover(int fome) const = 0;
    virtual int getPercecao() const = 0;

    int getID();
    void setID(int n);

    int getIDMae() { return IDMae; };
    void setIDMae(int n);

    int getSaude();
    void setSaude(int n);

    int getTmp_Vida();
    void setTmp_Vida();

    int getFome();
    void setFome();
    void setFome2(int n);

    int getPeso();
    void setPeso(int n);

    int getLinha();
    void setLinha(int n);

    int getColuna();
    void setColuna(int n);

    int getInstantes();
    void setInstantes();
    void setInstantes2(int n);
};

class Coelho : public Animal
{
public:
    int getPercecao() const override { return 4; };
    char getLetra() const override;
    int mover(int fome) const override; // move-se 1 ou 2 posicoes para qualquer lado //EXTRA  Fome>10: Passa a deslocar-se 1-3 posições (aleatoriamente)
    // Fome > 20: Passa a deslocar -se 1-4 posições(aleatoriamente)
    // Perceciona "Verdura": Dirige se na sua direção(Nao aleatorio)
    // Peso de outro animal > 10: Desloca -se na direção oposta

    Coelho(int nid, int nsaude = 20, int ntmp_vida = 30, int nfome = 0, int npeso = 1 + (rand() % 4)); // peso varia de 1 a 4
};

class Ovelha : public Animal
{
public:
    int getPercecao() const override { return 3; }
    char getLetra() const override;
    int mover(int fome) const override; // move-se 1 posicao para qualquer lado  //EXTRA Fome>15: Passa a deslocar-se 1-2 posições (aleatoriamente)
    // Perceciona "Erva": Dirige se na sua direção(Nao aleatorio)
    // Peso de outro animal > 15: Desloca -se na direção oposta

    Ovelha(int nid, int nsaude = 30, int ntmp_vida = 35, int nfome = 0, int npeso = 4 + (rand() % 5)); // peso varia de 4 a 8 kg
};

class Lobo : public Animal
{
public:
    int getPercecao() const override { return 5; }
    char getLetra() const override;
    int mover(int fome) const override; // move-se 1 posicao para qualquer lado //EXTRA: Desloca -se aleatoriamente a nao ser que veja algo interessante
    // Fome>15: Passa a deslocar-se 2 posições
    // Perceciona "Carne": Dirige se na sua direção(Nao aleatorio)
    // Perceciona outro animal: Avança com velocidade de 2 posições(Se Fome>15 avança 3) persegue o lobo mais pesado (Em caso de haver mais lobos)

    Lobo(int nid, int nsaude = 25, int ntmp_vida = -1, int nfome = 0, int npeso = 15); // nao morre por tempo de vida
};

class Canguru : public Animal
{

public:
    int getPercecao() const override { return 7; }
    char getLetra() const override;
    int mover(int fome) const override;
    // move-se 1 posicao para qualquer lado //EXTRA: Desloca -se uma posicao aleatoriamente
    // Instantes < 10: Fica a 4 ou menos posições de distância,linha e coluna do Canguru Progenitor
    // Instantes <10 e perceciona outro animal: Dirige se à posição do Progenitor numa velocidade de 2 posições por instante.
    // Quando o Canguru filho chega à posição do canguru progenitor, desaparece por 5 instantes e o que acontecer ao Canguru Progenitor acontece ao Canguru filho

    Canguru(int nid, int nsaude = 20, int ntmp_vida = 70, int nfome = -1, int npeso = 10); // apos 20 instantes o peso passa a ser 20  //  nao passa fome
};

class AnimMist : public Animal
{
public:
    int getPercecao() const override { return 7; }
    char getLetra() const override;
    int mover(int fome) const override;

    AnimMist(int nid, int nsaude = 50, int ntmp_vida = -1, int nfome = -1, int npeso = 7); // valores a definir
};

#endif