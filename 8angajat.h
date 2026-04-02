#pragma once
#include "7persoana.h"
#include <iostream>
#include <string>

class Angajat : public Persoana {
    protected:
        double salariuBaza;
        std::string dataAngajarii;
    public:
        // construcor cu paramentri
        Angajat(std::string& nume, std::string& prenume, std::string& telefon, double salariuBaza, std::string& dataAngajarii);

        // destructor virtual
        virtual ~Angajat();

        // calcularea salariului net
        virtual double calculeazaVenit() const;

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;

        // getter (salariu brut)
        double getSalariuBaza() const;
};
