#include"linkedList.h"

List::List():mySize(0),first(0),current(0)
{
}
List::List(dT item)
{
	first=new Node(item);
	current=first;
	mySize=1;

}
List::List(List & other)
{

	other.current=other.first;
	first=new Node(other.current->data);
	mySize=1;
	current=first;
	for(int i=1; i<other.mySize; i++)
	{
		other.current=other.current->next;
		current->next=new Node(other.current->data);
		mySize++;
		current=current->next;
	}
}
List::~List()
{
	while(first!=0)
	{
		//cout<<first->data<<endl; //makes sure my destructor's working
		current=first->next;
		delete first;
		first=current;
	}
}
int List::length()const
{
	return mySize;
}
bool List::empty()const
{
	if(first==0)
		return true;
	else
		return false;
}
bool List::inList(dT item)
{
	current=first;
	while(current->data!=item && current->next!=0)
	{
		current=current->next;
	}
	if(current->data==item)
		return true;
	else
		return false;

}
void List::display(ostream & out)
{
	if(first==0)
		cerr<<"The list is empty. ";
	else
	{
		current=first;
		for(int i=0; i!= mySize; i++)
		{
			out<<current->data<<" ";
			current=current->next;
		}
	}
}
void List::insert(int position, dT item)
{
	if(mySize<position || position<0)
		cerr<< "Invalid position being placed in insert"<<endl;
	else
	{
		Node * temp=getPredecessor(position);
		current=temp->next;
		temp->next=new Node(item);
		temp=temp->next;
		temp->next=current;
		mySize++;
	}

}
void List::erase(int position)
{
	if(mySize<position || position<0)
		cerr<< "Invalid position being placed in the erase"<<endl;
	else
	{
		Node * temp=getPredecessor(position);
		current=temp->next;
		temp->next=current->next;
		delete current;
		mySize--;
	}
}
Node * List::getPredecessor(int position)
{
	Node * temp=0;
	position--;
	if(position<0 || position>=mySize)
	{
		cerr<<"The position passed in getPredecessor is invalid. "<<endl;
		return temp;
	}
	else
	{
		if(position == 0)
			return temp;
		else
		{
			current=first;
			for(int i=0; i!=position; i++)
			{
				temp=current;
				current=current->next;
			}	
		}
		return temp;
	}
}
Node::Node():data(0),next(0)
{
}
Node::Node(dT item)
{
	data=item;
	next=0;
}
ostream & operator<<(ostream & out, List & d)
{
	d.display(out);
	return out;
}
void List::getData()
{
	dT val=0;

	while(val != -1) 
	{
		if(first==0)
		{
			cout<<"Enter in your first value for the list. "<<endl;
			cin>>val;
			first=new Node(val);
			mySize++;
		}
		else
		{
			cout<<"Enter in a values for the your list. or -1 to quit"<<endl;
			cin>>val;
			if(val!=-1)
			{
				current=first;
				first=new Node(val);
				first->next=current;
				mySize++;
			}
		}
	}
	system("cls");
}