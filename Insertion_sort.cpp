#include <iostream>
using namespace std;
void sort(int* arr,int size){
    int j,key;
    for(int i=1;i<=size-1;i++){
       key=arr[i];
       j=i-1;
       while(arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
       }
        arr[j+1]=key;
    }

}

int main()
{   
    int arr[]={1,7,2,4,10};
    cout<<"Before sorting"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr,5);
    cout<<"After sorting"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}