#ifndef GRAF_HPP
#define GRAF_HPP
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class wierzcholek {

public:

  string dane;

  wierzcholek(string dane0);

};

class krawedz {

public:

  wierzcholek *w1, *w2;
  int waga;

  krawedz(wierzcholek* u, wierzcholek* v, int w);

};

class graf {

  vector<wierzcholek*> wierzcholki;
  vector<krawedz*> krawedzie;

  bool juzDodany(wierzcholek* w);

public:

  void dodajWierzcholek(wierzcholek* w);

  void dodajKrawedz(krawedz* k);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void wyswietlWierzcholki();

};

#endif
