#include <iostream>
using namespace std;
class LinkedList{
struct node{
    int data;
    struct node* next;
};
struct node* start;
struct node* ptr;
struct node* prev;
public:
LinkedList(){
    start=NULL;
    ptr=NULL;
}
void traversal(){
    ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
void insert(int d){
    if(start==NULL){
       struct node* newnode=new node();
       newnode->data=d;
       newnode->next=NULL;
       start=newnode;
       ptr=start;
    }
    else{
        ptr=start;
    while(ptr!=NULL){
        if(ptr->next==NULL){
            struct node* newnode=new node();
            newnode->data=d;
            ptr->next=newnode;
            newnode->next=NULL;
            ptr=newnode->next;
        }
        else{
        ptr=ptr->next;
        }
    }
    }
}
void delFirst(){
    struct node* temp;
    temp=start->next;
    delete start;
    start=temp;
} 
void delLast(){
    ptr=start;
    struct node* temp;
    while(ptr!=NULL){
        if(ptr->next->next==NULL){
           temp=ptr->next;
           ptr->next=NULL;
           delete temp;
        }
        ptr=ptr->next;
    }
}
void delMiddle(int d){
    struct node* temp;
    prev=NULL;
    ptr=start;
    if(start->data==d){
        delFirst();
    }
    else{
    while(ptr!=NULL&&ptr->data!=d){
           prev=ptr;
           ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"Node of data "<<d<<" is not found"<<endl;
        }
        else{
        prev->next=ptr->next;
        delete ptr;
        }
    } 
    
}
};
int main()
{
    LinkedList l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.delMiddle(3);
    l.delMiddle(4);
    l.delMiddle(5);
    l.delMiddle(7);
    l.traversal();
    return 0;
}
