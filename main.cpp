#include "Tvary.h"
#include <iostream>
#include <cstdlib>

int main(int iargc, char* iargv[]) {

    Tvar* W;
    if (iargc == 2) {
        double a = std::atof(iargv[1]);
        W = new Ctverec(a);
    }
    else if (iargc == 4) {
        double a = std::atof(iargv[1]);
        double b = std::atof(iargv[2]);
        double c = std::atof(iargv[3]);
        W = new Trojuhelnik(a,b,c);
    }
    
    std::cout << "Tvar je " << W->jmeno() << std::endl;
    std::cout << "Obvod je " << W->obvod() << std::endl;
    std::cout << "Obsah je " << W->obsah() << std::endl;
    
    delete W;

    return 0;
}
