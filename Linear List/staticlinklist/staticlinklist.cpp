#include "StaticLinkList.h"

StaticLinkList::StaticLinkList()
{
	for(int i = 0; i < MAXSIZE - 1; i++)
		staticlinklist[i].cur = i + 1;
	staticlinklist[MAXSIZE - 1].cur = 0;
}

int StaticLinkList::GetLength() const
{
	int length = 0;
	int i = staticlinklist[MAXSIZE - 1].cur;
	while(i)
	{
		i = staticlinklist[i].cur;
		length++;
	}
	return length;
}

int StaticLinkList::Malloc_SSL()
{
	int i = staticlinklist[0].cur;
	if(staticlinklist[0].cur) //如果还有空间 
	staticlinklist[0].cur = staticlinklist[i].cur; 
	
	return i;
}	

void StaticLinkList::Free_SSL(int k)
{
	staticlinklist[k].cur = staticlinklist[0].cur;
	staticlinklist[0].cur = k;
}

int StaticLinkList::Erase(int i) 
{
	if(i < 1 || i > GetLength() + 1)
		return ERROR;
	int k = MAXSIZE - 1;
	int j;
	for(j = 1; j <= i - 1; j++)
		k = staticlinklist[k].cur; 
	j = staticlinklist[k].cur;
	staticlinklist[k].cur = staticlinklist[j].cur;
	Free_SSL(j);
	return OK;		
}

int StaticLinkList::Insert(int i, int item)
{
	if(i < 1 || i > GetLength() + 1)
		return ERROR;
	int j = Malloc_SSL();
	if(j)
	{
		staticlinklist[j].data = item;
		int k = MAXSIZE - 1;
		for(int l = 1; l <= i - 1; l++)
			 k = staticlinklist[k].cur;
		staticlinklist[j].cur = staticlinklist[k].cur;
		staticlinklist[k].cur = j;
		return OK;
	}
	return ERROR;
}

int StaticLinkList::ListTraverse()
{
	int j = 0;
	int i = staticlinklist[MAXSIZE - 1].cur;
	while(i)
	{
		cout << staticlinklist[i].data << "\t";
		i = staticlinklist[i].cur;
		j++;
	}
	cout << endl;	
	return j;
}
