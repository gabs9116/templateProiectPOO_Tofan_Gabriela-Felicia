#pragma once
#include "1entitate.h"
#include "2produs.h"
#include <iostream>
#include <vector>
#include <string>

class Comanda : public Entitate {
        std::vector<Produs*> produseComandate;
        std::string dataComanda;
        double totalPlata;
    public:
        // constructorul cu parametri
        explicit Comanda(const std::string& dataComanda);

        // destructor
        virtual ~Comanda();

        // adaugare produs in vector
        void adaugaProdus(Produs* p);

        // calculeaza pretul total
        double calculeazaTotal();

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;

        // getter
        double getTotalPlata() const;
};
