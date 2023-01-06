#include <iostream>
using namespace std;
class StackLL{
    struct node{
    int data;
    struct node* next;
};
struct node* start;
struct node* ptr;
struct node* prev;
struct node* top;
    public:
    StackLL(){
        start=NULL;
        ptr=NULL;
        top=NULL;
    }
    bool isEmpty(){
        if(top==NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
       struct node* n=new node();
       if(n==NULL){
        return true;
       }
       else{
        return false;
       }
    }
    void push(int d){
        if(isFull()){
            cout<<"Stack is full"<<endl;
        }
        else{
           struct node* newnode=new node();
           newnode->data=d;
           newnode->next=top;
           top=newnode;
           if(start==NULL){
            start=top;
           }
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
       struct node* del=top;
       top=top->next;
       delete del; 
        }
    }
    void peek(int index){
        ptr=top;
       for(int i=0;(i<index-1 &&ptr!=NULL);i++){
        ptr=ptr->next;
       }
       if(ptr!=NULL){
        cout<<ptr->data<<endl;
       }
       else{
        cout<<"Out of stack"<<endl;
       }
    }
    void traverse(){
        ptr=top;
        while(ptr!=NULL){
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }
    int stackTop(){
        return top->data;
    }
    int stackBottom(){
        ptr=start;
        return ptr->data;
    }
};
int main()
{
    StackLL s;
    //s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    cout<<s.stackBottom();
    
    return 0;
}