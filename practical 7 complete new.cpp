#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

struct node{
    int roll;
    char name[10];
    float marks;
    node *next;
};
class LinkedList
{
    node *head;
    public:
    LinkedList()
    {
        head=NULL;
    }
    
    void create()
    {
        char ch;
        node *n,*t;
        
        do{
            n=new node;
            
            cout<<"\nEnter roll no::";
            cin>>n->roll;
            cout<<"\nEnter name::";
            cin>>n->name;
            cout<<"\nEnter marks::";
            cin>>n->marks;
            
            n->next=NULL;
            
            if(head==NULL)
            {
                head=n;
                t=n;
            }
            else{
                t->next=n;
                t=t->next;
            }
            
            cout<<"\nDo u want to continue::";
            cin>>ch;
        }while(ch=='y'||ch=='Y');
    }
    
    void display()
    {
        node *t;
        t=head;
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else
        {
            while(t!=NULL)
            {
                cout<<t->roll<<"|";
                cout<<t->name<<"|";
                cout<<t->marks<<"|-->";
                t=t->next;
            }
        }
    }
    
    void add_front()
    {
        node *n,*t;
        
        n=new node;
        
        cout<<"\nEnter roll no::";
        cin>>n->roll;
        cout<<"\nEnter name::";
        cin>>n->name;
        cout<<"\nEnter marks::";
        cin>>n->marks;
            
        n->next=NULL;
        
        if(head==NULL)
        {
            head=n;
            t=n;
        }
        else
        {
            n->next=head;
            head=n;
            t=n;
        }
    }
    
    void add_end()
    {
        node *n,*t;
        
        n=new node;
        
        cout<<"\nEnter roll no::";
        cin>>n->roll;
        cout<<"\nEnter name::";
        cin>>n->name;
        cout<<"\nEnter marks::";
        cin>>n->marks;
            
        n->next=NULL;
        
        if(head==NULL)
        {
            cout<<"\nList is empty";
            head=n;
        }
        else
        {
            t=head;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=n;
            t=n;
        }
    }
    
    void add_mid()
    {
        node *n,*t;
        int key;
        int flag=0;
        
        n=new node;
        
        cout<<"\nEnter roll no::";
        cin>>n->roll;
        cout<<"\nEnter name::";
        cin>>n->name;
        cout<<"\nEnter marks::";
        cin>>n->marks;
            
        n->next=NULL;
        
        cout<<"\nAfter which roll to add::";
        cin>>key;
        
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else
        {
            t=head;
            while(t!=NULL)
            {
                if(key==t->roll)
                {
                    n->next=t->next;
                    t->next=n;
                    flag=1;
                    break;
                }
                t=t->next;
            }
            if(flag==0)
            {
                cout<<"\nRoll not found...";
            }
        }
        
    }
    
    void del_front()
    {
        node *t;
        
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else
        {
            t=head;
            head=head->next;
            delete t;
        }
    }
    
    void del_end()
    {
        node *t,*p;
        t=head;
        
        if(head==NULL)
        {
            cout<<"\nList is empty...";
        }
        else if(head->next==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            while(t->next!=NULL)
            {
                p=t;
                t=t->next;
            }
            p->next=NULL;
            delete t;
        }
    }
    
    void del_mid()
    {
        node *t,*p;
        int key,flag=0;
        
        cout<<"Which roll to delete::";
        cin>>key;
        
        if(head==NULL)
        {
            cout<<"List is empty...";
        }
        else if(head->roll==key)
        {
            t=head;
            head=head->next;
            delete t;
        }
        else
        {
           t=head;
           while(t!=NULL)
           {
               if(key==t->roll)
               {
                   p->next=t->next;
                   delete t;
                   flag=1;
                   break;
               }
               else
               {
                   p=t;
                   t=t->next;
               }
           }
           if(flag==0)
           {
               cout<<"Roll not found...";
           }
        }
    }
    
    void search()
    {
        node *t;
        int key,flag=0;
        
        cout<<"Which roll to search::";
        cin>>key;
        
        if(head==NULL)
        {
            cout<<"List is empty...";
        }
        else
        {
            t=head;
            while(t!=NULL)
            {
                if(key==t->roll)
                {
                    cout<<"Roll found...";
                    flag=1;
                    break;
                }
                t=t->next;
            }
            if(flag==0)
            {
                cout<<"Roll not found...";
            }
        }
    }
    
    void update()
    {
        node *t;
        int key,flag=0;
        
        cout<<"Which roll to search::";
        cin>>key;
        
        if(head==NULL)
        {
            cout<<"List is empty...";
        }
        else
        {
            t=head;
            while(t!=NULL)
            {
                if(key==t->roll)
                {
                    cout<<"Roll found...";
                    flag=1;
                    break;
                }
                t=t->next;
            }
            if(flag==0)
            {
                cout<<"Roll not found...";
            }
        }
        if(flag==1)
        {
            cout<<"\nEnter Updated records...";
            
            cout<<"\nEnter roll no::";
            cin>>t->roll;
            cout<<"\nEnter name::";
            cin>>t->name;
            cout<<"\nEnter marks::";
            cin>>t->marks;
            
        }
    }
    
    void sort()
    {
        node *i,*j;
        int temp;
        float temp1;
        char temp2[10];
        
        for(i=head;i!=NULL;i=i->next)
        {
            for(j=head;j->next!=NULL;j=j->next)
            {
                if(j->roll>j->next->roll)
                {
                    temp=j->roll;
                    j->roll=j->next->roll;
                    j->next->roll=temp;
                    
                    strcpy(temp2,j->name);
                    strcpy(j->name,j->next->name);
                    strcpy(j->next->name,temp2);
                    
                    temp1=j->marks;
                    j->marks=j->next->marks;
                    j->next->marks=temp1;
                }
            }
        }
    }
};

int main()
{
    LinkedList l;
    char choice;
    int ch;
    
    while(true)
    {
        cout<<"\n1.create\n2.display\n3.add front\n4.add end\n5.add mid\n6.delete front\n7.delete end\n8.delete mid\n9.search\n10.update\n11.sort";
        cout<<"\nEnter ur choice::";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            l.create();
            break;
            
            case 2:
            l.display();
            break;
            
            case 3:
            l.add_front();
            break;
            
            case 4:
            l.add_end();
            break;
            
            case 5:
            l.add_mid();
            break;
            
            case 6:
            l.del_front();
            break;
            
            case 7:
            l.del_end();
            break;
            
            case 8:
            l.del_mid();
            break;
            
            case 9:
            l.search();
            break;
            
            case 10:
            l.update();
            break;
            
            case 11:
            l.sort();
            break;
        }

    }
}