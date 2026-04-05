#include "12client.h"

// constructor cu parametri
Client::Client(const std::string& nume, const std::string& prenume, const std::string& telefon) 
    : Persoana(nume, prenume, telefon) {}

// destructor
Client::~Client() {
    for (auto c : comenzi) {
        delete c;
    }
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

        for (const Comanda* c : comenzi) {
            if (c != nullptr) {
                c->afisare(out);
            }
        }
    }
}

// implementam rolului
std::string Client::getRol() const {
    return "Client";
}

// adauga comanda in vector
void Client::adaugaComanda(Comanda* c) {
    if (c != nullptr) {
        comenzi.push_back(c);
    }
}
