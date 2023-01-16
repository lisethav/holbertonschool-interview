#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/**
 * struct binary_tree_s - Nodo de árbol binario
 *
 * @n: Entero almacenado en el nodo
 * @parent: Puntero al nodo padre
 * @left: Puntero al nodo secundario izquierdo
 * @right: Puntero al nodo secundario derecho
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

#include <stdlib.h>

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);

#endif /* BINARY */