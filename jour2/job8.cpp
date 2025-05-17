#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Entrez la valeur de a : ";
    cin >> a;

    cout << "Entrez la valeur de b : ";
    cin >> b;

    if (a <= b) {
        int i = a;
        while (i <= b) {
            cout << i << " ";
            i++;
        }
    } else {
        int i = a;
        while (i >= b) {
            cout << i << " ";
            i--;
        }
    }

    cout << endl;
    return 0;
}
