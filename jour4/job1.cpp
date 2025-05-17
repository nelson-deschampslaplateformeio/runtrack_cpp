#include <iostream>
using namespace std;

int main() {
    int number = 2019;
    int* ptr = &number; // pointeur vers number

    cout << "La valeur de \"number\" est : " << *ptr << endl;

    return 0;
}
