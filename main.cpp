#include <iostream>
// #include <sstream>
#include <string>
#include "Animais.h"
#include "Alimentos.h"
#include "Reserva.h"
#include "Comandos.h"


using namespace std;

int main()
{
    srand((unsigned)time(0));

    int i = 0, j = 0, words = 0;
    string filename;
    string cmd;
    //int x_tam = 16+(rand()%15), y_tam = 16+(rand()%15); // Tamanho da matriz visivel
    int x_tam = 15, y_tam = 15; // Tamanho da matriz visivel
    Reserva TabMAX(MAX, MAX, 0, 0);
    Reserva Visivel(x_tam, y_tam, 0, 0);
    SaveLoad Jogo;

    // TESTE ANIMAIS
    // TabMAX.setValue('C', 1, 0, 0); // coelho
    // TabMAX.setValue('L', 2, 1, 1); // lobo

    // TESTE COMIDA
    // TabMAX.setValue('t' 2, 2); // cenoura
    // TabMAX.setValue('r', 3, 3); // relva

    if (loadcnstfile())
    {
        cout << "Ficheiro lido com sucesso" << endl;
    }

    Visivel.Slide(TabMAX, 0, 0);
    // TabMAX.mostra();
    // cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
    Visivel.mostra();

    while (cmd != "exit")
    {
        // Atualizar a Visivel de forma a ir buscar as alteracoes feitas na TabMAX
        // Ao fazer um slide para a mesma posicao e feito um reload da visivel
        // Visivel.Slide(TabMAX, Visivel.get_pos_x(), Visivel.get_pos_y());

        cmd = " ";
        cout << endl
             << "Comando: ";
        getline(cin, cmd);
        words = contaPalavras(cmd);

        // cout << endl << "NumPalavras: " << contaPalavras(cmd) << endl;
        istringstream iss(cmd);

        if (verComando(iss, words, filename, TabMAX, Visivel, Jogo) != 1)
        {
            Visivel.setVector(TabMAX.getVector());

            Visivel.Slide(TabMAX, Visivel.get_pos_x(), Visivel.get_pos_y());

            // TabMAX.mostra();
            // cout << "=#=#=#=#=#=#=#=#=#=#=#=#=#=#" << endl;
            Visivel.mostra();
            cout << "TotalAnimais: " << TabMAX.gettotalAnimais() << endl;
            cout << "TotalAlimentos: " << TabMAX.gettotalAlimentos() << endl;
            cout << "ExtremoEsqMin: " << Visivel.get_pos_y() << endl;
            cout << "ExtremoDirMin: " << Visivel.get_pos_x() << endl;
            cout << "ExtremoEsqMAX: " << Visivel.get_NL() << endl;
            cout << "ExtremoDirMAX: " << Visivel.get_NC() << endl;
        }
    }

    return 0;
}