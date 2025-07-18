#include "bib.h"

int Produs::nextId = 0;
int Comanda::nextId = 0;

int main(int argc, char* argv[]) {

    ifstream f1 (argv[1]); // produse;                              // Deschidem si creem fisierele necesare;
    ifstream f2 (argv[2]); // clienti;
    ofstream fo1 ("output_comenzi.txt");
    ofstream fo2 ("output_stoc_ramas.txt");

    int numar_produse = CitesteNrElem(f1);                          // Citim numarul de produse si de clienti;
    int numar_clienti = CitesteNrElem(f2);
    
    Produs * stok = CreateStok(numar_produse, f1);                  // Creem baza de date a magazinului;
    ProcesareDate(numar_clienti, numar_produse, stok, fo1, f2);     // Procesam comenzile, facem vanzarea;

    StokAfis(numar_produse, fo2, stok);                             // Apoi se proceseaza stockul;   
    
    return 0;
}