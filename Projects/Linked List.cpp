#include<iostream>

//Node* head=NULL;

class Node
{
public :
	int data;
	Node* next;
};
Node* head = NULL;
void front(int d)
{
	Node* ptr = new Node();
	ptr->data = d;
	ptr->next = head;

	head = ptr;
}

void back(int d)
{
	Node* ptr = new Node();
	ptr->data = d;
	ptr->next = NULL;

	if (head == NULL)
		head = ptr;
	else
	{
		Node* temp=head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
	}
}

void disp()
{
	Node* temp = head;

	while (temp->next != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	/*Node* temp=new Node();
	temp->data = 5;

	temp->next = head;
	head = temp;*/

	front(4);
	front(30);
	front(5);
	back(10);
	disp();
	
}