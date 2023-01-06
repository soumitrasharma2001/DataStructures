#include <iostream>
using namespace std;
class Stack{
    int size;
    int top;
    int* stack;
    public:
    int getTop(){
        return top;
    }
    Stack(int s){
        stack=new int[s];
        size=s;
        top=-1;
    }
    bool isFull(){
        if(size-1==top){
            return true;
        }
        else{
            return false;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
       if(isFull()){
        cout<<"Stack is full"<<endl;
       }
       else{
       top++;
       stack[top]=data;
       }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
        }
        else{
            int* del;
            del=&stack[top];
            delete del;
            top--;
        }
    }
    int stackTop(){
        return stack[top];
    }
    int stackBottom(){
        return stack[0];
    }
    int peek(int index){
        return stack[top+1-index];
    }
    void printStack(){
        for(int i=top;i>-1;i--){
            cout<<stack[i]<<endl;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.peek(6);
    return 0;
}