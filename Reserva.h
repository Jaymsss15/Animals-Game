#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Animais.h"
#include "Alimentos.h"
#define MAX 500

using namespace std;

class Reserva
{
private:
    int NL;
    int NC;
    int pos_x;
    int pos_y;
    char **mat;
    int id;
    string NomeJogo;

    vector<Animal *> animais;
    int totalAnimais;
    vector<Alimento *> alimentos;
    int totalAlimentos;

    vector<int> deadlist;

public:
    Reserva(int lin, int col, int pos_x, int pos_y);

    ~Reserva();

    void LimpaReserva();

    string getNomeJogo();
    void setNomeJogo(string n);

    Reserva &operator=(const Reserva &aux)
    {
        NomeJogo = aux.NomeJogo;
        mat = aux.mat;
        id = aux.id;
        pos_x = aux.pos_x;
        pos_y = aux.pos_y;
        NC = aux.NC;
        NL = aux.NL;
        animais = aux.animais;
        alimentos = aux.alimentos;
        totalAnimais = aux.totalAnimais;
        totalAlimentos = aux.totalAlimentos;

        return *this;
    }

    // Vetor Animais Func
    vector<Animal *> getVector() { return animais; };
    void setVector(vector<Animal *> NovosAnim) { animais = NovosAnim; };

    // Vetor Alimentos Func
    vector<Alimento *> getVector2() { return alimentos; };
    void setVector2(vector<Alimento *> NovosAlim) { alimentos = NovosAlim; };

    vector<int> getVector3() { return deadlist; };

    int get_pos_x();

    int get_pos_y();

    int get_NL();

    int get_NC();

    void set_pos_x(int n);

    void set_pos_y(int n);

    void mostra();

    bool checkLinCol(int lin, int col);

    int getMainID();

    void setMainID();

    bool verInfo(int id);

    void VerTudo(int lin, int col);

    void ApagaTudo(int lin, int col);

    void FeedAnim(int id, int lin, int col, int nut, int tox);

    //---ANIMAIS---

    int gettotalAnimais();

    void settotalAnimais();

    void settotalAnimaisNeg();

    bool adicionaAnimais(Animal *a);

    bool setValue(char letra, int id, int lin, int col);

    void VerAnimais();

    void Slide(Reserva &Tab, int x_inicial, int y_inicial);

    Animal *EncontraAnim(int id, int lin, int col);

    bool MoveAnim(int id, int lin, int col);

    void AndaParaAComida(Animal *a, int posx, int posy, int deslocamento);

    void AndaPerto(Animal *a, int posx, int posy, int deslocamento);

    void FogeDoAnimal(Animal *a, int posx, int posy, int deslocamento);

    void Comer(Animal *a, Alimento *b);

    void ladorand(int *l, int *c, int x);

    void VerAnimaisVisivel();

    vector<Animal *> ApagaAnim(int id, int lin, int col);

    //---ALIMENTOS---

    int gettotalAlimentos();

    void settotalAlimentos();

    void settotalAlimentosNeg();

    bool AlteraAlim(int id, int lin, int col);

    Alimento *EncontraAlim(int id, int lin, int col);
    void MeteVaziosReserva();

    bool setValueAlim(char letra, int id, int lin, int col);

    void VerComida();

    vector<Alimento *> ApagaAlim(int id, int lin, int col);
};
class SaveLoad
{
private:
    vector<Reserva *> jogosGuardados;

public:
    void saveJogo(Reserva *aux);
    // bool removeJogo(string nome);
    Reserva *encontraJogo(string nome);
};

#endif
