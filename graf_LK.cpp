#include "graf_LK.hpp"
using namespace std;

void graf_LK::dodajWierzcholek(wierzcholek* w) {

  if (!juzDodany(w)) {

    w->indeks = ++indeks;
    wierzcholki.push_back(w);

  }
}

void graf_LK::dodajKrawedz(krawedz* k) {

  wierzcholek *u, *v;
  u = k->koniec1;
  v = k->koniec2;

  dodajWierzcholek(u);
  dodajWierzcholek(v);
  
  krawedzie.push_back(k);
  
}
  
void graf_LK::zapiszDoPliku(const char* nazwa) {

  ofstream plik(nazwa);
  int waga;
  
  for (unsigned int i=0; i<wierzcholki.size(); i++)
    plik << wierzcholki[i]->etykieta << " ";

  plik << endl;

  for (unsigned int i=0; i<wierzcholki.size(); i++) {
    for (unsigned int j=0; j<wierzcholki.size(); j++)
      if ((waga = wagaKrawedzi(wierzcholki[i], wierzcholki[j])) > 0)
	plik << waga << " ";
      else
	plik << 0 << " ";

    plik << endl;
  }	
  
  plik.close();
  
}

bool graf_LK::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    if ((krawedzie[i]->koniec1 == u and krawedzie[i]->koniec2 == v))
      return true;

  return false;

}

int graf_LK::wagaKrawedzi(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    if ((krawedzie[i]->koniec1 == u and krawedzie[i]->koniec2 == v))
      return krawedzie[i]->waga;

  return 0;

}

void graf_LK::wyswietlKrawedzie() {

  for (unsigned int i=0; i<krawedzie.size(); i++)
    cout << krawedzie[i]->koniec1->etykieta << ", "
	 << krawedzie[i]->koniec2->etykieta << ": "
	 << krawedzie[i]->waga << endl;
}

void graf_LK::wyczysc() {

  wierzcholki.clear();
  krawedzie.clear();
  indeks = -1;
  
}
