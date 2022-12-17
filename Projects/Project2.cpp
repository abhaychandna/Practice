// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile;
    myfile.open("example.txt");
    
    int n = 10;
    for (int i = 1; i <= n; i++) {
        vector<string> v;
        v.push_back(to_string(i));
        char cc = 'a' + i - 1;
        string c = "";
        c += cc;
        v.push_back(c);
        v.push_back(c);
        v.push_back(c);
        v.push_back(c);
        v.push_back(c + "@" + c + ".com");
        string x = "";
        for (int j = 0; j < 9; j++)x += to_string(i);
        v.push_back(x);

        for (auto word : v)
            myfile << word << ",";
        myfile << endl;
    }
    myfile.close();
}
