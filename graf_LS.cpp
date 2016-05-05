// Wojciech Michałowski
// nr albumu 218705

#include "graf_LS.hpp"
using namespace std;

void graf_LS::dodajKrawedz(krawedz* k) {

  wierzcholek* u = k->koniec1;
  wierzcholek* v = k->koniec2;

  dodajWierzcholek(u);
  dodajWierzcholek(v);

  listaSasiedztwa[u->indeks].push_back(k);
  listaSasiedztwa[v->indeks].push_back(k);

}

void graf_LS::dodajWierzcholek(wierzcholek* w) {
  
  if (!juzDodany(w)) {

    w->indeks = ++indeks;
    wierzcholki.push_back(w);
    listaSasiedztwa.push_back(vector<krawedz*>());
    
  }
}
  
void graf_LS::zapiszDoPliku(const char* nazwa) {

  ofstream plik(nazwa);

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    plik << wierzcholki[i]->etykieta << " ";
  plik << endl;

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    for (unsigned int j=0; j<listaSasiedztwa[i].size(); j++)
      if ((i == listaSasiedztwa[i][j]->koniec1->indeks
	   and listaSasiedztwa[i][j]->koniec2->indeks > i) or
	  (i == listaSasiedztwa[i][j]->koniec2->indeks
	   and listaSasiedztwa[i][j]->koniec1->indeks > i))
	plik << listaSasiedztwa[i][j]->koniec1->indeks << " "
	     << listaSasiedztwa[i][j]->koniec2->indeks << " "
	     << listaSasiedztwa[i][j]->waga << endl;

  plik.close();
}

bool graf_LS::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<listaSasiedztwa[u->indeks].size(); i++)
    if (listaSasiedztwa[u->indeks][i]->koniec2 == v)
      return true;

  for (unsigned int i=0; i<listaSasiedztwa[v->indeks].size(); i++)
    if (listaSasiedztwa[v->indeks][i]->koniec2 == u)
      return true;

  return false;

}

int graf_LS::wagaKrawedzi(wierzcholek* u, wierzcholek* v) {

  for (unsigned int i=0; i<listaSasiedztwa[u->indeks].size(); i++)
    if (listaSasiedztwa[u->indeks][i]->koniec2 == v)
      return listaSasiedztwa[u->indeks][i]->waga;

  return 0;

}

void graf_LS::wyswietlKrawedzie() {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    for (unsigned int j=0; j<listaSasiedztwa[i].size(); j++)
      if ((i == listaSasiedztwa[i][j]->koniec1->indeks
	   and listaSasiedztwa[i][j]->koniec2->indeks > i) or
	  (i == listaSasiedztwa[i][j]->koniec2->indeks
	   and listaSasiedztwa[i][j]->koniec1->indeks > i))
        cout << listaSasiedztwa[i][j]->koniec1->etykieta << ", "
	     << listaSasiedztwa[i][j]->koniec2->etykieta << ": "
	     << listaSasiedztwa[i][j]->waga << endl;
}

void graf_LS::przepiszNaKopiec(kopiec &K) {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    for (unsigned int j=0; j<listaSasiedztwa[i].size(); j++)
      if ((i == listaSasiedztwa[i][j]->koniec1->indeks
	   and listaSasiedztwa[i][j]->koniec2->indeks > i) or
	  (i == listaSasiedztwa[i][j]->koniec2->indeks
	   and listaSasiedztwa[i][j]->koniec1->indeks > i))
        K.dodaj(listaSasiedztwa[i][j]);
}

void graf_LS::przepiszIncydentneNaKopiec(wierzcholek* w, kopiec &K) {

  int i = w->indeks;
  krawedz* k;

  for (unsigned int j=0; j < listaSasiedztwa[i].size(); j++)
    if ((w == (k = listaSasiedztwa[i][j])->koniec1 and
	 w->klaster != k->koniec2->klaster) or
	(w == k->koniec2 and w->klaster != k->koniec1->klaster))
      K.dodaj(k);

}

void graf_LS::wyczysc() {

  wierzcholki.clear();
  for (unsigned int i=0; i<listaSasiedztwa.size(); i++)
    listaSasiedztwa[i].clear();
  listaSasiedztwa.clear();
  indeks = -1;
  
}
