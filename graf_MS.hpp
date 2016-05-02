#ifndef GRAF_MS_HPP
#define GRAF_MS_HPP
#include "graf.hpp"
using namespace std;

class graf_MS: public graf {

  vector< vector<krawedz*> > macierzSasiedztwa;
  
public:

  void dodajWierzcholek(wierzcholek* w);

  void dodajKrawedz(krawedz* k);

  void zapiszDoPliku(const char* nazwa);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  int wagaKrawedzi(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void wyczysc();

};

#endif
