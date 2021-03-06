#include<iostream>
using namespace std;
typedef
struct bnode
{
	int *arr;
	bnode** ptr;
	bnode* parent;
	int count;
}*bptr;
struct queue
{
	int size;
	int front;
	int rear;
	bptr elem[100];
};
void enque(struct queue &q,bptr &a)
{
	if((q.rear+1)%q.size==q.front)
	{
		cout<<"the queue is full"<<endl;
	}
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elem[q.rear]=a;
	}
}
bptr deque(struct queue &q)
{
	if(q.rear==-1)
	{
		cout<<"the queue is empty "<<endl;
	}
	else
	{
		bptr t=q.elem[q.front];
		if(q.front==q.rear)
		{
			q.rear=-1;
			q.front=-1;
		}
		else
		{
			q.front=(q.front+1)%q.size;
		}
		return t;
	}
}
void levelprint(bptr &h,int &d)
{
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=100;
	bptr temp;
	temp=new bnode;
	temp->arr=new int[2*d];
	temp->ptr=new bptr[2*d+1];
	for(int i=0;i<=2*d;i++)
	{
		if(i!=2*d)
		temp->arr[i]=-1;
		temp->ptr[i]=NULL;
	}
	temp->parent=NULL;
	temp->count=-1;
	if(h==NULL)
	{
		return;
	}
	enque(q,h);
	enque(q,temp);
	bptr t;
	while(q.front!=-1)
	{
		t=deque(q);
		if(t->count==-1&&q.front!=-1)
		{
			cout<<endl;
			enque(q,t);
		}
		else
		{
			for(int i=0;i<=t->count;i++)
			{
				if(i!=t->count)
				cout<<t->arr[i]<<" ";
				if(t->ptr[i]!=NULL)
				enque(q,t->ptr[i]);
				if(i==t->count) cout<<"*";
			}
		}	
	}
}
void print(bptr &h)
{
	if(h!=NULL)
	{
		for(int i=0;i<h->count;i++)
		{
			print(h->ptr[i]);
			cout<<h->arr[i]<<" ";
		}
		print(h->ptr[h->count]);
	}
}
//returns true if a node id not full
bool is_emp(bptr &h,int &d)
{
	if(h!=NULL)
	{
		if(h->count<=2*d-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
//returns true if a node is a leaf
bool is_leaf(bptr &h,int &d)
{
	for(int i=0;i<2*d+1;i++)
	{
		if(h->ptr[i]!=NULL)
		{
			return 0;
		}
	}
	return 1;
}
//adjust all the parent pointers 
void set_parent(bptr &h)
{
	if(h!=NULL)
	{
		for(int i=0;i<=h->count;i++)
		{
			if(h->ptr[i]!=NULL)
			{
				h->ptr[i]->parent=h;
			}
		}
		for(int i=0;i<=h->count;i++)
		{
			if(h->ptr[i]!=NULL)
			{
				set_parent(h->ptr[i]);
			}
		}
	}
}
//bubble sort an array
void sort(int arr[],int count)
{
	int t;
	for(int j=0;j<count-1;j++)
	{
		for(int i=0;i<count-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				t=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=t;
			}
		}
	}
}
//inserts a data into a node and sorts all the pointers and key values accordingly
void insert_sort(bptr &h,int &key)
{
	if(key>h->arr[h->count-1])
	{
		h->arr[h->count]=key;
		h->ptr[h->count]=NULL;
		h->ptr[h->count+1]=NULL;
	}
	else
	if(key<h->arr[0])
	{
		for(int j=h->count;j>0;j--)
		{
			h->arr[j]=h->arr[j-1];
			h->ptr[j+1]=h->ptr[j];
		}
		h->arr[0]=key;
		h->ptr[0]=NULL;
		h->ptr[1]=NULL;
	}
	else
	{
		for(int i=0;i<h->count;i++)
		{
			if(h->arr[i]<key&&h->arr[i+1]>key)
			{
				for(int j=h->count;j>i+1;j--)
				{
					h->arr[j]=h->arr[j-1];
					h->ptr[j+1]=h->ptr[j];
				}
				h->arr[i+1]=key;
				h->ptr[i+1]=NULL;
				h->ptr[i+2]=NULL;
			}
		}
	}
	h->count++;
}
//to insert a node int a btree
bptr insert(bptr &l,bptr &p)
{
	if(l==NULL)
	{
		return p;
	}
	else
	{
		if(p->arr[0]<l->arr[0])
		{
			l->ptr[0]=insert(l->ptr[0],p);
		}
		else
		if(l->arr[l->count-1]<p->arr[0])
		{
			l->ptr[l->count]=insert(l->ptr[l->count],p);
		}
		else
		{
			for(int i=0;i<l->count-1;i++)
			{
				if(l->arr[i]<p->arr[0]&&l->arr[i+1]>p->arr[0])
				{
					l->ptr[i+1]=insert(l->ptr[i+1],p);
				}
			}
		}
		return l;
	}
}
bptr add(bptr &h,int a,int d);
bptr key_redirect(bptr &h,bptr &t,int d,int a);
bptr overflow(bptr &h,int d,int &k);
int main()
{
	bptr h;
	h=NULL;
	int in,d;
	cout<<"enter the value of d for the Bd-tree ";
	cin>>d;
	cout<<"enter the data to be added ";
	cin>>in;
	int i=0;
	while(in!=-1)
	{
		h=add(h,in,d);
		i=0;
		h->parent=NULL;
		set_parent(h);
		levelprint(h,d);
		cout<<endl<<"enter the data to be added ";
		cin>>in;
	}
	levelprint(h,d);
	return 0;
}
/*first all the elem of the node and the data to be inserted are taken in an array and then it is sorted median is taken and then 3 cases*/
//t1 and t2 are the nodes formed by splitting
//case1 :there is no parent to the given node that is the given node is root 
//the parent node is not null and it has empty space then first insert and sort the data and the pointer
//then the split nodes t1 and t2 are on the left and right side of median
//case 3: the node where the data is inserted has a parent which is not empty
//store all info of parent in a temp node and then make its parent a leaf by making all the pointers null
//then call overflow of parent and then again insert the pointers stored in temp and also split nodes t1 and t2
bptr overflow(bptr &root,bptr &h,int d,int &k)
{
	int t[10];
	for(int i=0;i<h->count;i++)
	{
		t[i]=h->arr[i];
	}
	t[h->count]=k;
	sort(t,h->count+1);
	int n=2*d+1;
	int med=t[n/2];
	bptr l=h->parent;
	bptr t1,t2;
	t1=	NULL;
	t2=NULL;
	t1=new bnode;
	t2=new bnode;
	t1->arr=new int[2*d];
	t1->ptr=new bptr[2*d+1];
	t2->arr=new int[2*d];
	t2->ptr=new bptr[2*d+1];
	for(int i=0;i<n/2;i++)
	{
		t1->arr[i]=t[i];
		t2->arr[i]=t[(n/2)+i+1];
	}	
	for(int i=0;i<n;i++)
	{
		t1->ptr[i]=NULL;
		t2->ptr[i]=NULL;
	}
	t1->count=n/2;
	t2->count=n/2;
	if(l==NULL)
	{
		l=new bnode;
		l->arr=new int[2*d];
		l->ptr=new bptr[2*d+1];
		l->count=1;
		l->arr[0]=med;
		
		for(int i=1;i<2*d;i++)
		{
			l->arr[i]=-1;
			l->ptr[i+1]=NULL;
		}
		l->ptr[0]=t1;
		l->ptr[1]=t2;
		return l;
	}
	else
	{
		if(l!=NULL)
		{
			if(is_emp(l,d))
			{
				insert_sort(l,med);
				for(int i=0;i<l->count;i++)
				{
					if(l->arr[i]==med)
					{
						l->ptr[i]=t1;
						l->ptr[i+1]=t2;
					}
				}
				bptr r=l;
				while(r->parent!=NULL)
				r=r->parent;
				return r;
			}
			else
			{
				bptr temp=NULL;
				temp=new bnode;
				temp->arr=new int[2*d];
				temp->ptr=new bptr[2*d+1];
				for(int i=0;i<=2*d;i++)
				{
					if(i!=2*d)
					temp->arr[i]=l->arr[i];
					if(l->ptr[i]==h)
					temp->ptr[i]=NULL;
					else
					temp->ptr[i]=l->ptr[i];
					l->ptr[i]=NULL;
				}
				temp->count=l->count;
				l=key_redirect(root,l,d,med);
				for(int i=0;i<=temp->count;i++)
				{
					if(temp->ptr[i]!=NULL)
					l=insert(l,temp->ptr[i]);
				}
				l=insert(l,t1);
				l=insert(l,t2);
				delete(temp);
				return l;
			}
		}
	}
}
bptr key_redirect(bptr &h,bptr &t,int d,int a)
{
	bptr par=t->parent;
	if(par==NULL)
	return overflow(t,d,a);
	int ind,data;
	bptr sib;
	for(int i=0;i<=par->count;i++)
	{
		if(par->ptr[i]==t)
		{
			ind=i;
			break;
		}
	}
	if(ind!=0&&is_emp(par->ptr[ind-1],d))
	{
		sib=par->ptr[ind-1];
		data=par->arr[ind-1];
		sib->arr[sib->count]=data;
		sib->count++;
		par->arr[ind-1]=t->arr[0];
		t->arr[0]=a;
		sort(t->arr,t->count);
		return h;
	}
	else
	if(ind!=t->count&&is_emp(par->ptr[ind+1],d))
	{
		sib=par->ptr[ind+1];
		data=par->arr[ind];
		sib->arr[sib->count]=data;
		sib->count++;
		sort(sib->arr,sib->count);
		par->arr[ind]=t->arr[t->count-1];
		t->arr[t->count-1]=a;
		sort(t->arr,t->count);
		return h;
	}
	else
	{
		return overflow(h,t,d,a);
	}
}
//add function 
//case1 if h=NULL create new bnode
//case 2 the node is leaf and is empty insert and sort
//case3 move till tj=he leaf node and then if leaf is emp insert and sort else call overflow
bptr add(bptr &h,int a,int d)
{
	if(h==NULL)
	{
		h=new bnode;
		h->arr=new int[2*d];
		h->ptr=new bptr[2*d+1];
		h->count=1;
		for(int i=0;i<2*d;i++)
		{
			h->arr[i]=-1;
			h->ptr[i]=NULL;
		}
		h->ptr[2*d]=NULL;
		h->arr[0]=a;
		h->parent=NULL;
		return h;
	}
	else
	{
		bptr t=h;
		while(!is_leaf(t,d))
		{
			if(t->arr[t->count-1]<a)
			t=t->ptr[t->count];
			else
			{
				for(int i=0;i<t->count;i++)
				{
					if(t->arr[i]>a)
					{
						t=t->ptr[i];
						break;
					}
				}
			}
		}
		if(is_emp(t,d))
		insert_sort(t,a);
		else
		{
			h=key_redirect(h,t,d,a);
		}
		return h;
	}
}
