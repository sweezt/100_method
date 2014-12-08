#include <stdio.h>
#include <stdlib.h>

typedef struct intnode
{
    int num;
	struct intnode *next;
}INT;

//内存分配函数
INT* my_malloc()       
{
    INT *tmp = (INT*)malloc(sizeof(INT));
	tmp->next = NULL;

	return tmp;
}

//节点初始化函数
int init_node(INT *node, int num)
{
    if(NULL == node){
	    return 1;
	}

    node->num = num;

	return 0;
}

//插入链表操作
int insertlink(INT *head, INT *node)
{
    if((NULL == head) || (NULL == node) ){
	    return 1;
	}

    node->next = head->next;
    head->next = node;

	return 0;
}

//阶乘功能函数
int func(int n)
{
    int i;                     //循环控制变量
	INT *tmp = NULL;
    INT *last = NULL;

    INT *head = NULL;
	head = my_malloc();
    init_node(head,0);

    INT *first = NULL;
	first = my_malloc();
	init_node(first, 1);
    insertlink(head, first);


//printf("initial success\n");


	for(i=2; i<=n; i++)
	{
        tmp = head->next;
	    while(NULL != tmp)
		{
		    tmp->num = tmp->num * i;
//printf("tmp->num=%d\n",tmp->num);
			tmp = tmp->next;
		}
//if(i == 30){break;}
        tmp = head->next;
		last = head;
		while(NULL != tmp)
		{
		    if(tmp->num >= 10)
			{
			    if(NULL == tmp->next)
				{
				    tmp->next = my_malloc();
                    init_node(tmp->next,0);
				}

                tmp->next->num = tmp->num / 10 + tmp->next->num;
				tmp->num = tmp->num % 10;
//printf("tmp->next->num=%d\n",tmp->next->num);
//printf("tmp->num=%d\n",tmp->num);
			}

			tmp = tmp->next;
		}
	}


//printf("function success\n");


	while(NULL != head->next)
	{
        tmp = head->next;
		last = head;
	    while(NULL != tmp->next)
		{
		    tmp = tmp->next;
			last = last->next;
		}

		printf("%d",tmp->num);
        
		last->next = NULL;
		free(tmp);
	}
 
    return 0;
}

int main()
{
    int n;

	n = 100;

	func(n);

	printf("\n");

	return 0;
}
