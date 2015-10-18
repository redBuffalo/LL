#include"linkedList.h"

int main()
{
	List l1(9);
	List l3;
	int size=0;
	bool h;

	l1.getData();
	cout<<"original list 1: "<<l1<<endl;
	List l2(l1);
	l1.insert(4, 8);
	cout<<"List 1 after an item insert: "<<l1<<endl;
	size=l1.length();
	cout<<"The size of list 1: "<<size<<endl;
	l1.erase(8);
	cout<<"List 1 after an item delete: "<<l1<<endl;
	size=l1.length();
	cout<<"The size is list 1:  "<<size<<endl;
	h=l1.empty();
	cout<<"Is the List empty (0 means false and 1 is ture). "<<h<<endl;
	h=l1.inList(4);
	cout<<"Is the value 4 in the list(0=false and 1=true). "<<h<<endl;

	cout<<"List 1: "<<l1<<endl;
	l1.~List();
	cout<<"list 2: "<<l2<<endl;
	cout<<"List 1 after the destructor call: "<<l1<<endl;

	system("PAUSE");
	return 0;

}
/*
original list 1: 45 65 95 75 8 4 3 6 5 87 45 9
List 1 after an item insert: 45 65 95 8 75 8 4 3 6 5 87 45 9
The size of list 1: 13
List 1 after an item delete: 45 65 95 8 75 8 4 6 5 87 45 9
The size is list 1:  12
Is the List empty (0 means false and 1 is ture). 0
Is the value 4 in the list(0=false and 1=true). 1
List 1: 45 65 95 8 75 8 4 6 5 87 45 9
list 2: 45 65 95 75 8 4 3 6 5 87 45 9
List 1 after the destructor call: The list is empty.
Press any key to continue . . . //ex. test code */
