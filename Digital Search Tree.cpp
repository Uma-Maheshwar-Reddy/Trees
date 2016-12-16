#include<iostream>
#include<cstring>
using namespace std;
typedef
struct dstnode
{
	char bin[100];
	dstnode* lchild;
	dstnode* rchild;
}*dstptr;
int btod(char a[])
{
	int len=0;
	for(int i=0;a[i]!='\0';i++)
	{
		len++;
	}
	int p=1;
	int res=0;
	for(int i=len-1;i>=0;i--)
	{
		if(a[i]=='1')
		{
			res=res+p;
		}
		p=p*2;
	}
	return res;
}
dstptr insert(dstptr& root,char a[])
{
	if(root==NULL)
	{
		root=new dstnode;
		strcpy(root->bin,a);
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else
	{
		int a1=btod(root->bin);
		int a2=btod(a);
		if(a1>a2)
		{
			insert(root->lchild,a);
		}
		else
		{
			insert(root->rchild,a);
		}
	}
}
void inorder(dstptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		for(int i=0;i<strlen(h->bin);i++)
		{
			cout<<h->bin[i];
		}
		cout<<"  "<<btod(h->bin);
		cout<<endl;
		inorder(h->rchild);
	}
}
int main()
{
	char a[100];
	int ch;
	dstptr root;
	root=NULL;
	cout<<"do you wish to give input 1:yes -1:no ";
	cin>>ch;
	while(ch==1)
	{
		cout<<"enter a binary number ";
		cin>>a;
		insert(root,a);
		cout<<"do you wish to give input 1:yes -1:no ";
		cin>>ch;
	}
	cout<<endl;
	inorder(root);
	return 0;
}
