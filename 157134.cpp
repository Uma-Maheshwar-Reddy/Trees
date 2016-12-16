// rollnum 157134  section :A  question: 5-topological sort
#include<iostream>
using namespace std;
// structure for idno and next
struct pointer
{
	struct node* id;
	pointer* next;
};
//node structure
typedef
struct node
{
	int key;
	int count;
	node* next;
    pointer* rand;
}*nptr;
//function to add at end of the list
void addend(nptr &h,int k,int c)
{
	nptr t=h;
	while(t->next!=NULL)
	{
		t=t->next;
    }
	t->next=new node;
	t=t->next;
	t->count=c;
	t->key=k;
	t->next=NULL;
	t->rand=NULL;
}
//function to create a linked list
nptr create()
{
	//int k,c;
	nptr h=NULL;
	h=new node;
	h->count=0;
	h->key=1;
	h->next=NULL;
	h->rand=NULL;
	
	addend(h,2,1);
	addend(h,4,2);
	addend(h,6,1);
	addend(h,10,2);
	addend(h,8,2);
	addend(h,3,2);
	addend(h,5,2);
	addend(h,7,0);
	addend(h,9,1);
	addend(h,0,0);
	return h;
}
void print(nptr &h)
{
	nptr t=h;
	while(t!=NULL)
	{
		cout<<t->key<<" "<<t->count<<endl;
		t=t->next;
	}
}
nptr point(nptr& h,int a)
{
	nptr t=h;
	while(t!=NULL)
	{
		if(t->key==a)
		{
			return t;
		}
		t=t->next;
	}
}
//to assign the idno and next pointers to a random node
void assign(nptr &h)
{
	nptr t;
	t=h;
	t->rand=new pointer;
	t->rand->id=point(h,3);
	pointer* temp;
	t->rand->next=new pointer;
	temp=t->rand->next;
	temp->id=point(h,2);
	temp->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,10);
	t->rand->next=new pointer;
	temp=t->rand->next;
	temp->id=point(h,4);
	temp->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,8);
	t->rand->next=new pointer;
	temp=t->rand->next;
	temp->id=point(h,6);
	temp->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,3);
	t->rand->next=NULL;
	t=t->next->next->next;
	t->rand=new pointer;
	t->rand->id=point(h,5);
	t->rand->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,8);
	t->rand->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,9);
	t->rand->next=new pointer;
	temp=t->rand->next;
	temp->id=point(h,5);
	temp->next=NULL;
	t=t->next;
	t->rand=new pointer;
	t->rand->id=point(h,10);
	t->rand->next=new pointer;
	temp=t->rand->next;
	temp->id=point(h,4);
	temp->next=NULL;
	t=t->next;	
}
//returns 1 if course needs no prequisties
bool to_do(nptr&h,int a)
{
	nptr t=h;
	while(t->next!=NULL)
	{
		if(t->key==a&&t->count==0)
		return 1;
		t=t->next;
	}
	return 0;
}
//searches array to see if a num is already present
bool search(int a[],int s)
{
	for(int i=0;a[i]!=0;i++)
	{
		if(a[i]==s) return 1;
	}
	return 0;
}
void check(nptr& h,int k,int a[],int i)
{
	if(to_do(h,k))
	{
		return ;
	}
	else
	{
		
		nptr t=h;
		while(t!=NULL)
		{
			pointer* temp=t->rand;
			while(temp!=NULL)
			{
				if(temp->id->key==k)
				{
					if(!(search(a,t->key)))
					{
						a[i]=t->key;
						i++;
					}
					check(h,t->key,a,i);
				}
				temp=temp->next;
			}
			t=t->next;
		}
	}
}
int main()
{
	nptr root;
	root=NULL;
	root=create();
	assign(root);
	print(root);
	int co;
	
	cout<<endl<<"enter the course to be done 1,2,3,4,5,6,7,8,9,10 ";
	cin>>co;
	
	while(co!=0)
	{
		int arr[10];int i=0;
	    for(int j=0;j<10;j++)
	    arr[j]=0;
	    
		check(root,co,arr,0);
		
		for(int i=0;arr[i]!=0;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<"is / are the courses to be done before "<<co<<endl;
		cout<<"enter course num 0 to exit ";
		cin>>co;
    }   
	return 0;
}
