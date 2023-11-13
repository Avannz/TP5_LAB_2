#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/// ESTRUCTURAS ///

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct nodo
{
    persona dato;
    struct nodo * sig;
} nodo;


/// PROTOTIPADOS ///

nodoArbol* insertar (nodoArbol* arbolito, persona dato);
nodoArbol* inicNodoArbol();
nodoArbol* buscarEnArbol(nodoArbol* arbolito, int legajo);
nodoArbol* buscarEnArbolNombre(nodoArbol* arbolito, char nombre[]);

nodo* crearNodo (persona aux);
nodo* inicNodo ();
nodo* agregarPpio (nodo* lista, nodo* nuevoNodo);
nodo* cargarAlista (nodoArbol *arbolito, nodo* lista);

void preorder(nodoArbol* arbolito);
void inorder(nodoArbol *arbolito);
void recorrerLista (nodo* lista);
void recorrer(nodoArbol *arbolito);
void mostrarRama(nodoArbol *arbolito);

int altura_arbol(nodoArbol* arbolito);
int cantidad_hojas (nodoArbol* arbolito);
int calcular_cant_nodos (nodoArbol* arbolito);
nodoArbol* nodo_mas_derecha (nodoArbol* arbolito);
nodoArbol* nodo_mas_izquierda (nodoArbol* arbolito);
nodoArbol * borrar_arbol (nodoArbol * arbolito, int dato);

/// MAIN ///

