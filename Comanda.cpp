#include "Comanda.h"

#pragma region Constructori, Destructori, Operator =
Comanda::Comanda(int _zi, int _luna, int _an, int _nrProd, Produs* _ps)
:id(nextId++),zi(_zi),luna(_luna),an(_an),nrProduse(_nrProd)
{
    produse = new Produs[_nrProd];
    for(int i=0 ; i<_nrProd ; i++){
        produse[i] = _ps[i];
    }
}

Comanda::Comanda(Comanda& c)
:id(nextId++),zi(c.zi),luna(c.luna),an(c.an),nrProduse(c.nrProduse)
{
    produse = new Produs[c.nrProduse];
    for(int i=0 ; i< c.nrProduse ; i++){
        produse[i] = c.produse[i];
    }
}

Comanda::~Comanda(){
    delete [] produse;
}

Comanda& Comanda::operator=(Comanda& c){
    if (this == &c) return *this;

    delete[] produse;

    zi = c.zi;
    luna = c.luna;
    an = c.an;
    nrProduse = c.nrProduse;

    produse = new Produs[nrProduse];
    for (int i = 0; i < nrProduse; ++i) {
        produse[i] = c.produse[i];
    }

    return *this;
}
#pragma endregion

#pragma region Operatori
bool Comanda::operator==(const Comanda& c) const{
    return (id == c.id);
}

bool Comanda::operator!=(const Comanda& c) const{
    return (id != c.id);
}
#pragma endregion

#pragma region Getteri
int Comanda::get_id() const {
    return id;
}

int Comanda::get_zi() const {
    return zi;
}

int Comanda::get_luna() const {
    return luna;
}

int Comanda::get_an() const {
    return an;
}

int Comanda::get_nrProduse() const {
    return nrProduse;
}

Produs* Comanda::get_produse() const{
    return produse;
}
#pragma endregion

#pragma region Setteri
void Comanda::set_zi(int _zi) {
    zi = _zi;
}

void Comanda::set_luna(int _luna) {
    luna = _luna;
}

void Comanda::set_an(int _an) {
    an = _an;
}

void Comanda::set_nrProduse(int _nrProduse) {
    nrProduse = _nrProduse;
}

void Comanda::set_produse(Produs* _produse, int _nr) {
    delete[] produse;
    nrProduse = _nr;
    produse = new Produs[nrProduse];
    for (int i = 0; i < nrProduse; ++i) {
        produse[i] = _produse[i];
    }
}
#pragma endregion

#pragma region IO
ostream& operator<<(ostream& out, const Comanda& c){
    out << "Comanda ID: " << c.id << "\n";
    out << "Data comenzii: " << c.zi << "/" << c.luna << "/" << c.an << "\n";
    out << "Produse comandate:\n";
    for(int i = 0; i < c.nrProduse ; i++){
        afisX(out, c.produse[i]);
    }
    out << "Total comanda: " << c.pret_total() <<" RON";
    return out;
}

istream& operator>>(istream& in, Comanda& c){
    in >> c.zi >> c.luna >> c.an >> c.nrProduse;

    c.produse = new Produs[c.nrProduse];
    for(int i = 0; i < c.nrProduse ; i++){
        char buf[50]; int x;
        in >> buf;
        c.produse[i].set_denumire(buf);
        in >> x;
        c.produse[i].set_cantitate(x);
    }
    return in;
}
#pragma endregion

#pragma region Other
float Comanda::pret_total() const{
    float s = 0;
    for(int i=0 ; i<nrProduse ; i++){
        s += produse[i].get_pret() * produse[i].get_cantitate();
    }
    return s;
}
#pragma endregion