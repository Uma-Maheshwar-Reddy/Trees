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
//single left rotation 
void single_left_rot(bstptr &k1)
{
	bstptr k2,temp;
	k2=k1->lchild;
	temp=k2->rchild;
	k2->rchild=k1;
	k1->lchild=temp;
	k1=k2;//assigns the root to the new root after rotation;
}
void single_right_rot(bstptr &k1)
{
	bstptr k2,temp;
	k2=k1->rchild;
	temp=k2->lchild;
	k2->lchild=k1;
	k1->rchild=temp;
	k1=k2;//assigns the root to the new root after rotation
}
/*double rotation can be written as two single rotations k1_k2_k3 then first rotate k2_k3  then k1_k3*/
void double_left_rot(bstptr &k1)
{
	single_right_rot(k1->lchild);
	single_left_rot(k1);
}
/*double rotation can be written as two single rotations k1_k2_k3 then first rotate k2_k3  then k1_k3*/
void double_right_rot(bstptr &k1)
{
	single_left_rot(k1->rchild);
	single_right_rot(k1);
}
//fumction that returns the maximum among two elements
int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
//function to return height of tree given its root
int height(bstptr &h)
{
	if(h==NULL) return -1;
	else
	return max(height(h->lchild),height(h->rchild))+1;
}
//insertion operation
void AVL_insert(bstptr &h,int a)
{
	if(h==NULL)
	{
		h=new bstnode;
		h->data=a;
		h->lchild=NULL;
		h->rchild=NULL;
	}
	else
	{
		if(h->data>a)
		{
			AVL_insert(h->lchild,a);//recursive
			if((height(h->lchild)-height(h->rchild))==2) //unbalanced when the two heights differ by 2
			{
				if(a<h->lchild->data)//if a is b/w datas of h and h->lchild then double rot else single rot
				single_left_rot(h);
				else
				double_left_rot(h);
			}
	    }
		else
		if(h->data<a)
		{
			AVL_insert(h->rchild,a);//recursive
			if(height(h->rchild)-height(h->lchild)==2)
			{
				//if a is b/w datas of h and h->rchild then double rot else single rot
				if(a>h->rchild->data)
				{
					single_right_rot(h);
				}
				else
				double_right_rot(h);
			}
		}
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
	int in;
	cout<<"enter the data you wish to insert -1 if you want to stop ";
	cin>>in;
	while(in!=-1)
	{
		AVL_insert(root,in); //calling the insertion function
		cout<<"enter data ";
		cin>>in;
	}
	preorder(root);
	return 0;
}
