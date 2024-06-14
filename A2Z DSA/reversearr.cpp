#include<bits/stdc++.h>
using namespace std;

void printarr(int n, int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// Method 1 using iteration
void revarr(int n, int arr[]){
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}

// Method 2 using recursion(two pointer approach)
void reversearr(int l, int r, int arr[]){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    reversearr(l+1,r-1,arr);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reversearr(0,n-1,arr);
    printarr(n,arr);
    return 0;
}