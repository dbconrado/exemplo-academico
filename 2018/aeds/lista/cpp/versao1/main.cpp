#include <iostream>
#include <string>

#include "lista.h"

using namespace std;

class Aplicativo
{
private:
    Lista minha_lista;

public:
    void exibirLista();
    void inserir();
    void remover();
    void procurar();
    void rodar();
};

void Aplicativo::rodar()
{

    int opcao = 0;
    do
    {
        cout << endl << "LISTA ATUAL" << endl;
        exibirLista();

        cout << "Menuzinho" << endl;
        cout << "---------" << endl;
        cout << "1. Inserir" << endl;
        cout << "2. Remover" << endl;
        cout << "3. Procurar" << endl;
        cout << "4. Sair" << endl << endl;

        cout << "O que você quer? ";

        cin >> opcao;

        switch (opcao)
        {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: procurar(); break;
            case 4: break;
            default:
                cout << "Que opção estranha..." << endl;
        }
    } while (opcao != 4);
}

void Aplicativo::exibirLista()
{
    cout << minha_lista.montarListaEmString() << endl;
}

void Aplicativo::inserir()
{
    int chave;
    string dado;

    cout << "chave: ";
    cin >> chave;
    cout << "dado: ";
    cin >> dado;

    minha_lista.inserir(chave, dado);
}

void Aplicativo::remover()
{
    int chave;
    cout << "chave: ";
    cin >> chave;
    cout << "Tentando remover a chave " << chave << endl;

    minha_lista.remover(chave);
}

void Aplicativo::procurar()
{
    int chave;
    cout << "chave: ";
    cin >> chave;

    cout << "Procurando o elemento de chave " << chave << endl << endl;
    string resultado = minha_lista.procurar(chave);
    cout << "Resultado: " << resultado << endl;
}

int main()
{
    cout << "Vamos brincar de lista duplamente encadeada" << endl << endl;

    Aplicativo app;
    app.rodar();

    return 0;
}
