#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Entrez la valeur de a : ";
    cin >> a;

    cout << "Entrez la valeur de b : ";
    cin >> b;

    if (a <= b) {
        for (int i = a; i <= b; i++) {
            cout << i << " ";
        }
    } else {
        for (int i = a; i >= b; i--) {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
