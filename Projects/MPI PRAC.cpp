#include<iostream>
#include <vector>

using namespace std;

void gauss(vector<vector<double>> v, vector<double> &x, vector<double> b) {
    int n = v.size();

    for (int j = 0; j < n; j++) {
        int d = b[j];
        for (int i = 0; i < n; i++) {
            if (j != i) {
                d -= v[j][i] * x[i];
            }
        }
        x[j] = d / v[j][j];
    }
    return;
}

int main() {
    int n = 3;
    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n);
    vector<double> x(n);

    b = { 4,7,3 };
    a = {
        {4, 1, 2},
        {3, 5, 1},
        {1, 1, 3}
    };

    x = { 0, 0, 0 };
    
    for (int i = 0; i < 20; i++) {
        gauss(a, x, b);
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    return 0;
}