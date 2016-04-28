#include "graf.hpp"

wierzcholek::wierzcholek(string etykieta) { wierzcholek::etykieta = etykieta; }

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
    if ((krawedzie[i]->w1 == u and krawedzie[i]->w2 == v))
      return true;

  return false;

}

int graf::wagaKrawedzi(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    if ((krawedzie[i]->w1 == u and krawedzie[i]->w2 == v))
      return krawedzie[i]->waga;

  return 0;
  
}

void graf::wyswietlKrawedzie() {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    cout << krawedzie[i]->w1->etykieta << ", "
	 << krawedzie[i]->w2->etykieta << ": "
	 << krawedzie[i]->waga << endl;

}

void graf::wyswietlWierzcholki() {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    cout << wierzcholki[i]->etykieta << endl;

}

void graf::wyczysc() { wierzcholki.clear(); krawedzie.clear(); }

graf::~graf() { wyczysc(); }
