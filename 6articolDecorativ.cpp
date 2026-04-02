#include "6articolDecorativ.h"

// constructor cu parametri
ArticolDecorativ::ArticolDecorativ(std::string& nume, double pretBaza, std::string& material, bool esteFragil) : Produs(nume, pretBaza), material(material), esteFragil(esteFragil) {}

// destructor
ArticolDecorativ::~ArticolDecorativ() {}

// redefinirea calculul pretului
double ArticolDecorativ::calculeazaPretFinal() const {
    double pretCalculat = pretBaza;
    
    // taxa de 10% daca produsul este fragil
    if (esteFragil) {
        pretCalculat += (pretBaza * 0.1);
    }
    
    return pretCalculat;
}

// redefinirea metodei de ingrijire
void ArticolDecorativ::aplicaIngrijire() {
    std::cout << "Articolul decorativ '" << nume << "' din " << material << " a fost sters de praf si verificat.\n";
}

// redefinirea afisarii
void ArticolDecorativ::afisare(std::ostream& out) const {
    Produs::afisare(out);
    out << "Material: " << material << " | Fragil: " << (esteFragil ? "DA" : "NU") << " | Pret Final: " << calculeazaPretFinal() << " RON\n";
}
