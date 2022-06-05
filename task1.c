#include<stdio.h>
#include<math.h>

int main(){
    double height, mass, bmi, bmiNew;

    printf("Enter mass:\n ");
    scanf("%lf", &mass);
    printf("Enter height:\n ");
    scanf("%lf", &height);

    bmi = mass / pow(height,2);
    printf("BMI (old): %.2lf\n", bmi);  

    bmiNew = 1.3 * (mass / pow(height,2.5));
    printf("BMI (new): %.2lf\n", bmiNew);  

return 0;
}