#include <iostream>

using namespace std;

void somabinarios(int a[], int b[], int c[], int n)
{
    int vai_um = 0;
    for (int i = n-1; i >= 0; i--)
    {
        c[i+1] = a[i] + b[i] + vai_um;
        vai_um = c[i+1] / 2;
        c[i+1] = c[i+1] % 2;
    }
    c[0] = vai_um;
}

int main()
{
    const int n = 4;
    int a[n] = {1,1,0,1};
    int b[n] = {1,0,1,0};
    int c[n+1];

    cout << "Somando os binários 1101 + 1010 = ";
    somabinarios(a, b, c, n);

    cout << "[ ";
    for (int i = 0; i < (n+1); i++)
        cout << c[i] << " ";
    cout << "]" << endl;

    return 0;
}
