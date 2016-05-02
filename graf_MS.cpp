#include "graf_MS.hpp"
using namespace std;

void graf_MS::dodajKrawedz(krawedz* k) {

  wierzcholek* u = k->koniec1;
  wierzcholek* v = k->koniec2;

  dodajWierzcholek(u);
  dodajWierzcholek(v);

  macierzSasiedztwa[u->indeks][v->indeks] = k;
  macierzSasiedztwa[v->indeks][u->indeks] = k;
}

void graf_MS::dodajWierzcholek(wierzcholek* w) {

  if (!juzDodany(w)) {
    
    wierzcholki.push_back(w);
    for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
      macierzSasiedztwa[i].push_back(NULL);
    w->indeks = ++indeks;
    macierzSasiedztwa.push_back(vector<krawedz*>());
    for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
      macierzSasiedztwa[indeks].push_back(NULL);
    
  }
}
  
void graf_MS::zapiszDoPliku(const char* nazwa) {

  ofstream plik(nazwa);
  
  for (unsigned int i=0; i<wierzcholki.size(); i++)
    plik << wierzcholki[i]->etykieta << " ";

  plik << endl;

  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++) {
    for (unsigned int j=0; j<macierzSasiedztwa.size(); j++)
      if (macierzSasiedztwa[i][j] != NULL)
	plik << macierzSasiedztwa[i][j]->waga << " ";
      else
	plik << "0 ";

    plik << endl;
  }	
  
  plik.close();
  
}

bool graf_MS::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  int i = u->indeks;
  int j = v->indeks;

  if (macierzSasiedztwa[i][j] != NULL)
    return true;

  else
    return false;

}

int graf_MS::wagaKrawedzi(wierzcholek* u, wierzcholek* v) {

  int i = u->indeks;
  int j = v->indeks;

  if (macierzSasiedztwa[i][j] != NULL)
    return macierzSasiedztwa[i][j]->waga;

  else
    return 0;

}

void graf_MS::wyswietlKrawedzie() {

  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
    for (unsigned int j=0; j<i; j++)
      if (macierzSasiedztwa[i][j] != NULL)
	cout << wierzcholki[i]->etykieta << ", " << wierzcholki[j]->etykieta
	     << ": " << macierzSasiedztwa[i][j]->waga << endl;

}

void graf_MS::wyczysc() {

  wierzcholki.clear();
  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
    macierzSasiedztwa[i].clear();
  macierzSasiedztwa.clear();
  indeks = -1;
  
}