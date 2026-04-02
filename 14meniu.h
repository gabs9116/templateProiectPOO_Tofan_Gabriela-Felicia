#pragma once
#include <vector>
#include "2produs.h"
#include "7persoana.h"

class Meniu {
        static Meniu* instanta;
        std::vector<Produs*> inventar;
        std::vector<Persoana*> oameni;

        // constructor privat
        Meniu();
    public:
        // metoda de acces
        static Meniu* getInstanta();

        // destructor
        ~Meniu();

        // bucla principala a programului
        void ruleaza();

        // functii specifice
        void cautaDupaNume() const;
        void ingrijireGenerala();

        // functii pentru adaugarea externa (nu din meniu)
        void adaugaProdusExtern(Produs* p);
        void adaugaPersoanaExtern(Persoana* p);

        // Management Produse
        void adaugaProdus();
        void afiseazaTot() const;
        void modificaPret();
        void stergeProdus();

        // Management Personal
        void angajeazaPersoana();
        void concediazaAngajat();
        void afiseazaAngajati() const;

        // Management Clienti & Comenzi
        void adaugaClient();
        void stergeClient();
        void adaugaComandaClient();
        void afiseazaClienti() const;
};