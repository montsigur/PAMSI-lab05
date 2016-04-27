#include <iostream>
#include <vector>
#include <string>
using namespace std;

class wierzcholek {

  string dane;

public:

  wierzcholek(string dane0);

};

class graf {

  vector<wierzcholek*> wierzcholki;
  vector<krawedz*> krawedzie;

  bool juzDodany(wierzcholek* w);

public:

  void dodajWierzcholek(wierzcholek* w);

  void dodajKrawedz(wierzcholek* k);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

};
