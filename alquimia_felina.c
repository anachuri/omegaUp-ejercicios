#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

int get_resonance_groups(char* cadena,int n,int l,int r){
    int calida=0,solitario=0,baja_constante=0;
    int groups=0;
    for(int i=l+1;i<r-1;i++){
        if(cadena[i] == cadena[i+1] == cadena[l+2])
          groups++;
        else if(cadena[
    }
}

int main(int argc, char *argv[]) {
  int n,q;
  scanf("%d %d", &n, &q);
  char cadena[n];
  //printf("%d y %d\n", n,q);
  scanf(" %s",cadena);
  //printf("%s\n",cadena);
 int type,l,r,p,c;
for(int i=0;i<q;i++){
   scanf("%d", &type);
   if(type==1){
       scanf("%d %d",l,r);
       if(l<0 || n>=r)
        return;
        printf("%d",get_resonace_groups(cadena,n,l,r)
       return;
   }
   scanf("%d %c",p,c);
   
 }

  return 0;
}
