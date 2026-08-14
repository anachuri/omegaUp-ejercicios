#include <stdio.h>

// El nodo necesita conocer ambos extremos para poder fusionarse
typedef struct {
    int groups;
    char left_char;
    char right_char;
} Node;

// Función pura para combinar dos nodos
Node combine(Node a, Node b) {
    // Si un nodo está vacío (elemento neutro), devolvemos el otro
    if (a.groups == 0) return b;
    if (b.groups == 0) return a;

    Node res;
    res.left_char = a.left_char;
    res.right_char = b.right_char;
    res.groups = a.groups + b.groups;

    // Si los colores en la costura coinciden, se fusionan en un solo grupo
    if (a.right_char == b.left_char) {
        res.groups--;
    }
    
    return res;
}

void create_tree(Node *tree, char arr[], int n) {
    // 1. Inicializar las hojas con los caracteres originales
    for (int i = 0; i < n; i++) {
        tree[n + i].left_char = arr[i];
        tree[n + i].right_char = arr[i];
        tree[n + i].groups = 1;
    }

    // 2. Construir los nodos internos usando la función combine
    for (int i = n - 1; i > 0; i--) {
        tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }
}

int query(Node *tree, int l, int r, int n) {
    // Inicializar variables vacías para acumular los lados
    Node res_l = {0, '\0', '\0'};
    Node res_r = {0, '\0', '\0'};

    l += n;
    r += n + 1; // Rango semiabierto [l, r)

    while (l < r) {
        if (l & 1) res_l = combine(res_l, tree[l++]);
        if (r & 1) res_r = combine(tree[--r], res_r); // tree[--r] va primero por orden posicional
        
        l >>= 1; 
        r >>= 1; 
    }

    // Unir la acumulación izquierda con la derecha
    Node total = combine(res_l, res_r);
    return total.groups;
}

void update(Node *tree, int n, int pos, char potion) {
    pos += n;
    // Actualizar la hoja
    tree[pos].left_char = potion;
    tree[pos].right_char = potion;
    tree[pos].groups = 1;

    // Subir actualizando los padres
    for (pos >>= 1; pos > 0; pos >>= 1) {
        tree[pos] = combine(tree[pos << 1], tree[pos << 1 | 1]);
    }
}

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    char cadena[n + 1]; // Declarado DESPUÉS de leer 'n', con +1 para el '\0'
    scanf(" %s", cadena);

    Node tree[n * 2];
    create_tree(tree, cadena, n);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        
        if (type == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            // El problema da índices 1-based, los pasamos a 0-based
            printf("%d\n", query(tree, l - 1, r - 1, n));
        } else if (type == 2) {
            int pos;
            char c;
            scanf("%d %c", &pos, &c);
            update(tree, n, pos - 1, c);
        }
    }
    
    return 0;
}
