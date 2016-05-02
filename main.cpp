// Wojciech Michałowski
// nr albumu 218705

#include "graf_MS.hpp"
#include "graf_LK.hpp"
#include "graf_LS.hpp"
#include "generujGraf.hpp"
using namespace std;

int main(int argc, char** argv) {

  if (argc > 2) {

    int n_wierzcholkow = stoi(string(argv[1]));
    double gestosc = stod(string(argv[2]));
    
    graf_MS G_MS;
    graf_LK G_LK;
    graf_LS G_LS;
    
    generujGraf(G_MS, n_wierzcholkow, gestosc);
    generujGraf(G_LS, n_wierzcholkow, gestosc);
    generujGraf(G_LK, n_wierzcholkow, gestosc);
    
    G_MS.zapiszDoPliku("MS_out.txt");
    G_LS.zapiszDoPliku("LS_out.txt");
    G_LK.zapiszDoPliku("LK_out.txt");

    G_MS.wyczysc();
    G_LS.wyczysc();
    G_LK.wyczysc();

    G_MS.wczytajZPliku("MS_out.txt");
    G_LS.wczytajZPliku("LS_out.txt");
    G_LK.wczytajZPliku("LK_out.txt");

    G_MS.zapiszDoPliku("MS_out2.txt");
    G_LS.zapiszDoPliku("LS_out2.txt");
    G_LK.zapiszDoPliku("LK_out2.txt");
  }
    
  return 0;

}
