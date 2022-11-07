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
    struct dir_cell* cells;
    //profundidade do diretório
    int dir_prof;
};


int make_address(int key, int profundidade);

void init_function(FILE* arquivo_diretorio);

void finish_function(FILE* arquivo_diretorio);

int op_find(int key, int * rrn_found_bucket)

int op_add(int key);

int bk_add_key(struct bucket bk, int key);

int bk_split(struct bucket bk);

int dir_double();

void leia_bucket(int rrn_bucket, bucket * bk);

int find_new_range(struct bucket old_bk, int* new_start, int* new_end);

int dir_ins_bucket(int bucket_address, int start, int end);

#endif