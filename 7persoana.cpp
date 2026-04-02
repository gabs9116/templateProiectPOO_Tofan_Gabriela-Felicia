#include "7persoana.h"

// constructor cu parametri
Persoana::Persoana(const std::string& nume, const std::string& prenume, const std::string& telefon) : Entitate(), nume(nume), prenume(prenume), telefon(telefon) {}

// destructor virtual
Persoana::~Persoana() {}

// redefinirea afisarii
void Persoana::afisare(std::ostream& out) const {
    out << "ID: " << id << " | [" << getRol() << "] " << nume << " " << prenume << " | Tel: " << telefon << "\n";
}

// getteri
// std::string Persoana::getNumeComplet() const { return nume + " " + prenume;}
// std::string Persoana::getNume() const { return nume; }
// std::string Persoana::getPrenume() const { return prenume; }
// std::string Persoana::getTelefon() const { return telefon; }

// validare
// bool Persoana::areTelefonValid() const { return telefon.length() == 10; }
