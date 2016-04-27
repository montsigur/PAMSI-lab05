#include "graf.hpp"

wierzcholek::wierzcholek(string dane0) { dane = dane0; }

krawedz::krawedz(wierzcholek* u, wierzcholek* v, int w) { w1 = u; w2 = v; waga = w; }

bool graf::juzDodany(wierzcholek* w) {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
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
  u = k->w1;
  v = k->w2;

  dodajWierzcholek(u);
  dodajWierzcholek(v);
  
  krawedzie.push_back(k);

}

bool graf::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    if ((krawedzie[i]->w1 == u and krawedzie[i]->w2 == v) or
	(krawedzie[i]->w1 == v and krawedzie[i]->w2 == u))
      return true;

  return false;

}

void graf::wyswietlKrawedzie() {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    cout << krawedzie[i]->w1->dane << ", "
	 << krawedzie[i]->w2->dane << ": "
	 << krawedzie[i]->waga << endl;

}

void graf::wyswietlWierzcholki() {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    cout << wierzcholki[i]->dane << endl;

}
