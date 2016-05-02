#ifndef WIERZCHOLEK_HPP
#define WIERZCHOLEK_HPP
#include <string>
using namespace std;

class wierzcholek {

public:

  string etykieta;
  int indeks;

  wierzcholek(string e) { etykieta = e; indeks = -1; }
};

#endif
