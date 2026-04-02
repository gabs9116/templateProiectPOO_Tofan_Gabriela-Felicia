#include "2produs.h"

// constructor cu parametri
Produs::Produs(const std::string& nume, double pretBaza) : Entitate(), nume(nume), pretBaza(pretBaza) {}

// destructor virtual
Produs::~Produs() {} 

// redefinirea afisarii
void Produs::afisare(std::ostream& out) const {
    out << "ID: " << id << " | Nume: " << nume << " | Pret de baza: " << pretBaza << " RON\n";
}

// getteri
std::string Produs::getNume() const {
    return nume;
}
double Produs::getPretBaza() const {
    return pretBaza;
}

// setter
void Produs::setPretBaza(double pretNou) { 
    pretBaza = pretNou; 
}
