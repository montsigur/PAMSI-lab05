#ifndef GRAF_LS_HPP
#define GRAF_LS_HPP
#include "graf.hpp"
using namespace std;

class graf_LS: public graf {
  
public:
  
  vector< vector<krawedz*> > listaSasiedztwa;

  void dodajWierzcholek(wierzcholek *w);
  
  void dodajKrawedz(krawedz* k);

  void zapiszDoPliku(const char* nazwa);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  int wagaKrawedzi(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void przepiszNaKopiec(kopiec &K);

  void przepiszIncydentneNaKopiec(wierzcholek* w, kopiec &K);
  
  void wyczysc();

};

#endif
