#include<stdio.h>
#include<math.h>

void floatComp(float, float);
void doubleComp(double, double);
void floatCompWithE(float, float);
void doubleCompWithE(double, double);


int main(){
    float a = 1;
    float b = 1;
    double c = 10.0;
    double d = 10.0;

    floatComp(a,b);
    floatCompWithE(a, b);
    doubleComp(c,d);
    doubleCompWithE(c, d);

    for(int i= 0; i < 10; i++){
        printf("%d \n", i);
        b += 0.1;
        d += 0.1;
        floatComp(a,b);
        floatCompWithE(a, b);
        doubleComp(c,d);
        doubleCompWithE(c, d);

        printf("\n");
    }
    

    return 0;
}

void floatCompWithE(float a, float b){
    float e = 0.1;
    if(a >= b){
        e *= a;
    }else{
        e *= b;
    }

    if(fabs(a-b)< e){
        printf("Equals! (float E)\n");
    }else{
        printf("Not equals! (float E)\n");
    }
}

void floatComp(float a, float b){
    if(a == b){
        printf("Equals! (float)\n");
    }else{
        printf("Not equals! (float)\n");
    }
}

void doubleComp(double a, double b){
    if(a == b){
        printf("Equals! (double)\n");
    }else{
        printf("Not equals! (double)\n");
    }
}


void doubleCompWithE(double a, double b){
    double e = 0.0001;
    if(a >= b){
        e *= a;
    }else{
        e *= b;
    }

    if(fabs(a-b)< e){
        printf("Equals! (double E)\n");
    }else{
        printf("Not equals! (double E)\n");
    }
}
