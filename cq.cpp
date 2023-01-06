#include <iostream>
using namespace std;
class Cqueue{
    public:
    int* queue;
    int front,rear,size;
    Cqueue(int s){
       queue=new int[s];
       front=0;
       rear=0;
       size=s;
    }
    void enqueue(int data){
       if(isFull()){
        cout<<"Queue is full"<<endl;
       }
       else{
        rear=(rear+1)%size;
        queue[rear]=data;
       }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            front=(front+1)%size;
            cout<<"Dequeing element: "<<queue[front]<<endl;
        }
    }
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if((rear+1)%size==front){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        int f=front,r=rear;
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
        if(f<=r){
        while(f<=r){
            cout<<queue[f]<<" ";
            f++;
        }
        }
        else{
            while(f<=size-1){
                cout<<queue[f]<<" ";
                f++;
            }
        f = 0;
         while (f <= r){
         cout<<queue[f]<<" ";
         f++;
      }
        }
        }
       cout<<endl; 
    }
};
int main()
{
    Cqueue c(5);
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.dequeue();
    c.dequeue();
    c.dequeue();
    c.enqueue(4);
    c.enqueue(5);
    //c.enqueue(5);
    // c.dequeue();
    // c.dequeue();
    // c.dequeue();
    c.print();
    return 0;
}