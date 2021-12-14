/* 
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去 掉不满足条件的排列。 
*/

#include<stdio.h>
 
int main()
{
    int i,j,k;
    printf("\n");
    for(i=1;i<5;i++) { // 以下为三重循环
        for(j=1;j<5;j++) {
            for (k=1;k<5;k++) { // 确保i、j、k三位互不相同
                if (i!=k&&i!=j&&j!=k) { 
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
}


/* 
//为了尽量减少不必要的循环，做了如下的小优化。
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t i; // 百位
    uint32_t j; // 十位
    uint32_t k; // 个位
    
    for (i=1; i<5; i++)
    {
        for (j=1; j<5; j++)
        {
            // 百位与十位重复
            // 跳过当前十位
            if (j==i)
            {
                continue;
            }
            
            for (k=1; k<5; k++)
            {
                // 个位与百位或十位重复
                // 跳过当前个位
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
//深搜法(DFS)写此题:
#include <stdio.h>
#include <stdlib.h>

int  b[4],arr[4];//定义两个数组用来类比
int Count=0;//计数器
void DFS(int step){
    if(step==5){
        if(arr[1]!=arr[2]&& arr[1]!=arr[3]&&arr[2]!=arr[3]){//判断哪些符合条件
            Count++;
            printf("%d%d%d\n",arr[1],arr[2],arr[3]);//输出可用排列
        }
        return ;
    }

    for(int i=1;i<=4;i++){
        if(b[i]==0){
            arr[step]=i;
            b[i]=1;//排除重复
            DFS(step+1);//自己调用自己
            b[i]=0;
        }
    }
    return ;
}

int main(void)
{
    DFS(1);
    printf("共有%d种",Count);
    return 0;
}
 */