#ifndef WIERZCHOLEK_HPP
#define WIERZCHOLEK_HPP
#include <string>
#include <vector>
using namespace std;

class wierzcholek {
  
public:

  string etykieta;
  int indeks;
  vector<wierzcholek*>* klaster;

  wierzcholek(string e) { etykieta = e; indeks = -1; klaster = NULL; }
};

#endif
