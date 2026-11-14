#include<iostream>
using namespace std;

class AdjList
{
	struct Node
	{
		int point;
		int time;
		Node *next;
		
		Node()
		{
			point=0;
			time=0;
			next=NULL;
		}
	};
	
	public:
		static const int size=10;
		
		Node *HTable[size];
		
		AdjList()
		{
			for(int i=0;i<size;i++)
			{
				HTable[i]=NULL;
			}
		}
		
	void create()
	{
		int choice;
		cout<<"\nHow many node to add:";
		cin>>choice;
		
		char ch;
		for(int i=0;i<choice;i++)
		{
			Node *t=HTable[i];
			
			do
			{
				Node *n=new Node();
				
				cout<<"\nEnter point:";
				cin>>n->point;
				
				cout<<"\nEnter time:";
				cin>>n->time;
				
				n->next=NULL;
				
				if(t==NULL)
				{
					HTable[i]=n;
					t=n;
				}
				else
				{
					t->next=n;
					t=n;
				}
				
				cout<<"\nAny adjacent node :";
				cin>>ch;
			}while(ch=='Y'||ch=='y');
		}
	}
	
	void display()
	{
		for(int i=0;i<size;i++)
		{
			Node *t=HTable[i];
			
			cout<<"\n"<<i<<":";
			
			while(t!=NULL)
			{
				cout<<t->point<<"|"<<t->time<<"|-->";
				t=t->next;
			}
			
			cout<<"NULL"<<endl;
		}
	}
};

int main()
{
	AdjList A;
	A.create();
	A.display();
	
	return 0;
}
