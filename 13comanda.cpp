#include "13comanda.h"
#include <numeric>
#include <algorithm>

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

// calcul pret total (folosesc std::accumulate deoarece ubuntu nu accepta for urile)
double Comanda::calculeazaTotal() {
    return std::accumulate(produseComandate.begin(), produseComandate.end(), 0.0, [](double sumaCurenta, const Produs* p) {
            return sumaCurenta + p->calculeazaPretFinal();
        });
}

// redefinirea afisarii
void Comanda::afisare(std::ostream& out) const {
    out << "------------------------------------\n";
    out << "Comanda nr: " << id << " | Data: " << dataComanda << "\n";

    std::for_each(produseComandate.begin(), produseComandate.end(), [&out](const Produs* p) {
        p->afisare(out);
    });

    out << "Total de plata: " << totalPlata << " RON\n";
    out << "------------------------------------\n";
}

// getter
// double Comanda::getTotalPlata() const {
//     return totalPlata;
// }
