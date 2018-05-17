#include <iostream>
#include "tabelahash.h"

using namespace std;

int main()
{
    TabelaHash minhatabela;

    minhatabela.inserir(101, "Edine");
    minhatabela.inserir(117, "Lucas");
    minhatabela.inserir(61, "Lucas");

    cout << "digite a chave:";
    int chave;
    cin >> chave;

    cout << minhatabela.procurar(chave) << endl;

    return 0;
}
