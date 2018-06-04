#include <stdio.h>  
#include <stdlib.h>
// #include <windows.h>  
  
#define N 4  
#define abs(x) (((x)>=0)?(x):-(x))   
int col[N+1];  
int count=0;  
  
void Output();  
void Queen(int i,int n);  
void BucketSorting();
  
int main()  
{  
    // N皇后
    int i;  
    for(i=1;i<=N;i++)  
    {  
        col[1] = i;  
        Queen(2,N);  
    }  
    printf("%d\n",count);  

    // 桶排序
    BucketSorting();
    return 0; 
}  
void BucketSorting(){
    printf("开始BucketSorting:\n");
    int arrs[11]={0},res[101]={0},i,j;
    for(i=0;i<10;i++)  
        arrs[i]=rand()%100+1;

    printf("测试数据:\n");
    for(i=0;i<10;i++){
        printf("%d ",arrs[i]);        
    }

    for (i=0;i<10;i++){
        res[arrs[i]]++;
    }

    printf("\n 结果:\n");
    for(i=0;i<=100;i++)              // 可能的值得范围越少，使用起来效率越高
        for (j=1;j<=res[i];j++)
            printf("%d ",i);
        
}

void Queen(int i,int n)  
{  
    if(i>n)  
        Output();  
    else  
    {  
        int j;  
        for(j=1;j<=N;j++)  
        {  
            col[i]=j;  
            int k=1; //已经安排了位置的皇后的游标指示  
            while(k<i)//比较现在的皇后与之前的皇后有没有冲突  
            {     
                if((col[k]-col[i])*(abs(col[k]-col[i]) - abs(k-i))!=0)//冲突条件  
                {  
                    k++;  
                    if(k==i)  
                        Queen(i+1,n);  
                }  
                else  
                    break;  
            }  
        }  
    }  
}  
void Output()  
{  
    int i;  
    count++;  
    for(i=1;i<=N;i++)  
    {  
        printf("(%d,%d)\n",i,col[i]);  
    }  
    printf("\n");  
}  
