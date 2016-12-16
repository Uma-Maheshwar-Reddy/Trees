#include<iostream>
using namespace std;
//definition of a BST node
typedef
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
}*bstptr;
//searches a given key value and returns the ptr
bstptr search(bstptr &h,int a)
{
	bstptr t=h;
	while(t!=NULL)
	{
		if(t->data==a)
		return t;
		else
		if(t->data>a)
		t=t->lchild;
		else
		t=t->rchild;
	}
	return t;
}
//normal insertion into a BST
void insert(bstptr &h,int a)
{
	if(h==NULL)
	{
		h=new bstnode;
		h->lchild=NULL;
		h->data=a;
		h->rchild=NULL;
	}
	else
	{
		if(h->data>a)
		{
			insert(h->lchild,a);
		}
		else
		{
			insert(h->rchild,a);
		}
	}
}
bstptr parent(bstptr &h,bstptr &k)
{
	bstptr temp=h;
	while(temp!=NULL)
	{
		if(temp->lchild==k||temp->rchild==k)
		{
			return temp;
		}
		else
		{
			if(temp->data>k->data)
			{
				temp=temp->lchild;
			}
			else
			temp=temp->rchild;
		}
	}
}
void norm_right_rot(bstptr &h)
{
	bstptr k1=h->lchild;
	bstptr temp=k1->rchild;
	k1->rchild=h;
	h->lchild=temp;
	h=k1;
}
void norm_left_rot(bstptr &h)
{
	bstptr k1=h->rchild;
	bstptr temp=k1->lchild;
	k1->lchild=h;
	h->rchild=temp;
	h=k1;
}

void single_left_rot(bstptr& k3)
{
	bstptr k1,k2;
	k2=k3->rchild;
	k1=k2->rchild;
	norm_left_rot(k3);
	norm_left_rot(k3);
}
void single_right_rot(bstptr &k3)
{
	bstptr k1,k2;
	k2=k3->lchild;
	k1=k2->lchild;
	norm_right_rot(k3);
	norm_right_rot(k3);
}
void double_left_rot(bstptr &k3)
{
	bstptr k1,k2;
	k2=k3->lchild;
	k1=k2->rchild;
	norm_left_rot(k2);
	norm_right_rot(k3);
}
void double_right_rot(bstptr &k3)
{
	bstptr k1,k2;
	k2=k3->rchild;
	k1=k2->lchild;
	norm_right_rot(k2);
	norm_left_rot(k3);
}
void splay(bstptr &h,int &a)
{
	if(h->data==a)
	return;
	bstptr k1,k2,k3;
	k1=search(h,a);
	if(parent(h,k1)==h)
	{
		if(h->lchild==k1)
		{
		    norm_right_rot(h);
			return;
		}
		else
		{
			norm_left_rot(h);
			return;
		}
	}
	else
	{
		k2=parent(h,k1);
		k3=parent(h,k2);
		if(k3->data<k2->data&&k2->data<k1->data)
		{
			single_left_rot(k3);
		}
		else
		if(k3->data>k2->data&&k2->data>k1->data)
		{
			single_right_rot(k3);
		}
		else
		if(k3->data<k2->data&&k2->data>k1->data)
		{
			double_right_rot(k3);
		}
		else
		if(k3->data>k2->data&&k2->data<k1->data)
		{
			double_left_rot(k3);
		}
		splay(h,a);
	}
}
//pre_order DLR printing of a Binary search tree 
void preorder(bstptr &h)
{
	if(h!=NULL)
	{
		cout<<h->data<<" ";
		preorder(h->lchild);
		preorder(h->rchild);
	}
}
int main()
{
	bstptr root;
	root=NULL;
	int in,s;
	cout<<"enter the data you wish to insert -1 if you want to stop ";
	cin>>in;
	while(in!=-1)
	{
		insert(root,in);
		cout<<"enter data ";
		cin>>in;
	}
	preorder(root);
	cout<<"enter the data you wish to splay ";
	cin>>s;
	while(s!=-1)
	{
		splay(root,s);
		preorder(root);
		cout<<"enter the data you wish to spaly ";
		cin>>s;
	}
	return 0;
}
