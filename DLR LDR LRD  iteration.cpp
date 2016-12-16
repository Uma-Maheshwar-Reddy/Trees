#include<iostream>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	int data;
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
void DLR(btptr h)
{
	stack st;
	st.top=-1;
	st.size=100;
	if(h==NULL)
	{
		return;
	}
	else
	if(h->lchild==NULL&&h->rchild==NULL)
	{
		cout<<h->data<<" ";
		return;
	}
	else
	{
		if(h->rchild!=NULL)
		{
			cout<<h->data<<" ";
			push(st,h->rchild);
			h=h->lchild;
		}
		while(1)
		{
			while(h!=NULL)
			{
				cout<<h->data<<" ";
				if(h->rchild!=NULL)
				push(st,h->rchild);
				h=h->lchild;
			}
			if(st.top==-1)
			{
				break;
			}
			h=pop(st);
		}
	}
}
void LDR(btptr h)
{
	stack st;
	st.top=-1;
	st.size=100;
	if(h==NULL)
	{
		return;
	}
	else
	{
		while(1)
		{
			while(h!=NULL)
			{
				push(st,h);
				h=h->lchild;
			}
			if(st.top==-1)
			{
				break;
			}
			h=pop(st);
			cout<<h->data<<" ";
			h=h->rchild;
		}
	}
}
void LRD(btptr h)
{
	if(h==NULL)
	{
		return;
	}
	else
	{
		stack st1,st2;
		st1.size=100;
		st1.top=-1;
		st2.size=100;
		st2.top=-1;
		btptr temp;
		push(st1,h);
		while(st1.top!=-1)
		{
			temp=pop(st1);
			push(st2,temp);
			if(temp->lchild!=NULL)
			{
				push(st1,temp->lchild);
			}
			if(temp->rchild!=NULL)
			{
				push(st1,temp->rchild);
			}
		}
		while(st2.top!=-1)
		{
			temp=pop(st2);
			cout<<temp->data<<" ";
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
	cout<<"the pre order print o/p is  "<<endl;
	DLR(root);
	cout<<endl;
	cout<<"the inorder print o/p is  "<<endl;
	LDR(root);
	cout<<endl;
	cout<<"the post order o/p is "<<endl;
	LRD(root);
	return 0;
}
