#include "lista.h"
#include "stdio.h"
#include "stdlib.h"

lista_t *crear_lista_vacia()
{
    lista_t *lista_vacia = malloc(sizeof(lista_t));
    lista_vacia->cabeza = NULL;
    return lista_vacia;
}

nodo_t *crear_nuevo_nodo(int valor)
{
    nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->valor = valor;
    return nuevo_nodo;
}

void insertar_al_final(lista_t *lista, int valor)
{
    nodo_t *actual = lista->cabeza;
    nodo_t *a_insertar = crear_nuevo_nodo(valor);

    if (actual == NULL)
    {
        lista->cabeza = a_insertar;
        return;
    }
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = a_insertar;
}

int eliminar_cabeza(lista_t *lista)
{
    nodo_t *actual = lista->cabeza;
    if (actual == NULL)
        return -1;
    lista->cabeza = actual->siguiente;
    free(actual);
    return 0;
}

void eliminar_lista(lista_t *lista)
{
    nodo_t *actual = lista->cabeza;
    while (actual != NULL)
    {
        nodo_t *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void map(lista_t *lista, int (*operacion)(int))
{
    nodo_t *actual = lista->cabeza;
    while (actual != NULL)
    {
        actual->valor = operacion(actual->valor);
        actual = actual->siguiente;
    }
}

int es_par(int x)
{
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

void filter(lista_t *lista, int (*criterio)(int))
{
    nodo_t **cabeza_actual = &lista->cabeza;
    while (cabeza_actual != NULL)
    {
        if (!criterio((*cabeza_actual)->valor))
        {
            nodo_t *a_borrar = *cabeza_actual;
            *cabeza_actual = (*cabeza_actual)->siguiente;
            free(a_borrar);
        }
        else
        {
            cabeza_actual = &(*cabeza_actual)->siguiente;
        }
    }
}