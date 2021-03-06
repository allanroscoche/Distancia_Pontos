FLAGS=-O2 -lm -lpthread

BIN_PARALELO=paralelo
BIN_SEQUENCIAL=sequencial
BIN_TABELA=cria_tabela
BIN_PONTOS=cria_pontos

SCR_PATH=./src
LIB_PATH=./src/lib

SRC_PARALELO=${SCR_PATH}/paralelo.c
SRC_SEQUENCIAL=${SCR_PATH}/sequencial.c
SRC_TABELA=${LIB_PATH}/cria_tabela.cpp
SRC_PONTOS=${LIB_PATH}/cria_pontos.c

LIB=${LIB_PATH}/utilidades


all: paralelo sequencial cria_pontos

${BIN_PARALELO}: ${BIN_PARALELO}.o ${LIB}.o
	gcc ${FLAGS} -o ${BIN_PARALELO} ${BIN_PARALELO}.o ${LIB}.o

${BIN_SEQUENCIAL}: ${BIN_SEQUENCIAL}.o ${LIB}.o
	gcc ${FLAGS} -o ${BIN_SEQUENCIAL} ${BIN_SEQUENCIAL}.o ${LIB}.o

${BIN_TABELA}:
	g++ ${FLAGS} -o ${BIN_TABELA} ${SRC_TABELA}

${BIN_PONTOS}: ${SRC_PONTOS}
	gcc ${FLAGS} -o ${BIN_PONTOS} ${SRC_PONTOS}

${BIN_SEQUENCIAL}.o: ${SRC_SEQUENCIAL}
	gcc ${FLAGS} -c -o ${BIN_SEQUENCIAL}.o ${SRC_SEQUENCIAL}

${BIN_PARALELO}.o: ${SRC_PARALELO}
	gcc ${FLAGS} -c -o ${BIN_PARALELO}.o ${SRC_PARALELO}

${LIB}.o: ${LIB}.c
	gcc ${FLAGS} -c -o ${LIB}.o ${LIB}.c

clean:
	rm -rf ${BIN_PARALELO} ${BIN_SEQUENCIAL} ${BIN_TABELA} ${BIN_PONTOS} *.o *~ ${LIB_PATH}/*.o *.*~ ${SCR_PATH}/*.*~ ${LIB_PATH}/*.*~
