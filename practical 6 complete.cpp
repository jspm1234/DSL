#include<iostream>
using namespace std;

class CallRecord
{
    int cid[10];
    int ct[10];
    int f,r,size;
    public:
    CallRecord()
    {
        f=-1;
        r=-1;
        size=10;
    }
    
    void add_call(int x,int y)
    {
        if((r+1)%size==f)
        {
            cout<<"\nCan't hold more record...";
        }
        else if(f==-1)
        {
            f=0;
        }
        r=(r+1)%size;
        cid[r]=x;
        ct[r]=y;
    }
    
    void answer_call()
    {
        if(f==-1)
        {
            cout<<"\nNo calls in record...";
        }
        else if(f==r)
        {
            cout<<"\nCurrent call:"<<cid[f];
            cid[f]=-1;
            f=-1;
            r=-1;
        }
        else
        {
            cout<<"\nCurrent call:"<<cid[f];
            cid[f]=-1;
            f=(f+1)%size;
        }
        
    }
    
    void view_queue()
    {
        int i;
        for(i=f;i<=r;i++)
        {
            cout<<"Cust Id"<<"\tCall time";
            cout<<cid[i]<<"\t"<<ct[i];
        }
    }
    
    void is_queue_empty()
    {
        if(f==-1)
        {
            cout<<"\nQueue is empty...";
        }
    }
};

int main()
{
    CallRecord c;
    int ch;
    int x,y;
    while(true){
    cout<<"\n1.Add Call\n2.Answer Call\n3.View Call Queue\n4.Is Queue Empty";
    cout<<"\nEnter your choice:";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
        cout<<"\nRecord Cust Id:";
        cin>>x;
        cout<<"\nRecord Call Time:";
        cin>>y;
        c.add_call(x,y);
        break;
        
        case 2:
        c.answer_call();
        break;
        
        case 3:
        c.view_queue();
        break;
        
        case 4:
        c.is_queue_empty();
        break;
    }
    
}
}