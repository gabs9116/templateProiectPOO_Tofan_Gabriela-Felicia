#include "1entitate.h"

// initializam contorul static
int Entitate::contorId = 1;

// constructor
Entitate::Entitate () {
    this -> id = contorId++;
}

// destructor virtual
Entitate::~Entitate() {}

// getter pentru Id-ul unui obiect
int Entitate::getId() const {
    return this -> id;
}

// supraincarcarea operatorului de afisare
std::ostream& operator<<(std::ostream& out, const Entitate& e) {
    e.afisare(out);
    return out;
}