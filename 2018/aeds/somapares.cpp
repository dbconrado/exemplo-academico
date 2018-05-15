#include <iostream>

using namespace std;

int somapares(int v[], int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0)
            soma += v[i];
    return soma;
}

int main()
{
    const int n = 5;
    int v[n] = {1,2,3,4,5};
    cout << "Somando os pares do vetor [1,2,3,4,5]" << endl;
    cout << "Soma: " << somapares(v, n) << endl;
    return 0;
}
