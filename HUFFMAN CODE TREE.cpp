#include<iostream>
#include<cstring>
using namespace std;
struct info
{
	int freq;
	char alph;
};
typedef
struct node
{
	node* lchild;
	struct info data;
	node* rchild;
}*nptr;
// function to find minimum and bring the terms after min 1 step forward 
nptr min(nptr s[],int &n)
{
	if(n==1) return s[n-1];
	else
	{
		nptr min=s[0];
		for(int i=1;i<n;i++)
		{
			if(min->data.freq>s[i]->data.freq)
			{
				min=s[i];
			}
		}
		int ref;
		for(ref=0;ref<n;ref++)
		{
			if(s[ref]==min)
			{
				break;
			}
		}
		for(int i=ref;i<n-1;i++)
		{
			s[i]=s[i+1];
		}
		return min;
	}
}
void inorder(nptr h)
{
	if(h!=NULL)
	{
		inorder(h->lchild);
		cout<<h->data.alph<<" ";
		inorder(h->rchild);
	}
}
int main()
{
	nptr s[26];
	int n;
	cout<<"enter  number of alphabets ";
	cin>>n;
	for(int i=0;i<26;i++)
	{
		s[i]=NULL;
	}
	for(int i=0;i<n;i++)
	{
		s[i]=new node;
		cout<<"enter alphabet ";
		cin>>s[i]->data.alph;
		cout<<"enter its freq ";
		cin>>s[i]->data.freq;
		s[i]->lchild=NULL;
		s[i]->rchild=NULL;
	}
	nptr m1,m2;
	nptr root;
	root=NULL;
	while(n!=1)
	{
		m1=min(s,n);
		s[n-1]=NULL;
		n--;
		m2=min(s,n);
		root=new node;
		root->data.alph='*';
		root->data.freq=m1->data.freq+m2->data.freq;
		root->lchild=m1;
		root->rchild=m2;
		s[n-1]=root;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!=NULL)
		{
			root=s[i];
			break;
		}
	}
	inorder(root);
	cout<<endl;
	char in[30];
	//root=s[0];
	nptr h=root;
	cout<<"enter input ";
	cin>>in;
	while(1)
	{
		int len=strlen(in);
		int i=0;
		while(i<=len)
		{
		    if(h->lchild==NULL&&h->rchild==NULL)
			{
				cout<<h->data.alph<<" ";
				h=root;
				if(i==len)
				i++;
			}
			else
			if(in[i]=='1')
			{
				h=h->rchild;
				i++;
			}
			else
			{
				h=h->lchild;
				i++;
			}
			
	    }
	    cout<<"enter in ";
		cin>>in;
	    if(in[0]=='-') break;
    }
	return 0;
}
