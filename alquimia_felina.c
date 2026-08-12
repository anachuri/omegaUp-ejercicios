#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int n;
    char *tree;
} SegmentTree;

SegmentTree* crear_segment_tree(char* arr, int n) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    st->n = n;
    st->tree = (char*)malloc(sizeof(char) * 2 * n);
    // 1. Copiar elementos originales a las hojas [n ... 2n - 1]
    for (int i = 0; i < n; i++) {
        st->tree[n + i] = arr[i];
    }
    // 2. Calcular nodos interiores [n-1 ... 1]
    for (int i = n - 1; i > 0; i--) {
        //st->tree[i] = st->tree[i << 1] + st->tree[i << 1 | 1];
        if(st->tree[i << 1] == st->tree[i << 1 | 1])
          st->tree[i] = '1';
        else
          st->tree[i] = '2';
    }
    return st;
}

// Consulta de Rango [l, r] inclusive O(log N)
/*int consultar(SegmentTree *st, int l, int r) {
    int res = 0;
    // Mover a los índices de las hojas
    l += st->n;
    r += st->n + 1; // Convertir a intervalo semiabierto [l, r)

    while (l < r) {
        // Si l es un hijo derecho, su valor debe incluirse solo,
        // luego se pasa al siguiente nodo
        if (l & 1) {
            res += (st->tree[l++] - '0');
        }
        // Si r es un hijo derecho (en rango abierto), 
        // el elemento anterior debe incluirse
        if (r & 1) {
            res += (st->tree[--r] - '0');
        }
        // Subir un nivel en el árbol
        printf("res: %d\n",res);
        l >>= 1;
        r >>= 1;
    }
    return res;
}*/

int consultar(SegmentTree* st, int l, int r) {
    int res = 0; 
    // 1. Mover los índices del arreglo original a las HOJAS del Segment Tree
    l += st->n;
    r += st->n + 1; // Convertir a rango semiabierto [l, r)

    // 2. Recorrer de abajo hacia arriba en el árbol
    while (l < r) {
        if (l & 1 && st->tree[l++]>='0' && st->tree[l++]<='9') {
          res += st->tree[l++];
          printf("der: %c\n",st->tree[l++]);
        } // Si 'l' es hijo derecho
        if (r & 1 && st->tree[--r]>='0' && st->tree[--r]<='9'){ 
          res += st->tree[--r];
          printf("der: %c\n",st->tree[--r]);
        } // Si 'r' es hijo derecho
        
        
        l >>= 1; // Subir 'l' a su padre (l = l / 2)
        r >>= 1; // Subir 'r' a su padre (r = r / 2)
    }
    
    return res;
}

int main(int argc, char *argv[]) {
  int n,q;
  char cadena[n];
  scanf("%d %d", &n, &q);
  //printf("%d y %d\n", n,q);
  scanf(" %s",cadena);
  //printf("%s\n",cadena);
  SegmentTree *st = crear_segment_tree(cadena, n);
  printf("%d\n", consultar(st, 1, 5));  

  return 0;
}
