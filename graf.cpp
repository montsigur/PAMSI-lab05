#include "graf.hpp"
using namespace std;

bool graf::juzDodany(wierzcholek* w) {

  if (w->indeks < 0)
    return false;

  else
    return true;

}

void graf::wyswietlWierzcholki() {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    cout << wierzcholki[i]->etykieta << endl;

}

void graf::wczytajZPliku(const char* nazwa) {

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
    dodajWierzcholek(new wierzcholek(etykiety[i]));

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
	dodajKrawedz(new krawedz(wierzcholki[i], wierzcholki[j], wagi[j]));
  }

  plik.close();
}

void graf::wyczysc() {

  wierzcholki.clear();
  indeks = -1;

}
