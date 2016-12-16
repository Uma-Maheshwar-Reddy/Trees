#include<iostream>
using namespace std;
typedef
struct btnode
{
	btnode* lchild;
	int data;
	btnode* rchild;
}*btptr;
struct queue
{
	int size;
	int front;
	int rear;
	btptr elem[100];
};
void exact_print(btptr h)
{
	
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
	exact_print(root);
	return 0;
}
