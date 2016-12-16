#include<iostream>
using namespace std;
typedef
struct kdnode
{
	kdnode* lchild;
	int data[2];
	kdnode* rchild;
}*kdptr;
kdptr insert(kdptr h,int d[],int i)
{
	if(h==NULL)
	{
		cout<<"get out ";
		h=new kdnode;
		h->lchild=NULL;
		h->rchild=NULL;
		for(int i=0;i<2;i++)
		{
			h->data[i]=d[i];
		}
		return h;
	}
	else
	{
		if(h->data[i]>d[i])
		{
			h->lchild=insert(h->lchild,d,(i+1)%2);
		}
		else
		if(h->data[i]<d[i])
		{
			h->rchild=insert(h->rchild,d,(i+1)%2);
		}
		else
		{
			h=insert(h,d,(i+1)%2);
		}
		return h;
	}
}
bool equal(int a[],int b[])
{
	for(int i=0;i<2;i++)
	{
		if(a[i]!=b[i])
		{
			return 0;
		}
	}
	return 1;
}
int kdsearch(kdptr t,int key[],int i)
{
	if(t==NULL)
	{
		return -1;
	}
	else
	{
		if(equal(t->data,key))
		{
			return 1;
		}
		else
        if(t->data[i]>key[i])
		{
			return kdsearch(t->lchild,key,(i+1)%2);
		}	
		else
		if(t->data[i]<key[i])
		{
			return kdsearch(t->rchild,key,(i+1)%2);
		}
		else
		{
			return kdsearch(t,key,(i+1)%2);
		}
	}
}
int main()
{
	kdptr root;
	root=NULL;
	int arr[2],ch;
	cout<<"do you wish to add 1:yes 0:no ";
	cin>>ch;
	while(ch==1)
	{
		cout<<"enter 2 elements ";
		for(int i=0;i<2;i++)
		{
			cin>>arr[i];
		}
		root=insert(root,arr,0);
		cout<<"do you wish to add 1:yes 0:no ";
		cin>>ch;
	}
	int key[2];
	cout<<"enter key to be searched ";
	for(int i=0;i<2;i++)
	{
		cin>>key[i];
	}
	int res;
	res=kdsearch(root,key,0);
	if(res==1)
	{
		cout<<"the key is found ";
	}
	else
	{
		cout<<"not found ";
	}
	return 0;
}
