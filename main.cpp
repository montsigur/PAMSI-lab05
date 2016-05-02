#include "graf_MS.hpp"
#include "graf_LK.hpp"
#include "graf_LS.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

  graf_MS G_MS;
  graf_LK G_LK;
  graf_LS G_LS;

  G_MS.wczytajZPliku("graf_in.txt");
  G_LK.wczytajZPliku("graf_in.txt");
  G_LS.wczytajZPliku("graf_in.txt");

  cout << "a" << endl;
  
  G_MS.wyswietlWierzcholki();
  G_MS.wyswietlKrawedzie();

  G_LK.wyswietlWierzcholki();
  G_LK.wyswietlKrawedzie();

  G_MS.zapiszDoPliku("graf_out_MS.txt");
  G_LK.zapiszDoPliku("graf_out_LK.txt");
  G_LS.zapiszDoPliku("graf_out_LS.txt");

  cout << endl << "############" << endl;

  G_MS.wyczysc();
  G_LK.wyczysc();
  G_LS.wyczysc();
  
  G_MS.wczytajZPliku("graf_out_MS.txt");
  G_LK.wczytajZPliku("graf_out_LK.txt");
  G_LS.wczytajZPliku("graf_out_LS.txt");
  
  G_MS.wyswietlWierzcholki();
  G_MS.wyswietlKrawedzie();

  G_LK.wyswietlWierzcholki();
  G_LK.wyswietlKrawedzie();
  
  return 0;

}
