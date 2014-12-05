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
int inti_node(INT *node, int num)
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

    INT *head = my_malloc;
    
    INT *first = my_malloc;
	inti_node(first, 1);
    insertlink(head, node);

	for(i=2; i<=n; i++)
	{
        tmp = head->next;
	    while(NULL == tmp)
		{
		    tmp->num = tmp->num * i;
			tmp = tmp-<next;
		}

        tmp = head->next;
		while(NULL == tmp)
		{
		    if(tmp->num >= 10){
			    if(NULL == tmp->next)
				{
				    tmp->next = my_malloc();
				}

                tmp->next->num = tmp->num / 10;
				tmp->num = tmp->num % 10;
			}

			tmp = tmp->next;
		}
	}
 
    return 0;
}


int display(INT *head)
{
    if(NULL == head)
	{
	    return 1;
	}

	while()
}
int main()
{
    
}
