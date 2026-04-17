#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

float costoTotal(Producto * producto){
    float costoFinal = producto->Cantidad * producto->PrecioUnitario;
    return costoFinal;
}

int main(){

    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cantClientes;
    srand(time(NULL));

    do
    {
        printf("Ingrese la cantidad de clientes: \n");
        scanf("%d",&cantClientes);

        if (cantClientes < 1 ||cantClientes > 5)
        {
            printf("Por cuestiones operativas, cada preventista puede visitar hasta 5 clientes. Ingrese de nuevo\n");
        }
        
    } while (cantClientes < 1 ||cantClientes > 5);

    Cliente *clientes = (Cliente *) malloc(cantClientes * sizeof(Cliente));

    char buff[50];

    //cargar clientes
    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID = i+1;

        printf("\nIngrese el nombre del cliente: ");
        scanf("%s",buff);

        clientes[i].NombreCliente = (char *) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente,buff);

        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;

        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
            clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
        }
        

    }


    //Mostrar todo por cliente
    printf("\n\n---RESUMEN POR CLIENTE---\n");
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n-Cliente Numero %d", clientes[i].ClienteID);
        printf("\n\tNombre: %s", clientes[i].NombreCliente);
        printf("\n\tCantidad productos a pedir: %d", clientes[i].CantidadProductosAPedir);
        printf("\n\t-Informacion acerca del producto:");

        float totalCliente = 0;

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\t\tID del Prodcuto: %d", clientes[i].Productos[j].ProductoID);
            printf("\n\t\tCantidad comprada de ese producto: %d", clientes[i].Productos[j].Cantidad);
            printf("\n\t\tTipo de producto: %s", clientes[i].Productos[j].TipoProducto);
            printf("\n\t\tPrecio unitario: $%.2f\n", clientes[i].Productos[j].PrecioUnitario);
            
            float costo = costoTotal(&clientes[i].Productos[j]);
            totalCliente += costo;
            
        }
        printf("\n\t---TOTAL A PAGAR POR EL CLIENTE: $%.2f\n", totalCliente);

    }
    


    for (int i = 0; i < cantClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);  
        
    }
    free(clientes);
    


    return 0;
}