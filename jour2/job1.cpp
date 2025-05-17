#include <iostream>
using namespace std;

int main() {
    int n = 0;

    do {
        cout << "Donnez un nombre > 0 : ";
        cin >> n;
    } while (n <= 0);

    return 0;
}
