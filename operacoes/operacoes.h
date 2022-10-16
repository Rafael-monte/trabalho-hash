#ifndef OPERACOES_H
#define OPERACOES_H
#include <stdio.h>

//Função de imprimir o diretório (-pd)
void imprimir_diretorio();

//Função de importar as chaves a partir de um arquivo (-i)
void importar_chaves(char nome_arquivo_importacao[]);

FILE* __abrir_arquivo(const char FILE_NAME[]);

const char NOME_ARQUIVO_BUCKETS[]="buckets.dat";

const char MODO_LEITURA[]="r";

#endif