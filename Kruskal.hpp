#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP
#include "graf.hpp"
using namespace std;


void polaczKlastry(wierzcholek* u, wierzcholek* v) {

  wierzcholek* w;
  unsigned int n;

  vector<wierzcholek*>* klaster_u = u->klaster;
  vector<wierzcholek*>* klaster_v = v->klaster;
  
  if (klaster_u->size() < klaster_v->size()) {

    n = klaster_u->size();
    while (n > 0) {

      w = (*klaster_u)[n-1];
      (*klaster_u)[n-1] = NULL;
      w->klaster = klaster_v;
      klaster_v->push_back(w);
      n--;
      
    }

    klaster_u->clear();
  }
  
  else {

    n = klaster_v->size();
    while (n > 0) {

      w = (*klaster_v)[n-1];
      (*klaster_v)[n-1] = NULL;
      w->klaster = klaster_u;
      klaster_u->push_back(w);
      n--;
      
    }

    klaster_v->clear();
  }
}


template <typename Graf>
Graf Kruskal(Graf G) {

  Graf T;
  kopiec krawedzie;
  wierzcholek *u, *v, *w;
  krawedz* k;
  int ilosc_wierzcholkow_G = G.wierzcholki.size();

  G.przepiszNaKopiec(krawedzie);
  
  for (unsigned int i=0; i<ilosc_wierzcholkow_G; i++) {

    w = G.wierzcholki[i];
    w->klaster = new vector<wierzcholek*>;
    w->klaster->push_back(w);
    w->indeks = -1;
    
  }
  
  while (T.wierzcholki.size() < ilosc_wierzcholkow_G and !krawedzie.pusty()) {
    
    k = krawedzie.zdejmijMinimalny();
    u = k->koniec1;
    v = k->koniec2;

    if (u->klaster != v->klaster) {
      
      T.dodajKrawedz(k);
      polaczKlastry(u, v);

    }
  }
  
  return T;

}

#endif
