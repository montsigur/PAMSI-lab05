#ifndef GRAF_HPP
#define GRAF_HPP
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class wierzcholek {

public:

  string etykieta;

  wierzcholek(string etykieta);

};

class krawedz {

public:

  wierzcholek *w1, *w2;
  int waga;

  krawedz(wierzcholek* u, wierzcholek* v, int w);

};

class graf {

  bool juzDodany(wierzcholek* w);

public:

  vector<wierzcholek*> wierzcholki;
  vector<krawedz*> krawedzie;

  ~graf();
  
  void dodajWierzcholek(wierzcholek* w);

  void dodajKrawedz(krawedz* k);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  int wagaKrawedzi(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void wyswietlWierzcholki();

  void wyczysc();
};

#endif
