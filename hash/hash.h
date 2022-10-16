#ifndef HASH_H
#define HASH_H
#include <stdio.h>

//Tamanho máximo de chaves que um bucket pode possuir na implementação
const int TAM_MAX_CHAVES=2;

//Definicao das estruturas

//Estrutura de dados que representa um bucket
struct bucket 
{
    //profundidade do bucket
    int prof;
    //quantidade de chaves armazenadas no bucket
    int count;
    //vetor que guarda as chaves que serão armazenadas no bucket
    int chaves[TAM_MAX_CHAVES];
};

//Estrutura de dados que representa uma célula do diretorio, que aponta para um bucket
struct dir_cell 
{
    //armazena o RRN de um bucket
    int bucket_ref;
};

//Estrutura de dados que representa um diretório
struct directory
{
    //células do diretório, é um vetor com todas as células que vão apontar para os buckets com os dados
    dir_cell* cells;
    //profundidade do diretório
    int dir_prof;
};


int make_address(int key, int profundidade);

void init_function(FILE* arquivo_diretorio);

void finish_function(FILE* arquivo_diretorio);

int op_find(int key, int* found_bucket);

int op_add(int key);

int bk_add_key(struct bucket bucket, int key);

int bk_split(struct bucket bucket);

int dir_double();

int find_new_range(struct bucket bucket, int* new_start, int* new_range);

int dir_ins_bucket(struct bucket bucket, int start, int end);

#endif