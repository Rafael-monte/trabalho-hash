#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flag-controller.h"
#include "../logger/logger.c"
#include "../operacoes/operacoes.c"

//Inicializa o programa lendo as flags do terminal
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