#include "3floare.h"

// constructor cu parametri
Floare::Floare(const std::string& nume, double pretBaza, int gradStare) : Produs(nume, pretBaza), gradStare(gradStare) {
    // verific ca nu se depasesc limitele
    if(this -> gradStare > 100)
        this -> gradStare = 100;
    if(this -> gradStare < 0)
        this -> gradStare = 0;
}

// desctructor virtual
Floare::~Floare() {}

// redefinirea afisarii
void Floare::afisare(std::ostream& out) const {
    Produs::afisare(out);
    out << "Stare: " << gradStare << "%\n";
}

// schimbarea starii
void Floare::aplicaIngrijire() {
    this->gradStare += 10;
    if (this->gradStare > 100) this->gradStare = 100;
    std::cout << "Floarea '" << nume << "' a fost ingrijita.\n";
}

// getter
int Floare::getGradStare() const {
    return gradStare;
}
