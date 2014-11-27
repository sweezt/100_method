#include <stdio.h>
#include <sddlib.h>

typedef struct intnode
{
    int num;
	struct intnode *next;
}INT;


INT* my_malloc()
{
    INT *tmp = (INT*)malloc(sizeof(INT));
	tmp->next = NULL;

	return tmp;
}


int insertlink(INT *head, INT *node)
{
    node->next = head->next;
    head->next = node;

	return 1;
}


int func(int n)
{
    INT *head = my_malloc;
    
    INT *fist = my_malloc;
}


int main()
{
}
