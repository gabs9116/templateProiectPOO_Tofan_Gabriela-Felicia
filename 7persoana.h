#pragma once
#include <iostream>
#include <string>
#include "1entitate.h"

class Persoana : public Entitate {
    protected:
        std::string nume;
        std::string prenume;
        std::string telefon; // un sir de 10 cifre
    public:
        // constructor cu parametri
        Persoana(const std::string& nume, const std::string& prenume, const std::string& telefon);

        // destructor virtual
        virtual ~Persoana();

        // redefinirea afisarii
        void afisare(std::ostream& out) const override;

        // metoda virtuala pura pentru a obliga copii de a avea un rol
        virtual std::string getRol() const = 0;

        // getteri
        std::string getNumeComplet() const;
        std::string getNume() const;
        std::string getPrenume() const;
        std::string getTelefon() const;

        // validare
        bool areTelefonValid() const;
};
