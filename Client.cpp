#include "Client.h"

#pragma region Constructori, Destructori, Operator =
Client::Client(char * _nume, Comanda& c): comanda(c){
    nume = new char[strlen(_nume) + 1];
    strcpy(nume,_nume);
}

Client::Client(Client& c): comanda(c.comanda){
    nume = new char[strlen(c.nume) + 1];
    strcpy(nume,c.nume);
}

Client::~Client(){
    delete [] nume;
}
#pragma endregion

#pragma region Getteri
char * Client::get_nume() const{
    return nume;
}

Comanda& Client::get_comanda() const{
    return (Comanda&)comanda;
}
#pragma endregion

#pragma region Setteri
void Client::set_nume(char * _nume){
    delete [] nume;
    nume = new char[strlen(_nume) + 1];
    strcpy(nume,_nume);
}

void Client::set_comanda(Comanda& c){
    comanda = c;
}
#pragma endregion

#pragma region IO
ostream& operator<<(ostream& out, const Client& c){
    out << "Nume: "<< c.nume << "\n";
    out << (Comanda&)c.comanda;
    return out;
}

istream& operator>>(istream& in, Client& c){
    char line[50];
    in.getline(line, sizeof(line));
    in.getline(line, sizeof(line));
    c.set_nume(line);
    //std::cout << line << std::endl;
    in>> c.comanda;
    return in;
}
#pragma endregion