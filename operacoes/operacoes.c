#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacoes.h"
#include "../logger/logger.c"


void iniciar_programa(int numero_argumentos, char** argumentos)
{
    if (numero_argumentos == 1) 
    {
        log_error("Poucos argumentos informados (Esperados: 3 ou mais, informados: 1)", NULL);
        exit(errno);
    }

    if (strcmp(argumentos[POSICAO_FLAG_OPERACAO], FLAG_IMPRESSAO_DIRETORIO) == 0) 
    {
        log_info("Operacao: Impressao do diretorio (-pd)", NULL);
        imprimir_diretorio();
        return;
    }


    if (strcmp(argumentos[POSICAO_FLAG_OPERACAO], FLAG_IMPORTACAO) == 0)
    {
        log_info("Operacao: Importacao (-i)", NULL);
        if (numero_argumentos < 3)
        {
            log_error("Uma importacao foi acionada mas nenhum arquivo foi informado", NULL);
            exit(errno);
        }
        char* informacao_arquivo;
        log_info("Arquivo Informado:", argumentos[POSICAO_FLAG_NOME_ARQUIVO]);
        importar_chaves(argumentos[POSICAO_FLAG_NOME_ARQUIVO]);
        return;
    }
    log_error("Ocorreu um erro inesperado. Tente novamente", NULL);
}

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