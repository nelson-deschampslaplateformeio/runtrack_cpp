#include <iostream>
using namespace std;

int main() {
    int i = 0, n, som = 0;

    do {
        cout << "Donnez un entier : ";
        cin >> n;
        som += n;
        i++;
    } while (i < 4);

    cout << "Somme : " << som << endl;

    return 0;
}
