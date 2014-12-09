#include <stdio.h>
#include <stdlib.h>

typedef struct intnode
{
    int num;
	struct intnode *next;
	struct intnode *last;
}INT;

//内存分配函数
INT* my_malloc()       
{
    INT *tmp = (INT*)malloc(sizeof(INT));
	tmp->next = NULL;
	tmp->last = NULL;

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
	head->next->last = node;
	node->last = head;

	return 0;
}

//阶乘功能函数
int func(int n)
{
    int i;                     //循环控制变量
	INT *tmp = NULL;
	INT *new = NULL;

    INT *head = NULL;
	INT *tail = NULL;

    INT *first = NULL;

	head = my_malloc();
	init_node(head,-1);
	tail = my_malloc();
	init_node(tail,-1);

	head->next = tail;
	tail->last = head;

	first = my_malloc();
	init_node(first, 1);
    insertlink(head, first);


//printf("initial success\n");


	for(i=2; i<=n; i++)
	{
        tmp = head->next;
	    while(-1 != tmp->num)
		{
		    tmp->num = tmp->num * i;
//printf("tmp->num=%d\n",tmp->num);
			tmp = tmp->next;
		}
//if(i == 30){break;}
        tmp = tail->last;
		while(-1 != tmp->num)
		{
		    if(tmp->num >= 10)
			{
			    if(-1 == tmp->last->num)
				{
				    new = my_malloc();
                    init_node(new,0);
					insertlink(head,new);
				}

                tmp->last->num = tmp->num / 10 + tmp->last->num;
				tmp->num = tmp->num % 10;
//printf("tmp->next->num=%d\n",tmp->next->num);
//printf("tmp->num=%d\n",tmp->num);
			}

			tmp = tmp->last;
		}
	}


//printf("function success\n");

    tmp = head->next;
	free(tmp);

	while(NULL != tmp->next)
	{
		printf("%d",tmp->num);
        tmp = tmp->nex;
		free(tmp->last);
	}

	free(tail);
 
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
