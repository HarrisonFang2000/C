#include<stdio.h>
#include <stdlib.h>

int main()
{
    int num;
 
    printf("������һ������: ");
    scanf("%d",&num);
    (num%2==0)?printf("����"):printf("ż��");
    system("pause");
}