int main()
{
    nodo* lista = inicNodo();
    nodoArbol* arbolito = inicNodoArbol();

    char letra = 's';
    char nombre[30];

    int opc;
    int legajo;
    int cantHojas = 0;
    int cantNodos = 0;
    int alturaArbolito = 0;
    persona dato;

    while(letra == 's')
    {


        printf("Ingresa un legajo a la persona: ");
        fflush(stdin);
        scanf("%i", &dato.legajo);

        printf("Ingresale una edad: ");
        fflush(stdin);
        scanf("%i", &dato.edad);

        printf("Ingresa su nombre: ");
        fflush(stdin);
        gets(dato.nombre);

        arbolito = insertar(arbolito, dato);

        printf("Ingresa 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &letra);

        system("cls");
    }

    printf("Seleccione un ejercicio 2/ 3/ 4/ 5/ 6/ 7/ 8/ || ");
    fflush(stdin);
    scanf("%i", &opc);

    switch(opc)
    {

    case 2:



        printf("MOSTRAR ARBOL: \n");
        inorder (arbolito);

        break;

    case 3:


        lista = cargarAlista(arbolito, lista);

        printf("\n\nMOSTRAR LISTA: \n");
        recorrerLista(lista);

        break;



    case 4:

        printf("Ingrese el legajo a buscar: ");
        fflush(stdin);
        scanf("%i", &legajo);

        nodoArbol* rta = buscarEnArbol(arbolito, legajo);
        mostrarRama(rta);

        break;

    case 5:



        printf("Ingrese el nombre a buscar: ");
        fflush(stdin);
        gets(nombre);

        rta = buscarEnArbolNombre(arbolito, nombre);
        mostrarRama(rta);

        break;

    case 6:

        alturaArbolito = altura_arbol (arbolito);
        printf("La altura del arbol es de : %d", alturaArbolito);

        break;

    case 7:

        cantNodos = calcular_cant_nodos(arbolito);
        printf("\n * La cantidad de nodos es: %d", cantNodos);

        break;

    case 8:



        cantHojas = cantidad_hojas(arbolito);
        printf("Cantidad de hojas del arbol: %d", cantHojas);

        break;

    case 9:

            printf("Ingresa el legajo a eliminar: ");
            fflush(stdin);
            scanf("%i", &legajo);

            arbolito = borrar_arbol(arbolito, legajo);
            inorder(arbolito);

        break;

    }

}

nodoArbol* inicNodoArbol()
{
    return NULL;
}


nodoArbol* crearNodoArbol (persona dato)
{
    nodoArbol* aux = malloc(sizeof(nodoArbol));
    aux->dato= dato;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

nodoArbol* insertar (nodoArbol* arbolito, persona dato)
{

    if(!arbolito)
    {

        arbolito = crearNodoArbol(dato);
    }
    else
    {
        if(dato.legajo > arbolito->dato.legajo)
        {
            arbolito->der = insertar(arbolito->der, dato);

        }
        else
        {

            arbolito->izq = insertar(arbolito->izq, dato);
        }

    }

    return arbolito;
}

void preorder(nodoArbol* arbolito)
{

    if(arbolito != NULL)
    {

        printf("/ %d /", arbolito->dato.legajo);
        preorder(arbolito->izq);
        preorder(arbolito->der);
    }
}

void inorder(nodoArbol *arbolito)
{

    if(arbolito)
    {
        inorder(arbolito->izq);
        printf("/ %d /", arbolito->dato.legajo);
        inorder(arbolito->der);

    }
}

void mostrarRama(nodoArbol *arbolito)
{

    printf("\nNumero de Legajo: %i \n", arbolito->dato.legajo);
    printf("Nombre: %s \n", arbolito->dato.nombre);
    printf("Edad: %i \n", arbolito->dato.edad);
}


nodo* crearNodo (persona aux)
{

    nodo* auxN = (nodo*) malloc(sizeof(nodo));
    auxN->dato = aux;
    auxN->sig = NULL;

    return auxN;
}

nodo* inicNodo ()
{

    return NULL;
}

nodo* agregarPpio (nodo* lista, nodo* nuevoNodo)
{

    if(!lista)
    {

        lista = nuevoNodo;
    }
    else
    {

        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }


    return lista;
}

nodo* cargarAlista (nodoArbol* arbolito, nodo* lista)
{

    nodo* nuevoNodo = inicNodo();

    if(arbolito)
    {
        lista = cargarAlista(arbolito->izq, lista);

        nuevoNodo = crearNodo(arbolito->dato);
        lista = agregarPpio(lista, nuevoNodo);

        lista = cargarAlista(arbolito->der, lista);
    }

    return lista;
}

void recorrerLista (nodo* lista)
{

    if(lista)
    {
        printf(".........................\n");
        printf("Legajo: %d \n", lista->dato.legajo);
        printf("Edad: %d \n", lista->dato.edad);
        printf("Nombre: %s \n\n", lista->dato.nombre);

        lista = lista->sig;

        recorrerLista(lista);
    }
}



nodoArbol* buscarEnArbol(nodoArbol* arbolito, int legajo)
{

    nodoArbol* rta = arbolito;

    if(arbolito && arbolito->dato.legajo != legajo)
    {
        rta= buscarEnArbol(arbolito->izq, legajo);
        if(!rta)
            rta= buscarEnArbol(arbolito->der, legajo);
    }

    return rta;
}

nodoArbol* buscarEnArbolNombre(nodoArbol* arbolito, char nombre[])
{

    nodoArbol* rta = inicNodoArbol();

    if(arbolito)
    {

        if(strcmp(arbolito->dato.nombre, nombre) != 0)
        {

            rta = buscarEnArbolNombre(arbolito->izq, nombre);

            if(!rta)
                rta = buscarEnArbolNombre(arbolito->der, nombre);
        }
        else
        {

            rta = arbolito;
        }
    }

    return rta;
}

int cantidad_hojas (nodoArbol* arbolito)
{
    int i = 0;

    if(arbolito)
    {
        if(arbolito->izq == NULL && arbolito->der == NULL)
            i=1;
        else
            i = cantidad_hojas(arbolito->izq) + cantidad_hojas(arbolito->der);
    }

    return i;
}

int altura_arbol(nodoArbol* arbolito)
{

    int alturaIzq = 0;
    int alturaDer = 0;
    int rta = 0;
    if(arbolito)
    {
        rta++;
        if(arbolito->izq != NULL)
        {
            alturaIzq += altura_arbol(arbolito->izq);
        }
        if(arbolito->der != NULL)
        {
            alturaDer += altura_arbol(arbolito->der);

        }

        if(alturaDer>alturaIzq)
            rta += alturaDer;
        else
            rta += alturaIzq;
    }
    return rta;
}

int calcular_cant_nodos (nodoArbol* arbolito)
{

    int cantNodos = 0;


    if(arbolito)
    {
        cantNodos++;
        if(arbolito->izq != NULL)
        {

            cantNodos += calcular_cant_nodos(arbolito->izq);

        }
        if(arbolito->der != NULL)
        {

            cantNodos += calcular_cant_nodos(arbolito->der);
        }
    }

    return cantNodos;
}

nodoArbol* nodo_mas_derecha (nodoArbol* arbolito)
{
    nodoArbol* aux = inicNodoArbol();

    if(arbolito->der)
    {

        aux =   nodo_mas_derecha(arbolito->der);
    }

    return aux;
}

nodoArbol* nodo_mas_izquierda (nodoArbol* arbolito)
{

    nodoArbol* aux = inicNodoArbol();

    if(arbolito->izq)
    {

        aux = nodo_mas_izquierda(arbolito->izq);
    }

    return aux;
}

nodoArbol * borrar_arbol (nodoArbol * arbolito, int dato)
{

    if(arbolito)
    {
        if(dato == arbolito->dato.legajo)
        {

            if(arbolito->izq != NULL)
            {
                nodoArbol* masDer = nodo_mas_derecha(arbolito->izq);
                arbolito->dato = masDer->dato;
                arbolito->izq = borrar_arbol(arbolito->izq, masDer->dato.legajo);
            }
            else if (arbolito->izq != NULL){

                nodoArbol* masIzq = nodo_mas_izquierda(arbolito->der);
                arbolito->dato = masIzq->dato;
                arbolito->der = borrar_arbol(arbolito->der, masIzq->dato.legajo);

            }
            else
            {
                free(arbolito);
                arbolito = NULL;
            }
        }

        if(dato > arbolito->dato.legajo)
        {
            arbolito->der = borrar_arbol(arbolito->der,dato);
        }

        if(dato < arbolito->dato.legajo)
        {
            arbolito->izq = borrar_arbol(arbolito->izq,dato);
        }
    }
    if(arbolito == NULL)
    {

    }

    return arbolito;
}
