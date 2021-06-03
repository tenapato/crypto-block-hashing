#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>




int main(){
    int num = 0;
    char pass[1000];

    for (int i = 0; i < 1000; i++){

        sprintf(pass, "%d", num);

        printf("Num: %d, Hash: %s\n", num, crypt(pass, "$5$"));

        num++;

    }
    

   

    return 0;
}