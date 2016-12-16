#include<iostream>
using namespace std;
typedef
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
}*bstptr;
struct queue
{
	int front;
	int rear;
	int size;
	bstptr elem[100];
};
void enque(queue &q,bstptr &t)
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
bstptr deque(queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the  queue is empty ";
	}
	else
	{
		bstptr t=q.elem[q.front];
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
bstptr create()
{
	bstptr h=NULL;
	struct queue q1;
	q1.front=-1;
	q1.rear=-1;
	q1.size=100;
	int s;
	cout<<"enter the score of the player -1 to end ";
	cin>>s;
	while(s!=-1)
	{
		h=new bstnode;
		h->data=s;
		h->lchild=NULL;
		h->rchild=NULL;
		enque(q1,h);
		cout<<"enter the score of player ";
		cin>>s;
	}
	bstptr t1=NULL,t2=NULL;h=NULL;
	while(q1.front!=q1.rear)
	{
		t1=deque(q1);
		t2=deque(q1);
		h=new bstnode;
		h->data=-1;
		h->lchild=t1;
		h->rchild=t2;
		enque(q1,h);
	}
	h=deque(q1);
	return h;
}
bool is_leaf(bstptr &h)
{
	if(h->lchild==NULL&&h->rchild==NULL)
	return 1;
	else
	return 0;
}
int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	else
	return b;
}
int win(bstptr &h)
{
	if(h==NULL) return -1;
	else
	if(h->lchild==NULL&&h->rchild==NULL)
	{
		return h->data;
    }
	else
	{
		h->data=max(win(h->lchild),win(h->rchild));
		return h->data;
	}
}
void del_leaf(bstptr &h)
{
	bstptr t=h;
	while(!is_leaf(t))
	{
		if(t->lchild->data==t->data)
		t=t->lchild;
		else
		t=t->rchild;
	}
	t->data=-1;
}
int main()
{
	bstptr root=NULL;
	root=create();
	cout<<endl;
	while(1)
	{
		int c;
		c=win(root);
		if(c==-1)
		break;
		cout<<c<<" ";
		del_leaf(root);
    }
	return 0;
}
