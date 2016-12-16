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
	btptr elem[20];
};
struct stack
{
	int size;
	btptr elem[100];
	int top;
};
void push(struct stack &s,btptr &a)
{
	if(s.top==s.size-1)
	{
		cout<<"the stack is full";
	}
	else
	{
		s.top++;
		s.elem[s.top]=a;
	}
}
btptr pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
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
void printstack(struct stack &st)
{
	btptr temp;
	while(st.top!=-1)
	{
		temp=pop(st);
		if(temp->data==-1)
		{
			cout<<endl;
		}
		else
		{
			cout<<temp->data<<" ";
		}
	}
}
void levelprint(btptr &h)
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=20;
	struct stack st;
	st.top=-1;
	st.size=20;
	btptr temp;
	temp=new btnode;
	temp->data=-1;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(h==NULL)
	{
		return;
	}
	enque(q,h);
	enque(q,temp);
	while(q.front!=-1)
	{
		btptr t=deque(q);
		if(t->data==-1)
		{
		    if(q.front!=-1)
			enque(q,t);
		}
		push(st,t);
		if(t->rchild!=NULL)
		{
			enque(q,t->rchild);
		}
		if(t->lchild!=NULL)
		{
			enque(q,t->lchild);
		}
	}
	printstack(st);
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
