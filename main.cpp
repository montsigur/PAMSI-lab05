// Wojciech Michałowski
// nr albumu 218705

#include "graf_MS.hpp"
#include "graf_LK.hpp"
#include "graf_LS.hpp"
#include "generujGraf.hpp"
#include "Kruskal.hpp"
using namespace std;

int main(int argc, char** argv) {

  if (argc > 2) {

    int n_wierzcholkow = stoi(string(argv[1]));
    double gestosc = stod(string(argv[2]));

    graf_MS G_MS, T_MS;
    graf_LS G_LS, T_LS;
    graf_LK G_LK, T_LK;

    generujGraf<graf_MS>(G_MS, n_wierzcholkow, gestosc);
    generujGraf<graf_LS>(G_LS, n_wierzcholkow, gestosc);
    generujGraf<graf_LK>(G_LK, n_wierzcholkow, gestosc);

    G_MS.zapiszDoPliku("G_MS.txt");
    G_LS.zapiszDoPliku("G_LS.txt");
    G_LK.zapiszDoPliku("G_LK.txt");
    
    T_MS = Kruskal<graf_MS>(G_MS);
    T_LS = Kruskal<graf_LS>(G_LS);
    T_LK = Kruskal<graf_LK>(G_LK);

    T_MS.zapiszDoPliku("T_MS.txt");
    T_LS.zapiszDoPliku("T_LS.txt");
    T_LK.zapiszDoPliku("T_LK.txt");
    
  }
    
  return 0;

}
