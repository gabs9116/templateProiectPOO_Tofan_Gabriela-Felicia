#include <iostream>
#include <vector>
#include "14meniu.h"
#include "11manager.h"
#include "9florist.h"
#include "4floareLaFir.h"
#include "5floareGhiveci.h"
#include "6articolDecorativ.h"
#include "15erori.h"
#include "12client.h"
#include "13comanda.h"

void introducereDateInitiale(Meniu* aplicatie) {
    try {
        // ANGAJATI

        // Manager (Diamant)
        Manager* m = new Manager("Popa", "Marcel", "0712345678", 6500, "02.04.2024", 20, 5.0, 50, 10.0, 2000);
        aplicatie->adaugaPersoanaExtern(m);

        // Florist
        Florist* f = new Florist("Ionescu", "Elena", "0722334455", 4000, "10.05.2024", 120, 2.5);
        aplicatie->adaugaPersoanaExtern(f);

        // Vanzator
        Vanzator* v = new Vanzator("Vasile", "Ion", "0733445566", 3500, "15.06.2024", 200, 1.5);
        aplicatie->adaugaPersoanaExtern(v);

        // CLIENTI
        Client* c1 = new Client("Georgescu", "Ana", "0744112233");
        aplicatie->adaugaPersoanaExtern(c1);
        Client* c2 = new Client("Dumitru", "Dan", "0755998877");
        aplicatie->adaugaPersoanaExtern(c2);
        
        // Simulam o comanda veche pentru primul client
        Comanda com1("01.04.2026");
        com1.adaugaProdus(new FloareLaFir("Lalea", 10.0, 100, "Galben", 5));
        c1->adaugaComanda(com1);


        // PRODUSE
        // Flori la fir
        aplicatie->adaugaProdusExtern(new FloareLaFir("Trandafir", 15.0, 90, "Rosu", 50));
        aplicatie->adaugaProdusExtern(new FloareLaFir("Crini", 25.0, 85, "Alb", 20));

        // Flori la ghiveci
        aplicatie->adaugaProdusExtern(new FloareGhiveci("Orhidee", 55.0, 100, "Ceramica"));
        aplicatie->adaugaProdusExtern(new FloareGhiveci("Cactus Mini", 20.0, 100, "Plastic"));

        // Articole decorative
        aplicatie->adaugaProdusExtern(new ArticolDecorativ("Vaza Cristal", 150.0, "Sticla", true));
        aplicatie->adaugaProdusExtern(new ArticolDecorativ("Felicitare Handmade", 15.0, "Carton", false));

    } catch (const std::exception& e) {
        std::cout << "Eroare la initializare: " << e.what() << "\n";
    }
}

int main() {
    Meniu* aplicatie = Meniu::getInstanta();

    introducereDateInitiale(aplicatie);

    aplicatie->ruleaza();

    std::cout << "\nProgramul s-a inchis.\n";
}
