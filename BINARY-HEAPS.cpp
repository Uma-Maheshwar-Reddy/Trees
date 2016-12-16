#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void percolate_up(int h[],int &s,int k)
{
	s++;
	h[s]=k;
	int j=s;
	while(j!=0&&h[j]<h[j/2])
	{
		swap(h[j],h[j/2]);
		j=j/2;
	}
}
int  percolate_down(int h[],int &s)
{
	int r=h[1];
	h[1]=h[s];
	s--;
	int j=1;
	while(2*j<=s&&(h[j]>h[2*j]||h[j]>h[2*j+1]))
	{
		if(h[j]>h[2*j]&&h[2*j]<h[2*j+1])
		{
			swap(h[j],h[2*j]);
			j=2*j;
		}
		else
		{
			swap(h[j],h[2*j+1]);
			j=2*j+1;
		}
	}
	return r;
}
int main()
{
	int heap[100];
	int d;
	int s=0;
	heap[s]=-1;
	cout<<"enter data -1 to quit ";
	cin>>d;
	while(d!=-1)
	{
		percolate_up(heap,s,d);
		cout<<"enter data -1 to quit ";
		cin>>d;
	}
	cout<<"enter data you wish to enter ";
	cin>>d;
	percolate_up(heap,s,d);
	for(int i=1;i<=s;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	while(s!=0)
	{
		d=percolate_down(heap,s);
		cout<<d<<" ";
	}
	return 0;
}
