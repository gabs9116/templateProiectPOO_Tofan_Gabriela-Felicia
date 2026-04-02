#include "12client.h"

// constructor cu parametri
Client::Client(std::string nume, std::string prenume, std::string telefon) 
    : Persoana(nume, prenume, telefon) {}

// destructor
Client::~Client() {
    comenzi.clear(); // sterg obiectele nu pointerii
}   

// redefinirea afisarii
void Client::afisare(std::ostream& out) const {
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    Persoana::afisare(out);
    if (comenzi.empty()) {
        out << "Nu exista comenzi pentru acest client.\n";
    } else {
        out << "Comenzi:\n";

        for (const Comanda& c : comenzi) {
            c.afisare(out);
        }
    }
}

// implementam rolului
std::string Client::getRol() const {
    return "Client";
}

// adauga comanda in vector
void Client::adaugaComanda(const Comanda& c) {
    comenzi.push_back(c);
}