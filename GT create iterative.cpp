#include<iostream>
using namespace std;
typedef
struct gtnode
{
	gtnode* fc;
	int data;
	gtnode* ns;
}*gtptr;
struct queue
{
	int front;
	int rear;
	int size;
	gtptr elem[100];
};
void enque(queue &q,gtptr &t)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full ";
	}
	else
	{
		if(q.front==-1)
		{
			q.front++;
		}
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=t;
	}
}
gtptr deque(queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the  queue is empty ";
	}
	else
	{
		gtptr t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
gtptr create()
{
	queue q;
	q.size=100;
	q.rear=-1;
	q.front=-1;
	int ch;
	gtptr h=NULL;
	gtptr t=NULL;
	cout<<"enter the root data ";
	cin>>ch;
	h=new gtnode;
	h->data=ch;
	h->fc=NULL;
	h->ns=NULL;
	t=h;
	enque(q,t);
	while(q.rear!=-1)
	{
		t=deque(q);
		cout<<"enter the first child of "<<t->data<<" -1 to end ";
		cin>>ch;
		if(ch!=-1)
		{
			t->fc=new gtnode;
			t=t->fc;
			t->data=ch;
			t->fc=NULL;
			t->ns=NULL;
			enque(q,t);
			cout<<"enter the sibling of "<<t->data<<" -1 to end ";
			cin>>ch;
			while(ch!=-1)
			{
				t->ns=new gtnode;
				t=t->ns;
				t->data=ch;
				t->fc=NULL;
				t->ns=NULL;
				enque(q,t);
				cout<<"enter next sibling of "<<t->data<<" -1 to end ";
				cin>>ch;
			}
		}
	}
	return h;
}
void BFT(gtptr &h)
{
	gtptr t=h;
	queue q;
	q.front=-1;
	q.rear=-1;
	q.size=100;
	gtptr p;
	p=new gtnode;
	p->data=-1;
	p->fc=NULL;
	p->ns=NULL;
	enque(q,t);
	enque(q,p);
	while(q.rear!=q.front)
	{
		t=deque(q);
		if(t->data==-1)
		{
			cout<<endl;
			enque(q,t);
		}
		else
		{
			cout<<t->data<<" ";
			if(t->fc!=NULL)
			{
				t=t->fc;
				while(t!=NULL)
				{
					enque(q,t);
					t=t->ns;
				}
		    }
		}
	}
}
int main()
{
	gtptr root;
	root=create();
	BFT(root);
	return 0;
}
