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
  
  
  return T;
  
}

#endif
