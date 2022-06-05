#include<stdio.h>
#include<math.h>

#define Pi 3.142857

int main(){
    double r, l, h, vol, area;
    int option;
    printf("Enter option:\n");
    scanf("%d", &option);

    if(option == 1){
        printf("Enter R: ");
        scanf("%lf", &r);
        printf("Enter H: ");
        scanf("%lf", &h);

        vol = Pi * pow(r,2) * h;
        printf("Volume: %.2lf\n", vol);

    }else if(option == 2){
        printf("Enter R: ");
        scanf("%lf", &r);
        printf("Enter L: ");
        scanf("%lf", &l);
        printf("Enter H: ");
        scanf("%lf", &h);

        area = (1/ cos((r - h)/ r))*pow(r,2) - (r - h)*sqrt(2 * r * h - pow(h, 2));
        vol = area * l;
        printf("Volume: %.2lf\n", vol);

    }else{
        printf("Invalid option!\n");
    }

    return 0;
}


