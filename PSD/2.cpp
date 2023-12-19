#include<iostream>
#include<vector>
using namespace std;
// DAFFODIL coding round interview question of FizzBuzz
int main()
{
    vector<string>v1;
    for(int i=1; i<=15; i++)
    {
        if(i%15==0)
        {
            v1.push_back("FizzBuzz");
        }
        else if(i%3==0)
        {
            v1.push_back("Fizz");
        }
        else if(i%5==0)
        {
            v1.push_back("Buzz");
        }
        else
        {
            v1.push_back(to_string(i));
        }
    }

    cout<<v1.size()<<endl;
    for(string st:v1)
    {
        cout<<"\""<<st<<"\""<<", ";
    }
}