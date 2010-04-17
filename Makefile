FLAGS=-O2 -Wall

BIN_PARALELO=paralelo
BIN_SEQUENCIAL=sequencial
BIN_TABELA=cria_tabela

SCR_PATH=./src
LIB_PATH=./src/lib

SRC_PARALELO=${SCR_PATH}/paralelo.cpp
SRC_SEQUENCIAL=${SCR_PATH}/sequencial.cpp
SRC_TABELA=${LIB_PATH}/cria_tabela.cpp

LIB=${LIB_PATH}/utilidades


all: paralelo sequencial cria_tabela

paralelo: ${SRC_PARALELO}
	g++ ${FLAGS} -Lphtreads -o ${BIN_PARALELO} ${SRC_PARALELO}

${BIN_SEQUENCIAL}: ${BIN_SEQUENCIAL}.o ${LIB}.o
	g++ ${FLAGS} -o ${BIN_SEQUENCIAL} ${BIN_SEQUENCIAL}.o ${LIB}.o

${BIN_TABELA}:
	g++ ${FLAGS} -o ${BIN_TABELA} ${SRC_TABELA}

${BIN_SEQUENCIAL}.o: ${SRC_SEQUENCIAL}
	g++ ${FLAGS} -c -o ${BIN_SEQUENCIAL}.o ${SRC_SEQUENCIAL}

${LIB}.o:
	g++ ${FLAGS} -c -o ${LIB}.o ${LIB}.cpp

clean:
	rm -rf ${BIN_PARALELO} ${BIN_SEQUENCIAL} ${BIN_TABELA} *.o *~
