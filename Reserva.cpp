#include "Reserva.h"

using namespace std;

Reserva::Reserva(int lin, int col, int x, int y)
{
    pos_x = x;
    pos_y = y;

    NL = lin;
    NC = col;

    mat = nullptr;
    int i, j;

    id = 1;
    totalAnimais = 0;
    totalAlimentos = 0;

    mat = new char *[NL]; // Reserva espaço para um array que é para as linhas

    for (i = 0; i < NL; i++)
    {
        mat[i] = new char[NC]; // Para cada célula do array das linhas,reservo espaço para o array das colunas

        for (j = 0; j < NC; j++)
            mat[i][j] = ' ';
    }
}

Reserva::~Reserva()
{
    for (int i = 0; i < NL; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

void Reserva::mostra()
{
    for (int k = 0; k < NC; k++)
    {
        cout << "--";
    }
    cout << '-';
    cout << endl;

    for (int i = 0; i < NL; i++)
    {
        cout << '|';

        for (int j = 0; j < NC; j++)
        {
            cout << mat[i][j] << '|';
        }
        cout << endl;

        for (int k = 0; k < NC; k++)
        {
            cout << "--";
        }
        cout << '-';
        cout << endl;
    }
}

bool Reserva::adicionaAnimais(Animal *a)
{
    for (int i = 0; i < animais.size(); i++)
        if (animais[i]->getID() == a->getID())
            return false;
    animais.push_back(a);
    return true;
}

bool Reserva::setValue(char letra, int id, int lin, int col)
{
    ifstream readFile;
    string String;
    string aux;
    int num;

    int SOvelha = 30;
    int VOvelha = 35;
    int SCoelho = 20;
    int VCoelho = 30;
    int SLobo = 25;
    int VLobo = -1;
    int SCanguru = 20;
    int VCanguru = 70;

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
        recebe >> String >> num;
        if (String == "SOvelha")
        {
            SOvelha = num;
        }
        else if (String == "VOvelha")
        {
            VOvelha = num;
        }
        else if (String == "SCoelho")
        {
            SCoelho = num;
        }
        else if (String == "VCoelho")
        {
            VCoelho = num;
        }
        else if (String == "SLobo")
        {
        }
        if (String == "VLobo")
        {
            VLobo = num;
        }
        else if (String == "SCanguru")
        {
            SCanguru = num;
        }
        else if (String == "VCanguru")
        {
            VCanguru = num;
        }
    }
    readFile.close();

    Animal *a;
    if (!checkLinCol(lin, col))
    {
        cout << "Este lugar esta ocupado!" << endl;
        return false;
    }

    if (letra == 'C')
    {
        a = new Coelho(id, SCoelho, VCoelho);
        animais.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAnimais();
        return true;
    }
    else if (letra == 'O')
    {
        a = new Ovelha(id, SOvelha, VOvelha);
        animais.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAnimais();
        return true;
    }
    else if (letra == 'L')
    {
        a = new Lobo(id);
        animais.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAnimais();
        return true;
    }
    else if (letra == 'G')
    {
        a = new Canguru(id);
        animais.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAnimais();
        return true;
    }
    else if (letra == 'M')
    {
        a = new AnimMist(id);
        animais.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAnimais();
        return true;
    }
    else
    {
        cout << "Esse animal nao existe!";
        return false;
    }
}
bool Reserva::setValueAlim(char letra, int id, int lin, int col)
{
    Alimento *a;
    if (!checkLinCol(lin, col))
    {
        cout << "Este lugar esta ocupado!" << endl;
        return false;
    }

    if (letra == 'r')
    {
        a = new Relva(id);
        alimentos.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAlimentos();
        return true;
    }
    else if (letra == 't')
    {
        a = new Cenoura(id);
        alimentos.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAlimentos();
        return true;
    }
    else if (letra == 'b')
    {
        a = new Bife(id);
        alimentos.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAlimentos();
        return true;
    }
    else if (letra == 'a')
    {
        a = new AlimMist(id);
        alimentos.push_back(a);
        mat[lin][col] = a->getLetra();
        a->setColuna(col);
        a->setLinha(lin);
        settotalAlimentos();
        return true;
    }
    else
    {
        cout << "Esse alimento nao existe!";
        return false;
    }
}

bool Reserva::checkLinCol(int lin, int col)
{
    if (mat[lin][col] == ' ')
        return true;
    else
    {
        cout << "Este lugar esta ocupado!" << endl;
        return false;
    }
}

bool Reserva::verInfo(int id)
{
    for (auto it : animais)
    {
        if (it->getID() == id)
        {
            cout << "TipoAnimal: " << it->getLetra() << endl
                 << "ID: " << it->getID() << endl
                 << "Saude: " << it->getSaude() << endl
                 << "Fome: " << it->getFome() << endl
                 << "Peso: " << it->getPeso() << endl
                 << "Tmp_Vida: " << it->getTmp_Vida() << endl
                 << "Linha: " << it->getLinha() << endl
                 << "Coluna: " << it->getColuna() << endl;

            cout << endl
                 << "----LISTA DE ALIMENTOS COMIDOS----" << endl;
            it->MostraVector3();
            return true;
        }
    }
    for (auto it : alimentos)
    {
        if (it->getID() == id)
        {
            cout << "TipoAlimento: " << it->getLetra() << endl
                 << "ID: " << it->getID() << endl
                 << "ValorNutritivo: " << it->getValor_Nut() << endl
                 << "Toxicidade: " << it->getToxicidade() << endl
                 << "Tmp_Vida: " << it->getTmp_Vida() << endl
                 << "Linha: " << it->getLinha() << endl
                 << "Coluna: " << it->getColuna() << endl;

            return true;
        }
    }
    return false;
}

void Reserva::VerAnimais()
{
    for (auto it : animais)
    {
        cout << "TipoAnimal: " << it->getLetra() << endl
             << "ID: " << it->getID() << endl
             << "Saude: " << it->getSaude() << endl
             << "Fome: " << it->getFome() << endl
             << "Peso: " << it->getPeso() << endl
             << "Tmp_Vida: " << it->getTmp_Vida() << endl
             << endl;
    }
}

void Reserva::VerComida()
{
    for (auto it : alimentos)
    {
        cout << "TipoAlimento: " << it->getLetra() << endl
             << "ID: " << it->getID() << endl
             << "ValorNutritivo: " << it->getValor_Nut() << endl
             << "Toxicidade: " << it->getToxicidade() << endl
             << "Tmp_Vida: " << it->getTmp_Vida() << endl
             << endl;
    }
}

void Reserva::VerTudo(int lin, int col)
{
    for (auto it : animais)
    {
        if (it->getLinha() == lin && it->getColuna() == col)
        {
            cout << "String: " << it->getLetra() << endl
                 << "ID: " << it->getID() << endl
                 << "Saude: " << it->getSaude() << endl
                 << "Fome: " << it->getFome() << endl
                 << "Peso: " << it->getPeso() << endl
                 << "Tmp_Vida: " << it->getTmp_Vida() << endl
                 << endl;
        }
    }

    for (auto it : alimentos)
    {
        if (it->getLinha() == lin && it->getColuna() == col)
        {
            cout << "TipoAlimento: " << it->getLetra() << endl
                 << "ID: " << it->getID() << endl
                 << "ValorNutritivo: " << it->getValor_Nut() << endl
                 << "Toxicidade: " << it->getToxicidade() << endl
                 << "Tmp_Vida: " << it->getTmp_Vida() << endl
                 << endl;
        }
    }
}

void Reserva::ApagaTudo(int lin, int col)
{

    for (int i = 0; i < animais.size(); i++)
    {
        if (animais[i]->getLinha() == lin && animais[i]->getColuna() == col)
        {
            mat[lin][col] = ' ';
            animais.erase(animais.begin() + i);
        }
    }

    for (int j = 0; j < alimentos.size(); j++)
    {
        if (alimentos[j]->getLinha() == lin && alimentos[j]->getColuna() == col)
        {
            mat[lin][col] = ' ';
            alimentos.erase(alimentos.begin() + j);
        }
    }
}

void Reserva::FeedAnim(int id, int lin, int col, int nut, int tox)
{
    if (id == -1)
    {
        for (int i = 0; i < animais.size(); i++)
        {
            if (animais[i]->getLinha() == lin && animais[i]->getColuna() == col)
            {
                animais[i]->setSaude(animais[i]->getSaude() + nut);
                animais[i]->setSaude(animais[i]->getSaude() - tox);
            }
        }
    }
    else if (lin == -1 && col == -1)
    {
        for (int j = 0; j < animais.size(); j++)
        {
            if (animais[j]->getID() == id)
            {
                animais[j]->setSaude(animais[j]->getSaude() + nut);
                animais[j]->setSaude(animais[j]->getSaude() - tox);
            }
        }
    }
}

void Reserva::Slide(Reserva &TabMAX, int x_inicial, int y_inicial)
{

    int lin = 0, col = 0;

    // Atualizar os valores da visivel
    for (int i = x_inicial; i < x_inicial + NL; i++)
    {
        col = 0;
        for (int j = y_inicial; j < y_inicial + NC; j++)
        {
            // cout << "Valor de TabMAX[" << i + 1 << "][" << j + 1 << "] ->" << TabMAX.mat[i][j] << endl;
            mat[lin][col] = TabMAX.mat[i][j];
            // cout << "Valor de Visivel[" << lin + 1 << "][" << col + 1 << "] ->" << mat[i][j] << endl;
            col++;
        }
        lin++;
    }
}

Animal *Reserva::EncontraAnim(int id, int lin, int col)
{
    if (id == -1)
    {
        for (int i = 0; i < animais.size(); i++)
        {
            if (animais[i]->getLinha() == lin && animais[i]->getColuna() == col)
                return animais[i];
        }
    }
    else if (lin == -1 && col == -1)
    {
        for (int i = 0; i < animais.size(); i++)
        {
            if (animais[i]->getID() == id)
                return animais[i];
        }
    }
    // cout << "Esse Animal nao existe!" << endl;
    return nullptr;
}

Alimento *Reserva::EncontraAlim(int id, int lin, int col)
{
    if (id == -1)
    {
        for (int i = 0; i < alimentos.size(); i++)
        {
            if (alimentos[i]->getLinha() == lin && alimentos[i]->getColuna() == col)
                return alimentos[i];
        }
    }
    else if (lin == -1 && col == -1)
    {
        for (int i = 0; i < alimentos.size(); i++)
        {
            if (alimentos[i]->getID() == id)
                return alimentos[i];
        }
    }

    // cout << "Esse Alimento nao existe!" << endl;
    return nullptr;
}

bool Reserva::MoveAnim(int id, int lin, int col)
{
    Animal *a, *a2, *a3; // a->animal atual a2->Animal percecionado a3->Animal RecemNascido
    Alimento *b;
    int *apaga;

    int aux, oldL = lin, oldC = col;

    a = EncontraAnim(id, -1, -1);

    mat[lin][col] = a->getLetra();

    a->setTmp_Vida();
    a->setInstantes();

    if (a->getFome() != -1)
        a->setFome();

    // Morre animal

    if (a->getSaude() <= 0 || a->getTmp_Vida() == 0)
    {
        deadlist.push_back(a->getID());
    }
    else
    {
        if (a->getLetra() == 'C')
        {
            if (a->getFome() > 10 && a->getFome() <= 20)
            {
                a->setSaude(a->getSaude() - 1);
            }
            else if (a->getFome() > 20)
            {
                a->setSaude(a->getSaude() - 2);
            }

            int i2 = lin + a->getPercecao();
            int j2 = col + a->getPercecao();
            for (int i = lin - a->getPercecao(); i <= i2; i++)
            {
                if (i < 0)
                    i = 0;
                else if (i2 > NL)
                    i2 = NL;

                for (int j = col - a->getPercecao(); j <= j2; j++)
                {
                    if (j < 0)
                        j = 0;
                    else if (j2 > NC)
                        j2 = NC;

                    if (mat[i][j] == 'r' || mat[i][j] == 't' || mat[i][j] == 'a')
                    {
                        aux = a->mover(a->getFome());
                        // cout << "MoveCoelho: " << aux << endl;
                        AndaParaAComida(a, j, i, aux);
                        // if (mat[a->getLinha()][a->getColuna()] == 'r' || mat[a->getLinha()][a->getColuna()] == 't' || mat[a->getLinha()][a->getColuna()] == ' ')
                        //{
                        mat[oldL][oldC] = ' ';
                        mat[a->getLinha()][a->getColuna()] = a->getLetra();

                        b = EncontraAlim(-1, i, j);

                        if (b != nullptr)
                        {
                            // Alimentos
                            cout << "ID[" << a->getID() << "]"
                                 << "Coelho vai para a comida do tipo: " << b->getLetra() << endl;

                            if (b->getLinha() == a->getLinha() && b->getColuna() == a->getColuna() && (b->getLetra() == 'r' || b->getLetra() == 't' || mat[i][j] == 'a'))
                            {
                                Comer(a, b);
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                cout << "ID[" << a->getID() << "]"
                                     << "Coelho comeu um alimento do tipo: " << b->getLetra() << endl;
                            }
                        }

                        return true;
                        //}
                    }
                    else
                    {
                        // mat[i][j] = 'T';

                        a2 = EncontraAnim(-1, i, j);
                        if (a2 != nullptr)
                        {
                            if (a2->getPeso() > 10)
                            {
                                aux = a->mover(a->getFome());
                                FogeDoAnimal(a, j, i, aux);
                                if(a->getLinha() < 0 || a->getLinha() >= get_NL() || a->getColuna() < 0 || a->getColuna() >= get_NC())
                                {
                                    a->setLinha(oldL);
                                    a->setColuna(oldC);
                                }
                                cout << "ID[" << a->getID() << "]"
                                     << "Coelho foge de um animal do tipo: " << a2->getLetra() << endl;
                                mat[oldL][oldC] = ' ';
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                return true;
                            }
                        }
                    }
                }
            }

            if (a->getInstantes() == 8)
            {
                int random = rand() % 2; // 0  1
                if (random == 0)
                {
                    int linaux = lin, colaux = col;

                    do
                    {
                        ladorand(&linaux, &colaux, 1 + (rand() % 7));

                    } while (!checkLinCol(linaux, colaux));

                    cout << "ID[" << a->getID() << "]"
                         << "Coelho teve um filho" << endl;

                    setValue('C', getMainID(), linaux, colaux);
                    setMainID();
                    settotalAnimais();
                }

                a->setInstantes2(0);
            }

            aux = a->mover(a->getFome());

            do
            {
                ladorand(&lin, &col, aux);

            } while (!checkLinCol(lin, col));

            mat[oldL][oldC] = ' ';
            mat[lin][col] = a->getLetra();
            a->setLinha(lin);
            a->setColuna(col);

            cout << "ID[" << a->getID() << "]"
                 << "Coelho andou Random: " << endl;
        }
        else if (a->getLetra() == 'O')
        {
            //cout << "Entro Ovelha" << endl;
            if (a->getFome() > 15 && a->getFome() <= 20)
            {
                a->setSaude(a->getSaude() - 1);
            }
            else if (a->getFome() > 20)
            {
                a->setSaude(a->getSaude() - 2);
            }

            if (a->getInstantes() == 15)
            {

                int linaux = lin, colaux = col;

                do
                {
                    ladorand(&linaux, &colaux, 1 + (rand() % 9));

                } while (!checkLinCol(linaux, colaux));

                setValue('O', getMainID(), linaux, colaux);

                cout << "ID[" << a->getID() << "]"
                     << "Ovelha teve um filho: " << endl;

                a3 = EncontraAnim(getMainID(), -1, -1);

                if (a3 != nullptr)
                {
                    a3->setSaude(a->getSaude());
                    setMainID();
                    settotalAnimais();

                    a->setInstantes2(0);
                }
            }

            // cout << "Inicial Ovelha" << endl;

            int i2 = lin + a->getPercecao();
            int j2 = col + a->getPercecao();
            for (int i = lin - a->getPercecao(); i <= i2; i++)
            {
                if (i < 0)
                    i = 0;
                else if (i2 > NL)
                    i2 = NL;

                for (int j = col - a->getPercecao(); j <= j2; j++)
                {
                    if (j < 0)
                        j = 0;
                    else if (j2 > NC)
                        j2 = NC;

                    if (mat[i][j] == 'r')
                    {
                        aux = a->mover(a->getFome());
                        AndaParaAComida(a, j, i, aux);
                        mat[oldL][oldC] = ' ';
                        mat[a->getLinha()][a->getColuna()] = a->getLetra();

                        b = EncontraAlim(-1, i, j);
                        if (b != nullptr)
                        {
                            // Alimentos
                            cout << "ID[" << a->getID() << "]"
                                 << "Ovelha vai para a comida do tipo: " << b->getLetra() << endl;
                            if (b->getLinha() == a->getLinha() && b->getColuna() == a->getColuna() && (b->getLetra() == 'r'))
                            {
                                Comer(a, b);
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                cout << "ID[" << a->getID() << "]"
                                     << "Ovelha comeu um alimento do tipo: " << b->getLetra() << endl;
                            }
                        }

                        return true;
                    }

                    // mat[i][j] = 'T';
                    // cout << "Ovelha Ve Animal" << endl;
                    a2 = EncontraAnim(-1, i, j);
                    if (a2 != nullptr)
                    {
                        if (a2->getPeso() > 15)
                        {
                            aux = a->mover(a->getFome());
                            // cout << "Fugir!!" << endl;
                            FogeDoAnimal(a, j, i, aux);
                            cout << "ID[" << a->getID() << "]"
                                 << "Ovelha foge de um animal do tipo: " << a2->getLetra() << endl;
                            // cout << "Fugir!!" << endl;
                            /*if (!checkLinCol(a->getLinha(), a->getColuna()))
                            {
                                return false;
                            }*/
                            mat[oldL][oldC] = ' ';
                            mat[a->getLinha()][a->getColuna()] = a->getLetra();
                            return true;
                        }
                    }
                }
            }

            cout << "ID[" << a->getID() << "]"
                 << "Ovelha anda Random " << endl;

            aux = a->mover(a->getFome());

            do
            {
                ladorand(&lin, &col, aux);

            } while (!checkLinCol(lin, col));

            mat[oldL][oldC] = ' ';
            mat[lin][col] = a->getLetra();
            a->setLinha(lin);
            a->setColuna(col);
        }
        else if (a->getLetra() == 'L')
        {
            // cout << "Entro no Lobo" << endl;
            if (a->getFome() > 15 && a->getFome() <= 25)
            {
                a->setSaude(a->getSaude() - 1);
            }
            else if (a->getFome() > 25)
            {
                a->setSaude(a->getSaude() - 2);
            }

            if (a->getInstantes() == 5 + (rand() % 35))
            {

                int linaux = lin, colaux = col;

                do
                {
                    ladorand(&linaux, &colaux, 1 + (rand() % 13));

                } while (!checkLinCol(linaux, colaux));

                cout << "ID[" << a->getID() << "]"
                     << "Lobo teve um filho " << endl;

                setValue('L', getMainID(), linaux, colaux);
                setMainID();
                settotalAnimais();
            }

            // cout << "Inicial Feito Lobo" << endl;

            int i2 = lin + a->getPercecao();
            int j2 = col + a->getPercecao();
            int flag = 0;
            for (int i = lin - a->getPercecao(); i <= i2; i++)
            {
                if (i < 0)
                    i = 0;
                else if (i2 > NL)
                    i2 = NL;

                for (int j = col - a->getPercecao(); j <= j2; j++)
                {
                    if (j < 0)
                        j = 0;
                    else if (j2 > NC)
                        j2 = NC;

                    if (mat[i][j] == 'C' || mat[i][j] == 'O' || mat[i][j] == 'G' || mat[i][j] == 'b' || mat[i][j] == 'p')
                    {
                        aux = a->mover(a->getFome());
                        aux++;

                        a2 = EncontraAnim(-1, i, j);

                        if (a2 != nullptr)
                        {
                            // cout << "Andamento do Lobo: " << aux;
                            AndaParaAComida(a, j, i, aux);
                            cout << "ID[" << a->getID() << "]"
                                 << "Lobo vai para um animal do tipo: " << a2->getLetra() << endl;
                            mat[oldL][oldC] = ' ';
                            mat[a->getLinha()][a->getColuna()] = a->getLetra();
                            // cout << "Foi para Animais" << endl;

                            if (a2->getPeso() > a->getPeso() && a->getLinha() == a2->getLinha() && a->getColuna() == a2->getColuna()) // Lutar Animal com Peso >
                            {
                                int random = rand() % 2; // 0  1   // Morre Random
                                if (random == 0)         // Lobo Perde
                                {
                                    deadlist.push_back(a->getID());
                                    cout << "ID[" << a->getID() << "]"
                                         << "Lobo morre a lutar contra um animal do tipo: " << a2->getLetra() << endl;
                                    // mat[a->getLinha()][a->getColuna()] = a2->getLetra();
                                    return true;
                                }
                                else // Lobo Ganha
                                {
                                    deadlist.push_back(a2->getID());
                                    mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                    cout << "ID[" << a->getID() << "]"
                                         << "Lobo mata um animal do tipo: " << a2->getLetra() << endl;
                                    return true;
                                }
                            }
                            else if (a2->getPeso() < a->getPeso()) // Animal com Peso < o Lobo vai Mata lo
                            {
                                if (a->getLinha() == a2->getLinha() && a->getColuna() == a2->getColuna())
                                {
                                    // cout << "Apaga Fraco" << endl;
                                    deadlist.push_back(a2->getID());
                                    mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                    cout << "ID[" << a->getID() << "]"
                                         << "Lobo mata um animal do tipo: " << a2->getLetra() << endl;
                                    // cout << "Apagouuu Fraco" << endl;
                                    return true;
                                }
                            }
                            return true;
                        }
                        // cout << "Andamento do Lobo: " << aux;
                        AndaParaAComida(a, j, i, aux);
                        mat[oldL][oldC] = ' ';
                        mat[a->getLinha()][a->getColuna()] = a->getLetra();
                        // cout << "Foi para a Comida" << endl;

                        b = EncontraAlim(-1, i, j);
                        if (b != nullptr)
                        {
                            cout << "ID[" << a->getID() << "]"
                                 << "Lobo vai para um alimento do tipo: " << b->getLetra() << endl;
                            // Alimentos
                            if (b->getLinha() == a->getLinha() && b->getColuna() == a->getColuna() && (b->getLetra() == 'b' || b->getLetra() == 'p'))
                            {
                                Comer(a, b);
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                cout << "ID[" << a->getID() << "]"
                                     << "Lobo comeu um alimento do tipo: " << b->getLetra() << endl;
                            }
                        }

                        return true;
                    }
                }
            }

            cout << "ID[" << a->getID() << "]"
                 << "Lobo anda Random " << endl;

            aux = a->mover(a->getFome());

            do
            {
                ladorand(&lin, &col, aux);

            } while (!checkLinCol(lin, col));

            mat[oldL][oldC] = ' ';
            mat[lin][col] = a->getLetra();
            a->setLinha(lin);
            a->setColuna(col);
        }
        else if (a->getLetra() == 'G')
        {

            int flag = 0;
            int i2 = lin + a->getPercecao();
            int j2 = col + a->getPercecao();

            if (a->getInstantes() == 20) // Fica adulto
            {
                a->setPeso(20);
                cout << "ID[" << a->getID() << "]"
                     << "Canguru ficou adulto: " << endl;
            }

            if (a->getInstantes() == 30 || a->getInstantes() == 60) // 30  60  //Reproduz
            {

                int linaux = lin, colaux = col;

                do
                {
                    ladorand(&linaux, &colaux, 1 + (rand() % 2));

                } while (!checkLinCol(linaux, colaux));

                cout << "ID[" << a->getID() << "]"
                     << "Canguru teve um filho" << endl;

                setValue('G', getMainID(), linaux, colaux);

                a3 = EncontraAnim(getMainID(), -1, -1); // Canguru Filho

                if (a3 != nullptr)
                {
                    a3->setIDMae(a->getID());

                    a3->setSaude(a->getSaude());
                    setMainID();
                    settotalAnimais();

                    a->setInstantes2(30); // 30
                }
            }

            for (int i = lin - a->getPercecao(); i <= i2; i++)
            {
                if (i < 0)
                    i = 0;
                else if (i2 > NL)
                    i2 = NL;

                for (int j = col - a->getPercecao(); j <= j2; j++)
                {
                    if (j < 0)
                        j = 0;
                    else if (j2 > NC)
                        j2 = NC;
                    // mat[i][j] = 'T';

                    a2 = EncontraAnim(-1, i, j);
                    if (a2 != nullptr && a->getInstantes() < 10 && a2->getID() != a->getIDMae() && a2->getID() != a->getID()) // Se for um Animal desconhecido
                    {
                        a3 = EncontraAnim(a->getIDMae(), -1, -1); // Encontra a mae

                        if (a3 != nullptr)
                        {
                            cout << "ID[" << a->getID() << "]"
                                 << "Canguru com medo vai para a Mae " << endl;
                            mat[oldL][oldC] = ' ';
                            mat[a3->getLinha()][a3->getColuna()] = a->getLetra();
                            flag = 1;

                            return true;
                        }
                    }
                }
            }

            if (a->getInstantes() < 10 && flag == 0) // Canguru Filho
            {
                a3 = EncontraAnim(a->getIDMae(), -1, -1); // ProcuraMae

                if (a3 != nullptr)
                {
                    aux = a->mover(a->getFome());
                    cout << "ID[" << a->getID() << "]"
                         << "Canguru filho anda perto da Mae " << endl;
                    AndaPerto(a, a3->getColuna(), a3->getLinha(), aux); // Anda perto da Mae
                    mat[oldL][oldC] = ' ';
                    mat[a->getLinha()][a->getColuna()] = a->getLetra();
                    return true;
                }
            }

            cout << "ID[" << a->getID() << "]"
                 << "Canguru anda Random " << endl;
            aux = a->mover(a->getFome());

            do
            {
                ladorand(&lin, &col, aux);

            } while (!checkLinCol(lin, col));

            mat[oldL][oldC] = ' ';
            mat[lin][col] = a->getLetra();
            a->setLinha(lin);
            a->setColuna(col);

            return true;
        }
        else if (a->getLetra() == 'M')
        {
            int i2 = lin + a->getPercecao();
            int j2 = col + a->getPercecao();
            for (int i = lin - a->getPercecao(); i <= i2; i++)
            {
                if (i < 0)
                    i = 0;
                else if (i2 > NL)
                    i2 = NL;

                for (int j = col - a->getPercecao(); j <= j2; j++)
                {
                    if (j < 0)
                        j = 0;
                    else if (j2 > NC)
                        j2 = NC;

                    if (mat[i][j] == 'p' || mat[i][j] == 'a')
                    {
                        aux = a->mover(a->getFome());
                        AndaParaAComida(a, j, i, aux);
                        mat[oldL][oldC] = ' ';
                        mat[a->getLinha()][a->getColuna()] = a->getLetra();

                        cout << "ID[" << a->getID() << "]"
                             << "AnimalMisterio anda para a comida do tipo: " << endl;

                        b = EncontraAlim(-1, i, j);
                        if (b != nullptr)
                        {
                            if (b->getLinha() == a->getLinha() && b->getColuna() == a->getColuna() && (b->getLetra() == 'b' || b->getLetra() == 'p'))
                            {
                                Comer(a, b);
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                cout << "ID[" << a->getID() << "]"
                                     << "AnimalMisterio comeu um alimento do tipo: " << b->getLetra() << endl;
                            }
                        }

                        return true;
                    }


                        a2 = EncontraAnim(-1, i, j);
                        if (a2 != nullptr)
                        {
                            if (a2->getSaude() <= 5)
                            {
                                aux = a->mover(a->getFome());
                                AndaParaAComida(a, j, i, aux);
                                cout << "ID[" << a->getID() << "]"
                                     << "AnimalMisterio anda para o animal do tipo: " << a2->getLetra() << endl;

                                mat[oldL][oldC] = ' ';
                                mat[a->getLinha()][a->getColuna()] = a->getLetra();

                                if (a->getLinha() == a2->getLinha() && a->getColuna() == a2->getColuna())
                                {

                                    deadlist.push_back(a2->getID());
                                    mat[a->getLinha()][a->getColuna()] = a->getLetra();
                                    cout << "ID[" << a->getID() << "]"
                                         << "AnimalMisterio mata um animal do tipo: " << a2->getLetra() << endl;
                                    return true;
                                }
                            }
                           // return true;
                        }

                }
            }

            cout << "ID[" << a->getID() << "]"
                 << "AnimalMisterio anda Random " << endl;

            aux = a->mover(a->getFome());

            do
            {
                ladorand(&lin, &col, aux);

            } while (!checkLinCol(lin, col));

            mat[oldL][oldC] = ' ';
            mat[lin][col] = a->getLetra();
            a->setLinha(lin);
            a->setColuna(col);
        }
    }
    return true;
}

void Reserva::Comer(Animal *a, Alimento *b)
{
    a->AdicionaVector3(b);

    a->setSaude(a->getSaude() + b->getValor_Nut());
    a->setSaude(a->getSaude() - b->getToxicidade());

    if (a->getFome() != -1)
    {
        a->setFome2(5); // setfome fome++     setfome2   fome = fome - n

        while (a->getFome() < 0)
        {
            a->setFome();
        }
    }

    // a->MostraVector3();

    setVector2(ApagaAlim(b->getID(), -1, -1));
}

bool Reserva::AlteraAlim(int id, int lin, int col)
{

    int random = 4 + (rand() % 4);
    // int random = 4;

    Alimento *a;

    a = EncontraAlim(id, -1, -1);

    a->setTmp_Vida();

    if (a->getTmp_Vida() == 15 && a->getLetra() == 'r')
    {
        int linaux = a->getLinha(), colaux = a->getColuna();
        do
        {
            ladorand(&linaux, &colaux, random); // 4 a 8 posicoes
        } while (!checkLinCol(linaux, colaux));

        setValueAlim('r', getMainID(), linaux, colaux);
        setMainID();
        settotalAlimentos();
    }

    if (a->getTmp_Vida() == 0)
    {
        return false;
    }

    mat[a->getLinha()][a->getColuna()] = a->getLetra();
    a->setMainValorNut(a->setValor_Nut(a->getValor_Nut()));
    a->setMainToxicidade(a->setToxicidade(a->getToxicidade(), a->getValor_NutFixo(), a->getInstantes()));
    a->setInstantes();

    return true;
}

int Reserva::get_pos_x() { return pos_x; }

int Reserva::get_pos_y() { return pos_y; }

void Reserva::set_pos_x(int n) { pos_x = n; }

void Reserva::set_pos_y(int n) { pos_y = n; }

int Reserva::get_NL() { return NL; }

int Reserva::get_NC() { return NC; }

int Reserva::gettotalAnimais() { return totalAnimais; }

int Reserva::gettotalAlimentos() { return totalAlimentos; }

void Reserva::settotalAlimentos() { totalAlimentos++; }

void Reserva::settotalAlimentosNeg() { totalAlimentos--; }

int Reserva::getMainID() { return id; }

void Reserva::setMainID() { id++; }

void Reserva::settotalAnimais() { totalAnimais++; }

void Reserva::settotalAnimaisNeg() { totalAnimais--; }

void Reserva::ladorand(int *l, int *c, int x)
{
    int random, random2;
    int aux = *l, aux2 = *c;
    do
    {
        *l = aux;

        random = (rand() % 2);

        if (*l + x < MAX && *l - x >= 0)
        {
            if (random == 0)
                *l = *l + x;
            else if (random == 1)
                *l = *l - x;
        }
        else if (*l + x < MAX)
        {
            *l = *l + x;
        }
        else if (*l - x >= 0)
        {
            *l = *l - x;
        }

        // cout << "Random L" << endl;

    } while (*l < 0 || *l >= MAX);

    srand((unsigned)time(0));

    do
    {
        *c = aux2;

        random2 = (rand() % 2);

        if (*c + x < MAX && *c - x >= 0)
        {
            if (random2 == 0)
                *c = *c + x;
            else if (random2 == 1)
                *c = *c - x;
        }
        else if (*c + x < MAX)
        {
            *c = *c + x;
        }
        else if (*c - x >= 0)
        {
            *c = *c - x;
        }

        // cout << "Random C" << endl;

    } while (*c < 0 || *c >= MAX);
}

void Reserva::AndaParaAComida(Animal *a, int posx, int posy, int deslocamento)
{
    if (a->getColuna() < posx && a->getLinha() > posy) // Diagonal Direita Cima
    {

        if (posx - a->getColuna() > deslocamento)
        {
            a->setColuna(a->getColuna() + deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }

        if (a->getLinha() - posy > deslocamento)
        {
            a->setLinha(a->getLinha() - deslocamento); // c.posy -= deslocamento;
        }
        else
        {
            a->setLinha(posy);
        }
    }
    else if (a->getColuna() < posx && a->getLinha() < posy) // Diagonal Direita Baixo
    {

        if (posx - a->getColuna() > deslocamento)
        {
            a->setColuna(a->getColuna() + deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }

        if (posy - a->getLinha() > deslocamento)
        {
            a->setLinha(a->getLinha() + deslocamento); // c.posy -= deslocamento;
        }
        else
        {
            a->setLinha(posy);
        }
    }
    else if (a->getColuna() > posx && a->getLinha() > posy) // Diagonal Esquerda Cima
    {

        if (a->getColuna() - posx > deslocamento)
        {
            a->setColuna(a->getColuna() - deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }

        if (a->getLinha() - posy > deslocamento)
        {
            a->setLinha(a->getLinha() - deslocamento); // c.posy -= deslocamento;
        }
        else
        {
            a->setLinha(posy);
        }
    }
    else if (a->getColuna() > posx && a->getLinha() < posy) // Diagonal Esquerda Baixo
    {

        if (a->getColuna() - posx > deslocamento)
        {
            a->setColuna(a->getColuna() - deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }

        if (posy - a->getLinha() > deslocamento)
        {
            a->setLinha(a->getLinha() + deslocamento); // c.posy -= deslocamento;
        }
        else
        {
            a->setLinha(posy);
        }
    }

    else if (a->getColuna() > posx)
    {
        if (a->getColuna() - posx > deslocamento)
        {
            a->setColuna(a->getColuna() - deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }
    }
    else if (a->getColuna() < posx)
    {
        if (posx - a->getColuna() > deslocamento)
        {
            a->setColuna(a->getColuna() + deslocamento);
        }
        else
        {
            a->setColuna(posx);
        }
    }
    else if (a->getLinha() > posy)
    {
        if (a->getLinha() - posy > deslocamento)
        {
            a->setLinha(a->getLinha() - deslocamento); // a->getLinha() -= deslocamento;
        }
        else
        {
            a->setLinha(posy);
        }
    }
    else if (a->getLinha() < posy)
    {
        if (posy - a->getLinha() > deslocamento)
        {
            a->setLinha(a->getLinha() + deslocamento);
        }
        else
        {
            a->setLinha(posy);
        }
    }
}

void Reserva::FogeDoAnimal(Animal *a, int posx, int posy, int deslocamento)
{
    if (a->getColuna() < posx && a->getLinha() > posy)
    {

        a->setColuna(a->getLinha() - deslocamento);
        a->setLinha(a->getLinha() + deslocamento);
    }
    else if (a->getColuna() > posx) // Presa lado direito do Predador
    {
        if (a->getColuna() == get_NC() - 1 && a->getLinha() < get_NL() - 1 && a->getLinha() >= 0)
        {
            if (a->getLinha() > get_NL() / 2)              // Se está mais para cima
                a->setLinha(a->getLinha() - deslocamento); // vai para baixo
            else
                a->setLinha(a->getLinha() + deslocamento); // Se nao vai para cima
        }
        else
        {
            a->setColuna(a->getColuna() + deslocamento);
        }
    }
    else if (a->getColuna() < posx) // Presa lado esquerda do Predador
    {
        if (a->getColuna() == get_NC() - 1 && a->getLinha() < get_NL() - 1 && a->getLinha() >= 0)
        {
            if (a->getLinha() > get_NL() / 2)              // Se está mais para cima
                a->setLinha(a->getLinha() - deslocamento); // vai para baixo
            else
                a->setLinha(a->getLinha() + deslocamento); // Se nao vai para cima
        }
        else
        {
            a->setColuna(a->getColuna() - deslocamento);
        }
    }
    else if (a->getLinha() > posy) // Presa em baixo do Predador
    {
        if (a->getLinha() == get_NL() - 1 && a->getColuna() < get_NC() - 1 && a->getColuna() >= 0) // Se esta no limite
        {
            if (a->getColuna() > get_NC() / 2)               // Se está mais para a direita
                a->setColuna(a->getColuna() - deslocamento); // vai para a esquerda
            else
                a->setColuna(a->getColuna() + deslocamento); // Se nao vai para a direita
        }
        else
        {
            a->setLinha(a->getLinha() + deslocamento);
        }
    }
    else if (a->getLinha() < posy) // Presa em cima do Predador
    {
        if (a->getLinha() == 0 && a->getColuna() < get_NC() - 1 && a->getColuna() >= 0) // Se esta no limite
        {
            if (a->getColuna() > get_NC() / 2)               // Se está mais para a direita
                a->setColuna(a->getColuna() - deslocamento); // vai para a esquerda
            else
                a->setColuna(a->getColuna() + deslocamento); // Se nao vai para a direita
        }
        else
        {
            a->setLinha(a->getLinha() - deslocamento);
        }
    }
}

void Reserva::AndaPerto(Animal *a, int posx, int posy, int deslocamento)
{
    int random = rand() % 8;
    if (random == 0 && posy + deslocamento <= NL)
        a->setLinha(posy + deslocamento);
    else if (random == 1 && posy - deslocamento >= 0)
        a->setLinha(posy - deslocamento);
    else if (random == 2 && posx + deslocamento <= NC)
        a->setColuna(posx + deslocamento);
    else if (random == 3 && posx - deslocamento >= 0)
        a->setColuna(posx - deslocamento);
    else if (random == 4 && posy + deslocamento <= NL && posx + deslocamento <= NC)
    {
        a->setLinha(posy + deslocamento);
        a->setColuna(posx + deslocamento);
    }
    else if (random == 5 && posy - deslocamento >= 0 && posx - deslocamento >= 0)
    {
        a->setLinha(posy - deslocamento);
        a->setColuna(posx - deslocamento);
    }
    else if (random == 6 && posy + deslocamento <= NL && posx - deslocamento >= 0)
    {
        a->setLinha(posy + deslocamento);
        a->setColuna(posx - deslocamento);
    }
    else if (random == 7 && posy - deslocamento >= 0 && posx + deslocamento <= NC)
    {
        a->setLinha(posy - deslocamento);
        a->setColuna(posx + deslocamento);
    }
}

void Reserva::VerAnimaisVisivel()
{
    for (auto it : animais)
    {
        if (it->getLinha() < get_NL() + get_pos_x() && it->getColuna() < get_NC() + get_pos_y() && it->getLinha() >= get_pos_x() && it->getColuna() >= get_pos_y())
        {
            cout << "TipoAnimal: " << it->getLetra() << endl
                 << "ID: " << it->getID() << endl
                 << "Saude: " << it->getSaude() << endl
                 << "Fome: " << it->getFome() << endl
                 << "Peso: " << it->getPeso() << endl
                 << "Tmp_Vida: " << it->getTmp_Vida() << endl
                 << endl;
        }
    }
}

vector<Animal *> Reserva::ApagaAnim(int id, int lin, int col)
{
    Alimento *b;
    if (id == -1)
    {
        for (int i = 0; i < animais.size(); i++)
        {
            if (animais[i]->getLinha() == lin && animais[i]->getColuna() == col)
            {
                mat[lin][col] = ' ';
                settotalAnimaisNeg();
                do
                {
                    ladorand(&lin, &col, 1);

                } while (!checkLinCol(lin, col));

                if (animais[i]->getLetra() == 'L')
                {

                    b = new Corpo(getMainID(), -1, 10, 0);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                    settotalAlimentos();
                }
                else if (animais[i]->getLetra() == 'O')
                {
                    b = new Corpo(getMainID(), -1, animais[i]->getPeso(), 0);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                    settotalAlimentos();
                }
                else if (animais[i]->getLetra() == 'G')
                {
                    b = new Corpo(getMainID(), -1, 15, 5);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                    settotalAlimentos();
                }
                animais.erase(animais.begin() + i);
            }
        }
    }
    else if (lin == -1 && col == -1)
    {
        for (int j = 0; j < animais.size(); j++)
        {
            if (animais[j]->getID() == id)
            {
                mat[animais[j]->getLinha()][animais[j]->getColuna()] = ' ';
                settotalAnimaisNeg();
                lin = animais[j]->getLinha();
                col = animais[j]->getColuna();
                do
                {
                    ladorand(&lin, &col, 1);

                } while (!checkLinCol(lin, col));

                if (animais[j]->getLetra() == 'L')
                {

                    b = new Corpo(getMainID(), -1, 10, 0);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                }
                else if (animais[j]->getLetra() == 'O')
                {
                    b = new Corpo(getMainID(), -1, animais[j]->getPeso(), 0);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                }
                else if (animais[j]->getLetra() == 'G')
                {
                    b = new Corpo(getMainID(), -1, 15, 5);
                    alimentos.push_back(b);
                    mat[lin][col] = b->getLetra();
                    setMainID();
                    b->setColuna(col);
                    b->setLinha(lin);
                    b->setValor_NutFixo();
                }
                animais.erase(animais.begin() + j);
            }
        }
    }

    return animais;
}

vector<Alimento *> Reserva::ApagaAlim(int id, int lin, int col)
{
    if (id == -1)
    {

        for (int i = 0; i < alimentos.size(); i++)
        {
            if (alimentos[i]->getLinha() == lin && alimentos[i]->getColuna() == col)
            {
                mat[lin][col] = ' ';
                settotalAlimentosNeg();
                alimentos.erase(alimentos.begin() + i);
            }
        }
    }
    else if (lin == -1 && col == -1)
    {
        for (int j = 0; j < alimentos.size(); j++)
        {
            if (alimentos[j]->getID() == id)
            {
                mat[alimentos[j]->getLinha()][alimentos[j]->getColuna()] = ' ';
                settotalAlimentosNeg();
                alimentos.erase(alimentos.begin() + j);
            }
        }
    }

    return alimentos;
}

void Reserva::LimpaReserva()
{
    int i, j, x, y;
    int aux = 0;

    for (i = 0; i < NL; i++)
    {
        for (j = 0; j < NC; j++)
        {
            if (mat[i][j] != ' ')
            {
                for (int x = 0; x < animais.size(); x++)
                {
                    if (animais[x]->getLinha() == i && animais[x]->getColuna() == j)
                    {
                        aux++;
                    }
                }
                for (int y = 0; y < alimentos.size(); y++)
                {
                    if (alimentos[y]->getLinha() == i && alimentos[y]->getColuna() == j)
                    {
                        aux++;
                    }
                }
                if (aux != 0)
                {
                    aux = 0;
                }
                else
                {
                    mat[i][j] = ' ';
                }
            }
        }
    }
}

void Reserva::MeteVaziosReserva()
{
    for (auto it : alimentos)
    {
        if (mat[it->getLinha()][it->getColuna()] == ' ')
        {
            mat[it->getLinha()][it->getColuna()] = it->getLetra();
        }
    }

    for (auto it2 : animais)
    {
        if (mat[it2->getLinha()][it2->getColuna()] == ' ')
        {
            mat[it2->getLinha()][it2->getColuna()] = it2->getLetra();
        }
    }
}

//---JOGOS-GUARDADOS---

string Reserva::getNomeJogo()
{
    return NomeJogo;
}
void Reserva::setNomeJogo(string n)
{
    NomeJogo = n;
}

void SaveLoad::saveJogo(Reserva *aux)
{
    jogosGuardados.push_back(aux);
}

Reserva *SaveLoad::encontraJogo(string nome)
{
    for (int i = 0; i < jogosGuardados.size(); i++)
        if (jogosGuardados[i]->getNomeJogo() == nome)
        {
            return jogosGuardados[i];
        }
    return nullptr;
}