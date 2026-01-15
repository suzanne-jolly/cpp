// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int arr[11]={1,2,3,4,5,6,6,7,8,8,2};
    int n=size(arr);
    //int c=0;
    for(int j=0; j<n; j++) {
        int c=0;
    
        
        for(int i=0;  i<n; i++){
            if (arr[i]==arr[j]){
                c+=1;
                
            }
            
        }
        if (c==1){
            cout<<arr[j]<<" ";
        }
                
        
        
    }
    
    return 0;
    
}
