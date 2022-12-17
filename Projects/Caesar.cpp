#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int m = 128;
class CaeserCipher {
public:
    string es;
    string ds;
    string s;
    int k;

    void pf() {
        cout << s << endl;
        cout << k << endl;
    }
    string encrypt() {
        es = "";
        for (char c : s)es += (c + k) % m;
        return es;
    }

    string decrypt(int k = -1) {
        if (k == -1)k = this->k;
        ds = "";
        for (auto c : es)ds += (c - k) % m;
        return ds;
    }

    void brute_force() {
        cout << "BRUTE FORCE\n";
        char ok;
        for (int i = 1; i < m; i++) {
            cout << "Key - " << i << endl;
            cout << decrypt(i) << endl;

            cin >> ok;
            if (ok == 'Y')break;
        }
    }


    void freq_analysis() {
        cout << "FREQ ANALYSIS\n";
        // wont work when most frequent letter is not e
        map<char, int> mp;
        for (auto c : es)mp[c]++;
        vector<pair<int, char>> v;
        for (auto m : mp)v.push_back({ m.second, m.first });
        sort(v.rbegin(), v.rend());
        char mf = 'e';

        for (auto p : v) {
            // will be  true when p.second is converted char of e 
            cout << p.first << p.second << endl;;
            int k = (p.second - mf + m) % m;;
            cout << "key " << k << endl;
            cout << decrypt(k) << endl;
        }
    }

};

int main()
{
    CaeserCipher c;
    c.s = "hello world 123 @#*!";
    c.s += "eeeeeeeeee";

    c.k = 3;

    c.pf();
    cout << c.encrypt() << endl;
    //cout << c.decrypt() << endl;
    c.brute_force();
    c.freq_analysis();

    return 0;
}