#pragma once
#include <iostream>

class Entitate {
    protected:
        int id; // Id pentru fiecare obiect
        static int contorId; // membru static pentru generarea Id-urilor
    public:
        // constructor
        Entitate(); 

        // destructor virtual
        virtual ~Entitate(); 

        // transform clasa in una abstracta
        virtual void afisare(std::ostream& out) const = 0; 

        // getter pentru Id-ul unui obiect
        int getId() const; 

        // supraincarcarea operatorului de afisare
        friend std::ostream& operator<<(std::ostream& out, const Entitate& e); 
};