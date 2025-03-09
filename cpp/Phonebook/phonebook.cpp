#include "phonebook.h"
#include <iostream>

int main() {
    PhoneBook phonebook;

    PhoneBookEntry matilde("Matilde", "3332512099", "m.battisti@unipi.it");
    phonebook.addEntry(matilde);

    PhoneBookEntry pietro = PhoneBookEntry("Pietro", "3342512099", "p.valese@unipi.it");
    pietro.addictionalNumbers["work"] = "0546769800";
    phonebook.addEntry(pietro);

    PhoneBookEntry valeria = PhoneBookEntry("Valeria", "+393476912738", "valeria@gmail.it");
    phonebook.addEntry(valeria);

    phonebook.sortEntries();
    phonebook.addPrefix();

    phonebook.printAll();

    // find contact by name
    PhoneBookEntry found;
    if (phonebook.findByName("Valeria", found)) {
        std::cout << "Found Valeria!" << std::endl;
        found = valeria;
        found.print();
    } else {
        std::cout << "Valeria not found!" << std::endl;
    }

    PhoneBookEntry found1;
    if (phonebook.findByName("Pietro", found1)) {
        std::cout << "Found Pietro!" << std::endl;
        found1 = pietro;
        found1.print();
    } else {
        std::cout << "Pietro not found!" << std::endl;
    }
}