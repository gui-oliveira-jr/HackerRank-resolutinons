#ifndef TRAIN_ROUTER_APPLICATION_H
#define TRAIN_ROUTER_APPLICATION_H

#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "train_routes_service.h"

using namespace std;

class TrainRouterApplication {
   private:
    TrainRoutesService* trainRoutes;
    map<string, string> menuOptions;

   public:
    TrainRouterApplication();
    ~TrainRouterApplication();

    void processOption(const string idOption) const;
    void addMenuOption(string titulo, string codigo);
    void executarOpcao(function<void()> funcao) const;

    void showMenu() const;
    void updateMenu() const;
    void clearWindow() const;

    char* keyboardInput();
};

#endif