#include<iostream>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	int data;
	btnode* rchild;
}*btptr;
struct queue
{
	int size;
	int front;
	int rear;
	btptr elem[100];
};
void enque(struct queue &q,btptr &a)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
btptr deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		btptr t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
//recursive creation of a binary tree
void create(btptr &h,int ch)
{
	int c;
	if(h==NULL)
	{
		h=new btnode;
		h->lchild=NULL;
		h->rchild=NULL;
		h->data=ch;
	}
	cout<<"enter the data left of "<<h->data<<" ";
	cin>>c;
	if(c!=-1)
	{
		create(h->lchild,c);
	}
	cout<<"enter data right of "<<h->data<<" ";
	cin>>c;
	if(c!=-1)
	{
		create(h->rchild,c);
	}
}
/*start at root push root into the queue then pop it and then its left and right children and again pop till we reach null*/
void levelprint(btptr h)
{
	struct queue q;
	//queue initialisation
	q.front=-1;
	q.rear=-1;
	q.size=100;
	if(h==NULL)
	{
		return;
	}
	enque(q,h);
	while(q.front!=-1)
	{
		btptr t=deque(q);
		cout<<t->data<<" ";
		if(t->lchild!=NULL)
		{
			enque(q,t->lchild);
		}
		if(t->rchild!=NULL)
		{
			enque(q,t->rchild);
		}
	}
}
int main()
{
	btptr root;
	root=NULL;
	int ch;
	cout<<"enter the root data -1 to end ";
	cin>>ch;
	if(ch!=-1)
	{
		create(root,ch);
	}
	levelprint(root);
	return 0;
}
