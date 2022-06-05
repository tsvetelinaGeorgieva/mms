#include<stdio.h>
#include<stdint.h>

uint32_t setAtt(uint32_t, int);
uint32_t clearAtt(uint32_t, int);
void AttInfo(uint32_t);
uint32_t changeAtt(uint32_t, int);

int main(){
    uint32_t attendance = 0;
    int option = 0;
    int bit;
    while(option != 5){
        printf("1. Set attendance.\n");
        printf("2. Clear attendance.\n");
        printf("3. Attendance info.\n");
        printf("4. Change attendance.\n");
        printf("5. Exit.\n");
        scanf("%d", &option);
        switch(option){
            case 1: 
                printf("Enter number: ");
                scanf("%d", &bit);
                if(setAtt(attendance, bit) == -1){
                    printf("Invalid number!\n");
                }else{
                    attendance = setAtt(attendance, bit);
                }
                break;
            case 2: 
                printf("Enter number: ");
                scanf("%d", &bit);
                if(clearAtt(attendance, bit) == -1){
                    printf("Invalid number!\n");
                }else{
                    attendance = clearAtt(attendance, bit);
                }
                break;
            case 3: 
                AttInfo(attendance);
                break;
            case 4: 
                printf("Enter number: ");
                scanf("%d", &bit);
                if(changeAtt(attendance, bit) == -1){
                    printf("Invalid number!\n");
                }else{
                    attendance = changeAtt(attendance, bit);
                }
                break;
        }
    }

    return 0;
}

uint32_t setAtt(uint32_t attendance, int bit){
    if(bit >= 32){
        return -1;
    }else{
        attendance |= (1 << (bit-1));
        return attendance;
    }
}

uint32_t clearAtt(uint32_t attendance, int bit){
    if(bit >= 32){
        return -1;
    }else{
        attendance &= ~(1 << (bit-1));
        return attendance;
    }
}

void AttInfo(uint32_t attendance){
    for(int bit = 0; bit < 32; bit++){
        if(!!(attendance & (1 << bit))){
            printf("%d. Here\n", (bit + 1));
        }else{
            printf("%d. Not here\n", (bit + 1));
        }
    }
}

uint32_t changeAtt(uint32_t attendance, int bit){
    if(bit >= 32){
        return -1;
    }else{
        attendance ^= (1 << (bit-1));
        return attendance;
    }

}
