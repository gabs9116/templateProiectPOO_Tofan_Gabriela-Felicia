#pragma once
#include "10vanzator.h"
#include "9florist.h"
#include <iostream>

class Manager : public Vanzator, public Florist {
        double bonusConducere;
    public:
        // constructor cu parametri
        Manager(std::string nume, std::string prenume, std::string telefon, double salariuBaza, std::string dataAngajarii, 
            int nrBuchete, double bonusPerBuchet,
            int nrVanzari, double Comision, 
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