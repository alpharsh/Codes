#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    // unordered_map is a hash table based associative container that stores of key value and a mapped value, with O(1) average time complexity for search, insert and delete operations. & for ordered_map, it is O(logn) 

    // creating a map m
    unordered_map<string, int> m; 

    // Inserting values in map m

    // method 1
    pair<string, int> p("harsh", 1);
    m.insert(p);

    // method 2
    m["lives"] = 2;
    m["in"] = 3;
    m["prayagraj"] = 4;
    m["uttar pradesh"] = 5;

    // searching for a key in map m
    cout << m["in"] << endl;
    cout << m.at("lives") << endl;
    cout << m["unknown"] << endl; // if key is not present, it will insert the key with value 0
    cout << m.at("unknown") << endl; // if key is not present, it will throw an exception

    // size of map m
    cout << m.size() << endl;

    // check if key is present in map m
    cout << m.count("harsh") << endl;
    cout << m.count("ucer") << endl;

    // erase a key from map m
    m.erase("uttar pradesh");
    cout << m.size() << endl;

    // print all keys and values in map m
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
}