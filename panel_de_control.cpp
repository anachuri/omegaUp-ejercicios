#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

typedef int tpanel[4][4];

double calculate(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
  int N;
  cin>>N;
  int commands[N];
  tpanel panel = {
                1,2,3,4,
                5,6,7,8,
                9,10,11,12,
                13,14,15,16
 };
  for(int i=0;i<N;i++)
    cin>>commands[i];


  return 0;
}
