#ifndef GRAF_LS_HPP
#define GRAF_LS_HPP
#include "graf.hpp"
using namespace std;

class graf_LS: public graf {

  vector< vector<krawedz*> > listaSasiedztwa;
  
public:

  void dodajWierzcholek(wierzcholek *w);
  
  void dodajKrawedz(krawedz* k);

  void zapiszDoPliku(const char* nazwa);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  int wagaKrawedzi(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void wyczysc();

};

#endif
