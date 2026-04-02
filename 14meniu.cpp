#include "14meniu.h"
#include "4floareLaFir.h"
#include "5floareGhiveci.h"
#include "6articolDecorativ.h"
#include "15erori.h"
#include "9florist.h"
#include "11manager.h"
#include "10vanzator.h"
#include "12client.h"
#include "13comanda.h"
#include <iostream>

// Initializarea pointerului static
Meniu* Meniu::instanta = nullptr;

// constructor
Meniu::Meniu() {}

// metoda de acces
Meniu* Meniu::getInstanta() {
    if (instanta == nullptr) {
        instanta = new Meniu();
    }
    return instanta;
}

// destructor
Meniu::~Meniu() {
    for (auto produs : inventar) {
        delete produs;
    }
    for (auto persoana : oameni) {
        delete persoana;
    }
    inventar.clear();
    oameni.clear();
}

// bucla principala a programului
void Meniu::ruleaza() { 
    int optiune = -1;
    do {
        std::cout << "\n====================================";
        std::cout << "\n   - Management Produse -";
        std::cout << "\n1. Adauga produs nou";
        std::cout << "\n2. Afiseaza inventar produse";
        std::cout << "\n3. Modifica pret produs";
        std::cout << "\n4. Sterge produs din stoc";
        std::cout << "\n5. Cauta produs dupa nume";
        std::cout << "\n6. Ingrijire generala flori";
        
        std::cout << "\n\n   - Management Personal -";
        std::cout << "\n7. Angajeaza persoana noua";
        std::cout << "\n8. Concediaza angajat (ID)";
        std::cout << "\n9. Afiseaza echipa (Angajati)";
        
        std::cout << "\n\n   - Management Clienti & Comenzi -";
        std::cout << "\n10. Inregistreaza client nou";
        std::cout << "\n11. Sterge client din baza";
        std::cout << "\n12. Adauga comanda pentru client";
        std::cout << "\n13. Afiseaza lista clienti";
        
        std::cout << "\n0. Iesire Platforma";
        std::cout << "\n====================================";
        std::cout << "\nAlege o optiune: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1: adaugaProdus(); break;
            case 2: afiseazaTot(); break;
            case 3: modificaPret(); break;
            case 4: stergeProdus(); break;
            case 5: cautaDupaNume(); break;
            case 6: ingrijireGenerala(); break;
            case 7: angajeazaPersoana(); break;
            case 8: concediazaAngajat(); break;
            case 9: afiseazaAngajati(); break;
            case 10: adaugaClient(); break;
            case 11: stergeClient(); break;
            case 12: adaugaComandaClient(); break;
            case 13: afiseazaClienti(); break;
            case 0: std::cout << "Inchidere platforma. La revedere!\n"; break;
            default: std::cout << "Optiune invalida!\n"; break;
        }
    } while (optiune != 0);
}

// === FUNCTII PRODUSE ===

