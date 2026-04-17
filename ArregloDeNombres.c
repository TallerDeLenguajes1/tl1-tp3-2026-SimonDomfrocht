#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

void BuscaNombrePorId(char *V[], int id,int cantidad){
    if (id >= 0 && id < cantidad) {
        printf("\nNombre con indice %d: %s", id, V[id]);
    } else {
        printf("\nNo se encontro el valor buscado");
    }

}

int main(){

    char buff[50];
    int cantidad;
    int id;
    int resultado;
    int opcion;

    printf("Ingrese la cantidad de nombres que va a cargar: ");
    scanf("%d", &cantidad);

    char **V = (char **) malloc(cantidad * sizeof(char *));
    
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nIngrese el nombre de la persona: ");
        scanf("%s",buff);
        V[i] = (char * ) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(V[i],buff);
        
    }
    
    mostrarPersonas(V,cantidad);

    printf("\n\n--- MENU ---\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por palabra clave\n");
    printf("Opcion: ");
    scanf("%d",&opcion);

    if (opcion == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &id);
        BuscaNombrePorId(V, id,cantidad);
    }else if (opcion == 2) {
        printf("Ingrese la palabra clave: ");
        scanf("%s", buff);
        resultado = BuscaNombrePorPalabra(V, cantidad, buff);
        if (resultado != -1) {
            printf("\nNombre encontrado en la posicion %d: %s", resultado,V[resultado]);
        } else {
            printf("\nNo se encontro ningun nombre con esa palabra");
        }
    } else {
        printf("\nOpcion invalida");
    }


    for (int i = 0; i < cantidad; i++)
    {
        free(V[i]);
    }
    

    return 0;
}