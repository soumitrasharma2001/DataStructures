#include <iostream>
using namespace std;
class Queue{
    public:
    int front,rear,size;
    int* queue;
    Queue(int s){
        queue=new int[s];
        front=-1;
        rear=-1;
        size=s;
    }
    void insert(int data){
        if(front==-1){
            front++;
        }
        rear++;
        queue[rear]=data;
    }
    void remove(){
        front++;
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
        if(rear==size-1){
            return true;
        }
        else{
            return false;
        }
    }
    int peek(int index){
        return queue[front+index];
    }
    void printQueue(){
        if(front==-1){
        for(int i=0;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<queue[i]<<" ";
            }
        }
    }
};
int main()
{
    Queue q(7);
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    cout<<q.peek(4)<<endl;
    q.remove();
    q.printQueue();
    return 0;
}