/* 
��Ŀ����1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
��������������ڰ�λ��ʮλ����λ�����ֶ���1��2��3��4��������е����к���ȥ �����������������С� 
*/

#include<stdio.h>
 
int main()
{
    int i,j,k;
    printf("\n");
    for(i=1;i<5;i++) { // ����Ϊ����ѭ��
        for(j=1;j<5;j++) {
            for (k=1;k<5;k++) { // ȷ��i��j��k��λ������ͬ
                if (i!=k&&i!=j&&j!=k) { 
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
}


/* 
//Ϊ�˾������ٲ���Ҫ��ѭ�����������µ�С�Ż���
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t i; // ��λ
    uint32_t j; // ʮλ
    uint32_t k; // ��λ
    
    for (i=1; i<5; i++)
    {
        for (j=1; j<5; j++)
        {
            // ��λ��ʮλ�ظ�
            // ������ǰʮλ
            if (j==i)
            {
                continue;
            }
            
            for (k=1; k<5; k++)
            {
                // ��λ���λ��ʮλ�ظ�
                // ������ǰ��λ
                if (k==j || k==i)
                {
                    continue;
                }
                
                printf("%u,%u,%u\n", i, j, k);
            }
        }
    }
}
 */



/* 
//���ѷ�(DFS)д����:
#include <stdio.h>
#include <stdlib.h>

int  b[4],arr[4];//�������������������
int Count=0;//������
void DFS(int step){
    if(step==5){
        if(arr[1]!=arr[2]&& arr[1]!=arr[3]&&arr[2]!=arr[3]){//�ж���Щ��������
            Count++;
            printf("%d%d%d\n",arr[1],arr[2],arr[3]);//�����������
        }
        return ;
    }

    for(int i=1;i<=4;i++){
        if(b[i]==0){
            arr[step]=i;
            b[i]=1;//�ų��ظ�
            DFS(step+1);//�Լ������Լ�
            b[i]=0;
        }
    }
    return ;
}

int main(void)
{
    DFS(1);
    printf("����%d��",Count);
    return 0;
}
 */