#include <stdio.h>
#include <math.h>
#include "../operacoes/operacoes.c"
#include "../logger/logger.c"
#include "hash.h"
#define SUCCESS 1
#define FAILURE 0
#define DELIM_STR "|"

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
        
    }

    diretorio.cells = malloc(sizeof(dir_cell));
    diretorio.cells[0].bucket_ref = 0;
    diretorio.dir_prof = 0;
}

void finish_function(directory diretorio)
{
    FILE* arq_dir = __abrir_arquivo(NOME_ARQUIVO_DIRETORIO);
    int numero_celulas = pow(2, diretorio.dir_prof);
    for (int i = 0; i < numero_celulas; i++) 
    {
        fwrite(&diretorio.cells[i].bucket_ref, sizeof(int), 1, arq_dir);
        fputs(DELIM_STR, arq_dir);
    }
}

void leia_bucket(int rrn_bucket, bucket * bk)
{
    int byteoffset = rrn_bucket*sizeof(bucket);
    FILE* arq_bucket = __abrir_arquivo(NOME_ARQUIVO_BUCKETS);
    fseek(arq_bucket, byteoffset, SEEK_SET);
    fread(bk, sizeof(bucket), 1, arq_bucket);
}

int op_find(int key, int * rrn_found_bucket)
{
    // int dir_prof = 0;
    bucket bk;
    int address = make_address(key, diretorio.dir_prof);
    *rrn_found_bucket = diretorio.cells[address].bucket_ref;
    leia_bucket(*rrn_found_bucket, &bk);
    for (int i = 0; i < TAM_MAX_CHAVES; i++)
    {
        if (bk.chaves[i] == key)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}

int op_add(int key)
{
    int* rrn_found_bucket = NULL;
    if (op_find(key, rrn_found_bucket) == SUCCESS)
    {
        bucket bk;
        leia_bucket(*rrn_found_bucket, &bk);
        bk_add_key(bk, key);
        return SUCCESS;
    }
    return FAILURE;

}

int bk_add_key(struct bucket bk, int key)
{
    if (bk.count < TAM_MAX_CHAVES) 
    {
        bk.chaves[bk.count+1] = key;
    } 
    else 
    {
        bk_split(bk);
    }

}

int bk_split(struct bucket bk)
{
    if (bk.prof == diretorio.dir_prof) 
    {
        dir_double();

        //Não entendi
        // bucket novo_bucket;
        // make_address()
    }
    return SUCCESS;
}

int dir_double()
{
    int tam_dir = pow(2, diretorio.dir_prof);
    int novo_tam = 2*tam_dir;
    directory novodir;
    novodir.cells = malloc(sizeof(dir_cell)*novo_tam);
    for (int i = 0; i < novo_tam; i++) {
        novodir.cells[2*i].bucket_ref = diretorio.cells[i].bucket_ref;
        novodir.cells[2*i+1].bucket_ref = diretorio.cells[i].bucket_ref;
    }
    free(diretorio.cells);
    diretorio.cells = novodir.cells;
    diretorio.dir_prof++;
    return SUCCESS;
}

int find_new_range(struct bucket old_bk, int* new_start, int* new_end)
{
    int mask = 1;
    int shared_address = make_address(old_bk.chaves[0], old_bk.prof);
    int new_shared = shared_address << 1;
    new_shared |= mask;
    int bits_to_fill = diretorio.dir_prof - (old_bk.prof +1);
    new_start = * new_end = new_shared;
    for (int j = 0; j < bits_to_fill; j++)
    {
        *new_start = *new_start << 1;
        *new_end = *new_end << 1;
        *new_end = *new_end | mask;
    }
    return SUCCESS;
}



int dir_ins_bucket(int bucket_address, int start, int end)
{
    for(int j = start; j < end; j++) 
    {
        diretorio.cells[j].bucket_ref = bucket_address;
    }
    return SUCCESS;
}
