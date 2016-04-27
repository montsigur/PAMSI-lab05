#include "graf.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main() {

  graf G, T;
  wierzcholek *u, *v, *w, *x;

  u = new wierzcholek(string("A"));
  v = new wierzcholek(string("B"));
  w = new wierzcholek(string("C"));
  x = new wierzcholek(string("D"));

  G.dodajKrawedz(new krawedz(u, v, 10));
  G.dodajKrawedz(new krawedz(v, u, 3));
  G.dodajKrawedz(new krawedz(w, u, 15));
  G.dodajKrawedz(new krawedz(v, w, 7));

  G.dodajWierzcholek(x);

  G.wyswietlKrawedzie();
  G.wyswietlWierzcholki();

  return 0;

}
