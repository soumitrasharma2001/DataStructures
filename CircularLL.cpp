#include <iostream>
using namespace std;
class CircularLL{
    struct node{
        int index;
        int data;
        struct node* next;
    };
    struct node* start;
    struct node* ptr;
    struct node* last;
    public:
    int size;
    int index;
    CircularLL(){
       start=NULL;
       index=-1;
       size=0;
    }
    void insert(int d){
        if(start==NULL){
            struct node* newnode=new node();
            newnode->data=d;
            newnode->next=newnode;
            start=newnode;
            last=newnode;
            index++;
            size++;
            newnode->index=index;
        }
        else if(start==last){
            struct node* newnode=new node();
            start->next=newnode;
            newnode->data=d;
            newnode->next=start;
            last=newnode;
            index++;
            size++;
            newnode->index=index;
        }
        else{
            ptr=start;
            do{ 
                if(ptr->next==start){
                    struct node* newnode=new node();
                    newnode->data=d;
                    newnode->next=start;
                    ptr->next=newnode;
                    last=newnode;
                    newnode->index=size;
                    size++;
                    break;
                }
                else{
                index++;
                ptr=ptr->next;
                }
            }while(ptr!=start);
        }
    }
    void traverse(){
        ptr=start;
        do{
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }while(ptr!=last->next);
    }
    int elementAtIndex(int ind){
        ptr=start;
        if(size<=ind){
            return -1;
        }
        else{
            while(ptr->index!=ind){
                ptr=ptr->next;
            }
            return ptr->data;
        }
    }
    void deleteAtIndex(int ind){
        struct node* del;
        if(ind>=size){
            cout<<"Deletion has been failed"<<endl;
        }
        else{
        if(ind==0){
            del=start;
            start=start->next;
            size--;
            delete del;
        }
        else{
            ptr=start;
        while(ptr->next->index!=ind){
            ptr=ptr->next;
        }
        del=ptr->next;
        ptr->next=ptr->next->next;
        delete del;
        size--;
        }
    }
    }
};
int main()
{
    CircularLL l;
    l.insert(10);
    l.insert(222);
    l.insert(33);
    l.insert(422);
    l.insert(578);
    l.insert(622);
    l.deleteAtIndex(10);
    l.traverse();
    return 0;
}