#include "13comanda.h"

// constructor cu parametri
Comanda::Comanda(const std::string& dataComanda) : Entitate(), dataComanda(dataComanda), totalPlata(0.0) {}

// destructor
Comanda::~Comanda() {
    produseComandate.clear(); // sterg pointerii nu produsele
}

// adaugare produs in vector
void Comanda::adaugaProdus(Produs* p) {
    if (p != nullptr) {
        produseComandate.push_back(p);
        totalPlata = calculeazaTotal();
    }
}

// calcul pret total
double Comanda::calculeazaTotal() {
    double suma = 0;
    for (const Produs* p : produseComandate) {
        suma += p -> calculeazaPretFinal();
    }
    return suma;
}

// redefinirea afisarii
void Comanda::afisare(std::ostream& out) const {
    out << "------------------------------------\n";
    out << "Comanda nr: " << id << " | Data: " << dataComanda << "\n";

    for (const Produs* p : produseComandate) {
        p->afisare(out);
    }

    out << "Total de plata: " << totalPlata << " RON\n";
    out << "------------------------------------\n";
}

// getter
double Comanda::getTotalPlata() const {
    return totalPlata;
}
