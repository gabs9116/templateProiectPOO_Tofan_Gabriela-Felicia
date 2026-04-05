#include "4floareLaFir.h"

// constructor cu parametri
FloareLaFir::FloareLaFir(const std::string& nume, double pretBaza, int gradStare, const std::string& culoare, int nrFire): Floare(nume, pretBaza, gradStare), culoare(culoare), nrFire(nrFire) {}

// destructor virtual
FloareLaFir::~FloareLaFir() {} 

// calculul pretului final
double FloareLaFir::calculeazaPretFinal() const {
    // pretul scade daca floarea este ofilita
    double pretCurent = pretBaza;
    if (gradStare >= 20 && gradStare < 50) {
        pretCurent *= 0.6;
    } else if (gradStare < 20) {
        pretCurent *= 0.3;
    }

    return pretCurent * nrFire;
}

// redefinirea afisarii
void FloareLaFir::afisare(std::ostream& out) const {
    Floare::afisare(out);
    out << "Culoare: " << culoare << " | Cantitate: " << nrFire << " fire.\n";
}

// getter
int FloareLaFir::getNrFire() const { 
    return nrFire; 
}
std::string FloareLaFir::getCuloare() const {
    return culoare;
}

// setter
void FloareLaFir::setNrFire(int valoare) { 
    nrFire = valoare; 
}
