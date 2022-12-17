#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;
string pushDominoes(string dominoes) {

    int n = dominoes.size();
    vector<char> ans(n, '.');

    int i, j;

    i = 0, j = 0;
    while (j < n) {
        bool found = false;
        int start = i, end = i;
        while (j < n && dominoes[j] != 'L') {
            if (dominoes[j] == 'R')found = true, i = j;
            j++;
        }
        end = j;
        if (end == n) {
            while (start < n && dominoes[start] != 'R')start++;
            while (start < n)ans[start++] = 'R';
            break;
        }

        if (!found) {
            for (int k = j; k >= i; k--)ans[k] = 'L';
        }
        else {
            while (dominoes[start] != 'R')start++;
            while (start < i)ans[start++] = 'R';
            ans[j] = 'L';
            while (i < j)ans[i++] = 'R', ans[j--] = 'L';
        }
        i = end + 1, j = end + 1;
    }

    string s;
    for (auto c : ans)s += c;
    return s;
}

int main()
{
    string s = ".L.R...LR..L..";
    cout << pushDominoes(s);
    return 0;
}
