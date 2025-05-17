#include "job8_2.hpp"
#include "job8_3.hpp"

int main() {
    Chien monChien;
    Chat monChat;

    cout << "=== Chien ===" << endl;
    monChien.crier();
    monChien.manger();

    cout << "\n=== Chat ===" << endl;
    monChat.crier();
    monChat.manger();

    return 0;
}
