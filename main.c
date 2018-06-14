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
    
    // 大数相加
    //al1010("999999999999999999999999999999999999999999999999999999999","999999999999999999999999999999999999999999999999999999999")	// 101011
    //mul1010("12345","20")
    return 0; 
}  
const(
	HEX=10
)
func mul1010(s1,s2 string){
	log.Println("开始输出mul1010：")
	arr:=[]string{}
	bei:=0
	for i:=len(s1)-1;i>=0;i--{
		m:=0
		tsum:=""
		for j:=len(s2)-1;j>=0;j--{
			t:=int(s1[i]-'0')*int(s2[j]-'0')+m
			tsum=to.String(t%HEX)+tsum
			m=t/HEX
		}
		if m>0{
			tsum=to.String(m)+tsum
		}
		arr=append(arr,to.String(tsum)+get8(bei))
		bei++		
	}
	log.Println("结果数组mul1010:",arr)
	sum:=""
	for k,v:=range arr{
		if k==0{
			sum=v
			continue
		}
		sum=al1010(sum,v)
	}
	log.Println("结果mul1010:",sum)	
}
func get8(n int)string{
	s:=""
	for i:=0;i<n;i++{
		s=s+"0"
	}
	return s
}
func al1010(s1,s2 string) string{
	max:=s1
	min:=s2
	if len(s1)<len(s2){
		max=s2
		min=s1
	}
	m:=0
	s:=""
	k:=len(min)-1
	for i:=len(max)-1;i>=0;i--{
		t:=int(max[i]-'0') +m
		if k>=0{
			t=t+int(min[k]-'0')
		}
		k--
		s=to.String(t%HEX)+s
		m=t/HEX
	}
	if m>0{
		s=to.String(m)+s
	}
	return s
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
