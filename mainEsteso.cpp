#include <iostream>
#include <string>
#include "DizionarioEsteso.cpp" // Assicurati che l'implementazione di DizionarioEsteso sia inclusa

int main() {

    // Creazione di un dizionario di tipo stringa
    DizionarioEsteso<std::string> dict;

    // Inserimento di coppie chiave-valore
    dict.inserisci("apple", "fruit");
    dict.inserisci("car", "vehicle");
    dict.inserisci("book", "object");

    // Recupero dei valori con chiavi esistenti
    std::cout << "Value for 'apple': " << dict.recupera("apple") << "\n";
    std::cout << "Value for 'car': " << dict.recupera("car") << "\n";

    // Tentativo di recupero di un valore con una chiave che non esiste
    std::string value = dict.recupera("pen");
    if (value != "Key not found!") {
        std::cout << "Value for 'pen': " << value << "\n";
    } else {
        std::cout << "Key 'pen' not found!\n";
    }

    // Verifica se una chiave appartiene al dizionario
    std::cout << "Does 'apple' belong to the dictionary? " << (dict.appartiene("apple") ? "Yes" : "No") << "\n";
    std::cout << "Does 'pen' belong to the dictionary? " << (dict.appartiene("pen") ? "Yes" : "No") << "\n";

    // Stampa il contenuto del dizionario
    dict.stampa();

    // Cancellazione di una chiave
    dict.cancella("car");
    std::cout << "After deleting 'car':\n";
    dict.stampa();

    return 0;
}
