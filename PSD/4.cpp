#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool test(std::vector<int>nums)
{

}

int main()
{
    // vector<int> nums= {1,2,5,7,4,3,6};
    vector<int> nums = {1,2,5,0,3,6,7};
    for(int x: nums)
        cout<<x<<" ";
    cout<<"\nCheck consecutive numbers in the said vector!"<<test(nums)<<endl;
}