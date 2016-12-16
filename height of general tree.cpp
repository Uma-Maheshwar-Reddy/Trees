#include<iostream>
using namespace std;
typedef
struct gtnode
{
	gtnode* fc;
	int data;
	int height;
	gtnode* ns;
}*gtptr;
void create(gtptr &h,int a)
{
	h=new gtnode;
	h->data=a;
	h->fc=NULL;
	h->ns=NULL;
	int ch;
	cout<<"enter the first child of "<<h->data<<" enter -1 to stop ";
	cin>>ch;
	if(ch!=-1)
	{
		create(h->fc,ch);
	}
	cout<<"enter the next sibling of "<<h->data<<" enter -1 if he has no sibling ";
	cin>>ch;
	if(ch!=-1)
	{
		create(h->ns,ch);
	}
}
int max(gtptr t)
{
	int a;
	a=t->height;
	while(t!=NULL)
	{
		if(a<t->height)
		a=t->height;
		t=t->ns;
	}
	return a;
}
int height(gtptr &h)
{
	if(h==NULL) return -1;
	else
	if(h->fc==NULL) 
	return 0;
	else
	{
		gtptr t=h->fc;
		while(t!=NULL)
		{
			t->height=height(t);
			t=t->ns;
		}
		h->height=max(h->fc)+1;
		return h->height;
	}
}
int main()
{
	gtptr root;
	root=NULL;
	int a;
	cout<<"enter the root data ";
	cin>>a;
	create(root,a);
	int h;
	h=height(root);
	cout<<"the total height is "<<root->height;
	return 0;
}
