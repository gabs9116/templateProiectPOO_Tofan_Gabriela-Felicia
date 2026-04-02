#include "11manager.h"

// constructor cu parametri
Manager::Manager(std::string nume, std::string prenume, std::string telefon, double salariuBaza, std::string dataAngajarii, 
            int nrBuchete, double bonusPerBuchet,
            int nrVanzari, double Comision, 
            double bonusConducere) : 
        Angajat(nume, prenume, telefon, salariuBaza, dataAngajarii),
        Florist(nume, prenume, telefon, salariuBaza, dataAngajarii, nrBuchete, bonusPerBuchet),
        Vanzator(nume, prenume, telefon, salariuBaza, dataAngajarii, nrVanzari, Comision),
        bonusConducere(bonusConducere) {}

// destructor
Manager::~Manager() {}

// implementarea rolului
std::string Manager::getRol() const {
    return "Manager";
}

// redefinirea venitului
double Manager::calculeazaVenit() const {
    double extraFlorist = nrBucheteCreate * bonusPerBuchet;
    double extraVanzator = nrVanzariEfectuate * comisionPerVanzare;
    return extraFlorist + extraVanzator + Angajat::calculeazaVenit() + bonusConducere;
}

// redefinirea afisarii
void Manager::afisare(std::ostream& out) const {
    Angajat::afisare(out);
    out << "ROL: " << getRol() << " | Bonus Conducere: " << bonusConducere << " | VENIT TOTAL: " << calculeazaVenit() << " RON\n";
}