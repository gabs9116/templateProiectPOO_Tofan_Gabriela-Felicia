#pragma once
#include "8angajat.h"
#include <iostream>

class Florist : virtual public Angajat {
    protected:
        int nrBucheteCreate;
        double bonusPerBuchet;
    public:
        // constructor cu parametri
        Florist(std::string& nume, std::string& prenume, std::string& telefon, double salariuBaza, std::string& dataAngajarii, int nrBucheteCreate, double bonusPerBuchet);

        // destructor virtual
        virtual ~Florist();

        // implementarea rolului
        std::string getRol() const override;

        // redefinirea venitului
        double calculeazaVenit() const override;

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;
};
