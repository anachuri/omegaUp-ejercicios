/*
Cada bit desplazado a la derecha divide el número entre 2 (usando división entera / descartando el residuo).
Cada bit desplazado a la izquierda multiplica el número por 2.

// Forma Tradicional (Fácil de leer)
pos = pos / 2;
pos = pos * 2;

// Forma con Asignación Compuesta de Bits (Compacta / Bajo nivel)
pos >>= 1;
pos <<= 1;
l & 1 es una operación de bits (bitwise AND) que se utiliza para verificar si un número entero es impar

i << 1	i * 2	Obtener el hijo izquierdo
i << 1 | 1	i * 2 + 1	Obtener el hijo derecho
i >> 1	i / 2 (división entera)	Subir al nodo padre
i & 1	i % 2 != 0	Saber si el índice es impar
*/

#include <stdio.h>
typedef struct{
    int groups;
    char c;
} Node;

void create_tree(Node *node, char arr[], int n){
    for (int i = 0; i < n; i++){
        node[n + i].c = arr[i];
        node[n + i].groups = 1;
        node[i].groups = 0;
        node[i].c = 'z';
    }
    // printf("v: %c y %c\n",node[n].c,node[n+1].c);
    if (n % 2 == 1 && node[n].c == node[n + 1].c)
        node[n].groups = 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (node[i << 1].c == 'z' && node[i << 1 | 1].c == 'z' || node[i << 1].c != node[i << 1 | 1].c)
            node[i].groups = node[i << 1].groups + node[i << 1 | 1].groups;
        else
            node[i].groups = 1;
    }

    /* for(int i=0;i<n*2;i++){
       printf("groups en i=%d, v:%d ,c %c\n",i,node[i].groups,node[i].c);
     }*/
    //printf("groups::: %d\n", node[1].groups);
}

int query(Node *node, int l, int r, int n){
    int res = 0;
    l += n;
    r += n + 1; // Convertir a rango semiabierto [l, r)
    // 2. Recorrer de abajo hacia arriba en el árbol
    while (l < r){
        printf("l:%d r:%d\n", l, r);
        if (l & 1)
            res += node[l++].groups; // Si 'l' es hijo derecho
        if (r & 1)
            res += node[--r].groups; // Si 'r' es hijo derecho
        l >>= 1; // Subir 'l' a su padre (l = l / 2)
        r >>= 1; // Subir 'r' a su padre (r = r / 2)
        
    }
    return res;
}

int main(int argc, char *argv[]){
    int n, q;
    char cadena[n];
    scanf("%d %d", &n, &q);
    // printf("%d y %d\n", n,q);
    scanf(" %s", cadena);
    // printf("%s\n",cadena);
    // SegmentTree *st = crear_segment_tree(cadena, n);
    // printf("%d\n", consultar(st, 1, 5));
    Node tree[n * 2];
    create_tree(tree, cadena, n);

    int type;
    scanf("%d", &type);

    if (type == 1){
        for (int i = 0; i < q; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(tree, l, r, n));
        }
    }else if(type == 2){
        int pos;
        char c;
    }
    return 0;
}
