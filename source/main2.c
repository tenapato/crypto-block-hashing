#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <omp.h>

#define ELEMENTOS 1000000000


int main(){
    int num = 0;
    char *pass = (char *)malloc(sizeof(char)*1000);	
	char *hash = (char *)malloc(sizeof(char)*1000);
	int dificultad = 1;
	char *strToCompare = (char *)malloc(dificultad);
	char *ceros = (char *)malloc(sizeof(char)*dificultad);
	int seguir = 0;

    int nthreads, tid;
    double t_inicial, t_final;
	
	for (int i = 0; i < dificultad; i++)
	{
		strcat(ceros, "0");
		
	}

    //t_inicial = omp_get_wtime();

    /* Crear Hilos */
    /*#pragma omp parallel for
    for (int i = 0; i < ELEMENTOS; i++)
    {
        printf("Hilo %d\n", omp_get_thread_num());
    }*/
    t_inicial = omp_get_wtime();
    /* Cada hilo tienen una variable tid privada */
    #pragma omp parallel private(tid) shared(seguir)
    {
        
        /* Obtener el thread id */
        tid = omp_get_thread_num();
        
        /* Obtener número de hilos */
        int nhilos = omp_get_num_threads();

        /* Particionamiento de los datos */
        int slots = ELEMENTOS / nhilos;
        int inicio = tid * slots;
        int fin;
        if (tid == nhilos - 1)
        {
            fin = ELEMENTOS;
        }
        else {
            fin = inicio + slots;
        }

        
        /* Buscar hash */
        for (int i = inicio; i < fin && seguir == 0; i++){
        
        sprintf(pass, "%d", num);
        hash = crypt(pass, "$5$");
        hash = hash+4;
        printf("Num: %d, Hash: %s\r", num, hash);
        //fflush();
        //printf("Seguir %d\n", seguir);
        strncpy(strToCompare, hash, dificultad);
        //printf("Hilo %d, Str %s, Ceros: %s\n", tid, strToCompare, ceros);
    

        if (!strcmp(strToCompare, ceros))
        {
            t_final = omp_get_wtime();

            printf("Es el numero buscado es: %s ------- Encontrado en el hilo %d\n", pass, tid);
            printf("Con el Hash: %s\n", hash);
            printf("Calculado en %.8fs\n", t_final-t_inicial);
            #pragma omp critical
            {
                seguir = 1;
            }
            break;
        }
        num++;

        } 
        
    
    }
    
    
   
	

   
	free(pass);
	free(ceros);
	//free(hash);
    return 0;
}