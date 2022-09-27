#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

int main() {

    std::cout << "Zadej cislo: ";
    int cele_cislo;
    std::cin >> cele_cislo;

    std::cout << "Cislo = " << cele_cislo << "\n";

    std::cout << "Zadej jmeno: ";
    std::string jmeno;
    std::cin >> jmeno;

    std::cout << "Jmeno je " << jmeno << "\n";

    enum typ_vzdelani {zs,ss,vs};

    typ_vzdelani skola = ss;

    if (skola == 1) {
        std::cout << "Vzdelani je stredni skola\n";
    }
    else {
        std::cout << "Vzdelani je jine\n";
    }

    std::ofstream vystupni_soubor("vystup.txt");

    vystupni_soubor << "Jmeno: " << jmeno << "\n";

    return 0;
}
