#pragma once
#include "7persoana.h"
#include "13comanda.h"
#include <vector>
#include <iostream>

class Client : public Persoana {
        std::vector<Comanda> comenzi;
    public:
        // constructor cu parametri
        Client(std::string& nume, std::string& prenume, std::string& telefon);

        // destructor
        virtual ~Client();

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;

        // implementam rolului
        std::string getRol() const override;

        // adauga comanda in vector
        void adaugaComanda(const Comanda& c);
};
