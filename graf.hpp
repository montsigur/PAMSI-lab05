#ifndef GRAF_HPP
#define GRAF_HPP
#include "krawedz.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class graf {

protected:

  bool juzDodany(wierzcholek* w);

  vector<wierzcholek*> wierzcholki;
  int indeks;
  
public:
  
  ~graf() { wyczysc(); };

  graf() { indeks = -1; }
  
  virtual void dodajWierzcholek(wierzcholek* w) = 0;

  virtual void dodajKrawedz(krawedz* k) = 0;

  void wczytajZPliku(const char* nazwa);

  virtual void zapiszDoPliku(const char* nazwa) = 0;
  
  virtual bool czySasiaduja(wierzcholek* u, wierzcholek* v) = 0;

  virtual int wagaKrawedzi(wierzcholek* u, wierzcholek* v) = 0;

  virtual void wyswietlKrawedzie() = 0;

  void wyswietlWierzcholki();

  virtual void wyczysc();
};

#endif
