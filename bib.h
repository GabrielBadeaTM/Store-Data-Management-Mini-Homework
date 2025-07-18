#include <iostream>
#include <fstream>
#include <cstring>
#include "Client.h"
using namespace std;

int CitesteNrElem(ifstream&);
Produs * CreateStok(int , ifstream&);
void ProcesareDate(int , int , Produs * , ofstream& , ifstream& );
void SellProdus(int , Produs * , Produs& );
void StokAfis(int, ofstream&, Produs *);