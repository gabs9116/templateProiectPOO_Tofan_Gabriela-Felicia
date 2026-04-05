#pragma once
#include <iostream>
#include "2produs.h"

class Floare : public Produs {
    protected:
        int gradStare; // procent: 0% -> ofilita, 100% -> proaspat udata
    public:
        // constructor cu parametri
        Floare(const std::string& nume, double pretBaza, int gradStare);

        // destructor virtual
        virtual ~Floare();

        // redefinirea afisarii
        void afisare(std::ostream& out) const override; 

        // functie pentru schimbarea gradului de stare al florii
        void aplicaIngrijire() override;

        //getter
        int getGradStare() const;
};
