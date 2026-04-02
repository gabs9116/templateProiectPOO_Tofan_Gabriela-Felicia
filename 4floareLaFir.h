#pragma once
#include <iostream>
#include <string>
#include "3floare.h"

class FloareLaFir : public Floare {
    private:
        std::string culoare;
        int nrFire;
    public:
        // constructor cu parametri
        FloareLaFir(const std::string& nume, double pretBaza, int gradStare, const std::string culoare, int nrFire);

        // destructor virtual
        virtual ~FloareLaFir();

        // redefinirea afisarii
        void afisare(std::ostream& out) const override; 

        // pret_baza * nr_fire
        double calculeazaPretFinal() const override;
    
        // getter
        int getNrFire() const;

        // setter
        void setNrFire(int valoare);
};
