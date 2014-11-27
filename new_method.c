#define MAXLEN 100
#define MAXSUM 300/*用来存放阶乘结果的数组最大长度*/
#include <stdio.h>
#include <math.h>


int main()
{
    int i,j,k,n,sum,s;
    int a[MAXSUM];

    for(i=0;i<MAXSUM;i++)
    {
	    a[i]=0;
	}//数组赋初值
	          
	a[0]=1;
	
	for(i=1;i<=MAXLEN;i++)
	{
	    for(j=MAXSUM-1;j>=0;j--)
		{
			if(a[j]!=0)
			{
			    n=j+1;
			    break;								
			}
		}//确定阶乘结果保存到数组中，存到数组的第几个元素
		
		for(k=0;k<n;k++)
		{
		    a[k]=a[k]*i;
		}//对存入数组中的数进行乘法运算
		
		for(k=0;k<n;k++)
		{
		    sum=a[k];
			if(sum/100>0)
		    {
			    a[k]=sum%100;
				a[k+1]=a[k+1]+sum/100;
			}
		}//乘法完成后进行进位
	}
	
	for(s=n;s>=0;s--)
	{
	    if(a[s]>=10)
		{
		    printf("%d",a[s]);
		}
		else 
		{
		    printf("0%d",a[s]);
		}
	}//打印完成的阶乘结果（由于03在数组中只显示3故进行相关操作补足
	printf("\n");

	return 0;
}
