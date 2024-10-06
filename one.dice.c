#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Rastgele sayı üreteci başlatılıyor
    int zar;    
    int sum1=0;
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int sum5=0;
    int sum6=0;
    
    for(int b=1 ; b<=10000 ; ++b )
{
    zar =1 + rand() % 6;

   switch(zar)
    {
    case 1: ++sum1; break;
    case 2: ++sum2; break;
    case 3: ++sum3; break;
    case 4: ++sum4; break;
    case 5: ++sum5; break;
    case 6: ++sum6; break;
    }

}
printf("Dicle Times\n");
printf("1%9d\n",sum1);
printf("2%9d\n",sum2);
printf("3%9d\n",sum3);
printf("4%9d\n",sum4);
printf("5%9d\n",sum5);
printf("6%9d\n\n",sum6);
    // 1. kısım
    for(int i=1650 ; i>=0 ; i-=280)
{
if(sum1>i)
    printf(" * ");
        else 
            printf("   ");    
if(sum2>i) 
    printf(" * ");
        else 
            printf("   ");
if(sum3>i)
    printf(" * ");
        else 
            printf("   ");
if(sum4>i)
    printf(" * ");
        else 
            printf("   ");
if(sum5>i)
    printf(" * ");
        else 
            printf("   ");
if(sum6>i)
    printf(" * ");
        else 
            printf("   ");
printf("\n");
}
printf(" 1  2  3  4  5  6");
    return 0;
}
