#include "Produs.h"
#include <cstring>

#pragma region Constructori, Destructori, Operator =
Produs::Produs(const char * _den , float _pret, int _cant): id(nextId++),pret(_pret),cantitate(_cant){
    denumire = new char[strlen(_den) + 1];
    strcpy(denumire,_den);
}

Produs::Produs(Produs& p):id(p.id), pret(p.pret), cantitate(p.cantitate){
    denumire = new char[strlen(p.denumire) +1];
    strcpy(denumire,p.denumire);
}

Produs::~Produs(){
    delete [] denumire;
}

Produs& Produs::operator=(Produs& p){
    if (this == &p) {
        return *this; 
    }

    delete [] denumire;
    denumire = new char[strlen(p.denumire) +1];
    strcpy(denumire,p.denumire);

    pret = p.pret;
    cantitate = p.cantitate;

    return *this;
}
#pragma endregion

#pragma region Operatori
Produs Produs::operator++(int){
    Produs aux = *this;
    cantitate++;
    return aux;
}

Produs Produs::operator--(int){
    Produs aux = *this;
    cantitate--;
    return aux;
}

Produs& Produs::operator+=(int _i){
    cantitate += _i;
    return *this;
}

Produs& Produs::operator-=(int _i){
    cantitate -= _i;
    return *this;
}

bool Produs::operator==(const Produs& p) const{
    return (id == p.id);
}

bool Produs::operator!=(const Produs& p) const{
    return (id != p.id);
}

bool Produs::operator==(const char * c) const {
    if (denumire == nullptr) return false;

    if(strcmp(c,denumire) == 0) return true;
    else return false;
}
#pragma endregion

#pragma region Getteri
int Produs::get_id() const {
    return id;
}

char* Produs::get_denumire() const {
    return denumire;
}

float Produs::get_pret() const {
    return pret;
}

int Produs::get_cantitate() const {
    return cantitate;
}
#pragma endregion

#pragma region Setteri
void Produs::set_denumire(const char* _den){
    delete[] denumire;
    denumire = new char[strlen(_den)+1];
    strcpy(denumire,_den);
}

void Produs::set_pret(float _pret){
    pret = _pret;
}

void Produs::set_cantitate(int _cant){
    cantitate = _cant;
}
#pragma endregion

#pragma region IO
ostream& operator<<(ostream& out, const Produs& p){
    if(p.denumire == nullptr) out << "NuLL";
    else out << p.denumire;
    out << ": " << p.cantitate << ", Pret: " << p.pret;
    return out;
}

istream& operator>>(istream& in, Produs& p){
    char buf[50];
    in >> buf;
    p.denumire = new char[strlen(buf) + 1];
    strcpy(p.denumire, buf);

    in >> p.pret >> p.cantitate;

    return in;
}

ostream& afisX(ostream& out, const Produs& p){
    out << p.cantitate << " X " << p.denumire << " (" << p.pret << ")\n";
    return out;
}
#pragma endregion

#pragma region Other
Produs& FindProd(const char * nume , Produs* p , int n){
    for(int i=0;i<n;i++){
        if(p[i] == nume){
            return p[i];
        }
    }

    // In cazul in care produsul nu exista in stok sau in baza de date
    // ar trebui sa treatam cazul cu niste erori, dar doar am inchis programul 
    // pentru ca nu se cera explicit in cerinta
    exit(1);
}
#pragma endregion