#pragma once
#include "10vanzator.h"
#include "9florist.h"
#include <iostream>

class Manager : public Vanzator, public Florist {
        double bonusConducere;
    public:
        // constructor cu parametri
        Manager(const std::string& nume, const std::string& prenume, const std::string& telefon, double salariuBaza, const std::string& dataAngajarii, 
            int nrVanzari, double Comision,
            int nrBuchete, double bonusPerBuchet,
            double bonusConducere);
        
        // destructor
        virtual ~Manager();

        // implementarea rolului
        std::string getRol() const override;

        // redefinirea venitului
        double calculeazaVenit() const override;

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;
};
