#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<ctime>
#include<iomanip>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;


bool safe(int col, int row, vector<string> & board, int n) {

    int dupcol = col;
    int duprow = row;

    //left
    while (dupcol >= 0) {
        if (board[duprow][dupcol] == 'Q') return false;

        dupcol--;
    }

    dupcol = col;
    duprow = row;

    //top-left
    while (dupcol >= 0 && duprow >= 0) {
        if (board[duprow][dupcol] == 'Q') return false;

        duprow--;
        dupcol--;
    }

    dupcol = col;
    duprow = row;

    //bottom-left
    while (dupcol >= 0 && duprow < n) {
        if (board[duprow][dupcol] == 'Q') return false;
        duprow++;
        dupcol--;
    }

    return true;
}

void solve(int col, vector<vector<string>> & ans, vector<string> & board, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (safe(col, row, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;
    vector<string>board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++) {
        board[i] = s;
    }

    solve(0, ans, board, n);
    return ans;

}


int main()
{
    clock_t start, end;

    start = clock();

    //time(&start);

    ios_base::sync_with_stdio(false);

    auto x = solveNQueens(11);

    end = clock();
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(12);
    cout << " millisec " << endl;
    cout << x.size();
}