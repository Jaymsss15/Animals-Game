#include "Comandos.h"
#include "Reserva.h"

int contaPalavras(string aux)
{
    int words = 0;
    string w;
    istringstream s(aux);

    while (s >> w)
        words++;

    // cout << endl << "NumPalavras: " << words << endl;

    return words;
}

bool loadcnstfile()
{
    ifstream readFile;
    string aux;
    string TipoAnimal;
    int num;

    readFile.open("constantes.txt");

    if (!readFile)
    {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return false;
    }
    while (getline(readFile, aux))
    {
        // cout << aux << endl;
        istringstream recebe(aux);
        recebe >> TipoAnimal >> num;
        // cout << num << endl;
    }
    readFile.close();

    return true;
}

bool loadcmdfile(string filename, Reserva &TabMAX, Reserva &Visivel, SaveLoad &Jogo)
{
    ifstream readFile;
    string aux;
    int words;

    readFile.open(filename);

    if (!readFile)
    {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return false;
    }
    while (getline(readFile, aux))
    {
        cout << aux << endl;
        words = contaPalavras(aux);
        istringstream recebe(aux);
        verComando(recebe, words, filename, TabMAX, Visivel, Jogo);
    }
    readFile.close();

    return true;
}

int verComando(istringstream &recebe, int words, string filename, Reserva &TabMAX, Reserva &Visivel, SaveLoad &Jogo)
{
    string comando;
    string tipo, direcao, nficheiro, nreserva;
    string letraLC;
    int linha, coluna;
    char letra;
    int N, P;
    int pontosnut, pontostox, saude;
    int id = TabMAX.getMainID();

    recebe >> comando;

    if (comando == "animal")
    {
        recebe >> letra >> linha >> coluna;
        if (recebe.fail() || words != 4)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (TabMAX.setValue(letra, id, linha, coluna))
            {
                TabMAX.setMainID();
                return 0;
            }
            else
                return 1;
        }
    }
    else if (comando == "kill")
    {
        recebe >> linha >> coluna;
        if (recebe.fail() || words != 3)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.setVector(TabMAX.ApagaAnim(-1, linha, coluna));
        }
    }
    else if (comando == "killid")
    {
        recebe >> id;
        if (recebe.fail() || words != 2)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.setVector(TabMAX.ApagaAnim(id, -1, -1));
        }
    }
    else if (comando == "food")
    {
        recebe >> letra >> linha >> coluna;
        if (recebe.fail() || words != 4)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (TabMAX.setValueAlim(letra, id, linha, coluna))
            {
                TabMAX.setMainID();
                return 0;
            }
            else
                return 1;
        }
    }
    else if (comando == "feed")
    {
        recebe >> linha >> coluna >> pontosnut >> pontostox;
        if (recebe.fail() || words != 5)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.FeedAnim(-1, linha, coluna, pontosnut, pontostox);
            return 1;
        }
    }
    else if (comando == "feedid")
    {
        recebe >> id >> pontosnut >> pontostox;
        if (recebe.fail() || words != 4)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.FeedAnim(id, -1, -1, pontosnut, pontostox);
            return 1;
        }
    }
    else if (comando == "nofood")
    {
        if (words == 2)
        {
            recebe >> id;

            if (recebe.fail())
            {
                cout << endl
                     << "Comandos Incorretos!!" << endl;
                return 1;
            }
            else
            {
                TabMAX.setVector2(TabMAX.ApagaAlim(id, -1, -1));
                return 0;
            }
        }

        else if (words == 3)
        {
            recebe >> linha >> coluna;

            if (recebe.fail())
            {
                cout << endl
                     << "Comandos Incorretos!!" << endl;
                return 1;
            }
            else
            {
                TabMAX.setVector2(TabMAX.ApagaAlim(-1, linha, coluna));
                return 0;
            }
        }

        if (recebe.fail())
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (linha == 0 && coluna == 0)
            {
                cout
                        << id << endl;
            }
            else
            {
                cout
                        << linha << endl
                        << coluna << endl;
            }
        }
    }
    else if (comando == "empty")
    {
        recebe >> linha >> coluna;
        if (recebe.fail() || words != 3)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.ApagaTudo(linha, coluna);
            return 0;
        }
    }
    else if (comando == "see")
    {
        recebe >> linha >> coluna;
        if (recebe.fail() || words != 3)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.VerTudo(linha, coluna);
            return 1;
        }
    }
    else if (comando == "info")
    {
        recebe >> id;

        if (recebe.fail() || words != 2)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (TabMAX.verInfo(id))
            {
                return 1;
            }

            else
            {
                cout << "Esse Elemento nao existe no Simulador!" << endl;
                return 1;
            }
        }
    }
    else if (comando == "n")
    {
        if (words == 1)
        {
            for (auto it : TabMAX.getVector2()) // Alimentos
            {
                // cout << "Entro nos Alimentos" << endl;

                if (!(TabMAX.AlteraAlim(it->getID(), it->getLinha(), it->getColuna())))
                    TabMAX.setVector2(TabMAX.ApagaAlim(it->getID(), -1, -1));

                // cout << "Saio nos Alimentos" << endl;
            }
            for (auto it2 : TabMAX.getVector()) // Animais
            {
                // cout << "Entro nos Animais" << endl;

                TabMAX.MoveAnim(it2->getID(), it2->getLinha(), it2->getColuna());

                // cout << "Saio nos Animais" << endl;
            }
            for (auto it3 : TabMAX.getVector3()) // Vetor de Que vai Morrer
            {
                TabMAX.ApagaAnim(it3, -1, -1);
            }

            // cout << "ChegueiAofinal" << endl;
            TabMAX.MeteVaziosReserva();
            TabMAX.LimpaReserva();

            Visivel.setVector2(TabMAX.getVector2());
            Visivel.setVector(TabMAX.getVector());
        }
        else if (words == 2)
        {
            recebe >> N;
            if (recebe.fail())
            {
                cout << endl
                     << "Comandos Incorretos!!" << endl;
                return 1;
            }
            else
            {
                for (int cena = 0; cena < N; cena++)
                {
                    for (auto it : TabMAX.getVector2()) // Alimentos
                    {
                        // cout << "Entro nos Alimentos" << endl;

                        if (!(TabMAX.AlteraAlim(it->getID(), it->getLinha(), it->getColuna())))
                            TabMAX.setVector2(TabMAX.ApagaAlim(it->getID(), -1, -1));

                        // cout << "Saio nos Alimentos" << endl;
                    }
                    for (auto it2 : TabMAX.getVector()) // Animais
                    {
                        // cout << "Entro nos Animais" << endl;

                        TabMAX.MoveAnim(it2->getID(), it2->getLinha(), it2->getColuna());

                        // cout << "Saio nos Animais" << endl;
                    }
                    for (auto it3 : TabMAX.getVector3()) // Vetor de Que vai Morrer
                    {
                        TabMAX.ApagaAnim(it3, -1, -1);
                    }

                    // cout << "ChegueiAofinal" << endl;
                    TabMAX.MeteVaziosReserva();
                    TabMAX.LimpaReserva();

                    Visivel.setVector2(TabMAX.getVector2());
                    Visivel.setVector(TabMAX.getVector());
                }
            }
        }
        else if (words == 3)
        {
            recebe >> N >> P;
            P *= 1000;
            if (recebe.fail())
            {
                cout << endl
                     << "Comandos Incorretos!!" << endl;
                return 1;
            }
            else
            {
                for (int cena = 0; cena < N; cena++)
                {
                    for (auto it : TabMAX.getVector2()) // Alimentos
                    {
                        // cout << "Entro nos Alimentos" << endl;

                        if (!(TabMAX.AlteraAlim(it->getID(), it->getLinha(), it->getColuna())))
                            TabMAX.setVector2(TabMAX.ApagaAlim(it->getID(), -1, -1));

                        // cout << "Saio nos Alimentos" << endl;
                    }
                    for (auto it2 : TabMAX.getVector()) // Animais
                    {
                        // cout << "Entro nos Animais" << endl;

                        TabMAX.MoveAnim(it2->getID(), it2->getLinha(), it2->getColuna());

                        // cout << "Saio nos Animais" << endl;
                    }
                    for (auto it3 : TabMAX.getVector3()) // Vetor de Que vai Morrer
                    {
                        TabMAX.ApagaAnim(it3, -1, -1);
                    }

                    //cout << "ChegueiAofinal" << endl;
                    TabMAX.MeteVaziosReserva();
                    TabMAX.LimpaReserva();

                    Sleep(P);
                    Visivel.setVector2(TabMAX.getVector2());
                    Visivel.setVector(TabMAX.getVector());
                    Visivel.mostra();
                    cout << "TotalAnimais: " << TabMAX.gettotalAnimais() << endl;
                    cout << "TotalAlimentos: " << TabMAX.gettotalAlimentos() << endl;
                    cout << "ExtremoEsqMin: " << Visivel.get_pos_y() << endl;
                    cout << "ExtremoDirMin: " << Visivel.get_pos_x() << endl;
                    cout << "ExtremoEsqMAX: " << Visivel.get_NL() << endl;
                    cout << "ExtremoDirMAX: " << Visivel.get_NC() << endl;
                    cout << endl;
                }
            }
        }
    }

    else if (comando == "anim")
    {
        if (words != 1)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            // Visivel.setVector(Visivel.ApagaAnimRes(Visivel.get_NL(), Visivel.get_NC(), Visivel.get_pos_x(), Visivel.get_pos_y()));
            Visivel.VerAnimaisVisivel();
            return 1;
        }
    }

    else if (comando == "alim")
    {
        if (words != 1)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.VerComida();
            return 1;
        }
    }
    else if (comando == "visanim")
    {
        if (words != 1)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.VerAnimais();
            return 1;
        }
    }

    else if (comando == "store")
    {
        recebe >> nreserva;
        if (recebe.fail() || words != 2)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            TabMAX.setNomeJogo(nreserva);
            Reserva *save = new Reserva(TabMAX);
            Jogo.saveJogo(save);
        }
    }

    else if (comando == "restore")
    {
        recebe >> nreserva;
        if (recebe.fail() || words != 2)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            Reserva *save = Jogo.encontraJogo(nreserva);
            TabMAX.operator=(*save);
            TabMAX.LimpaReserva();
            TabMAX.MeteVaziosReserva();
            // TabMAX.VerAnimais();
        }
    }

    else if (comando == "load")
    {
        recebe >> filename;
        if (recebe.fail() || words != 2)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (loadcmdfile(filename, TabMAX, Visivel, Jogo))
            {
                cout << "Ficheiro lido com sucesso" << endl;
            }
        }
    }

    else if (comando == "slide")
    {
        recebe >> direcao >> N;

        if (recebe.fail() || words != 3)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            if (direcao == "up")
            {
                if (Visivel.get_pos_x() - N < 0)
                {
                    cout << "A Area de visualizacao ultrapassa os limites da Reserva!" << endl;
                    return 1;
                }
                else
                {
                    Visivel.Slide(TabMAX, Visivel.get_pos_x() - N, Visivel.get_pos_y());
                    Visivel.set_pos_x(Visivel.get_pos_x() - N);
                }
            }
            else if (direcao == "down")
            {
                if (Visivel.get_pos_x() + Visivel.get_NL() + N > TabMAX.get_NL()) // TODO: colocar o tam do TabMAX.get_NL
                {
                    cout << "A Area de visualizacao ultrapassa os limites da Reserva!" << endl;
                    return 1;
                }
                else
                {
                    Visivel.Slide(TabMAX, Visivel.get_pos_x() + N, Visivel.get_pos_y());
                    Visivel.set_pos_x(Visivel.get_pos_x() + N);
                }
            }
            else if (direcao == "left")
            {
                if (Visivel.get_pos_y() - N < 0)
                {
                    cout << "A Area de visualizacao ultrapassa os limites da Reserva!" << endl;
                    return 1;
                }
                else
                {
                    Visivel.Slide(TabMAX, Visivel.get_pos_x(), Visivel.get_pos_y() - N);
                    Visivel.set_pos_y(Visivel.get_pos_y() - N);
                }
            }
            else if (direcao == "right")
            {
                if (Visivel.get_pos_y() + Visivel.get_NC() + N > TabMAX.get_NC()) // TODO: colocar o tam do TabMAX.get_NL
                {
                    cout << "A Area de visualizacao ultrapassa os limites da Reserva!" << endl;
                    return 1;
                }
                else
                {
                    Visivel.Slide(TabMAX, Visivel.get_pos_x(), Visivel.get_pos_y() + N);
                    Visivel.set_pos_y(Visivel.get_pos_y() + N);
                }
            }
        }
    }
    else if (comando == "exit")
    {
        if (words != 1)
        {
            cout << endl
                 << "Comandos Incorretos!!" << endl;
            return 1;
        }
        else
        {
            cout << endl
                 << "FIM do Jogo";
            return 1;
        }
    }
    else
    {
        cout << endl
             << "Comando nao existe" << endl;
        return 1;
    }
    return 0;
}