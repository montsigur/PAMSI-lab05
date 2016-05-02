#ifndef GRAF_LK_HPP
#define GRAF_LK_HPP
#include "graf.hpp"
using namespace std;

class graf_LK: public graf {

  vector<krawedz*> krawedzie;
  
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
