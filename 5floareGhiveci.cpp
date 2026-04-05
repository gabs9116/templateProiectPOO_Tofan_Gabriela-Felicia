#include "5floareGhiveci.h"

// constructor cu parametri
FloareGhiveci::FloareGhiveci(const std::string& nume, double pretBaza, int gradStare, const std::string& materialGhiveci): Floare(nume, pretBaza, gradStare), materialGhiveci(materialGhiveci) {}

// destructor
FloareGhiveci::~FloareGhiveci() {}

double FloareGhiveci::calculeazaPretFinal() const {
    // pretul scade daca floarea este ofilita
    double pretPlanta = pretBaza;
    if (gradStare >= 20 && gradStare < 50) {
        pretPlanta *= 0.6;
    } else if (gradStare < 20) {
        pretPlanta *= 0.3;
    }

    // adaugam la pret si costul ghiveciului
    double taxaGhiveci = pretBaza * 0.3;

    // cost suplimentar daca ghiveciul este din ceramica
    if (materialGhiveci == "ceramica" || materialGhiveci == "Ceramica") {
        taxaGhiveci += 15.0;
    }

    return pretPlanta + taxaGhiveci;
}

// redefinirea afisarii
void FloareGhiveci::afisare(std::ostream& out) const {
    Floare::afisare(out);
    out << "Tip: Ghiveci (" << materialGhiveci << ") | Pret Final (cu ghiveci): " << calculeazaPretFinal() << " RON\n";
}
