#include <iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> decode(vector<int> v) {
    int x = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i]) x ^= i;
    v[x] = !v[x];
    return v;
}

vector<int> encode(vector<int> v, string s) {
    
    int j = 0;
    for (int i = 1; i < v.size(); i++)
        if (!((i & (i - 1)) == 0))
            v[i] = (int)(s[j++] - '0');

    int x = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i]) x ^= i;

    int id = 1;
    for (int i = 0; x > 0; i++, id *= 2)
        if (1 << i & x) {
            v[id] = 1;
            x -= (1 << i);
        }
    
    return v;
}


int main()
{

    string s;
    cin >> s;
    vector<int> v(8);
    
    v = encode(v, s);

    cout << "E- ";
    for (int i = 0; i < v.size();i++)cout << v[i];
    cout << '\n';
    
    int k;
    cout << "enter index to flip\n";
    cin >> k;
    v[k] = !v[k];

    cout << "Received bits\n";
    for (int i = 0; i < v.size(); i++)cout << v[i];
    cout << '\n';

    v = decode(v);

    cout << "D- ";
    for (int i = 0; i < v.size(); i++)cout << v[i];
    cout << '\n';
}
