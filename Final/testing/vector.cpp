#include<iostream>
#include <vector>
#include <limits>
using namespace std;
int main(){/*
    vector <char> v ;
    cout << "Enter value  : ";
    cin >> v.insert();
    vector <vector <int> > v2(3,vector<int>(3,5));
    v.push_back(6);
    cout << "v : ";
    for(int i = 0 ; i < v.size();i++){
        cout << v[i] << " ";
    } 
    cout << endl;
    cout << "Using iterator \n v : ";
    for(auto i = v.begin();i!=v.end();i++){
        cout << *i << " ";
    }
    cout << endl;*/
    vector <char> v1;
    char inp;
    cout << "Enter data (Enter # to stop) : ";
    while (cin>> inp&&inp!='#'){
        v1.push_back(inp);
    }
    cout << "Inserted data ";
    for(auto i = v1.begin(); i!=v1.end();i++){
        cout << *i << " " <<endl;
    }
}