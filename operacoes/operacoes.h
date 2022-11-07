#ifndef OPERACOES_H
#define OPERACOES_H
#include <stdio.h>

//Define a operação que será realizada de acordo com os argumentos da linha de comando
void iniciar_programa(int numero_argumentos, char** argumentos);

//Função de imprimir o diretório (-pd)
void imprimir_diretorio();

//Função de importar as chaves a partir de um arquivo (-i)
void importar_chaves(char nome_arquivo_importacao[]);

//Função para abrir um arquivo
FILE* __abrir_arquivo(const char FILE_NAME[]);

//Constantes
const char NOME_ARQUIVO_BUCKETS[]="buckets.dat";
const char NOME_ARQUIVO_DIRETORIO[]="dir.dat";
const char MODO_LEITURA[]="r";
const char FLAG_IMPORTACAO[]="-i";
const char FLAG_IMPRESSAO_DIRETORIO[]="-pd";
const int POSICAO_FLAG_OPERACAO=1;
const int POSICAO_FLAG_NOME_ARQUIVO=2;

#endif