#include "8angajat.h"

// constructor cu parametri
Angajat::Angajat(std::string nume, std::string prenume, std::string telefon, double salariuBaza, std::string dataAngajarii) : Persoana(nume, prenume, telefon), salariuBaza(salariuBaza), dataAngajarii(dataAngajarii) {}

// destructor
Angajat::~Angajat() {}

// calcularea venit ului final
double Angajat::calculeazaVenit() const {
    return salariuBaza * 0.55; // salariu brut * 0.55
}

// redefinirea afisarii
void Angajat::afisare(std::ostream& out) const {
    Persoana::afisare(out);
    out << "Angajat din: " << dataAngajarii << " | Salariu Baza: " << salariuBaza << " RON\n";
}

// getter
double Angajat::getSalariuBaza() const {
    return salariuBaza;
}