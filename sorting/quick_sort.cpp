#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr, int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>=pivot && j>=low+1) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int>&arr, int low, int high){
    if(low>=high) return;
    int p=partition(arr, low, high);
    quicksort(arr, low, p-1);
    quicksort(arr, p+1, high);
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
