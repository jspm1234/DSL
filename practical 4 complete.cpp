#include<iostream>
#include<string>
using namespace std;

class Test{
    public:
        string stk[10];
        string val;
        int top_undo,top_redo,size;
    
    Test(){
        size=10;
        top_undo=-1;
        top_redo=size-1;
    }
    
    void make_change(string val){
        if(top_undo==size-1){
            cout<<"stack is full...";
        }
        else{
            top_undo++;
            stk[top_undo]=val;
        }
    }
    
    void undo(){
        if(top_undo==-1){
            cout<<"stack is empty...";
        }
        else{
            string key=stk[top_undo];
            stk[top_redo]=key;
            top_undo--;
            top_redo--;
        }
    }
    
    void redo(){
        if(top_redo==size-1){
            cout<<"no element to redo...";
        }
        else{
            top_redo++;
            string key=stk[top_redo];
            top_undo++;
            stk[top_undo]=key;
        }
    }
    
    void display(){
        int i;
        for(i=0;i<=top_undo;i++){
            cout<<stk[i]<<"";
        }
    }
};

int main(){
    Test t;
    string val;
    int ch;
    
    do{
        cout<<"\n1.make changes\n2.undo\n3.redo\n4.display";
        cout<<"\nenter your choice:";
        cin>>ch;
        
        switch(ch){
            case 1:
            cout<<"enter the value:";
            cin>>val;
            t.make_change(val);
            break;
            
            case 2:
            t.undo();
            break;
            
            case 3:
            t.redo();
            break;
            
            case 4:
            t.display();
            break;
        }
    }while(ch!=0);
}