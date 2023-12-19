#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5};
    cout<<vec.size()<<endl;
    cout<<vec.capacity()<<endl;
    vec.push_back(17);
    cout<<vec.size()<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
}