#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    unsigned long long factorielle = 1;

    cout << "Entrez un entier positif : ";
    cin >> n;

    for (unsigned int i = 1; i <= n; ++i) {
        factorielle *= i;
    }

    cout << n << "! = " << factorielle << endl;

    return 0;
}
