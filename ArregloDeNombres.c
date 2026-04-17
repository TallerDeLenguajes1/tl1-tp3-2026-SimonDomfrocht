#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

void mostrarPersonas(char *V[],int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nNombre: %s",V[i]);
    }
    
}

char* BuscarNombre(char *V[], int cantidad, char *palabra){
    for (int i = 0; i < cantidad; i++) {
        if (strstr(V[i], palabra) != NULL) {
            return V[i];  
        }
    }
    return NULL;  
}

int main(){

    char buff[50];
    char *V[MAX];
    

    for (int i = 0; i < MAX; i++)
    {
        printf("\nIngrese el nombre de la persona: ");
        scanf("%s",buff);
        V[i] = (char * ) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(V[i],buff);
        
    }
    
    mostrarPersonas(V,MAX);

    for (int i = 0; i < MAX; i++)
    {
        free(V[i]);
    }
    

    return 0;
}