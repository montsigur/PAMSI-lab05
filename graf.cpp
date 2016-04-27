#include "graf.hpp"

wierzcholek::wierzcholek(string dane0) { dane = dane0; }

bool graf::juzDodany(wierzcholek* w) {

  for (int i=0; i<wierzcholki.size(); i++)
    if (wierzcholki[i] == w)
      return true;

  return false;

}

void graf::dodajWierzcholek(wierzcholek* w) {

  if (!juzDodany(w))
    wierzcholki.push_back(w);

}

void graf::dodajKrawedz(krawedz* k) {

  wierzcholek *u, *v;
  u = k->poczatek;
  v = k->koniec;

  dodajWierzcholek(u);
  dodajWierzcholek(v);
  
  krawedzie.push_back(k);

}

bool graf::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  for (int i=0; i<krawedzie.size(); i++)
    if (krawedzie[i]->poczatek == u and krawedzie[i]->koniec == v or
	krawedzie[i]->poczatek == v and krawedzie[i]->koniec == u)
      return true;

  return false;

}
