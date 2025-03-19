# Nome do executável
EXEC = trains

# Diretórios
SRC_DIR = sources
HEADER_DIR = headers
UTILS_DIR = utils
BUILD_DIR = build

# Lista de arquivos-fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(UTILS_DIR)/*.cpp) main.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
OBJS := $(patsubst $(UTILS_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(OBJS))
OBJS := $(patsubst main.cpp, $(BUILD_DIR)/main.o, $(OBJS))

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(HEADER_DIR) -I$(UTILS_DIR)

# Regra padrão para compilar o projeto
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Regras para compilar os arquivos .cpp em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(HEADER_DIR)/*.h)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.cpp $(wildcard $(HEADER_DIR)/*.h)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra específica para compilar o main.cpp na raiz
$(BUILD_DIR)/main.o: main.cpp $(wildcard $(HEADER_DIR)/*.h)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

# Limpeza dos arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
