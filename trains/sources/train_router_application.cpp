
#include "../headers/train_router_application.h"

TrainRouterApplication::TrainRouterApplication() {
    trainRoutes = new TrainRoutesService();

    addMenuOption("distancia entre rotas", "1");

    addMenuOption("numero de viagens", "2");

    addMenuOption("menor caminho", "3");

    addMenuOption("numero de rotas diferentes", "4");
}

TrainRouterApplication::~TrainRouterApplication() { delete &trainRoutes; }

void TrainRouterApplication::addMenuOption(string titulo, string codigo) {
    auto isInsertedTitle = menuOptions.emplace(codigo, titulo);

    if (!isInsertedTitle.second) {
        throw runtime_error("Não foi possível inserir a opção" + titulo);
    }

    cout << "Opcao " << titulo << " adicionada com sucesso \n";
}

void TrainRouterApplication::executarOpcao(function<void()> funcao) const {
    clearWindow();
    cout << "executando funcao do cout" << endl;
    funcao();
}

void TrainRouterApplication::showMenu() const {
    for (auto& titulo : menuOptions) {
        cout << "Precione " << titulo.first << " para consultar a " << titulo.second << endl;
    }
}

void TrainRouterApplication::clearWindow() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void TrainRouterApplication::processOption(const string idOption) const {
    int idOptonConverted = stoi(idOption);

    switch (idOptonConverted) {
        case 1:
            executarOpcao([]() { trainRoutes->distanciaEntreRotas(); });
            break;

        default:
            break;
    }
}
