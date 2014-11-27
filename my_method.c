#include <stdio.h>

#define ARRAY_LEN 300
#define REQUIRE 100


int main()
{
    int array[ARRAY_LEN];
    int i;                         //循环控制变量
	int pos;                       //数组下标控制变量
	int n_pos = ARRAY_LEN - 1;     //数组存放最高位

    //数组初始化
	for(pos=0; pos<ARRAY_LEN; pos++)
	{
	    array[pos] = 0;
	}

    array[0] = 1;                 //从1开始
    //开始阶乘
	for(i=1; i<=REQUIRE; i++)
	{
	    
	    for(pos=0; pos<ARRAY_LEN; pos++)
		{
		    array[pos] = array[pos] * i;
		}

		//乘法结束后开始进位
		for(pos=0; pos<ARRAY_LEN; pos++)
		{
		    if(10 <= array[pos])
			{
			    array[pos+1] = array[pos+1] + (array[pos]/10);
				array[pos] = array[pos] % 10;
			}
		}
	}

    //寻找最高位
	while(0 == array[n_pos])
	{
	    n_pos--;
	}

	//打印结果
	for(pos=n_pos; pos>=0 ; pos--)
	{
	    printf("%d",array[pos]);
	}
	printf("\n");

	return 0;
}
