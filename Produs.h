#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>

using namespace std;

class Produs {
    static int nextId;

    const int id = nextId++;                                // Cod unic al produsului
    char * denumire = nullptr;                              // Denumirea produsului (șir de caractere)
    float pret = -1;                                        // Prețul produsului
    int cantitate = 0;                                      // Cantitatea pe stoc a produsului

public:
    Produs() = default;
    Produs(const char *, float, int);

    Produs(Produs&);
    ~Produs();
    Produs& operator=(Produs&);

    Produs operator++(int);                                 // Adauga 1 la nr de produse din stoc;
    Produs operator--(int);
    Produs& operator+=(int);
    Produs& operator-=(int);

    bool operator==(const Produs&) const;                   // Verifica daca 2 produse sunt identice dupa Id;
    bool operator!=(const Produs&) const;                   // I-am cam facut degeaba;

    bool operator==(const char *) const;                    // Verifica daca 2 produse sunt identice dupa numele primului;

    int get_id() const;                                     // Getteri;
    char* get_denumire() const;
    float get_pret() const;
    int get_cantitate() const;

    void set_denumire(const char*);                         // Setteri;
    void set_pret(float);
    void set_cantitate(int);

    friend ostream& afisX(ostream&, const Produs&);         // Afiseaza produsul in stilul comenzii de output;

    friend ostream& operator<<(ostream&, const Produs&);    // Afiseaza ca stoc ramas;
    friend istream& operator>>(istream&, Produs&);          // Citeste stoc;

    friend Produs& FindProd(const char * , Produs*, int);   // Cauta un produs intr-o baza de date;
};

#endif
