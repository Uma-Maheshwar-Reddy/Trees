#include<iostream>
#include<cstring>
using namespace std;
typedef
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
}*bstptr;
//recursive creation of a binary search tree 
void insert(bstptr &h,int a)
{
	if(h==NULL)
	{
		h=new bstnode;
		h->data=a;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	if(h->data>a)
	{
		insert(h->lchild,a);
	}
	else
	{
		insert(h->rchild,a);
	}
}
//inorder LDR printing
void inorder(bstptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		cout<<h->data<<" ";
		inorder(h->rchild);
	}
}
//returns pointer to node with min value
bstptr min(bstptr h)
{
	while(h->lchild!=NULL)
	{
		h=h->lchild;
	}
	return h;
}
/*returns pointer to node;  
if node to be deleted  has two chilren data in node is replaced by min value in right sub tree and then recursively delete 
the data in the right sub tree
else return the present child of the node to be deleted  */
bstptr delnode(bstptr &h,int &a)
{
	if(h==NULL) return h;
	if(h->data>a)
	{
		h->lchild=delnode(h->lchild,a);
	}
	else
	if(h->data<a)
	{
		h->rchild=delnode(h->rchild,a);
	}
	else
	{
		if(h->lchild!=NULL&&h->rchild!=NULL)
		{
			h->data=min(h->rchild)->data;
			h->rchild=delnode(h->rchild,h->data);
		}
		else
		if(h->lchild==NULL)
		{
			bstptr temp=h->rchild;
			delete(h);
			return temp;
		}
		else
		if(h->rchild==NULL)
		{
			bstptr temp=h->lchild;
			delete(h);
			return temp;
		}
	}
	return h;
}
int main()
{
	bstptr root;
	root=NULL;
	int in,del;
	cout<<"enter data -1 to end ";
	cin>>in;
	while(in!=-1)
	{
		insert(root,in);
		cout<<"enter data ";
		cin>>in;
	}
	inorder(root);
	cout<<"\nenter the data to be deleted ";
	cin>>del;
	while(del!=-1)
	{
		root=delnode(root,del);
		inorder(root);
		cout<<"\nenter the data to be deleted ";
		cin>>del;
	}
	return 0;
}
