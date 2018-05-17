#include <iostream>
#include "pilha.h"

using namespace std;

class A
{
private:
    int a;
public:
    A(int n): a(n) {};
    int n() { return a * 2; }
};

int main()
{

    Pilha <A> pi(3);
    A a1(1);
    A a2(2);

    pi.push(a1);
    pi.push(a2);

    cout << pi.pop().n() << endl;
    cout << pi.pop().n() << endl;

    return 0;
}

