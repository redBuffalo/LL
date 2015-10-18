#include<iostream>
#ifndef LL_h
#define LL_h

using namespace std;

typedef int dT; // dT=dataType

class Node
{
public:
	dT data;
	Node * next;

	Node(); //creates a empty node
	Node(dT item); //creates a node in a list
};

class List
{
private:
	int mySize;
	Node * first; //pointer to the first node in the list
	Node * current;  //pointer to the current position in the list
	Node * getPredecessor(int postion);//first node is at position 0;
public:
	List(); //creates an empty list 
	List(dT item); //creates a list with an intial node whose data will store item
	List(List & other); //copy constructor
	~List(); 
	int length()const; //returns mySize
	bool empty()const; 
	bool inList(dT item);
	void display(ostream & out); //called by the operator<< to display the list
	void insert(int position, dT item);
	void erase(int position);
	void getData(); //test code fills up my list with values
};
ostream & operator<<(ostream & out, List & d);
#endif