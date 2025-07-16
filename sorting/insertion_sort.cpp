#include<iostream>
#include <vector>
using namespace std;
vector<int> insertion_sort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;    
        }
    }
    return arr;
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> sorted_arr=insertion_sort(arr, n);
    for(int i=0; i<n; i++){
        cout<<sorted_arr[i]<<" ";  
    }
    return 0;
}

