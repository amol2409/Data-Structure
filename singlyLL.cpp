#include<iostream>

using namespace std;

struct node{
	int data;
	struct node * next;
};

struct node * makeNode();
void display(struct node *);
struct node * addFront(struct node *);
void addLast(struct node *);

struct node * createList(int);

int searching(int, struct node *);


int main()
{
	struct node * head;
	int C, key, flag;
	cout<<"Enter the size of the linked List\n";
	int size;
	cin>>size;
	head = createList(size);
	display(head);
	

	while(1)
	{
		cout<<"Enter 1 to add node in front\n";
		cout<<"Enter 2 to add node in end\n";
		cout<<"Enter 3 to search a key\n";
		cout<<"Enter 4 to display the list\n";
		cout<<"Enter 5 to EXIT\n";
		cin>>C;
		switch(C)
		{
			case 1:
				head = addFront(head);
				display(head);
				break;

			case 2:
				addLast(head);
				display(head);
				break;

			case 3:
				cout<<"Enter the Key you wana search";
				cin>>key;
				flag = searching(key, head);
				if (flag==-1)
				{
					cout<<"key is present\n\n\n";
				}
				else
					cout<<"key is not present\n\n\n";
				break;

			case 4:
				display(head);
				break;
			case 5:
				return 1;
				break;
				
			default:
				cout<<"You have entered the wrong choice\n\n\n";
		}


	}
	return 1;
}

struct node * makeNode()
{
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	if(!temp)
		cout<<"Overflow\n";

	temp -> data = rand() % 99;
	temp -> next = NULL;
	return temp;
}

struct node * addFront(struct node *h)
{
	struct node * temp = makeNode();
	temp -> next =  h;
	h = temp;
	return h;	


}

void display(struct node * h)
{
	while(h)
	{
		cout<<h->data<<"  ";
		h = h->next;
	}
	cout<<"\n";
}

void addLast(struct node * h)
{
	struct node * temp = makeNode();
	while(h->next)
	{
		h = h->next;
	}
	h->next = temp;
}

struct node * createList(int n)
{
	struct node * head = (struct node *)malloc(sizeof(struct node));
	if(!head)
		cout<<"overflow\n";
	head -> data = rand() % 99;
	head -> next = NULL;
	n--;
	while(n>0)
	{
		struct node * temp = makeNode();
		temp->next = head;
		head = temp;
		n--;
	}
	return head;
}

int searching(int key, struct node * h)
{
	while(h)
	{
		if(h->data == key)
			return -1;
		else
		{
			h = h->next;
		}
	}
	return -2;
}





