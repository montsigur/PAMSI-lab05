#ifndef PRIMJARNIK_HPP
#define PRIMJARNIK_HPP
#include "graf.hpp"
#include <ctime>
#include <cstdlib>

template <typename Graf>
Graf PrimJarnik(Graf G) {

  srand(time(NULL));
  Graf T;
  int indeks = rand() % G.wierzcholki.size();
  kopiec krawedzie;
  vector<wierzcholek*> wierzcholki;
  wierzcholek *u, *v, *w;
  krawedz* k;

  w = G.wierzcholki[indeks];
  G.przepiszIncydentneNaKopiec(w, krawedzie);
  wierzcholki.push_back(w);
  
  while(T.wierzcholki.size() < G.wierzcholki.size()) {

    k = krawedzie.zdejmijMinimalny();
    u = k->koniec1;
    v = k->koniec2;
    
    if (u != w and u->klaster->size() == 1)
      
    
  }
  
  return T;
  
}

#endif
