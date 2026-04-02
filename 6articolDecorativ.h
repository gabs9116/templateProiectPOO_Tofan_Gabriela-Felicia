#pragma once
#include <iostream>
#include <string>
#include "2produs.h"

class ArticolDecorativ : public Produs {
private:
    std::string material;
    bool esteFragil;

public:
    // constructor cu parametri
    ArticolDecorativ(const std::string& nume, double pretBaza, const std::string& material, bool esteFragil);

    // destructor
    virtual ~ArticolDecorativ();

    // redefinirea calculul pretului
    double calculeazaPretFinal() const override;

    // redefinirea metodei de ingrijire
    void aplicaIngrijire() override;

    // redefinirea afisarii
    void afisare(std::ostream& out) const override;
};