// adaugarea unui produs
void Meniu::adaugaProdus() {
    try {
        int tip;
        std::cout << "Ce tip de Produs ? (1 - Floare la fir | 2 - Floare la ghiveci | 3 - Articol Decorativ): ";
        std::cin >> tip;

        std::string nume;
        std::cout << "Nume: "; 
        std::cin >> nume;

        double pret;
        std::cout << "Pret: "; 
        std::cin >> pret;

        if (pret <= 0) 
            throw ExceptieValidareDate("Pretul trebuie sa fie pozitiv!");

        if (tip == 1) { // floare la fir
            int grad;
            std::cout << "Grad de prospetime (0 (foarte ofilite) - 100 (foarte proaspete)): "; std::cin >> grad;

            std::string culoare;
            std::cout << "Culoare: "; std::cin >> culoare;

            int nrFire;
            std::cout << "Nr. fire: "; std::cin >> nrFire;

            inventar.push_back(new FloareLaFir(nume, pret, grad, culoare, nrFire));
        } else 
            if (tip == 2) { // floare la ghiveci
                int grad;
                std::cout << "Grad de prospetime (0 (foarte ofilite) - 100 (foarte proaspete)): "; std::cin >> grad;

                std::string material;
                std::cout << "Material ghiveci: "; std::cin >> material;

                inventar.push_back(new FloareGhiveci(nume, pret, grad, material));
            } else 
                if (tip == 3) { // articol decorativ
                    std::string material;
                    std::cout << "Material: "; std::cin >> material;

                    int esteFragilInt;
                    std::cout << "Este fragil? (1 - Da | 0 - Nu): "; std::cin >> esteFragilInt;
                    bool esteFragil = (esteFragilInt == 1);

                    inventar.push_back(new ArticolDecorativ(nume, pret, material, esteFragil));
                } else {
                    std::cout << "Tip invalid!\n";
                }

        std::cout << "Produs adaugat!\n";

    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

// afisarea tuturor produselor
void Meniu::afiseazaTot() const {
    if (inventar.empty()) {
        std::cout << "Stocul este gol.\n";
        return;
    }
    for (const auto p : inventar) {
        p -> afisare(std::cout);
        std::cout << "\n";
    }
}

// modificarea pretului unui produs
void Meniu::modificaPret() {
    try {
        int idCautat;
        std::cout << "Introduceti ID-ul produsului pentru modificare: ";
        std::cin >> idCautat;

        bool gasit = false;
        for (Produs* p : inventar) {
            if (p -> getId() == idCautat) {
                gasit = true;
                double pretNou;
                std::cout << "Produs gasit: " << p -> getNume() << "\n";
                std::cout << "Pret actual: " << p -> getPretBaza() << " RON\n";
                std::cout << "Introduceti noul pret: ";
                std::cin >> pretNou;

                if (pretNou <= 0) {
                    throw ExceptieValidareDate("Noul pret trebuie sa fie pozitiv!");
                }

                p->setPretBaza(pretNou);
                
                std::cout << "Pretul a fost actualizat cu succes!\n";
                break;
            }
        }

        if (!gasit) {
            std::cout << "Produsul cu ID-ul " << idCautat << " nu a fost gasit.\n";
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
}

// stergerea unui produs
void Meniu::stergeProdus() {
    int idDeSters;
    std::cout << "Introduceti ID-ul produsului de sters: ";
    std::cin >> idDeSters;

    bool gasit = false;

    // cppcheck-suppress useStlAlgorithm
    for (auto it = inventar.begin(); it != inventar.end(); ++it) {
        if ((*it) -> getId() == idDeSters) {
            std::cout << "Produsul '" << (*it) -> getNume() << "' a fost sters.\n";
            delete *it;
            inventar.erase(it); 
            gasit = true;
            break;
        }
    }

    if (!gasit) {
        std::cout << "Eroare: Produsul cu ID-ul " << idDeSters << " nu exista in stoc.\n";
    }
}

// cautarea produselor dupa nume
void Meniu::cautaDupaNume() const {
    std::string numeCautat;
    std::cout << "Introduceti numele produsului cautat: ";
    std::cin >> numeCautat;

    bool gasit = false;
    std::cout << "Rezultatele cautarii pentru '" << numeCautat << "':\n";
    
    for (const Produs* p : inventar) {
        if (p -> getNume() == numeCautat) {
            p -> afisare(std::cout); 
            gasit = true;
        }
    }

    if (!gasit) {
        std::cout << "Nu s-a gasit niciun produs care sa contina numele '" << numeCautat << "'.\n";
    }
}

// ingrijirea generala a florilor
void Meniu::ingrijireGenerala() {
    std::cout << "Se aplica ingrijire florilor din stoc...\n";
    for (Produs* p : inventar) {
        // folosim dynamic_cast pentru a identifica doar obiectele de tip Floare
        Floare* f = dynamic_cast<Floare*>(p);

        if (f != nullptr) {
            f -> aplicaIngrijire();
        }
    }
}

// === FUNCTII ANGAJATI ===

// adaugare unui angajat nou in vector
void Meniu::angajeazaPersoana() {
    std::string nume, prenume, telefon, data;
    double salariu;
    int tip;

    std::cout << "Ce fel de angajat doriti sa adaugati? (1-Florist, 2-Vanzator, 3-Manager): "; std::cin >> tip;
    std::cout << "Nume: "; std::cin >> nume; 
    std::cout << "Prenume: "; std::cin >> prenume;
    std::cout << "Telefon: "; std::cin >> telefon; 
    std::cout << "Salariu: "; std::cin >> salariu;
    std::cout << "Data: "; std::cin >> data;

    if (tip == 1) {
        oameni.push_back(new Florist(nume, prenume, telefon, salariu, data, 0, 10));
    }  else if (tip == 2) {
        oameni.push_back(new Vanzator(nume, prenume, telefon, salariu, data, 0, 5));
    } else if (tip == 3) {
        oameni.push_back(new Manager(nume, prenume, telefon, salariu, data, 0, 5, 0, 5, 1000));
    }

    std::cout << "Angajat inregistrat!\n";
}

// stergerea unui angajat existent dupa id
void Meniu::concediazaAngajat() {
    int id; 
    std::cout << "ID Angajat de concediat: "; std::cin >> id;

    // cppcheck-suppress useStlAlgorithm
    for (auto it = oameni.begin(); it != oameni.end(); ++it) {
        if ((*it) -> getId() == id && dynamic_cast<Angajat*>(*it)) {
            delete *it; 
            oameni.erase(it);

            std::cout << "Angajat concediat.\n"; 
            return;
        }
    }
    std::cout << "Angajatul nu a fost gasit.\n";
}

// functie pentru afisarea tuturor angajatilor
void Meniu::afiseazaAngajati() const {
    for (auto p : oameni) {
        if (dynamic_cast<Angajat*>(p)) {
            p -> afisare(std::cout);
            std::cout << "\n";
        }
    }
}

// === FUNCTII CLIENTI ===

// adaugare unui client nou in vector
void Meniu::adaugaClient() {
    std::string nume, prenume, telefon;
    std::cout << "Nume: "; std::cin >> nume; 
    std::cout << "Prenume: "; std::cin >> prenume;
    std::cout << "Tel: "; std::cin >> telefon;

    oameni.push_back(new Client(nume, prenume, telefon));
}

// stergerea unui client existent dupa id
void Meniu::stergeClient() {
    int id; 
    std::cout << "ID Client de sters: "; std::cin >> id;

    // cppcheck-suppress useStlAlgorithm
    for (auto it = oameni.begin(); it != oameni.end(); ++it) {
        if ((*it) -> getId() == id && dynamic_cast<Client*>(*it)) {
            delete *it; 
            oameni.erase(it);

            std::cout << "Client sters.\n"; 
            return;
        }
    }
}

// adaugarea unei comenzi pentru un client
void Meniu::adaugaComandaClient() {
    int idClient; 
    std::cout << "ID Client: "; std::cin >> idClient;

    for (auto p : oameni) {
        Client* c = dynamic_cast<Client*>(p);
        if (c && c -> getId() == idClient) {
            std::string data; 
            std::cout << "Data comanda (dd.mm.yyyy): "; std::cin >> data;
            Comanda noua(data);

            int idProdus;
            std::cout << "ID Produse (0 pentru stop): ";

            while (std::cin >> idProdus && idProdus != 0) {
                for (auto prod : inventar) {
                    if (prod -> getId() == idProdus) noua.adaugaProdus(prod);
                }
            }
            c->adaugaComanda(noua);
            std::cout << "Comanda adaugata!\n"; return;
        }
    }
}

// afisarea tuturor clientilor
void Meniu::afiseazaClienti() const {
    for (auto p : oameni) {
        if (dynamic_cast<Client*>(p)) p->afisare(std::cout);
    }
}

// functii pentru adaugarea externa (nu din meniu)
void Meniu::adaugaProdusExtern(Produs* p) { inventar.push_back(p); }
void Meniu::adaugaPersoanaExtern(Persoana* p) { oameni.push_back(p); }
