#include<stdio.h>

#define MAX(x, y, z) ((x) > (y) && (x) > (z)? (x) : ((y) > (z) ? (y) : (z)))
#define MIN(x, y, z) ((x) < (y) && (x) < (z)? (x) : ((y) < (z) ? (y) : (z)))
#define SETBIT(mask, bit) mask |= (1<<bit)
#define CLEARBIT(mask, bit) mask &= ~(1<<bit)
#define INVERSEBIT(mask, bit) mask ^= (1<<bit)
#define CHECKBIT(mask, bit) !!(mask&(1<<bit))
#define SWAP(a, b)  int temp = a; a=b; b = temp
int main(){
    int a = 2, b = 5, c = 1;
    printf("Max: %d\n", MAX(a, b, c));
    printf("Min: %d\n", MIN(a, b, c));
    printf("%d\n", b);
    printf("Set: %d\n", SETBIT(b, 1));
    printf("Clear: %d\n", CLEARBIT(b, 1));
    printf("%d\n", b);
    printf("Invers: %d\n", INVERSEBIT(b, 3));
    printf("%d\n", b);
    printf("Check: %d\n", CHECKBIT(b, 0));
    printf("Before swap: c = %d b = %d\n", c, b);
    SWAP(c, b);
    printf("After swap: c = %d b = %d\n", c, b);
    return 0;
}