#include <iostream>
#include <list>
#include <string>

template <typename T>
class DizionarioEsteso {
private:
    static const int TABLE_SIZE = 100; 


    struct Entry {
        std::string key;
        T value;
    };

  
    std::list<Entry> table[TABLE_SIZE];

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % TABLE_SIZE;
        }
        return hash;
    }

public:

    void inserisci(const std::string& key, const T& value) {
        int index = hashFunction(key);
        
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

   
    void cancella(const std::string& key) {
        int index = hashFunction(key);

       
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (it->key == key) {
                list.erase(it);  
                return;
            }
        }

        std::cerr << "Key not found: " << key << "\n";
    }


    T recupera(const std::string& key) const {
        int index = hashFunction(key);

        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }

        throw std::runtime_error("Key not found: " + key);
    }

    
    bool appartiene(const std::string& key) const {
        int index = hashFunction(key);

   
        for (const auto& entry : table[index]) {
            if (entry.key == key) {
                return true;
            }
        }
        return false;
    }

   
    void stampa() const {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                for (const auto& entry : table[i]) {
                    std::cout << "Index " << i << ": " << entry.key << " => " << entry.value << "\n";
                }
            }
        }
    }
};
