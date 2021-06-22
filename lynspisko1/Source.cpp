#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct LIST
{
	int field;
	struct LIST *pNext;
};


struct LIST* pHead;


struct LIST* init(int number)
{
	struct LIST *lst;
	lst = (struct LIST*)malloc(sizeof(struct LIST));
	lst->field = number;
	lst->pNext = NULL;
	return lst;
};





struct LIST* add(struct LIST* lst, int number)
{
	struct LIST * pNew;
	pNew = (struct LIST*)malloc(sizeof(struct LIST));
	pNew->field = number;


	pNew->pNext = lst->pNext; //2
	lst->pNext = pNew; //3
	return pNew;
	
}

void delem(int number)
{
	struct LIST *p;
	p = pHead;
	int count = 0;
	while (count<number-1)
	{
		p = p->pNext;
		count++;
	}
	struct LIST *pTmp;
	pTmp = p->pNext;
	p->pNext = p->pNext->pNext;
	free(pTmp);
}
void list()
{
	struct LIST *p;
	p = pHead;
	while (p != NULL)
	{
		printf("%d,", p->field);
		p = p->pNext;
	}
	
}
int main()
{
	pHead = init(5);
	printf("%d\n", pHead->field);
	struct LIST* pTmp = add(pHead, 10);
	printf("%d\n", pTmp->field);
//	pTmp = add(pTmp, 20);
//	pTmp = add(pTmp, 30);
//	pTmp = add(pTmp, 40);
	int v = 77;
	for (int i = 0; i < 20; i++) {
		pTmp = add(pTmp, v++);
		printf("%d\n", pTmp->field);
	}

	delem(0);
	list();
	_getch();
	return 0;
}