#include <stdio.h>
typedef struct {
    int groups;
    char c;
} Node;

void create_tree(Node *node,char arr[],int n){
  for (int i = 0; i < n; i++){
    node[n + i].c = arr[i];
    node[n + i].groups = 1;
    node[i].groups = 0;
    node[i].c = 'z';
  }
  //printf("v: %c y %c\n",node[n].c,node[n+1].c);
  if(n%2==1 && node[n].c == node[n+1].c)
    node[n].groups=1;
  for (int i = n - 1; i > 0; i--) {      
        if(node[i << 1].c == 'z' && node[i << 1 | 1].c == 'z')
          node[i].groups = node[i << 1].groups + node[i << 1 | 1].groups;
        else if(node[i << 1].c == node[i << 1 | 1].c )
            node[i].groups=1;
        else
            node[i].groups = node[i << 1].groups + node[i << 1 | 1].groups;  
  }
    
  for(int i=0;i<n*2;i++){
    printf("groups en i=%d, v:%d ,c %c\n",i,node[i].groups,node[i].c);
  }
  
  printf("groups::: %d\n",node[1].groups);
}

int main(int argc, char *argv[]) {
   int n,q;
  char cadena[n];
  scanf("%d %d", &n, &q);
  //printf("%d y %d\n", n,q);
  scanf(" %s",cadena);
  //printf("%s\n",cadena);
  //SegmentTree *st = crear_segment_tree(cadena, n);
  //printf("%d\n", consultar(st, 1, 5));  
  Node tree[n*2];
  create_tree(tree,cadena,n);
  return 0;
}
