// Wojciech Michałowski
// nr albumu 218705

#include "graf_MS.hpp"
#include "graf_LK.hpp"
#include "graf_LS.hpp"
#include "generujGraf.hpp"
#include "Kruskal.hpp"
#include "PrimJarnik.hpp"
#include "./timer/src/Timer.h"
using namespace std;

int main() {

  string nazwa_pliku;
  char buffer[40];
  Timer timer;
  
  for (double gestosc : {0.25, 0.5, 0.75, 1.0}) {

    double gestosc_procent = gestosc * 100;
    
    sprintf(buffer, "./pomiary/pomiar_MS_%3.1f%%.txt", gestosc_procent);
    nazwa_pliku = string(buffer);
    ofstream plik_MS(nazwa_pliku);

    sprintf(buffer, "./pomiary/pomiar_LS_%3.1f%%.txt", gestosc_procent);
    nazwa_pliku = string(buffer);
    ofstream plik_LS(nazwa_pliku);

    sprintf(buffer, "./pomiary/pomiar_LK_%3.1f%%.txt", gestosc_procent);
    nazwa_pliku = string(buffer);
    ofstream plik_LK(nazwa_pliku);
    
    for (int n_wierzcholkow : {10, 50, 100, 500, 1000}) {

      graf_MS G_MS, T_MS;
      graf_LS G_LS, T_LS;
      graf_LK G_LK, T_LK;

      generujGraf<graf_LK>(G_LK, n_wierzcholkow, gestosc);
      generujGraf<graf_LS>(G_LS, n_wierzcholkow, gestosc);      
      generujGraf<graf_MS>(G_MS, n_wierzcholkow, gestosc);

      sprintf(buffer, "./grafy/graf_MS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_MS.zapiszDoPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./grafy/graf_LS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_LS.zapiszDoPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./grafy/graf_LK_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_LK.zapiszDoPliku(nazwa_pliku.c_str());

      timer.start();
      T_LK = PrimJarnik<graf_LK>(G_LK);
      timer.stop();
      plik_LK << timer.getElapsedTimeInMilliSec() << " ";

      timer.start();
      T_LS = PrimJarnik<graf_LS>(G_LS);
      timer.stop();
      plik_LS << timer.getElapsedTimeInMilliSec() << " ";

      timer.start();
      T_MS = PrimJarnik<graf_MS>(G_MS);
      timer.stop();
      plik_MS << timer.getElapsedTimeInMilliSec() << " ";
    
      sprintf(buffer, "./drzewa/MST_MS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      T_MS.zapiszDoPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./drzewa/MST_LS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      T_LS.zapiszDoPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./drzewa/MST_LK_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      T_LK.zapiszDoPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./grafy/graf_MS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_MS.wczytajZPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./grafy/graf_LS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_LS.wczytajZPliku(nazwa_pliku.c_str());

      sprintf(buffer, "./grafy/graf_LK_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      G_LK.wczytajZPliku(nazwa_pliku.c_str());

      timer.start();
      T_LK = Kruskal<graf_LK>(G_LK);
      timer.stop();
      plik_LK << timer.getElapsedTimeInMilliSec() << endl;

      timer.start();
      T_LS = Kruskal<graf_LS>(G_LS);
      timer.stop();
      plik_LS << timer.getElapsedTimeInMilliSec() << endl;

      timer.start();
      T_MS = Kruskal<graf_MS>(G_MS);
      timer.stop();
      plik_MS << timer.getElapsedTimeInMilliSec() << endl;
      
    }

    plik_MS.close();
    plik_LS.close();
    plik_LK.close();
  }
  
  return 0;

}
