#include <bits/stdc++.h>
using namespace std;

int setbits(int n){
    int count = 0; 
    while(n){
        if((n&1)==1)
        count++;
        n = n >> 1;
    }
    return count;
}

int main()
{
    int a, b; 
    cout << "enter two no: " << endl;
    cin >> a >> b;
    
    cout << "Sum of set bits: " << (setbits(a)+setbits(b)) << endl;

}