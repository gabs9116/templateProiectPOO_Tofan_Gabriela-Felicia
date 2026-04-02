#pragma once
#include "3floare.h"
#include <iostream>
#include <string>

class FloareGhiveci : public Floare {
private:
    std::string materialGhiveci; // plastic, ceramica, etc.

public:
    // constructor cu parametri
    FloareGhiveci(const std::string& nume, double pretBaza, int gradStare, const std::string& materialGhiveci);

    // destructor
    virtual ~FloareGhiveci();

    // redefinirea calculul pretului
    double calculeazaPretFinal() const override;

    // redefinirea afisarea
    void afisare(std::ostream& out) const override;
};
