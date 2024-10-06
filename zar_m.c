#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int zar[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for(int i=0 ; i<10000 ; i++){
        zar[rand()%6+rand()%6]++;
    }
    
    for(int i = 15; i>=0; i--){
        for(int j=0; j<11 ; j++){
            if(zar[j]>= i*100){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
