#pragma once
#include <stdexcept>
#include <string>

// clasa de baza
class ExceptieFlorarie : public std::runtime_error {
    public:
        ExceptieFlorarie(const std::string& mesaj) : std::runtime_error(mesaj) {}
};

// exceptie pt validarea preturilor sau firelor
class ExceptieValidareDate : public std::logic_error {
    public:
        ExceptieValidareDate(const std::string& mesaj) : std::logic_error("Eroare Validare: " + mesaj) {}
};

// exceptie pentru cand nu sunt suficiente produse
class ExceptieStocInsuficient : public ExceptieFlorarie {
    public:
        ExceptieStocInsuficient() : ExceptieFlorarie("Eroare: Stocul este insuficient pentru a finaliza comanda!") {}
};

// exceptie cand comanda nu are niciu produs
class ExceptieComandaGoala : public ExceptieFlorarie {
public:
    ExceptieComandaGoala() : ExceptieFlorarie("Eroare: Nu poti finaliza o comanda fara produse!") {}
};