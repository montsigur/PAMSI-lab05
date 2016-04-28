#include "graf.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void wczytajGraf(const char* nazwa, graf &G) {

  char c;
  vector<string> etykiety;
  int ilosc_wierzcholkow, n = 0;
  string bufor, bufor_int;
  
  ifstream plik(nazwa);
  
  getline(plik, bufor);

  for (unsigned int i=0; i<bufor.size();) {

    if ((c = bufor[i]) != ' ') {
      etykiety.push_back(string()); n++;
    }
    
    else i++;
    
    while (i < bufor.size() and (c = bufor[i++]) != ' ')
      etykiety[n-1] += c;
  }

  ilosc_wierzcholkow = n;
    
  for (int i = 0; i<ilosc_wierzcholkow; i++)
    G.dodajWierzcholek(new wierzcholek(etykiety[i]));

  int* wagi = new int[ilosc_wierzcholkow];
  
  for (int i = 0; i<ilosc_wierzcholkow; i++) {

    bufor.clear();
    getline(plik, bufor);
    n = 0;
    
    for (unsigned int j=0; j<bufor.size();) {
      
      if (bufor[j] - '0' > 0 and bufor[j] - '9' <= 0
	  and n < ilosc_wierzcholkow) {
      
	while (j < bufor.size() and (c = bufor[j++]) - '0' >= 0
	       and c - '9' <= 0)
	  bufor_int += c;

	wagi[n++] = stoi(bufor_int);
	bufor_int.clear();
	
      }

      else if (bufor[j] - '0' == 0 and n < ilosc_wierzcholkow) {
	wagi[n++] = 0; j++;
      }
	
      else j++;
    }

    for (int j=0; j<ilosc_wierzcholkow; j++)
      if (wagi[j] > 0)
	G.dodajKrawedz(new krawedz(G.wierzcholki[i], G.wierzcholki[j], wagi[j]));
  }

  plik.close();
}

void zapiszGraf(const char* nazwa, graf &G) {

  ofstream plik(nazwa);
  int waga;
  
  for (unsigned int i=0; i<G.wierzcholki.size(); i++)
    plik << G.wierzcholki[i]->etykieta << " ";

  plik << endl;

  for (unsigned int i=0; i<G.wierzcholki.size(); i++) {
    for (unsigned int j=0; j<G.wierzcholki.size(); j++)
      if ((waga = G.wagaKrawedzi(G.wierzcholki[i], G.wierzcholki[j])) > 0)
	plik << waga << " ";
      else
	plik << 0 << " ";

    plik << endl;
  }	
  
  plik.close();
}

int main() {

  graf G;

  wczytajGraf("graf.txt", G);
  
  G.wyswietlWierzcholki();
  G.wyswietlKrawedzie();

  zapiszGraf("graf2.txt", G);

  cout << endl << "############" << endl;

  G.wyczysc();
  
  wczytajGraf("graf2.txt", G);
  
  G.wyswietlWierzcholki();
  G.wyswietlKrawedzie();
  
  return 0;

}
