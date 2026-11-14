#include<iostream>
#include<string>
#include<limits>
using namespace std;

class Event_Management
{
    public:
    
    int f,r,size;
    string val;
    string q[5];
    
    Event_Management()
    {
        f=-1;
        r=-1;
        size=5;
    }
    
    void add_event(string val)
    {
        if(r==size-1)
        {
            cout<<"\nNo space to add events!!!";
            return;
        }
        else if(f==-1)
        {
            f=0;
        }
        r++;
        q[r]=val;
    }
    
    void next_event()
    {
        if(f==-1 || f>r)
        {
            cout<<"\nNo further events...";
        }
        else
        {
            cout<<"\nUpcoming Event:"<<q[f];
            f++;
        }
    }
    
    void display()
    {
        if(f==-1 || f>r)
        {
            cout<<"\nNo records to show!!!";
            cout<<"\n";
        }
        else
        {
            int i;
            for(i=f;i<=r;i++)
            {
                cout<<i+1<<"."<<q[i]<<" ";
            }
            cout<<"\n";
        }
    }
    
    void cancel_event(string val)
    {
        int flag=0;
        for(int i=f;i<=r;i++)
        {
            if(val==q[i])
            {
                cout<<"\nEvent Found:"<<q[i];
                cout<<"\n";
                int temp = i;
                
                for(int j=temp;j<r;j++)
                {
                    q[j]=q[j+1];
                }
                r--;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"\nEvent not found!!!";
        }
       
    }
};

int main()
{
    Event_Management e;
    string x;
    int ch;
    
    while (true)
    {
    cout<<"\n1.add event\n2.next event\n3.display events\n4.cancel event";
    
    cout<<"\n\nenter your choice:";
    
    cin>>ch;
    
    switch(ch)
    {
        case 1:
        cout<<"\nenter event:";
        cin.ignore();
        getline(cin,x);
        e.add_event(x);
        break;
        
        case 2:
        e.next_event();
        break;
        
        case 3:
        e.display();
        break;
        
        case 4:
        cout<<"\nwhich event to cancel:";
        cin.ignore();
        getline(cin,x);
        e.cancel_event(x);
        break;
    }
    
    }
    
    return 0;
}