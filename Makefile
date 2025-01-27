# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
TEST_DIR = tests
OBJ_DIR = $(LIB_DIR)/obj
LIB_NAME = libCStructs.a
SHARED_LIB_NAME = libCStructs.so

# Lista de arquivos
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_EXEC = $(TEST_DIR)/test_exec

# Regras padrão
.PHONY: all clean

all: $(LIB_DIR)/$(LIB_NAME) $(LIB_DIR)/$(SHARED_LIB_NAME)

# Compilar a biblioteca estática (.a)
$(LIB_DIR)/$(LIB_NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Compilar a biblioteca compartilhada (.so)
$(LIB_DIR)/$(SHARED_LIB_NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -o $@ $^

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Compilar o executável de testes
$(TEST_EXEC): $(TEST_SRCS) $(LIB_DIR)/$(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(TEST_SRCS) -L$(LIB_DIR) -lCStructs

# Limpeza
clean:
	rm -rf $(LIB_DIR) $(OBJ_DIR) $(TEST_EXEC)