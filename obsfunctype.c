#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int *pa , int *pb){
    int p = *pa;
    *pa = *pb;
    *pb = p;


}

void main(){
    int a = 17;
    int b = 22;
    swapNumbers(&a, &b);

    printf("a is %d \n", a);
    printf("b is %d \n", b);

}