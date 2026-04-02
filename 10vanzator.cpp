#include "10vanzator.h"

// Constructor cu parametri
Vanzator::Vanzator(std::string nume, std::string prenume, std::string telefon, 
                   double salariuBaza, std::string dataAngajarii, 
                   int nrVanzari, double comision)
    : Angajat(nume, prenume, telefon, salariuBaza, dataAngajarii), 
      nrVanzariEfectuate(nrVanzari), comisionPerVanzare(comision) {}

// destructor
Vanzator::~Vanzator() {}

// implementam rolului
std::string Vanzator::getRol() const {
    return "Vanzator";
}

// redefinirea venitului: salariu net + (nr vanzari * comision)
double Vanzator::calculeazaVenit() const {
    return Angajat::calculeazaVenit() + (nrVanzariEfectuate * comisionPerVanzare);
}

// redefinirea afisarii
void Vanzator::afisare(std::ostream& out) const {
    Angajat::afisare(out);
    out << "Rol: " << getRol()  << " | Vanzari: " << nrVanzariEfectuate << " | Venit Total: " << calculeazaVenit() << " RON\n";
}