// Program: Create an initialize integer type of vector after initilasation sort the elt. with the help of inbuilt function sort algorithm class

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v1={7,5,8,9,2};
    cout<<"Before sorting"<<endl;
    for(int num:v1)
    {
        cout<<num<<" ";
    }
    cout<<"\nAfter sorting"<<endl;
    sort(v1.begin(),v1.end());
    for(int num:v1)
    {
        cout<<num<<" ";
    }
    return 0;
}