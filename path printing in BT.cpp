#include<iostream>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	int data;
	btnode* rchild;
}*btptr;
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
void pathprint(btptr h,int arr[],int len)
{
	if(h==NULL)
	{
		return;
	}
	if(h!=NULL)
	{
		arr[len]=h->data;
		len++;
	}
	if(h->lchild==NULL&&h->rchild==NULL)
	{
		for(int i=0;i<len;i++)
	    {
		    cout<<arr[i]<<"  ";
	    }
	    cout<<endl;
	}
	else
	{
		pathprint(h->lchild,arr,len);
		pathprint(h->rchild,arr,len);
	}
}
void inorder(btptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		cout<<h->data<<"  ";
		inorder(h->rchild);
	}
}
int main()
{
	btptr root;
	root=NULL;
	int ch,arr[100];
	cout<<"enter the root data,-1 to end ";
	cin>>ch;
	if(ch!=-1)
	{
		create(root,ch);
	}
	inorder(root);
	cout<<endl;
	pathprint(root,arr,0);
	return 0;
}
