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


int BuscaNombrePorPalabra(char *V[], int cantidad, char *palabra){
    for (int i = 0; i < cantidad; i++) {
        if (strstr(V[i], palabra) != NULL) {
            return i;  
        }
    }
    return -1;  
}

void BuscaNombrePorId(char *V[], int id){
    if (id >= 0 && id < MAX) {
        printf("\nNombre con indice %d: %s", id, V[id]);
    } else {
        printf("\nNo se encontro el valor buscado");
    }

}

int main(){

    char buff[50];
    char *V[MAX];
    
    int id;
    int resultado;
    int opcion;
    

    for (int i = 0; i < MAX; i++)
    {
        printf("\nIngrese el nombre de la persona: ");
        scanf("%s",buff);
        V[i] = (char * ) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(V[i],buff);
        
    }
    
    mostrarPersonas(V,MAX);

    printf("\n\n--- MENU ---\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por palabra clave\n");
    printf("Opcion: ");
    scanf("%d",&opcion);

    if (opcion == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &id);
        BuscaNombrePorId(V, id);
    }else if (opcion == 2) {
        printf("Ingrese la palabra clave: ");
        scanf("%s", buff);
        resultado = BuscaNombrePorPalabra(V, MAX, buff);
        if (resultado != -1) {
            printf("\nNombre encontrado en la posicion %d: %s", resultado,V[resultado]);
        } else {
            printf("\nNo se encontro ningun nombre con esa palabra");
        }
    } else {
        printf("\nOpcion invalida");
    }


    for (int i = 0; i < MAX; i++)
    {
        free(V[i]);
    }
    

    return 0;
}