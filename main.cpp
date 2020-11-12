#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <exception>
#include <vector>

typedef std::vector<std::string> seznam_slov;

void nacti(std::string const& jmeno_souboru, seznam_slov & slova) {
    std::string radka;
    std::ifstream soubor;
    soubor.open(jmeno_souboru.c_str(),std::ios::in);

    while (std::getline(soubor, radka))
        slova.push_back(radka);

    soubor.close();
}

void serad(seznam_slov & seznam) {
    bool bylo_prohozeno = true;

    while(bylo_prohozeno) {
        bylo_prohozeno = false;
        for (int i=1;i<seznam.size();i++) {
	    if (seznam[i].compare(seznam[i-1]) < 0) {
                std::string s = seznam[i];
                seznam[i] = seznam[i-1];
                seznam[i-1] = s;
                bylo_prohozeno = true;
            }
        }
    }
}

void vypis(seznam_slov const& seznam) {
    for (int i=0;i<seznam.size();i++) {
        std::cout << seznam[i] << "\n";
    }
}

bool zeptej_se_jestli_vypsat() {
    char vypsat;
    while (true) {
      std::cout << "Chcete vypsat serazena jmena na obrazovku? (A/N)" << std::endl;
      std::cin >> vypsat;
      if (vypsat == 'A' || vypsat == 'a') return true;
      else if (vypsat == 'N' || vypsat == 'n') return false;
      else std::cout << "Nerozumim. ";
    } 
}

// Nacteni 1. argumentu z prikazove radky
// Promenna argc obsahuje pocet argumentu programu (vcetne samotneho nazvu programu)
// Pole argv obsahuje jednotlive argumenty z prikazove radky
std::string nazev_z_prikazove_radky(int argc, char* argv[]) {
    if (argc < 2)
        throw std::runtime_error("Musite zadat nazev vstupniho souboru");

    return std::string(argv[1]);
}

// Samotny program

int main(int argc, char* argv[]) {

    std::string nazev_vstupniho_souboru = nazev_z_prikazove_radky(argc,argv);
    
    seznam_slov jmena;

    // UKOL 1 - Implementujte nasledujici funkci, ktera nacte do objektu "jmena"
    //          vsechna slova ve vstupnim souboru (1 radek = 1 polozka)
    nacti(nazev_vstupniho_souboru, jmena);

    std::cout << "Nacteno " << jmena.size() << " slov." << std::endl;
    std::cout << "Serazuji slova ... " << std::endl;

    // Zacatek mereni CPU casu
    clock_t start = clock();

    // UKOL 2 - Tato funkce seradi jmena podle abecedy
    //          (tridici algoritmus zvolte dle libosti :) )
    serad(jmena);

    // Konec mereni CPU casu
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    std::cout << "Hotovo. Serazeni trvalo " << seconds << " sekundy." <<  std::endl << std::endl;

    // UKOL 3 - funkce v podmince se zepta uzivatele,
    //          jestli chce vypsat jmena na obrazovku
    if (zeptej_se_jestli_vypsat()) {
      // UKOL 4 - Tato funkce vypise serazena jmena na obrazovku
      vypis(jmena);
    }

    return 0;
}
