#include <iostream>
using namespace std;

int main() {
    int i = 0, n, som = 0;

    while (i < 4) {
        cout << "Donnez un entier : ";
        cin >> n;
        som += n;
        i++;
    }

    cout << "Somme : " << som << endl;

    return 0;
}
