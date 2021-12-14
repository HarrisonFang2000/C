#include<stdio.h>
#include <stdlib.h>

int main()
{
    int num;
 
    printf("请输入一个数字: ");
    scanf("%d",&num);
    (num%2==0)?printf("奇数"):printf("偶数");
    system("pause");
}