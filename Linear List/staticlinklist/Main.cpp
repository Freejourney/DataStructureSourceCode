#include "StaticLinkList.h"

int main()
{
	StaticLinkList L;
	
	L.Insert(1, 'F');
	L.Insert(1, 'E');
	L.Insert(1, 'D');
	L.Insert(1, 'B');
	L.Insert(1, 'A');
	
	cout << "The length of the list: " << L.GetLength() << endl; 
	
	cout << "After insert FEDBA before the head: " << endl;
	L.ListTraverse();
	
	L.Insert(3, 'C');
	cout << "After insert 'C' between 'B' and 'D': " << endl;
	L.ListTraverse();
	
	L.Erase(1);
	cout << "After delete the fisrt data: "<< endl;
	L.ListTraverse();
	
	cout << endl << endl;
	return 0;
}
