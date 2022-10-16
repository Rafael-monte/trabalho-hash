#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes.h"
#include "../logger/logger.h"


void importar_chaves(char nome_arquivo_importacao[])
{
    FILE* arquivo_chaves = __abrir_arquivo(nome_arquivo_importacao);
    log_info("Iniciando importacao de arquivo!", NULL);
}


void imprimir_diretorio()
{
    FILE* arquivo_diretorio = __abrir_arquivo(NOME_ARQUIVO_BUCKETS);
    log_info("Iniciando impressao de diretorio!", NULL);
}


FILE* __abrir_arquivo(const char FILE_NAME[])
{
    FILE* arq = fopen(FILE_NAME, MODO_LEITURA);

    if (arq == NULL)
    {
        char* informacao_erro_nome_arquivo;
        log_error("Ocorreu um erro ao abrir o arquivo informado, verifique se ele existe e tente novamente -> ", FILE_NAME);
        exit(errno);
    }

    return arq;

}