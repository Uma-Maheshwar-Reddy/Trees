#include<iostream>
using namespace std;
typedef
struct mstnode
{
	int count;
	int* key;
	mstnode** ptr;
}*mstptr;
void insert(mstptr &h,int d,int m)
{
	if(h==NULL)
	{
		h=new mstnode;
		h->key=new int[m-1];
		for(int i=0;i<m-1;i++)
		{
			h->key[i]=-1;
		}
		h->ptr=new mstptr[m];
		for(int i=0;i<m;i++)
		{
			h->ptr[i]=NULL;
		}
		h->count=1;
		h->key[h->count-1]=d;
	}
	else
	if(h->count!=m-1)
	{
		int i;
		for(i=0;i<h->count;i++)
		{
			if(h->key[i]>d)
			{
				for(int j=i;j<h->count;j++)
				{
					h->key[j+1]=h->key[j];
				}
				break;
			}
		}
		h->key[i]=d;
		h->count++;
	}
	else
	{
		if(d>h->key[m-2]) 
		insert(h->ptr[m-1],d,m);
		else
		{
			for(int i=0;i<=m-2;i++)
			{
				if(d<h->key[i])
				{
					insert(h->ptr[i],d,m);
					break;
				}
			}
		}
	}
}
void print(mstptr &h)
{
	if(h!=NULL)
	{
		for(int i=0;i<h->count;i++)
		{
			print(h->ptr[i]);
			cout<<h->key[i]<<" ";
		}
		print(h->ptr[h->count]);
	}
}
bool search(mstptr &h,int &a)
{
	if(h==NULL) return 0;
	else
	if(a<h->key[0])
	{
		return search(h->ptr[0],a);
	}
	else
	if(a>h->key[h->count-1])
	{
		return search(h->ptr[h->count],a);
	}
	else
	{
		int hi=h->count-1;
		int lo=0;
		int mid;
		while(hi>=lo)
		{
			mid=(hi+lo)/2;
			if(h->key[mid]==a) return 1;
			else
			if(h->key[mid]>a) hi=mid-1;
			else
			lo=mid+1;
		}
		mid=(hi+lo)/2;
		if(h->key[mid]>a) return search(h->ptr[mid],a);
		else
		return search(h->ptr[mid+1],a);
	}
}
bool is_leaf(mstptr h)
{
	for(int i=0;i<=h->count;i++)
	{
		if(h->ptr[i]!=NULL)
		return 0;
	}
	return 0;
}
int min(mstptr &h)
{
	mstptr t=h;
	while(t->ptr[0]!=NULL)
	t=t->ptr[0];
	return t->key[0];
}
int max(mstptr &h)
{
	mstptr t=h;
	while(t->ptr[t->count]!=NULL)
	{
		t=t->ptr[t->count];
	}
	return t->key[t->count-1];
}
mstptr del(mstptr &h,int d)
{	
	int i=0;
	if(h->key[0]>d)
	h->ptr[0]=del(h->ptr[0],d);
	else
	if(h->key[h->count-1]<d)
	h->ptr[h->count]=del(h->ptr[h->count],d);
	else
	{
		while(i<h->count)
		{
			if(h->key[i]==d)
			{
				if(h->ptr[i]!=NULL&&h->ptr[i+1]!=NULL)
				{
					h->key[i]=min(h->ptr[i+1]);
					h->ptr[i+1]=del(h->ptr[i+1],h->key[i]);
				}
				else
				if(h->ptr[i+1]!=NULL)
				{
					h->key[i]=min(h->ptr[i+1]);
					h->ptr[i+1]=del(h->ptr[i+1],h->key[i]);
				}
				else
				if(h->ptr[i]!=NULL)
				{
					h->key[i]=max(h->ptr[i]);
					h->ptr[i]=del(h->ptr[i],h->key[i]);
				}
				else
				{
					for(int j=i;j<h->count;j++)
					{
						h->key[i]=h->key[i+1];
						h->ptr[i+1]=h->ptr[i+2];
						h->count--;
					}
				}
			}
			else
			if(h->key[i]<d&&h->key[i+1]>d)
			{
				h->ptr[i+1]=del(h->ptr[i+1],d);
			}
			i++;
				}
			}
		
		return h;
}
int main()
{
	int m,d,s;
	mstptr root;
	root=NULL;
	cout<<"enter the value of m ";
	cin>>m;
	cout<<"enter the data to insert -1 to end ";
	cin>>d;
	while(d!=-1)
	{
		insert(root,d,m);
		cout<<"enter the data to be inserted ";
		cin>>d;
	}
	print(root);
	cout<<"enter the search value ";
	cin>>s;
	while(s!=-1)
	{
		if(search(root,s))
		{
			cout<<"the value "<<s<<" is found "<<endl;
		}
		else
		{
			cout<<s<<" is not found"<<endl;
		}
		cout<<"enter the search value ";
		cin>>s;
	}
	cout<<"enter the data to be deleted ";
	cin>>d;
	while(d!=-1)
	{
		if(search(root,d))
		{
			root=del(root,d);
		}
		print(root);
		cout<<"enter data to be be deleted ";
		cin>>d;
	}
	return 0;
}
