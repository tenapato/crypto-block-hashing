#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <omp.h>
#include "mpi.h"

#define ELEMENTOS 1000000000
//#define MAXSIZE 1000

int main(int argc, char *argv[]){
    int myid, numprocs, nhilos, n, c;
    int longitud;
    char hostname[MPI_MAX_PROCESSOR_NAME];
    
    char *pass = (char *)malloc(sizeof(char)*1000);	
	char *hash = (char *)malloc(sizeof(char)*1000);
	int dificultad;
	char *strToCompare = (char *)malloc(dificultad);
	char *ceros = (char *)malloc(sizeof(char)*dificultad);
	int seguir = 0;
    //int data[MAXSIZE];
    //n = MAXSIZE;
    int nthreads, tid, x, low, high;
    double t_inicial, t_final;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    MPI_Get_processor_name(hostname, &longitud);

    //printf("Argv %s\n", argv[1]);

    dificultad = atoi(argv[1]);

    //printf("Dificultad %d\n", dificultad);
    //MPI_Bcast(data, seguir ,MPI_INT, 0, MPI_COMM_WORLD);

    // Dividir datos para cada procesador

    x = ELEMENTOS/numprocs;
    low = myid * x;
    high = low + x;
    if (myid == numprocs - 1) {
        high = ELEMENTOS;
    }

	
	for (int i = 0; i < dificultad; i++)
	{
		strcat(ceros, "0");
		
	}

   
    t_inicial = omp_get_wtime();
    /* Cada hilo tienen una variable tid privada */
    #pragma omp parallel private(tid, nhilos) shared(seguir)
    {
        int num = low;
        
        /* Obtener el thread id */
        tid = omp_get_thread_num();
        
        /* Obtener número de hilos */
        nhilos = omp_get_num_threads();
        //nhilos = 10;
        //printf("High %d, low %d, Id %d, hilos %d\n", high, low, myid, nhilos);

        // Particionar los datos para cada hilo
        int slots = high / nhilos;
        int inicio = tid * slots;
        int fin;
        if (tid == nhilos - 1)
        {
            fin = high;
        }
        else {
            fin = inicio + slots;
        }



        /* Buscar hash */
        for (int i = low; i < high && seguir == 0; i++){
        //printf("I: %d\n", i);
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

            printf("Es el numero buscado es: %s Encontrado en el hilo %d, en el Nodo %d\n", pass, tid, myid);
            printf("Con el Hash: %s\n", hash);
            printf("Calculado en %.8fs en el procesador %d (%s) \n", t_final-t_inicial, myid, hostname);
            #pragma omp critical
            {
                seguir = 1;
                MPI_Bcast(&seguir, 1, MPI_INT, 0, MPI_COMM_WORLD);
            }
            break;
        }
        num++;

        } 
        
    
    }
    
    
   MPI_Finalize();
	

   
	free(pass);
	free(ceros);
	//free(hash);
    return 0;
}