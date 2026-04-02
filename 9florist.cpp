#include "9florist.h"

// constructor cu parametri
Florist::Florist(std::string nume, std::string prenume, std::string telefon, double salariuBaza, std::string dataAngajarii, int nrBucheteCreate, double bonusPerBuchet) : Angajat(nume, prenume, telefon, salariuBaza, dataAngajarii), nrBucheteCreate(nrBucheteCreate), bonusPerBuchet(bonusPerBuchet) {}

// destructor
Florist::~Florist() {}

// implementarea rolului
std::string Florist::getRol() const {
    return "Florist";
}   

// redefinirea venitului: salariu net + (nr buchete * bonus)
double Florist::calculeazaVenit() const {
    return Angajat::calculeazaVenit() + (nrBucheteCreate * bonusPerBuchet);
}

// redefinirea afisarii
void Florist::afisare(std::ostream& out) const {
    Angajat::afisare(out);
    out << "Rol: " << getRol() << " | Buchete: " << nrBucheteCreate << " | Venit Total (Net): " << calculeazaVenit() << " RON\n";
}
