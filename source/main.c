#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>





int main(){
    int num = 0;
    char *pass = (char *)malloc(sizeof(char)*1000);	
	char *hash = (char *)malloc(sizeof(char)*1000);
	int dificultad = 2;
	char *strToCompare = (char *)malloc(dificultad);
	char *ceros = (char *)malloc(sizeof(char)*dificultad);
	//int *aux;
	//int *fin = ceros + dificultad;
	
	for (int i = 0; i < dificultad; i++)
	{
		strcat(ceros, "0");
		
	}
	
    for (int i = 0; i < 1000000000; i++){
		
        sprintf(pass, "%d", num);
		hash = crypt(pass, "$5$");
		hash = hash+4;
        printf("Num: %d, Hash: %s\n", num, hash);
		
		strncpy(strToCompare, hash, dificultad);
		printf("Str %s Ceros: %s\n", strToCompare, ceros);
		

		if (!strcmp(strToCompare, ceros))
		{
			printf("Es el numero buscado es: %s -------\n", pass);
			break;
		}

		
		


        num++;

    } 
    
	

   
	free(pass);
	free(ceros);
	free(hash);
	free(strToCompare);
	free(ceros);
    return 0;
}