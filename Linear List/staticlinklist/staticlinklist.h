#include <iostream>
#include "public.h"
using namespace std;

typedef struct
{
	char data;
	int cur;
}Node;

class StaticLinkList
{
public:
	StaticLinkList();
	
	int Malloc_SSL();
	void Free_SSL(int k);
	int GetLength() const;
	int Insert(int i, int item);
	int Erase(int i);
	int ListTraverse();
private:
	Node staticlinklist[MAXSIZE];
};
