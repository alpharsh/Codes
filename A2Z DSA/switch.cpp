// Q: Find out the no of notes Rs. 100, 50, 20, 1 can be in Rs 1330

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int hundreds, fiftys, twentys, tens, ones;

    int a;
    cout << "Enter the amount you want to know count of" << endl;
    cin >> a;

    switch (1)
    {

    case 1:
        hundreds = a / 100;
        cout << "Hundreds: " << hundreds << endl;
        a = a - 100 * hundreds;

    case 2:
        fiftys = a / 50;
        cout << "Fifties: " << fiftys << endl;
        a = a - 50 * fiftys;

    case 3:
        twentys = a / 20;
        cout << "Twenties: " << twentys << endl;
        a = a - 20 * twentys;

    case 4:
        ones = a / 1;
        cout << "Ones: " << ones << endl;
        a = a - 1 * ones;
    }
}
