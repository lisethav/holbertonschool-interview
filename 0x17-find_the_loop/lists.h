#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - lista enlazada individualmente
 * @n: entero
 * @next: apunta al siguiente nodo
 *
 * Descripción: estructura de nodo de lista enlazada individualmente
 * para el proyecto Holberton
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);

#endif