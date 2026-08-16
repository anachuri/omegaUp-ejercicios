#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

typedef struct tcasilla{
    int command;
    int cdr;
};

typedef tcasilla tpanel[4][4];

double calculate(double x1, double y1, double x2, double y2){
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main(){
    int N;
    cin>>N;
    int commands[N];
    tpanel panel =
    {
        {{1, 1},  {2, 1},  {3, 2},  {4, 2}},
        {{5, 1},  {6, 1},  {7, 2},  {8, 2}},
        {{9, 3},  {10, 3}, {11, 4}, {12, 4}},
        {{13, 3}, {14, 3}, {15, 4}, {16, 4}}
    };

    for(int i=0; i<N; i++)
        cin>>commands[i];
    //for(int i=0; i<4; i++){
       double d1 = calculate(panel[i])
        ==
    //}

    return 0;
}
