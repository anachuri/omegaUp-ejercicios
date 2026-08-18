#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

struct tbutton{
  int x,y;
};

typedef tbutton tpanel[16];

void initialize(tpanel panel){
  int k=0,j=0;
  for(int i=0;i<16;i++){
    panel[i].x = j;
    panel[i].y = k++;
    if(k==4){
      k=0;
      j++;
    }
    if(j==4)
      j=0;
  }
}

double calculate(double x1, double y1, double x2, double y2){
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

void calculateDistance(double dist[16][16],tpanel panel){
  for (int i = 0; i < 16; i++) {
    for (int j = i; j < 16; j++) {
        double d = calculate(panel[i].x,panel[i].y,panel[j].x,panel[j].y);
        dist[i][j] = d;
        dist[j][i] = d;
    }
  }
}

int main(){
    int N;
    cin>>N;
    int commands[N];
    double dist[16][16];
    tpanel panel;
    initialize(panel);
    calculateDistance(dist,panel);
    /*for(int i=0;i<16;i++){
      for(int j=0;j<16;j++){
        cout<<dist[i][j]<<" ";
      }
      cout<<endl;
    }*/
    for(int i=0; i<N; i++)
        cin>>commands[i];
        
    return 0;
}

/*double getDistance(tpanel panel,int f,int c){
  double min=-1;
  double distance;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(min == -1)
        min = getMinimum(panel,f,c);
      else
        distance = calculate(x1,y1,y1,y2);
      if(distance < min)
        min = distance;
      y2++;
    }
    y2--;
    y1++;
  }
}

double getMinimum(tpanel panel,int x1,int y1,int y1,int y2){
  double distance;
  double min=-1;
  bool band = false;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(min == -1)
        min = calculate(x1,y1,y1,y2);
      else
        distance = calculate(x1,y1,y1,y2);
      if(distance < min)
        min = distance;
      y2++;
    }
    y2--;
    y1++;
  }
  return min;
}
