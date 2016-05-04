// Wojciech Michałowski
// nr albumu 218705

#ifndef GENERUJGRAF_HPP
#define GENERUJGRAF_HPP
#include <ctime>
#include <cstdlib>
#include "graf.hpp"
#include "permutacje.hpp"
using namespace std;

int silnia(int n) {

  if (n < 0)
    return -1;
  
  else if (n < 2)
    return 1;

  else
    return n * silnia(n-1);
  
}

template <typename Graf>
void generujGraf(Graf &G, int n_wierzcholkow, double gestosc) {

  vector<string> permutacje, etykiety;
  vector<krawedz*> krawedzie;
  vector<wierzcholek*> wierzcholki;
  
  string znaki = string("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
  string uzyte_znaki;
  int n_znakow = 0, indeks, nty;
  int n_max_krawedzi = n_wierzcholkow * (n_wierzcholkow - 1) / 2;
  
  srand(time(NULL));

  while (silnia(n_znakow) < n_wierzcholkow) n_znakow++;
  
  uzyte_znaki = znaki.substr(rand() % 25, n_znakow);

  Permutacje(uzyte_znaki, n_znakow, permutacje);
  
  for (int i = 0; i < n_wierzcholkow; i++) {
    
    wierzcholki.push_back(new wierzcholek(permutacje[i]));
    G.dodajWierzcholek(wierzcholki[i]);

  }
  
  permutacje.clear();

  for (int i = 0; i < n_wierzcholkow-1; i++)
    for (int j = i+1; j < n_wierzcholkow; j++)
      krawedzie.push_back(new krawedz(wierzcholki[i], wierzcholki[j], rand() % 100 + 1));
  
  if (gestosc > 0.5 and gestosc < 1) {

    nty = 1 / (1-gestosc);
    
    for (int i = 0; i < n_max_krawedzi; i++)
      if ((i+1) % nty != 0)
	G.dodajKrawedz(krawedzie[i]);
  }
  
  else if (gestosc > 0 and gestosc <= 0.5) {

    nty = 1 / gestosc;

    for (int i = 0; i < n_max_krawedzi; i++)
      if ((i+1) % nty == 0)
	G.dodajKrawedz(krawedzie[i]);
  }

  else if (gestosc == 1)
    for (int i = 0; i < n_wierzcholkow * (n_wierzcholkow - 1) / 2; i++)
      G.dodajKrawedz(krawedzie[i]);
}

#endif
