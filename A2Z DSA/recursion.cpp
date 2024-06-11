#include<bits/stdc++.h>
using namespace std;

int cnt=0;
int printno(int n){
    if(n==0){
        return 0;
    }
    printno(n-1);
    cout<<n<<" ";
    return 0;
}

int main(){
    int n;
    cin>>n;
    printno(n);
    return 0;
}