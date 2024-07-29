#ifndef COMANDOS_H
#define COMANDOS_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Reserva.h"

using namespace std;

int contaPalavras(string aux);

int verComando(istringstream &recebe, int words, string filename, Reserva &TabMAX, Reserva &Visivel, SaveLoad &Jogo);

bool loadcnstfile();

bool loadcmdfile(string filename, Reserva &Tab, Reserva &Visivel, SaveLoad &Jogo);

#endif