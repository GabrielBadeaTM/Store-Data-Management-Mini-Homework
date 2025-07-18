#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"

class Comanda {
protected:
    static int nextId;

    const int id = nextId++;                                    // Id;
    int zi = -1, luna = -1, an = -1;                            // Data comenzii;
    int nrProduse = 0;                                          // Numarul total de produse din comanda;
    Produs* produse = nullptr;                                  // Vector alocat dinamic pentru produsele din comanda;

public:
    Comanda() = default;                                        // Constructor
    Comanda(int, int, int, int, Produs*);

    Comanda(Comanda&);
    ~Comanda();
    Comanda& operator=(Comanda&);

    bool operator==(const Comanda&) const;                      // Verifica daca 2 comenzi sunt identice dupa id;
    bool operator!=(const Comanda&) const;                      // Si astia cred ca i-am facut degeaba;

    int get_id() const;                                         // Getteri;
    int get_zi() const;
    int get_luna() const;
    int get_an() const;
    int get_nrProduse() const;
    Produs* get_produse() const;

    void set_zi(int);                                           // Setteri;
    void set_luna(int);
    void set_an(int);
    void set_nrProduse(int);
    void set_produse(Produs*, int);

    float pret_total() const;                                   // Calculeaza pretul total al comenzii;

    friend ostream& operator<<(ostream&, const Comanda&);       // Scrie o comanda conform output-ului (partea fara Numele Clientului);
    friend istream& operator>>(istream&, Comanda&);             // Citeste o comanda din fisierul intrare;
};

#endif
