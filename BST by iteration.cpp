#include<iostream>
using namespace std;
//definition of node
typedef
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
}*bstptr;
//to create and return a BST
bstptr create()
{
	bstptr t;
	t=NULL;
	int in;
	cout<<"enter the data -1 if you want to end ";
	cin>>in;
	if(in!=-1)
	{
		t=new bstnode;
		t->data=in;
		t->rchild=NULL;
		t->lchild=NULL;
	}
	bstptr h=t;
	cout<<"enter data ";
	cin>>in;
	//reach until null and insert the input there
	while(in!=-1)
	{
		while(1)
		{
			if(t->data>in) 
			{
				if(t->lchild==NULL)
				{
					t->lchild=new bstnode;
					t=t->lchild;
					t->data=in;
					t->lchild=NULL;
					t->rchild=NULL;
					break;
				}
				else
				{
					t=t->lchild;
				}
			}
			else
			{
				if(t->rchild==NULL)
				{
					t->rchild=new bstnode;
					t=t->rchild;
					t->data=in;
					t->lchild=NULL;
					t->rchild=NULL;
					break;
				}
				else
				{
					t=t->rchild;
				}
			}
		}
		t=h;
		cout<<"enter data ";
		cin>>in;
	}
	return h;
}
void inorder(bstptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		cout<<h->data<<" ";
		inorder(h->rchild);
	}
}
int main()
{
	bstptr root;
	root=create();
	cout<<endl;
	inorder(root);
	return 0;
}
