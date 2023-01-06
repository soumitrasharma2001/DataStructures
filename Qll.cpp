#include <iostream>
using namespace std;
class QLL{
    public:
    struct node{
        int data;
        struct node* next;
    };
    struct node* front;
    struct node* rear;
    struct node* ptr;
    QLL(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int data){
        if(front==NULL){
            struct node* newnode=new node();
            if(newnode==NULL){
                cout<<"queue is full"<<endl;
            }
            else{
            front=newnode;
            rear=newnode;
            newnode->data=data;
            newnode->next=NULL;
            }
        }
        else{
            struct node* newnode=new node();
            newnode->data=data;
            newnode->next=NULL;
            rear->next=newnode;
            rear=rear->next;
        }
    }
    void dequeue(){
        if(front==NULL||rear==NULL){
            cout<<"Queue is empty"<<endl;
        }
        else{
            front=front->next;
        }
    }
    void print(){
        ptr=front;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
};
int main()
{
    QLL q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    return 0;
}