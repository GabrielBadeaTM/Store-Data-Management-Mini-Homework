#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"

class Client {
private:
    char * nume = nullptr;                                  // Numele clientului
    Comanda comanda = Comanda();                            // Comanda clientului

public:
    Client() = default;                                     // Constructori
    Client(char *, Comanda&);

    Client(Client&);
    ~Client();

    char * get_nume() const;                                // Getteri
    Comanda& get_comanda() const;

    void set_nume(char *);                                  // Setteri
    void set_comanda(Comanda&);

    friend ostream& operator<<(ostream&, const Client&);    // Afisare conform output-ului
    friend istream& operator>>(istream&, Client&);          // Citire client
};

#endif
