#include <iostream>
#include "Ingredient.h"
#include "Pizza.h"
#include "Comanda_Online.h"
#include "Meniu.h"

void verificaTip(const Produs* produs) {
    if (dynamic_cast<const Comanda_Online*>(produs)) {
        std::cout << "Este o comanda online.\n";
    } else if (dynamic_cast<const Pizza*>(produs)) {
        std::cout << "Este o pizza.\n";
    } else {
        std::cout << "Tip necunoscut.\n";
    }
}

int main() {
    Meniu<Pizza> meniuPizza;
    Meniu<Comanda_Online> meniuOnline;

    unordered_map<int, std::vector<Ingredient>> ingrediente = {
            {1, {{"Mozzarella", 0.2, 5.0}, {"Tomate", 0.1, 3.0}}}
    };

    Pizza* pizza = new Pizza(ingrediente);
    Comanda_Online* comanda = new Comanda_Online(ingrediente, 15.0);

    meniuPizza += pizza;
    meniuOnline += comanda;


    cout << meniuPizza;
    cout << meniuOnline;

    verificaTip(pizza);
    verificaTip(comanda);

    return 0;
}
