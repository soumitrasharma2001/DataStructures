#include <bits/stdc++.h>
using namespace std;
void sort(int* arr,int size){
    int mindex,j,pt,min;
    for(int i=0;i<size-1;i++){
       mindex=i;
       for(int j=i+1;j<size;j++){
          if(arr[j]<arr[mindex]){
             mindex=j;
          }
       }
       swap(arr[mindex],arr[i]);
    }
}

int main()
{   
    int arr[]={3,2,7,19,1};
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