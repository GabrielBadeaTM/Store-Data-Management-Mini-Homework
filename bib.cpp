#include "bib.h"S

int CitesteNrElem(ifstream& f){
    f.seekg(0, ios::end);
    bool esteGol = (f.tellg() == 0);
    f.seekg(0, ios::beg);

    int x;
    if(f && !esteGol) f >> x;
    else x = 0;

    return x;
}

Produs * CreateStok(int _nrProd, ifstream& f){
    Produs * stok = new Produs[_nrProd]; 
    if(_nrProd != 0){
        for(int i = 0 ; i < _nrProd ; i++){
            f >> stok[i];
        }
        return stok;
    }
    return nullptr;
}

void ProcesareDate(int _nrCli, int _nrPord, Produs * database, ofstream& fout, ifstream& fin){
    Client * clienti = new Client[_nrCli];
    if(_nrCli == 0){
        clienti = nullptr;
        fout << "Nu exista clienti in magazin.";

    } else {
       
        for(int i = 0 ; i < _nrCli ; i++){
            // Citim clientul;
            fin >> clienti[i];

            // Pentru fiecare Produs din comanda clientului il vindem;
            for(int j = 0 ; j < clienti[i].get_comanda().get_nrProduse() ; j++)
            {
                SellProdus(_nrPord , database , clienti[i].get_comanda().get_produse()[j]);
            }

            // Scriem output-ul comenzii;
            fout << clienti[i];
            // In caz ca este ultimul element nu mai scriem \n\n la final
            if(i+1 != _nrCli) fout << "\n\n";
        }
    }
}

void SellProdus(int _nrProd, Produs * database, Produs& p){
    // Cauta produsul p in baza de date;
    Produs& obj = FindProd(p.get_denumire(), database, _nrProd);
                
    // Seteaza pretul produsului p;
    p.set_pret(obj.get_pret());
                
    // Scoate produsul p din baza de date;
    obj-=p.get_cantitate();
}

void StokAfis(int _nrProd, ofstream& f, Produs * _stok){
    f << "Stoc ramas\n";
    if(_nrProd != 0){
        for(int i = 0 ; i < _nrProd ; i++){
            f << _stok[i].get_id() << ". " << _stok[i];
            if(i+1 != _nrProd) f << "\n";
        }
    }
}
