#ifndef GRAPH_H
#define GRAPH_H

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using ListaAdjacencia = map<string, int>;

class Graph {
 private:
  unordered_map<string, ListaAdjacencia> graphMatriz;

 public:
  Graph() : graphMatriz() {}
  ~Graph() {}

  void addVertice(const string &vertice) {
    if (graphMatriz.find(vertice) == graphMatriz.end()) {
      graphMatriz[vertice] = ListaAdjacencia();
    }
  }

  void rmVertice(const string &vertice) {
    if (graphMatriz.find(vertice) != graphMatriz.end()) {
      for (auto &[origem, destinos] : graphMatriz) {
        destinos.erase(vertice);
      }
      graphMatriz.erase(vertice);
    }
  }

  void addAresta(const string &verticeInicial, const string &verticeFinal,
                 int peso) {
    addVertice(verticeInicial);
    addVertice(verticeFinal);
    graphMatriz[verticeInicial][verticeFinal] = peso;
  }

  void rmAresta(const string &verticeInicial, const string &verticeFinal) {
    if (graphMatriz.find(verticeInicial) != graphMatriz.end()) {
      graphMatriz[verticeInicial].erase(verticeFinal);
    }
  }
};

#endif
