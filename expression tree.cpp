#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef
struct btnode
{
	int flag;
	union u1
	{
		int num;
		struct symbol
		{
			btnode* lchild;
			char sym;
			btnode* rchild;
		}obj;
	}data;
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
	cout<<"enter a postfix exp num by num ";
    cin>>po;
	int len=strlen(po);
	//cout<<len<<" ";
	stack st;
	st.top=-1;
	st.size=100;
	for(int i=0;i<len;i++)
	{
		//cout<<"hello ";
		btptr t=NULL;
		if(po[i]>='0'&&po[i]<='9')
		{
			t=new btnode;
			t->flag=0;
			(t->data).num=po[i]-'0';
			push(st,t);
		}
		else
		{
			btptr t1=pop(st);
			btptr t2=pop(st);
			btptr t=new btnode;
			t->flag=1;
			((t->data).obj).sym=po[i];
			((t->data).obj).lchild=t1;
			((t->data).obj).rchild=t2;
			push(st,t);
		}
	}
	btptr res=pop(st);
	return res;
}
int eval(btptr t)
{
	
	if(t->flag==0)
	{
		return (t->data).num;
	}
	else
	{
		int op1=eval((t->data).obj.lchild);
		int op2=eval((t->data).obj.rchild);
		switch((t->data).obj.sym)
		{
			case '+':
				return op1+op2;
				break;
			case '-' :
				return op2-op1;
				break;
			case '*':
				return op1*op2;
				break;
			case '/':
				return op2/op1;
				break;
		}
	}
}
int main()
{
	btptr root;
	root=create();
	int ans;
	ans=eval(root);
	cout<<"the result of given exp is "<<ans;
	return 0;
}
