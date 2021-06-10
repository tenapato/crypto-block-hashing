#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <omp.h>
#include "mpi.h"

#define ELEMENTOS 1000000000 //Rango donde se busca el hasheo


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
    int nthreads, tid, x, low, high;
    double t_inicial, t_final;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    MPI_Get_processor_name(hostname, &longitud);

    dificultad = atoi(argv[1]);
    /* Division de los elementos entre los nodos */
    x = ELEMENTOS/numprocs;
    low = myid * x;//Donde empieza a buscar cada nodo
    high = low + x;//Donde termina de buscar cada nodo
    if (myid == numprocs - 1) {
        high = ELEMENTOS;
    }

	
	for (int i = 0; i < dificultad; i++){//Se ponen cuantos ceros tiene que tener el hash al principio para poder buscarlo
		strcat(ceros, "0");
	}
   
    t_inicial = omp_get_wtime();//Se empieza a tomar el tiempo
    /* Cada hilo tienen una variable tid privada */
    #pragma omp parallel private(tid, nhilos) shared(seguir)
    {//Compartimos la variable seguir entre los hilos
        int num = low;
        
        /* Obtener el thread id */
        tid = omp_get_thread_num();
        
        /* Obtener número de hilos */
        nhilos = omp_get_num_threads();

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
        for (int i = low; i < high && seguir == 0; i++){//Mientras no se haya encontrado un hash los hilos siguen buscando
        //printf("I: %d\n", i);
        sprintf(pass, "%d", num);
        hash = crypt(pass, "$5$");
        hash = hash+4;
        printf("Num: %d, Hash: %s\r", num, hash);
        strncpy(strToCompare, hash, dificultad);    

        if (!strcmp(strToCompare, ceros))
        {
            t_final = omp_get_wtime();

            printf("Es el numero buscado es: %s Encontrado en el hilo %d, en el Nodo %d\n", pass, tid, myid);
            printf("Con el Hash: %s\n", hash);
            printf("Calculado en %.8fs en el procesador %d (%s) \n", t_final-t_inicial, myid, hostname);
            #pragma omp critical
            {
                seguir = 1;
                MPI_Bcast(&seguir, 1, MPI_INT, 0, MPI_COMM_WORLD);//Se le avisa a los nodos e hilos que un hash ya fue encontrado
            }
            break;
        }
        num++;
        } 
    }
    
    
   MPI_Finalize();
	
	free(pass);
	free(ceros);
    return 0;
}