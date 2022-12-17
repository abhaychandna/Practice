#include <iostream>
#include<vector>
#include<string>

using namespace std;

int calcHammingDistance(string w1, string w2) {
    int n = w1.size();
    int k = 0;
    for (int i = 0; i < n; i++) 
        if (w1[i] != w2[i]) k++;

    return k;
}

int main()
{
    cout << "Enter no of words - ";
    int n;
    cin >> n;
    vector<string> v(n);
    int minimum_hamming_distance = 500, hamming_distance;
    for (int i = 0; i < n; i++) {
        cout << "Enter word #"<<i+1<<" ";
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            hamming_distance = calcHammingDistance(v[i],v[j]);
            if (hamming_distance < minimum_hamming_distance) minimum_hamming_distance = hamming_distance;
            cout << "Hamming Distance (" << v[i] << "," << v[j] << ") - " << " " << hamming_distance << '\n';
        }
    }

    cout << "Minimum Hamming Distance - " << minimum_hamming_distance << '\n';

}
