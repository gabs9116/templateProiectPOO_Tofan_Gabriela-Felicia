#pragma once
#include <iostream>
#include <string>
#include "1entitate.h"

class Produs : public Entitate {
    protected:
        std::string nume; // numele produsului
        double pretBaza; // pretul produsului
    public:
        // constructor cu parametri
        Produs(std::string nume, double pretBaza); 

        // destructor virtual
        virtual ~Produs(); 

        // redefinirea afisarii
        void afisare(std::ostream& out) const override; 

        // polimorfisme momentan virtuale pure
        virtual double calculeazaPretFinal() const = 0;
        virtual void aplicaIngrijire() = 0;

        // getteri
        std::string getNume() const;
        double getPretBaza() const;

        // setter
        void setPretBaza(double pretNou);
};