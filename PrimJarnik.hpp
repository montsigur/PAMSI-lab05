// Wojciech Michałowski
// nr albumu 218705

#ifndef PRIMJARNIK_HPP
#define PRIMJARNIK_HPP
#include "graf.hpp"
#include <ctime>
#include <cstdlib>

void polaczKlastryPrim(wierzcholek* u, wierzcholek* v) {

  vector<wierzcholek*>* klaster_u = u->klaster;
  vector<wierzcholek*>* klaster_v = v->klaster;
  
  (*klaster_u)[0] = NULL;
  u->klaster = klaster_v;
  klaster_v->push_back(u);
  klaster_u->clear();
  
}

template <typename Graf>
Graf PrimJarnik(Graf G) {

  srand(time(NULL));
  Graf T;
  int indeks = rand() % G.wierzcholki.size();
  kopiec krawedzie;
  vector<wierzcholek*> wierzcholki_T;
  vector<krawedz*> krawedzie_T;
  wierzcholek *u, *v, *w;
  krawedz* k;

  w = G.wierzcholki[indeks];
  G.przepiszIncydentneNaKopiec(w, krawedzie);
  wierzcholki_T.push_back(w);
  
  while(wierzcholki_T.size() < G.wierzcholki.size()) {

    k = krawedzie.zdejmijMinimalny();
    u = k->koniec1;
    v = k->koniec2;
 
    if (u != w and u->klaster->size() == 1) {
      
      wierzcholki_T.push_back(u);
      polaczKlastryPrim(u, v);
      G.przepiszIncydentneNaKopiec(u, krawedzie);
      krawedzie_T.push_back(k);

    }

    else if (v != w and v->klaster->size() == 1) {
      
      wierzcholki_T.push_back(v);
      polaczKlastryPrim(v, u);
      G.przepiszIncydentneNaKopiec(v, krawedzie);
      krawedzie_T.push_back(k);
      
    }
  }

  for (unsigned int i=0; i<wierzcholki_T.size(); i++)
    wierzcholki_T[i]->indeks = -1;

  for (unsigned int i=0; i<krawedzie_T.size(); i++)
    T.dodajKrawedz(krawedzie_T[i]);
  
  return T;
  
}

#endif
