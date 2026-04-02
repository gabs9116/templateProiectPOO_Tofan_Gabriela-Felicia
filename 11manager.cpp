#include "11manager.h"

// constructor cu parametri
Manager::Manager(const std::string& nume, const std::string& prenume, const std::string& telefon, double salariuBaza, const std::string& dataAngajarii, 
            int nrVanzari, double Comision, 
            int nrBuchete, double bonusPerBuchet,
            double bonusConducere) : 
        Angajat(nume, prenume, telefon, salariuBaza, dataAngajarii),
        Vanzator(nume, prenume, telefon, salariuBaza, dataAngajarii, nrVanzari, Comision),
        Florist(nume, prenume, telefon, salariuBaza, dataAngajarii, nrBuchete, bonusPerBuchet),
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
