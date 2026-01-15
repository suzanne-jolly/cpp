// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;


void swapMaxMin(int arr[], int size){
    if (size<=1){
        return ;
    }
    int minidx=0;
    int maxidx=0;
    for (int i=1; i<size; i++){
        if (arr[i]<arr[minidx]){
            minidx=i;
        }
        if (arr[i]>arr[maxidx]){
            maxidx=i;
        }
        
    }
    swap(arr[minidx],arr[maxidx]);

    
}

int main() {
    int arr[5]={8,9,235,-1,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    swapMaxMin(arr, n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
        
        
    

return 0;
}
