#ifndef TRAIN_ROUTES_SERVICE_H
#define TRAIN_ROUTES_SERVICE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../utils/graph.h"

using namespace std;

class TrainRoutesService {
   private:
    Graph routes;

   public:
    TrainRoutesService();
    ~TrainRoutesService();

    void distanciaEntreRotas() const;
    int numeroDeViagens();
    int menorCaminho();
    int numeroDeRotasDiferentes();
};

#endif