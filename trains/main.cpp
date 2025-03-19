#include <iostream>

#include "headers/train_router_application.h"

int main() {
    TrainRouterApplication* app;

    cout << "Applicacao iniciada \n";

    app = new TrainRouterApplication();

    app->addMenuOption("distancia entre rotas", "1");

    app->addMenuOption("numero de viagens", "2");

    app->addMenuOption("menor caminho", "3");

    app->addMenuOption("numero de rotas diferentes", "4");

    app->showMenu();

    string opton;

    cin >> opton;

    app->processOption(opton);

    return 0;
}
