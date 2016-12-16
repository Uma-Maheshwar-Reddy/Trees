#include<iostream>
using namespace std;
typedef
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
}*bstptr;
bstptr create(int a[],int hi,int lo,bstptr l)
{
	if(hi<lo)
	{
		return NULL;
	}
	else
	if(hi==lo)
	{
		l=new bstnode;
		l->data=a[hi];
		l->lchild=NULL;
		l->rchild=NULL;
		return l;
	}
	else
	{
		int mid=(hi+lo)/2;
		l=new bstnode;
		l->data=a[mid];
		l->lchild=create(a,mid-1,lo,l);
		l->rchild=create(a,hi,mid+1,l);
	}
}
void print(bstptr l)
{
	if(l!=NULL)
	{
		cout<<l->data<<" ";
		print(l->lchild);
		print(l->rchild);
    }
    else
    return;
}
int main()
{
	int a[100];
	int n;
	cout<<"enter the number of elements ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter data ";
		cin>>a[i];
	}
	int hi=n-1;
	int lo=0;
	bstptr root,r;
	r=NULL;
	root=create(a,hi,lo,r);
	print(root);
	return 0;
}
