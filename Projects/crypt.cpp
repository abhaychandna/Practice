#include <iostream>
#include<vector>
using namespace std;

bool three = false;

struct node {
    char letter;
    int value;
};

int convert(string s1, const int count, node* nodes) {
    int res = 0;
    int m = 1, j = 0;
    for (int i = s1.length() - 1; i >= 0; i--) {
        char ch = s1[i];
        for (j = 0; j < count; j++)
            if (nodes[j].letter == ch)
                break;
        res += m * nodes[j].value;
        m *= 10;
    }
    return res;
}


int check(node* nodes, const int count, string s1, string s2, string s3) {
    int val1 = 0, val2 = 0, val3 = 0, m = 1, j, i;
	val1 = convert(s1, count, nodes);
	val2 = convert(s2, count, nodes);
	val3 = convert(s3, count, nodes);

    if (val3 == (val1 + val2))
        return 1;
    return 0;
}

vector<int> vis(10);
string calc = "";
bool cryptArithemetic(int count, node* nodes, int n, string s1, string s2, string s3) {
    if (n == count - 1) { 
        for (int i = 0; i < 10; i++) {
            if (vis[i] == 0) {
                nodes[n].value = i; 
                if (check(nodes, count, s1, s2, s3) == 1) { 
                    cout << "COMBINATION FOUND!!!!\n";
                    for (int j = 0; j < count; j++)
                        cout << " " << nodes[j].letter << " = "
                        << nodes[j].value << endl;
                    
                    int ans = 0;
                    for (auto ch : calc) {
                        for (int j = 0; j < count; j++)
                            if (nodes[j].letter == ch) {
                                ans += nodes[j].value;
                                break;
                            }
                    }
                    cout << "Answer for sum of "<< calc << " is " << ans << endl;
                    return true;
                }
            }
        }
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (vis[i] == 0) {
            nodes[n].value = i; 
            vis[i] = 1;
            if (cryptArithemetic(count, nodes, n + 1, s1, s2, s3)) 
                return true;
            vis[i] = 0;
        }
    }
    return false;
}
bool solve(string s1, string s2, string s3) {
    int uniqueChar = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    vector<int> freq(26);

    vector<string> s;
	int n=2;
    cin >> n;
    cout << "ENTER " << n << " STRINGS\n";
    for (int i = 0; i < 2; i++) {
        string ss;
        cin >> ss;
        s.push_back(ss);
    }
    cout << "ENTER RESULT STRING\n";
    string res;
    cin >> res;
    s.push_back(res);
    for (auto& ss : s) {
        for (int i = 0; i < ss.size(); i++)
            ++freq[ss[i] - 'A'];
    }
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) 
            uniqueChar++;
    node nodes[uniqueChar];
    for (int i = 0, j = 0; i < 26; i++) { 
        if (freq[i] > 0) {
            nodes[j].letter = char(i + 'A');
            j++;
        }
    }
    return cryptArithemetic(uniqueChar, nodes, 0, s1, s2, s3);
}
int main() {
    string s1;
    string s2;
    string s3;
    cout << "ENTER STRINGS\n";
    cin >> s1 >> s2 >> s3;
    //calc = "GROSS";
    if (solve(s1, s2, s3) == false)
        cout << "SOLUTION DOESNT EXIST";
}