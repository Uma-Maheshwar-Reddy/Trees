#include<iostream>
#include<cstring>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	char data;
	btnode* rchild;
}*btptr;
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
btptr create()
{
	char po[100];
	cout<<"enter a postfix exp ";
    cin>>po;
	int len=strlen(po);
	//cout<<len<<" ";
	stack st;
	st.top=-1;
	st.size=100;
	for(int i=0;i<len;i++)
	{
		btptr t=NULL;
		if(po[i]>='0'&&po[i]<='9')
		{
			t=new btnode;
			t->data=po[i];
			t->lchild=NULL;
			t->rchild=NULL;
			push(st,t);
		}
		else
		{
			btptr t1=pop(st);
			btptr t2=pop(st);
			btptr t=new btnode;
			t->data=po[i];
			t->lchild=t1;
			t->rchild=t2;
			push(st,t);
		}
	}
	btptr res=pop(st);
	return res;
}
int eval(btptr t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		int res=t->data-'0';
	}
	else
	{
		int op1=eval(t->lchild);
		int op2=eval(t->rchild);
		switch(t->data)
		{
			case '+':
				return op1+op2;
			case '-':
				return op2-op1;
			case '*':
				return op1*op2;
			case '/':
				return op2/op1;
		}
	}
}
int main()
{
	btptr root;
	root=create();
	int res;
	res=eval(root);
	cout<<"the ans is  "<<res;
	return 0;
}
