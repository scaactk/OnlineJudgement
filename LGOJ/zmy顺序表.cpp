#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MaxSize 100
typedef int ElemType;
typedef struct SqList{
	ElemType data[MaxSize];
	int length;
}SqList;
typedef SqList* LinkList;
LinkList int_initSqList()
{
	LinkList L;
	L=(LinkList)malloc(sizeof(SqList));
	/*if(!L)
	{
		exit(1);
	}*/
	scanf("%d",&L->length);
	if(L->length<MaxSize)
	{
		int i=0;
		while(i<L->length)
		{
			scanf("%d",&L->data[i]);
			i++;
		}
	}
	return L;
}
void Display(LinkList L)
{
	int i=0;
	if(L->length==0)
	{
		printf("-1\n");
		return;
	}
	while(i<L->length-1)
	{
		printf("%d ",L->data[i]);
		i++;
	}
	printf("%d\n",L->data[i]);
}
LinkList Delete(LinkList L)
{
	int x=0;
	int i,n;
	int l=L->length ;
	scanf("%d",&x);
	for(i=0;i<L->length;i++)
	{
		if(L->data[i]==x)
		{
			for(n=i;n<L->length ;n++)
			{
				L->data[n]=L->data[n+1];
				
			}
			L->length--;
			break;
		}
	}
	if(i==l)
	{
		printf("-1\n");
	}
	return L;
}
int main()
{
	int T=0;
	scanf("%d",&T);
	LinkList L;
	//L=int_initSqList();
	while(T>0)
	{
		L=int_initSqList();
		int q=0;
		scanf("%d",&q);
		while(q>0)
		{
			int choice;
			scanf("%d",&choice);
			switch(choice)
			{
				case 0:
					Display(L);
					break;
				case 1:
					L=Delete(L);
					break;
			}
			q--;
		}
		//std::cout<<"FIREST END"<<std::endl; 
		T--;
	 } 
	return 0;
 } 
