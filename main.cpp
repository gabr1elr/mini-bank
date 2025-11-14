#include <iostream>
using namespace std;

struct ContBancar {
    char titular[50];
    double sold;
};

void creeazaCont(ContBancar &cont) {
    cout << "Introdu numele titularului: ";
    cin.getline(cont.titular, 50);

    cout << "Introdu suma initiala: ";
    cin >> cont.sold;
    cin.ignore();
}

void depune(ContBancar &cont) {
    double suma;
    cout << "Suma de depus: ";
    cin >> suma;

    if (suma > 0) {
        cont.sold += suma;
        cout << "Ai depus " << suma << " lei. Sold actual: " << cont.sold << " lei.\n";
    } else {
        cout << "Suma invalida!\n";
    }
}

void retrage(ContBancar &cont) {
    double suma;
    cout << "Suma de retras: ";
    cin >> suma;

    if (suma <= 0) {
        cout << "Suma invalida!\n";
    } else if (suma > cont.sold) {
        cout << "Fonduri insuficiente! Sold actual: " << cont.sold << " lei.\n";
    } else {
        cont.sold -= suma;
        cout << "Ai retras " << suma << " lei. Sold actual: " << cont.sold << " lei.\n";
    }
}

void afiseazaSold(const ContBancar &cont) {
    cout << "Titular: " << cont.titular << " | Sold curent: " << cont.sold << " lei.\n";
}

int main() {
    ContBancar cont;
    cout << "=== Mini Banca ===\n";

    creeazaCont(cont);

    int optiune;
    do {
        cout << "\n--- Meniu ---\n";
        cout << "1. Depunere bani\n";
        cout << "2. Retragere bani\n";
        cout << "3. Afisare sold\n";
        cout << "4. Iesire\n";
        cout << "Alege optiunea: ";
        cin >> optiune;
        cin.ignore();

        switch (optiune) {
            case 1: depune(cont); break;
            case 2: retrage(cont); break;
            case 3: afiseazaSold(cont); break;
            case 4: cout << "La revedere!\n"; break;
            default: cout << "Optiune invalida!\n";
        }
    } while (optiune != 4);

    return 0;
}
