#include <iostream>

using namespace std;

void selectionsort(int v[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int menor = i;
        for (int j = i+1; j < n; j++)
            if (v[j] < v[menor])
                menor = j;
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

int main()
{
    const int n = 4;
    int v[n] = {9,2,5,4};

    cout << "Ordenando com selection sort..." << endl;

    cout << "vetor atual: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    selectionsort(v, n);

    cout << "vetor ordenado: ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
