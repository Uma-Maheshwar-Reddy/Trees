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
struct stack
{
	int size;
	gtptr elem[100];
	int top;
};
void push(struct stack &s,gtptr &a)
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
gtptr pop(struct stack &s)
{
	if(s.top==-1)
	cout<<"the stack is empty";
	else
	return s.elem[s.top--];
}
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
void create(gtptr &h,int a)
{
	h=new gtnode;
	h->data=a;
	h->fc=NULL;
	h->ns=NULL;
	int ch;
	cout<<"enter the first child of "<<h->data<<" enter -1 to stop ";
	cin>>ch;
	if(ch!=-1)
	{
		create(h->fc,ch);
	}
	cout<<"enter the next sibling of "<<h->data<<" enter -1 if he has no sibling ";
	cin>>ch;
	if(ch!=-1)
	{
		create(h->ns,ch);
	}
}
void print(gtptr &h)
{
	if(h!=NULL)
	{
		cout<<h->data<<" ";
		if(h->fc!=NULL)
		cout<<"(";
		print(h->fc);
		if(h->ns==NULL)
		cout<<")";
		else
		print(h->ns);
	}
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
void rec_DFT(gtptr &h)
{
	if(h!=NULL)
	{
		//if(h->fc==NULL)
		cout<<h->data<<" ";
		rec_DFT(h->fc);
		rec_DFT(h->ns);
	}
}
void it_DFT(gtptr &h)
{
	gtptr t=h;
	stack st;
	st.top=-1;
	st.size=100;
	push(st,t);
	while(st.top!=-1)
	{
		t=pop(st);
		cout<<t->data<<" ";
		if(t->ns!=NULL) push(st,t->ns);
		if(t->fc!=NULL) push(st,t->fc);
	}
}
int main()
{
	gtptr root;
	root=NULL;
	int a;
	cout<<"enter the root data ";
	cin>>a;
	create(root,a);
	cout<<"(";
	print(root);
	cout<<endl;
	cout<<"the breadth order traversal of the tree is "<<endl;
	BFT(root);
	cout<<endl<<"the depth_first_traversal of the tree is "<<endl;
	rec_DFT(root);
	return 0;
}
