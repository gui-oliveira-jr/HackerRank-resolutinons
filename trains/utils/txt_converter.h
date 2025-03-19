#ifndef TXT_CONVERTER_H
#define TXT_CONVERTER_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class txtConverter {
 public:
  inline vector<string> txtConverter::splitTextFile(const char spliter,
                                                    const string file) {
    ifstream arquivo(file);

    vector<string> arquivoConvertido;

    if (!arquivo.is_open()) {
      throw runtime_error("Não foi possível abrir o arquivo.");
    }

    string linha;
    while (getline(arquivo, linha)) {
      istringstream fluxoLinha(linha);
      string segmento;

      while (getline(fluxoLinha, segmento, spliter)) {
        string temp;
        for (char c : segmento) {
          if (c != ' ') temp += c;
        }

        if (!temp.empty()) {
          arquivoConvertido.push_back(temp);
        }
      }
    }

    arquivo.close();

    return arquivoConvertido;
  }
};

#endif
