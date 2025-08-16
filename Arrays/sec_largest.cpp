#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=arr[0];
    int sl=-1;
    for(int i=0; i<n; i++){
        if(arr[i]>l){
            sl=l;
            l=arr[i];
        }
        else{
            if(arr[i]<l && arr[i]>sl){
                sl=arr[i];
            }
        }
    }
    cout<<"Second largest element is"<<sl;
}