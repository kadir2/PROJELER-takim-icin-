#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

srand(time(0));
    int zar1;
    int zar2;    
    int sum2=0;
    int sum3=0;
    int sum4=0;
    int sum5=0;
    int sum6=0;
    int sum7=0;
    int sum8=0;
    int sum9=0;
    int sum10=0;
    int sum11=0;
    int sum12=0;

    for(int b=1 ; b<=10000 ; ++b )
{
    zar1 =1 + rand() % 6;
    zar2 =1 + rand() % 6;

   switch(zar1+zar2)
    {
    case 2: ++sum2;   break;    
    case 3: ++sum3;   break;
    case 4: ++sum4;   break;
    case 5: ++sum5;   break;
    case 6: ++sum6;   break;
    case 7: ++sum7;   break;
    case 8: ++sum8;   break;
    case 9: ++sum9;   break;
    case 10: ++sum10; break;
    case 11: ++sum11; break;
    case 12: ++sum12; break;
    }
}
printf("%3s%7s\n","Sum","Times");
printf("2%8d\n",sum2);
printf("3%8d\n",sum3);
printf("4%8d\n",sum4);
printf("5%8d\n",sum5);
printf("6%8d\n",sum6);
printf("7%8d\n",sum7);
printf("8%8d\n",sum8);
printf("9%8d\n",sum9);
printf("10%7d\n",sum10);
printf("11%7d\n",sum11);
printf("12%7d\n\n",sum12);
for(int i=1600 ; i>=100 ; i-=110)
{
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
if(sum7>i)
    printf(" * ");
        else 
            printf("   ");
if(sum8>i)
    printf(" * ");
        else 
            printf("   ");                        
if(sum9>i)
    printf(" * ");
        else 
            printf("   ");
if(sum10>i)
    printf(" * ");
        else 
            printf("   ");
if(sum11>i)
    printf(" * ");
        else 
            printf("   ");
if(sum12>i)
    printf(" * ");
        else 
            printf("   ");
printf("\n");
}
printf(" 2  3  4  5  6  7  8  9  10 11 12");
return 0;
}
