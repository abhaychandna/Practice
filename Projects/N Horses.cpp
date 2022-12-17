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

bool safe(int col, int row, vector<string>& board, int n) {

    vector<int> dx = { 1,-1,1,-1,2,-2,2,-2 };
    vector<int> dy = { 2,2,-2,-2,1,1,-1,-1 };

    for (int i = 0; i < dx.size(); i++) {
        int x = row + dy[i], y = col + dx[i];
        if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 'H')
            return false;
    }
    return true;
}

void solve(int col, int row, vector<vector<string>>& ans, vector<string>& board, int n) {
    if (col == n) {
        solve(0, row + 1, ans, board, n);
        return;
    }

    if (row==n) {
        ans.push_back(board);
        return;
    }

    for (; row < n; col++){
        if (col == n) {
            col = 0;
            row++;
            continue;
        }
        if (safe(col, row, board, n)) {
            board[row][col] = 'H';
            solve(col + 1, row, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNHorses(int n) {

    vector<vector<string>> ans;
    vector<string>board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++) {
        board[i] = s;
    }

    solve(0,0, ans, board, n);
    return ans;

}


int main()
{
    clock_t start, end;

    start = clock();

    //time(&start);

    ios_base::sync_with_stdio(false);

    auto x = solveNHorses(3); // 24 sec for 6

    end = clock();
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(12);
    cout << " millisec " << endl;
    cout << x.size();
}