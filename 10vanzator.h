#pragma once
#include "8angajat.h"
#include <iostream>

class Vanzator : virtual public Angajat {
    protected:
        int nrVanzariEfectuate;
        double comisionPerVanzare;

    public:
        // Constructor cu parametri
        Vanzator(std::string nume, std::string prenume, std::string telefon, double salariuBaza, std::string dataAngajarii, int nrVanzari, double comision);

        // destructor
        virtual ~Vanzator();

        // implementam rolului
        std::string getRol() const override;

        // redefinirea venitului
        double calculeazaVenit() const override;

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;
};