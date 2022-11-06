#include <stdio.h>
#include <math.h>
#include "../operacoes/operacoes.c"
#include "../logger/logger.c"
#include "hash.h"
#define SUCCESS 1
#define FAILURE 0

//Definição das estruturas de dados como tipo, para facilitar a escrita de código
typedef struct directory directory;
typedef struct bucket bucket;
typedef struct dir_cell dir_cell;

directory diretorio;


int hash(int key) 
{

}

int make_address(int key, int profundidade) 
{
    int ret_val = 0;
    int mask = 1;
    int hash_val = key;
    for (int i = 0; i < profundidade; i++) 
    {
        ret_val = ret_val << 1;
        int low_bit = hash_val & mask;
        ret_val = hash_val | low_bit;
        hash_val = hash_val >> 1;
    }
    return ret_val;
}


void init_function(FILE* arquivo_diretorio)
{
    if (arquivo_diretorio != NULL) 
    {
        // dir_cell[] diretorio
        // directory diretorio;
        // int dir_prof = log2(diretorio.dir_prof);
        log_info("Funcao ainda nao inplementada", NULL);
        return;
    }

    diretorio.cells = malloc(sizeof(dir_cell));
    diretorio.cells[0].bucket_ref = 0;
    diretorio.dir_prof = 0;
}

void finish_function(directory diretorio)
{

}

void leia_bucket(int rrn_bucket, bucket * bk){
    int byteoffset = rrn_bucket*sizeof(bucket);
    fseek();
    fread(bk, sizeof(bucket), 1, arq_bucket);

}

int op_find(int key, int * rrn_found_bucket)
{
    // int dir_prof = 0;
    bucket bk;
    int address = make_address(key, diretorio.dir_prof);
    *rrn_found_bucket = diretorio.cells[address].bucket_ref;
    leia_bucket(*rrn_found_bucket, &bk);
    if (/*Chave está em FOUND_BUCKET*/)
    {
        return SUCCESS; 
    }
    return FAILURE;
}

int op_add(int key)
{
    int* found_bucket = NULL;
    if (op_find(key, found_bucket) == SUCCESS)
    {
        bk_add_key()
    }

}

int bk_add_key(struct bucket bucket, int key);

int bk_split(struct bucket bucket);

int dir_double();

int find_new_range(struct bucket bucket, int* new_start, int* new_range);

int dir_ins_bucket(struct bucket bucket, int start, int end);
